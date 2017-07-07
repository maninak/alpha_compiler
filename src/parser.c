/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "./src/parser.y" /* yacc.c:339  */

	#include "../include/manage.h"
	#include "../include/SymbolTable.h"
	#include "../include/expressions.h"
	#include "../include/ExprList.h"
	#include "../include/ExprDblList.h"
    #include "../include/generator.h"
	#include "../include/exeOutput.h"

	int yyerror (const char* yaccProvidedMessage);
	int yylex (void);

#line 79 "./src/parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 18 "./src/parser.y" /* yacc.c:355  */

	char *					stringVal;
	int						intVal;
	double					realVal;
	struct Symbol		*	SymbolVal;
	struct ExprList		*	ExprListVal;
	struct ExprDblList	*	ExprDblListVal;
	struct Expr			*	ExprVal;

#line 191 "./src/parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 208 "./src/parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   688

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,     2,     2,
      43,    44,    35,    33,    46,    34,    39,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
      32,    30,    31,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    38,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    60,    61,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    97,   100,   101,   102,   103,   104,   105,   106,
     107,   110,   113,   114,   115,   116,   117,   120,   121,   122,
     123,   126,   127,   128,   129,   132,   133,   134,   137,   138,
     141,   144,   147,   148,   151,   152,   155,   156,   159,   161,
     162,   165,   167,   167,   175,   177,   183,   184,   187,   190,
     193,   194,   195,   196,   197,   200,   201,   204,   205,   208,
     209,   212,   215,   218,   221,   224,   227,   230,   231,   234,
     237
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "FOR", "NOT",
  "RETURN", "BREAK", "CONTINUE", "LOCAL", "DBLCOLON", "TRUE", "FALSE",
  "NIL", "FUNCTION", "EQ", "NOT_EQ", "DBLDOT", "STR", "PLUS_PLUS",
  "MINUS_MINUS", "GREATER_EQ", "LESS_EQ", "AND", "OR", "UNRECOGNIZED",
  "ID", "NUMBER", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "'.'", "DBL_DOT", "'['", "']'", "'('", "')'", "';'", "','",
  "'{'", "':'", "'}'", "$accept", "program", "stmts", "stmt", "expr", "M",
  "term", "assignexpr", "primary", "lvalue", "tableitem", "call",
  "callsuffix", "normcall", "methodcall", "elist", "exprs", "tablemake",
  "indexed", "indexedelems", "indexedelem", "block", "$@1", "funcdef",
  "funcprefix", "funcname", "funcargs", "funcbody", "const", "idlist",
  "ids", "if", "ifprefix", "elseprefix", "while", "whilestart",
  "whilecond", "forstmt", "returnstmt", "break", "continue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      61,    62,    60,    43,    45,    42,    47,    37,   285,    46,
     286,    91,    93,    40,    41,    59,    44,   123,    58,   125
};
# endif

