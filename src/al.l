%{
#include <string.h>
#include <stdlib.h>
#include "../include/parser.h"
#if defined(WIN32)
#define YY_NO_UNISTD_H
static int isatty(int i) { return 1; }
#elif defined (_WIN32_WCE)
#define YY_NO_UNISTD_H 
static int isatty(void *i) {return 1;}
#endif

unsigned int tokenCounter = 0, tmpLine;
unsigned short  strError = 0, mlCommentsPending = 0, foundErrors = 0;
char stringBuf[8192];
%}


%option noyywrap
%option yylineno

%x MULTILINE_COMMENT
%x STRING


INTCONST    [0-9]+
REAL  {INTCONST}+"."{INTCONST}+

KW_IF  "if"
KW_ELSE "else"
KW_WHILE "while"
KW_FOR "for"
KW_RETURN "return"
KW_BREAK "break"
KW_CONTINUE "continue"
KW_NOT "not"
KW_OR "or"
KW_AND "and"
KW_LOCAL "local"
KW_TRUE "true"
KW_FALSE "false"
KW_NIL "nil"
KW_FUNCTION "function"

OPERATOR_PLUS "+"
OPERATOR_MINUS "-"
OPERATOR_STAR "*"
OPERATOR_DIV "/"
OPERATOR_ASSIGN "="
OPERATOR_PERCENT "%"
OPERATOR_EQ "=="
OPERATOR_NOTEQ "!="
OPERATOR_PLUSPLUS "++"
OPERATOR_MINUS_MINUS "--"
OPERATOR_GREATER ">"
OPERATOR_LESS "<"
OPERATOR_GREATER_EQ ">="
OPERATOR_LESS_EQ "<="

PUNCTUATION_LSCOPE "{"
PUNCTUATION_RSCOPE "}"
PUNCTUATION_LBRACKET "["
PUNCTUATION_RBRACKET "]"
PUNCTUATION_LPAR "("
PUNCTUATION_RPAR ")"
PUNCTUATION_SEMIC ";"
PUNCTUATION_COMMA ","
PUNCTUATION_COLON ":"
PUNCTUATION_DBLCOLON "::"
PUNCTUATION_DOT "."
PUNCTUATION_DBLDOT ".."

ID [a-zA-Z]([a-zA-Z0-9_])* 

%%

[\r\n \t\v] {}
"//".*+"\n" {}

