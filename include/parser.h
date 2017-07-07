/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     FOR = 261,
     NOT = 262,
     RETURN = 263,
     BREAK = 264,
     CONTINUE = 265,
     LOCAL = 266,
     DBLCOLON = 267,
     TRUE = 268,
     FALSE = 269,
     NIL = 270,
     FUNCTION = 271,
     EQ = 272,
     NOT_EQ = 273,
     DBLDOT = 274,
     STR = 275,
     PLUS_PLUS = 276,
     MINUS_MINUS = 277,
     GREATER_EQ = 278,
     LESS_EQ = 279,
     AND = 280,
     OR = 281,
     UNRECOGNIZED = 282,
     ID = 283,
     NUMBER = 284,
     UMINUS = 285,
     DBL_DOT = 286
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define NOT 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define LOCAL 266
#define DBLCOLON 267
#define TRUE 268
#define FALSE 269
#define NIL 270
#define FUNCTION 271
#define EQ 272
#define NOT_EQ 273
#define DBLDOT 274
#define STR 275
#define PLUS_PLUS 276
#define MINUS_MINUS 277
#define GREATER_EQ 278
#define LESS_EQ 279
#define AND 280
#define OR 281
#define UNRECOGNIZED 282
#define ID 283
#define NUMBER 284
#define UMINUS 285
#define DBL_DOT 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 15 "parser.y"

	char * 			stringVal;
	int				intVal;
	double 			realVal;
	struct Symbol * symbolVal;
	struct Expr   * exprVal;



/* Line 2068 of yacc.c  */
#line 122 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