#define YYPACT_NINF -112

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-112)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-3)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,     8,   199,  -112,  -112,   -29,  -112,   -24,   338,   279,
     -20,   -10,    -7,    21,  -112,  -112,  -112,    23,  -112,    -2,
      -2,  -112,  -112,  -112,   338,    16,   314,  -112,  -112,  -112,
     396,  -112,  -112,  -112,    40,  -112,   -19,  -112,  -112,  -112,
      10,  -112,  -112,   242,  -112,    11,  -112,  -112,  -112,  -112,
     338,   338,  -112,  -112,   419,  -112,  -112,  -112,  -112,  -112,
    -112,    39,   -28,   -19,   -28,  -112,   338,   372,    14,    18,
      19,   465,    27,  -112,   338,   338,   338,   338,  -112,  -112,
     338,   338,   338,   338,   338,   338,   338,  -112,  -112,  -112,
     338,    56,    59,   338,   338,  -112,  -112,  -112,    60,   338,
     338,    61,    43,    90,   338,   242,   487,    48,  -112,    51,
     351,   338,  -112,  -112,  -112,    50,  -112,  -112,    55,   149,
     615,   615,   651,   651,   338,   338,   651,   651,    -3,    -3,
    -112,  -112,  -112,   573,  -112,    57,   531,    58,  -112,   552,
      64,    53,    65,  -112,  -112,  -112,   242,   509,  -112,  -112,
     338,    55,   338,   372,    19,  -112,  -112,   636,   594,   338,
    -112,  -112,  -112,  -112,    73,  -112,  -112,  -112,  -112,   442,
      89,  -112,  -112,    66,    53,   338,  -112,  -112,  -112,    74,
     242,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    15,     0,    94,     0,     0,     0,
       0,     0,     0,     0,    83,    84,    82,    77,    81,     0,
       0,    14,    47,    80,     0,    63,     0,    16,    72,     3,
       0,    31,    17,    40,    42,    50,    43,    44,    12,    13,
       0,    46,     6,     0,     7,     0,     8,     9,    10,    11,
       0,    63,    35,    98,     0,    99,   100,    48,    49,    76,
      75,     0,    36,     0,    38,    34,     0,    65,     0,     0,
      70,     0,     0,     4,     0,     0,     0,     0,    32,    32,
       0,     0,     0,     0,     0,     0,     0,     5,    37,    39,
       0,     0,     0,     0,    63,    56,    58,    59,     0,     0,
      63,    86,     0,    89,     0,     0,     0,     0,    97,     0,
       0,     0,    62,    66,    67,     0,    68,    33,    45,     0,
      27,    28,    24,    26,     0,     0,    23,    25,    18,    19,
      20,    21,    22,    41,    51,     0,     0,     0,    53,     0,
       0,    88,     0,    79,    74,    92,     0,     0,    93,    91,
       0,     0,     0,    65,    70,    57,    73,    29,    30,    63,
      52,    60,    54,    55,     0,    85,    78,    90,    95,     0,
       0,    64,    69,     0,    88,    63,    71,    61,    87,     0,
       0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,    31,   -41,    -8,    49,  -112,  -112,  -112,   -14,
    -112,    28,  -112,  -111,  -112,   -48,   -34,  -112,  -112,   -25,
      15,    29,  -112,   -22,  -112,  -112,  -112,  -112,  -112,  -112,
     -42,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    29,    30,   124,    31,    32,    33,    34,
      35,    36,    95,    96,    97,    68,   112,    37,    69,   116,
      70,    38,    73,    39,    40,    60,   102,   144,    41,   142,
     165,    42,    43,   146,    44,    45,   105,    46,    47,    48,
      49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    54,   103,   107,    72,    62,    64,   155,     3,    12,
      13,    91,    92,    93,    50,    94,    65,    67,    71,    51,
      98,    57,    99,     8,   100,    55,    22,    12,    13,    14,
      15,    16,    84,    85,    86,    56,    18,    19,    20,   109,
     155,    61,   106,    67,    22,    23,   137,    63,    63,    58,
      24,    59,   140,   101,   104,    17,   113,    25,   110,    26,
     114,    88,    89,    66,   148,   115,   120,   121,   122,   123,
      90,   118,   126,   127,   128,   129,   130,   131,   132,    91,
      92,    93,   133,    94,   134,   136,    67,   135,   138,   141,
      28,   139,    67,   150,   145,   151,   147,    66,    94,   164,
     159,   174,   161,   153,   119,   167,    74,    75,   163,   166,
     177,   173,    76,    77,    78,    79,   157,   158,   180,   171,
      80,    81,    82,    83,    84,    85,    86,   179,   125,   172,
     154,   143,   178,     0,     0,     0,     0,     0,   176,   181,
       0,     0,   169,     0,   170,     0,     0,     0,     0,     0,
       4,    67,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,    67,     0,    18,
      19,    20,     0,     0,     0,     0,    21,    22,    23,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      25,     0,    26,     0,    27,     0,    28,     0,   156,    -2,
       4,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,    21,    22,    23,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      25,     0,    26,     4,    27,     5,    28,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,     0,    18,    19,    20,     0,     0,     0,     0,    21,
      22,    23,     0,     0,     0,     0,    24,     0,     0,     0,
       0,     0,     0,    25,     0,    26,     8,    27,     0,    28,
      12,    13,    14,    15,    16,     0,     0,     0,     0,    18,
      19,    20,     0,     0,     0,     0,     0,    22,    23,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
      25,     8,    26,     0,    53,    12,    13,    14,    15,    16,
      17,     0,     0,     0,    18,    19,    20,     0,     0,     0,
       0,     0,    22,    23,     0,     8,     0,     0,    24,    12,
      13,    14,    15,    16,     0,    25,     0,    26,    18,    19,
      20,     0,     0,     0,     0,     0,    22,    23,    74,    75,
       0,     0,    24,     0,    76,    77,    78,    79,     0,    25,
       0,    26,    80,    81,    82,    83,    84,    85,    86,    74,
      75,     0,     0,     0,     0,    76,    77,    78,    79,   152,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,     0,    74,    75,     0,     0,     0,   111,    76,
      77,    78,    79,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,     0,     0,    74,    75,     0,     0,
       0,    87,    76,    77,    78,    79,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,     0,    74,
      75,     0,     0,     0,   108,    76,    77,    78,    79,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
       0,     0,    74,    75,     0,     0,     0,   175,    76,    77,
      78,    79,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,     0,    74,    75,     0,     0,     0,   117,
      76,    77,    78,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,    74,    75,     0,     0,
       0,   149,    76,    77,    78,    79,     0,     0,     0,     0,
      80,    81,    82,    83,    84,    85,    86,     0,    74,    75,
       0,     0,     0,   168,    76,    77,    78,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    74,
      75,     0,     0,   160,     0,    76,    77,    78,    79,     0,
       0,     0,     0,    80,    81,    82,    83,    84,    85,    86,
      74,    75,     0,     0,   162,     0,    76,    77,    78,    79,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      86,    74,    75,     0,     0,     0,     0,    76,    77,    78,
       0,     0,     0,     0,     0,    80,    81,    82,    83,    84,
      85,    86,    -3,    -3,     0,     0,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,    80,    81,    82,    83,
      84,    85,    86,    74,    75,     0,     0,     0,     0,    76,
      77,     0,     0,     0,     0,     0,     0,    80,    81,    82,
      83,    84,    85,    86,    -3,    -3,     0,     0,     0,     0,
       0,     0,    -3,    -3,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       8,     9,    43,    51,    26,    19,    20,   118,     0,    11,
      12,    39,    40,    41,    43,    43,    24,    25,    26,    43,
      39,    28,    41,     7,    43,    45,    28,    11,    12,    13,
      14,    15,    35,    36,    37,    45,    20,    21,    22,    61,
     151,    43,    50,    51,    28,    29,    94,    19,    20,    28,
      34,    28,   100,    43,    43,    16,    42,    41,    66,    43,
      42,    21,    22,    47,   105,    46,    74,    75,    76,    77,
      30,    44,    80,    81,    82,    83,    84,    85,    86,    39,
      40,    41,    90,    43,    28,    93,    94,    28,    28,    28,
      47,    99,   100,    45,     4,    44,   104,    47,    43,    46,
      43,    28,    44,   111,    73,   146,    17,    18,    44,    44,
      44,   159,    23,    24,    25,    26,   124,   125,    44,   153,
      31,    32,    33,    34,    35,    36,    37,   175,    79,   154,
     115,   102,   174,    -1,    -1,    -1,    -1,    -1,    49,   180,
      -1,    -1,   150,    -1,   152,    -1,    -1,    -1,    -1,    -1,
       1,   159,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,   175,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    45,    -1,    47,    -1,    49,     0,
       1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,     1,    45,     3,    47,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,     7,    45,    -1,    47,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      41,     7,    43,    -1,    45,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,     7,    -1,    -1,    34,    11,
      12,    13,    14,    15,    -1,    41,    -1,    43,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    28,    29,    17,    18,
      -1,    -1,    34,    -1,    23,    24,    25,    26,    -1,    41,
      -1,    43,    31,    32,    33,    34,    35,    36,    37,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    48,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    46,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    17,    18,    -1,    -1,
      -1,    45,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    17,
      18,    -1,    -1,    -1,    45,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    17,    18,    -1,    -1,    -1,    45,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    17,    18,    -1,    -1,    -1,    44,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    -1,    17,    18,    -1,    -1,
      -1,    44,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    -1,    17,    18,
      -1,    -1,    -1,    44,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    17,
      18,    -1,    -1,    42,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      17,    18,    -1,    -1,    42,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,     1,     3,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    20,    21,
      22,    27,    28,    29,    34,    41,    43,    45,    47,    53,
      54,    56,    57,    58,    59,    60,    61,    67,    71,    73,
      74,    78,    81,    82,    84,    85,    87,    88,    89,    90,
      43,    43,    54,    45,    54,    45,    45,    28,    28,    28,
      75,    43,    59,    61,    59,    54,    47,    54,    65,    68,
      70,    54,    73,    72,    17,    18,    23,    24,    25,    26,
      31,    32,    33,    34,    35,    36,    37,    45,    21,    22,
      30,    39,    40,    41,    43,    62,    63,    64,    39,    41,
      43,    43,    76,    53,    43,    86,    54,    65,    45,    73,
      54,    46,    66,    42,    42,    46,    69,    44,    44,    52,
      54,    54,    54,    54,    55,    55,    54,    54,    54,    54,
      54,    54,    54,    54,    28,    28,    54,    65,    28,    54,
      65,    28,    79,    71,    77,     4,    83,    54,    53,    44,
      45,    44,    48,    54,    70,    63,    49,    54,    54,    43,
      42,    44,    42,    44,    46,    80,    44,    53,    44,    54,
      54,    66,    69,    65,    28,    45,    49,    44,    80,    65,
      44,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    58,    58,    58,    59,    59,    59,
      59,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    72,    71,    73,    74,    75,    75,    76,    77,
      78,    78,    78,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    83,    84,    85,    86,    87,    88,    88,    89,
      90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     1,     0,     3,     2,     2,     2,     2,     2,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     2,     2,
       1,     3,     4,     3,     4,     4,     2,     4,     1,     1,
       3,     5,     2,     0,     3,     0,     3,     3,     2,     3,
       0,     5,     0,     4,     3,     2,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     2,     0,     3,     0,     2,
       4,     4,     1,     3,     1,     3,     9,     3,     2,     2,
       2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmts						(); }