"\"" { tokenCounter++; BEGIN(STRING); tmpLine = yylineno; }// If opening of string
<STRING>"\n" {strError = 1;}			// If '\n' then mark syntax error
<STRING>[^\\\"]* {strcat(stringBuf, yytext);}// If not str ending then append it
<STRING>"\\\n" {}						// If '\' + '\n' then ignore 
<STRING>"\\n" {strcat(stringBuf,"\n");}	// If '\' + 'n' then add escaped char
<STRING>"\\t" {strcat(stringBuf,"\t");}	// If '\' + 't' then add escaped char
<STRING>"\\\"" {strcat(stringBuf,"\"");}// If '\' + quote then add escaped char
<STRING>"\\\\" {strcat(stringBuf,"\\");}// If '\' + '\' then add escaped char
<STRING><<EOF>> {	
	printf("%d: #ERROR: Unterminated STRING: \"%s\n", tmpLine, stringBuf);
	foundErrors = 1;
	return STR;
}
<STRING>"\\"[^nt\\<<EOF>>\"] {
	strcat(stringBuf, yytext);
	printf("%d: #WARNING: Invalid escape character\
	'\\%c' in string. \n", yylineno, yytext[1]);
}
<STRING>"\"" {							// If closing of string detected
	stringBuf[strlen(stringBuf)+1] = '\0';			// Just append the null terminator
	if (strError) {						// If error has been detected
		BEGIN(INITIAL);
		printf("%d: #ERROR: Multiline STRING: \"%s\".\n", tmpLine, stringBuf);
		foundErrors = 1;
		strError = 0;					// Reset string error flag
	}
	else{							// If no errors detected put in list
		yylval.stringVal = strdup(stringBuf);
	}
	BEGIN(INITIAL);							
	stringBuf[0] = '\0';					// Empty the string buffer
	return STR;						// and return.
}


<MULTILINE_COMMENT>"/*" {		// For each additional multiline comment start
	mlCommentsPending++;		// increment the pending comments counter
	BEGIN(MULTILINE_COMMENT);
}
<MULTILINE_COMMENT>[/]		{}	// Eat up plain '/'s	
<MULTILINE_COMMENT>"*"+[^*/]* 		// Eat up '*'s not followed by '/'s	

<MULTILINE_COMMENT>[^*/]*  		// Eat anything that's not a '*' //should not be here
<MULTILINE_COMMENT>"*/" {		// If you encounter '*' and '/'
	mlCommentsPending--;		// consecutively, then decrement the counter
	
	if(mlCommentsPending == 0){ 	// If no more mlcomments pending, then return
		BEGIN(INITIAL);
	}
}
<MULTILINE_COMMENT><<EOF>> {		// If you encounter EOF and there
			 		//are  still pending ML comments,	
	printf("%d: #ERROR: Unterminated MULTILINE_COMMENT.\n", tmpLine);
	foundErrors = 1;		// it is a syntax error.
}


{KW_IF} { tokenCounter++; return IF; }
{KW_ELSE} { tokenCounter++; return ELSE; }

{KW_WHILE} { tokenCounter++; return WHILE; }

{KW_FOR} { tokenCounter++; return FOR; }

{KW_RETURN} { tokenCounter++; return RETURN; }

{KW_BREAK} { tokenCounter++; return BREAK; }

{KW_CONTINUE} { tokenCounter++; return CONTINUE; }

{KW_NOT} { tokenCounter++; return NOT; }

{KW_OR} { tokenCounter++; return OR; }

{KW_AND} { tokenCounter++; return AND; }

{KW_LOCAL} { tokenCounter++; return LOCAL; }

{KW_TRUE} { tokenCounter++; return TRUE; }

{KW_FALSE} { tokenCounter++; return FALSE; }

{KW_NIL} { tokenCounter++; return NIL; }

{KW_FUNCTION} { tokenCounter++; return FUNCTION; }

{OPERATOR_PLUS} { tokenCounter++; return '+'; }

{OPERATOR_MINUS} { tokenCounter++; return '-'; }

{OPERATOR_STAR} { tokenCounter++; return '*'; }

{OPERATOR_DIV} { tokenCounter++; return '/'; }

{OPERATOR_PERCENT} { tokenCounter++; return '%'; }

{OPERATOR_ASSIGN} { tokenCounter++; return '='; }

{OPERATOR_EQ} { tokenCounter++; return EQ; }

{OPERATOR_NOTEQ} { tokenCounter++; return NOT_EQ; }

{OPERATOR_PLUSPLUS} { tokenCounter++; return PLUS_PLUS; }

{OPERATOR_MINUS_MINUS} { tokenCounter++; return MINUS_MINUS; }

{OPERATOR_GREATER} { tokenCounter++; return '>'; }

{OPERATOR_LESS} { tokenCounter++; return '<'; }

{OPERATOR_GREATER_EQ} { tokenCounter++; return GREATER_EQ; }

{OPERATOR_LESS_EQ} { tokenCounter++; return LESS_EQ; }

{INTCONST} { 
	tokenCounter++;
	yylval.realVal = atof(yytext);
	return NUMBER;
}

{REAL} {
	tokenCounter++;
	yylval.realVal = atof(yytext);
	return NUMBER;
}

{PUNCTUATION_LSCOPE} { tokenCounter++; return '{'; }

{PUNCTUATION_RSCOPE} { tokenCounter++; return '}'; }

{PUNCTUATION_LBRACKET} { tokenCounter++; return '['; }

{PUNCTUATION_RBRACKET} { tokenCounter++; return ']'; }

{PUNCTUATION_LPAR} { tokenCounter++; return '('; }

{PUNCTUATION_RPAR} { tokenCounter++; return ')'; }

{PUNCTUATION_SEMIC} { tokenCounter++; return ';'; }

{PUNCTUATION_COMMA} { tokenCounter++; return ','; }

{PUNCTUATION_COLON} { tokenCounter++; return ':'; }

{PUNCTUATION_DBLCOLON} { tokenCounter++; return DBLCOLON; }

{PUNCTUATION_DOT} { tokenCounter++; return '.'; }

{PUNCTUATION_DBLDOT} { tokenCounter++; return DBLDOT; }

{ID} { tokenCounter++; yylval.stringVal = strdup(yytext); return ID; }
  
.	{
	printf("%d: #ERROR: Character \"%s\" not in grammar.\n", yylineno, yytext);
	foundErrors = 1; //TODO move print to parser
	return UNRECOGNIZED;
}

%%