#line 1519 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmts_stmt					(); }
#line 1525 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmts_empty				(); }
#line 1531 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 64 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_expr				   ((yyvsp[-1].ExprVal));}
#line 1537 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 65 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_if					(); }
#line 1543 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 66 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_while					(); }
#line 1549 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 67 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_forstmt				(); }
#line 1555 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 68 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_returnstmt			(); }
#line 1561 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 69 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_brk					(); }
#line 1567 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 70 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_cntnue				(); }
#line 1573 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 71 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_block					(); }
#line 1579 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_funcdef				(); }
#line 1585 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 73 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_UNRECOGNIZED			(); }
#line 1591 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 74 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_error					(); }
#line 1597 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "./src/parser.y" /* yacc.c:1646  */
    { manage_stmt_semicolumn			(); }
#line 1603 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 80 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_expr_assignexpr	  ((yyvsp[0].ExprVal)); }
#line 1609 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 81 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_op_expr((yyvsp[-2].ExprVal),'+', (yyvsp[0].ExprVal)); }
#line 1615 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 82 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_op_expr((yyvsp[-2].ExprVal),'-', (yyvsp[0].ExprVal)); }
#line 1621 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_op_expr((yyvsp[-2].ExprVal),'*', (yyvsp[0].ExprVal)); }
#line 1627 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_op_expr((yyvsp[-2].ExprVal),'/', (yyvsp[0].ExprVal)); }
#line 1633 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_op_expr((yyvsp[-2].ExprVal),'%', (yyvsp[0].ExprVal)); }
#line 1639 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_gr_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));		}
#line 1645 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_gr_eq_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));	}
#line 1651 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_ls_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));		}
#line 1657 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_ls_eq_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));	}
#line 1663 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_eq_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));		}
#line 1669 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_not_eq_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));	}
#line 1675 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 92 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_and_expr((yyvsp[-3].ExprVal),(yyvsp[-1].intVal),(yyvsp[0].ExprVal));	}
#line 1681 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 93 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_expr_or_expr((yyvsp[-3].ExprVal),(yyvsp[-1].intVal),(yyvsp[0].ExprVal));	}
#line 1687 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 94 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_expr_term((yyvsp[0].ExprVal)); 			}
#line 1693 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 97 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = handle_boolean_M				();	}
#line 1699 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_term_expr_parenthesis((yyvsp[-1].ExprVal));}
#line 1705 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_term_uminus_expr((yyvsp[0].ExprVal)); 	}
#line 1711 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_term_not_expr((yyvsp[0].ExprVal)); 		}
#line 1717 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 103 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_op_op_lvalue((yyvsp[0].ExprVal), '+');	}
#line 1723 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 104 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_lvalue_op_op((yyvsp[-1].ExprVal), '+');	}
#line 1729 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 105 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_op_op_lvalue((yyvsp[0].ExprVal), '-');	}
#line 1735 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 106 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = handle_lvalue_op_op((yyvsp[-1].ExprVal), '-');	}
#line 1741 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 107 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_term_primary((yyvsp[0].ExprVal));			}
#line 1747 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 110 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_assignexpr_lvalue_assign_expr((yyvsp[-2].ExprVal), (yyvsp[0].ExprVal));}
#line 1753 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 113 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_primary_lvalue		((yyvsp[0].ExprVal));}
#line 1759 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 114 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_primary_call			((yyvsp[0].ExprVal));}
#line 1765 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 115 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_primary_tablemake		((yyvsp[0].ExprVal));}
#line 1771 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 116 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_primary_par_funcdef	((yyvsp[-1].SymbolVal));}
#line 1777 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 117 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_primary_const			((yyvsp[0].ExprVal));}
#line 1783 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_lvalue_ID				((yyvsp[0].stringVal));}
#line 1789 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 121 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_lvalue_LOCAL_ID		((yyvsp[0].stringVal));}
#line 1795 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 122 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_lvalue_DBLCOLON_ID	((yyvsp[0].stringVal));}
#line 1801 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 123 "./src/parser.y" /* yacc.c:1646  */
    { manage_lvalue_tableitem			();  }
#line 1807 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 126 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_tableitem_lvalue_dot_ID((yyvsp[-2].ExprVal), (yyvsp[0].stringVal));}
#line 1813 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 127 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_tableitem_lvalue_brackets_expr((yyvsp[-3].ExprVal), (yyvsp[-1].ExprVal));}
#line 1819 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 128 "./src/parser.y" /* yacc.c:1646  */
    { manage_tableitem_call_dot_ID			();}
#line 1825 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 129 "./src/parser.y" /* yacc.c:1646  */
    { manage_tableitem_call_brackets_expr	();}
#line 1831 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 132 "./src/parser.y" /* yacc.c:1646  */
    {}
#line 1837 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 133 "./src/parser.y" /* yacc.c:1646  */
    { }
#line 1843 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 134 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_call_par_funcdef_normcall((yyvsp[-2].SymbolVal), (yyvsp[0].ExprVal));}
#line 1849 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 137 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_callsuffix_normcall		((yyvsp[0].ExprVal));}
#line 1855 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 138 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_callsuffix_methodcall		((yyvsp[0].ExprVal));}
#line 1861 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 141 "./src/parser.y" /* yacc.c:1646  */
    { }
#line 1867 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 144 "./src/parser.y" /* yacc.c:1646  */
    { }
#line 1873 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 147 "./src/parser.y" /* yacc.c:1646  */
    { manage_elist_expr_exprs			(); }
#line 1879 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 148 "./src/parser.y" /* yacc.c:1646  */
    { manage_elist_empty				(); }
#line 1885 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 151 "./src/parser.y" /* yacc.c:1646  */
    { manage_exprs_comma_expr_exprs		(); }
#line 1891 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 152 "./src/parser.y" /* yacc.c:1646  */
    { manage_exprs_empty				(); }
#line 1897 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 155 "./src/parser.y" /* yacc.c:1646  */
    { }
#line 1903 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 156 "./src/parser.y" /* yacc.c:1646  */
    { }
#line 1909 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 159 "./src/parser.y" /* yacc.c:1646  */
    { manage_indexed_indexedelem_indexedelems();}
#line 1915 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 161 "./src/parser.y" /* yacc.c:1646  */
    { manage_indexedelems_comma_indexedelem_indexedelems();}
#line 1921 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 162 "./src/parser.y" /* yacc.c:1646  */
    { manage_indexedelems_empty			(); }
#line 1927 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 165 "./src/parser.y" /* yacc.c:1646  */
    { manage_indexedelem_brackets_expr_column_expr();}
#line 1933 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 167 "./src/parser.y" /* yacc.c:1646  */
    { currentScope++; }
#line 1939 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 168 "./src/parser.y" /* yacc.c:1646  */
    {
										hide();
										currentScope--;
										manage_block_brackets_stmts();
									}
#line 1949 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 175 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.SymbolVal) = manage_funcdef_funcprefix_funcargs_funcbody((yyvsp[-2].SymbolVal), (yyvsp[0].intVal)); }
#line 1955 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 177 "./src/parser.y" /* yacc.c:1646  */
    { 
										(yyval.SymbolVal) = manage_funcprefix_FUNCTION_funcname((yyvsp[0].stringVal));
										(yyval.SymbolVal)->iadress = nextquadlabel();
									}
#line 1964 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 183 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.stringVal) = manage_funcname_ID			((yyvsp[0].stringVal));}
#line 1970 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 184 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.stringVal) = manage_funcname_empty		();	 }
#line 1976 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 187 "./src/parser.y" /* yacc.c:1646  */
    { manage_funcargs_PAR_idlist_PAR	();  }
#line 1982 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 190 "./src/parser.y" /* yacc.c:1646  */
    { manage_funcbody_block				(&(yyval.intVal));}
#line 1988 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 193 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_const_NUMBER			((yyvsp[0].realVal));}
#line 1994 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 194 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_const_STR				((yyvsp[0].stringVal));}
#line 2000 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 195 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_const_NIL				();  }
#line 2006 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 196 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_const_TRUE			();  }
#line 2012 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 197 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_const_FALSE			();  }
#line 2018 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 200 "./src/parser.y" /* yacc.c:1646  */
    { manage_idlist_ID_ids				((yyvsp[-1].stringVal));}
#line 2024 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 201 "./src/parser.y" /* yacc.c:1646  */
    { manage_idlist_empty				();  }
#line 2030 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 204 "./src/parser.y" /* yacc.c:1646  */
    { manage_ids_comma_ID_ids			((yyvsp[-1].stringVal));}
#line 2036 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 205 "./src/parser.y" /* yacc.c:1646  */
    { manage_ids_empty					();}
#line 2042 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 208 "./src/parser.y" /* yacc.c:1646  */
    { manage_if_ifprefix_stmt			((yyvsp[-1].intVal));}
#line 2048 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 209 "./src/parser.y" /* yacc.c:1646  */
    { if_ifprefix_stmt_elseprefix_stmt((yyvsp[-3].intVal), (yyvsp[-1].intVal));}
#line 2054 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 212 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = manage_ifprefix_IF_par_expr	((yyvsp[-1].ExprVal));}
#line 2060 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 215 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = manage_elseprefix_ELSE		();	 }
#line 2066 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 218 "./src/parser.y" /* yacc.c:1646  */
    { manage_while_whilestart_whilecond_stmt((yyvsp[-2].intVal), (yyvsp[-1].intVal), (yyvsp[0].ExprVal));}
#line 2072 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 221 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = manage_whilestart_WHILE		();  }
#line 2078 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 224 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.intVal) = manage_whilecond_par_expr	((yyvsp[-1].ExprVal));}
#line 2084 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 227 "./src/parser.y" /* yacc.c:1646  */
    { manage_forstmt_FOR();}
#line 2090 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 230 "./src/parser.y" /* yacc.c:1646  */
    { manage_returnstmt_RETURN_expr_semicolon((yyvsp[-1].ExprVal));}
#line 2096 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 231 "./src/parser.y" /* yacc.c:1646  */
    { manage_returnstmt_RETURN_semicolon(); }
#line 2102 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 234 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_break_BREAK			();	}
#line 2108 "./src/parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 237 "./src/parser.y" /* yacc.c:1646  */
    { (yyval.ExprVal) = manage_continue_CONTINUE		();	}
#line 2114 "./src/parser.c" /* yacc.c:1646  */
    break;


#line 2118 "./src/parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 240 "./src/parser.y" /* yacc.c:1906  */



int yyerror (const char* yaccProvidedMessage) {
	printf("%d: #ERROR: %s, before token: %s\n", yylineno, yaccProvidedMessage,  yytext);
}

int main ( argc, argv ) int argc; char **argv;{
	++argv, --argc;  /* skip over program name */

	/* Lexer can read form file if such argument is provided */
	if (argc > 0)	{ yyin = fopen(argv[0], "r"); }
	else 		{ yyin = stdin; }

	/* Initialize */
	initManager();
	initSymbolTable();

	/* Compute */
	yyparse();
	generateInstructionTable();

	/* Verbose */
	printSymbolTable();
	printQuads();
	printInstructions();
	printConstTables();

	/* Generate Alpha executable */
	avmbinaryfile("out");	// TODO make filename as call arg instead of static

	return 0;
}
