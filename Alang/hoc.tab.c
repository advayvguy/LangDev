/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     VAR = 259,
     BLTIN = 260,
     UNDEF = 261,
     CNST = 262,
     BLTIN2 = 263,
     BLTIN0 = 264,
     SYS = 265,
     WHILE = 266,
     IF = 267,
     ELSE = 268,
     PRINT = 269,
     BREAK = 270,
     CONTINUE = 271,
     FOR = 272,
     STRING = 273,
     ARRLEN = 274,
     FUNCTION = 275,
     PROCEDURE = 276,
     RETURN = 277,
     FUNC = 278,
     PROC = 279,
     READ = 280,
     ARR = 281,
     ARRAY = 282,
     ARG = 283,
     OR = 284,
     AND = 285,
     DEC = 286,
     INC = 287,
     NE = 288,
     EQ = 289,
     LE = 290,
     LT = 291,
     GE = 292,
     GT = 293,
     NOT = 294,
     UNARYMINUS = 295
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define VAR 259
#define BLTIN 260
#define UNDEF 261
#define CNST 262
#define BLTIN2 263
#define BLTIN0 264
#define SYS 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define PRINT 269
#define BREAK 270
#define CONTINUE 271
#define FOR 272
#define STRING 273
#define ARRLEN 274
#define FUNCTION 275
#define PROCEDURE 276
#define RETURN 277
#define FUNC 278
#define PROC 279
#define READ 280
#define ARR 281
#define ARRAY 282
#define ARG 283
#define OR 284
#define AND 285
#define DEC 286
#define INC 287
#define NE 288
#define EQ 289
#define LE 290
#define LT 291
#define GE 292
#define GT 293
#define NOT 294
#define UNARYMINUS 295




/* Copy the first part of user declarations.  */
#line 1 "hoc.y"


//all standard libraries are included here
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include "hoc.h" // for lookup and install

#define code2(c1,c2) code(c1) ; code(c2)
#define code3(c1,c2,c3) code(c1) ; code(c2) ; code(c3)

extern double Pow(double a, double b); //belongs to math.c, Pow is invoked when '^' is encountered
extern void init(); //belongs to init.c, this initilaizes the constants and the builtins
extern int initcode();
extern int execute(Inst *p);
extern void *emalloc();

int yylex(void); //for lexing, sending values through yylval and returning its token type
int lineno = 1; 
char *progname;

jmp_buf begin; //we define a jum_buf struct- begin which would hold the timestamps and the necesary details with we setjmp

//some error catching functions
void fpecatch(); //for floating point errors
void execerror(const char *s, const char *t); //resets the state and gives warning the parameters
void warning (const char *s, const char *t); //prints on stderr
void yyerror(char *s); //called upon by yylex for misc errors

static int indef = 0;

void defnonly(char *s)
{
	if (indef == 0) execerror(s, "out of definition");
}

FILE *fin;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "hoc.y"
{
	Inst *inst; //machine instruction
	symbol *sym; //symbol table pointer type
	int narg; //number of arguments			
}
/* Line 193 of yacc.c.  */
#line 225 "hoc.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 238 "hoc.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   621

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      48,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      51,    52,    42,    40,    56,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    50,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      25,    26,    27,    28,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    27,
      31,    38,    42,    46,    48,    50,    52,    55,    61,    64,
      66,    68,    71,    83,    89,    95,   105,   109,   113,   115,
     117,   119,   120,   121,   124,   128,   130,   132,   134,   136,
     139,   142,   144,   146,   152,   157,   162,   169,   173,   177,
     181,   185,   189,   193,   197,   201,   205,   208,   212,   216,
     220,   224,   228,   232,   236,   240,   243,   248,   249,   251,
     253,   257,   261,   262,   263,   273,   274,   275,   285,   291,
     300,   302,   304,   306,   308,   309,   311,   315,   316,   318,
     322,   324,   326,   327,   329
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    -1,    58,    48,    -1,    58,    71,    48,
      -1,    58,    59,    48,    -1,    58,     1,    48,    -1,    58,
      68,    48,    -1,    58,    60,    48,    -1,     4,    29,    68,
      -1,    27,    49,    68,    50,    29,    68,    -1,     7,    29,
      68,    -1,    28,    29,    68,    -1,    68,    -1,    76,    -1,
      22,    -1,    22,    68,    -1,    21,    69,    51,    78,    52,
      -1,    14,    70,    -1,    80,    -1,    81,    -1,    14,    68,
      -1,    63,    51,    67,    53,    67,    53,    67,    52,    82,
      60,    65,    -1,    62,    61,    82,    60,    65,    -1,    64,
      61,    82,    60,    65,    -1,    64,    61,    82,    60,    65,
      13,    82,    60,    65,    -1,    54,    66,    55,    -1,    51,
      68,    52,    -1,    11,    -1,    17,    -1,    12,    -1,    -1,
      -1,    66,    82,    -1,    66,    60,    82,    -1,    68,    -1,
       3,    -1,     4,    -1,    28,    -1,     4,    33,    -1,     4,
      32,    -1,     7,    -1,    59,    -1,    20,    69,    51,    78,
      52,    -1,    27,    49,    68,    50,    -1,     5,    51,    68,
      52,    -1,     8,    51,    68,    56,    68,    52,    -1,    25,
      51,    52,    -1,     9,    51,    52,    -1,    68,    40,    68,
      -1,    68,    41,    68,    -1,    68,    42,    68,    -1,    68,
      43,    68,    -1,    68,    44,    68,    -1,    68,    47,    68,
      -1,    51,    68,    52,    -1,    41,    68,    -1,    68,    39,
      68,    -1,    68,    38,    68,    -1,    68,    37,    68,    -1,
      68,    36,    68,    -1,    68,    35,    68,    -1,    68,    34,
      68,    -1,    68,    31,    68,    -1,    68,    30,    68,    -1,
      45,    68,    -1,    19,    51,    27,    52,    -1,    -1,    68,
      -1,    18,    -1,    70,    56,    68,    -1,    70,    56,    18,
      -1,    -1,    -1,    23,    77,    72,    51,    79,    52,    73,
      82,    60,    -1,    -1,    -1,    24,    77,    74,    51,    79,
      52,    75,    82,    60,    -1,    26,     4,    49,    68,    50,
      -1,    26,     4,    49,    50,    29,    49,    78,    50,    -1,
       4,    -1,    20,    -1,    21,    -1,    27,    -1,    -1,    68,
      -1,    78,    56,    68,    -1,    -1,     4,    -1,     4,    56,
      79,    -1,    15,    -1,    16,    -1,    -1,    48,    -1,    82,
      48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    72,    73,    74,    75,    76,    78,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    98,    99,   100,   101,   104,   106,   109,
     111,   113,   115,   116,   117,   119,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   153,   155,   156,
     157,   158,   160,   160,   160,   161,   161,   161,   163,   164,
     166,   167,   168,   169,   171,   172,   173,   175,   176,   177,
     179,   181,   183,   184,   185
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VAR", "BLTIN", "UNDEF",
  "CNST", "BLTIN2", "BLTIN0", "SYS", "WHILE", "IF", "ELSE", "PRINT",
  "BREAK", "CONTINUE", "FOR", "STRING", "ARRLEN", "FUNCTION", "PROCEDURE",
  "RETURN", "FUNC", "PROC", "READ", "ARR", "ARRAY", "ARG", "'='", "OR",
  "AND", "DEC", "INC", "NE", "EQ", "LE", "LT", "GE", "GT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "NOT", "UNARYMINUS", "'^'", "'\\n'", "'['", "']'",
  "'('", "')'", "';'", "'{'", "'}'", "','", "$accept", "list", "asgn",
  "stmt", "cond", "while", "for", "if", "end", "stmtlist", "fexpr", "expr",
  "begin", "prlist", "defn", "@1", "@2", "@3", "@4", "array", "procname",
  "arglist", "paramlist", "break", "continue", "newl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    61,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
      43,    45,    42,    47,    37,   294,   295,    94,    10,    91,
      93,    40,    41,    59,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    62,    63,
      64,    65,    66,    66,    66,    67,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    70,    70,
      70,    70,    72,    73,    71,    74,    75,    71,    76,    76,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      80,    81,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       6,     3,     3,     1,     1,     1,     2,     5,     2,     1,
       1,     2,    11,     5,     5,     9,     3,     3,     1,     1,
       1,     0,     0,     2,     3,     1,     1,     1,     1,     2,
       2,     1,     1,     5,     4,     4,     6,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     4,     0,     1,     1,
       3,     3,     0,     0,     9,     0,     0,     9,     5,     8,
       1,     1,     1,     1,     0,     1,     3,     0,     1,     3,
       1,     1,     0,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    36,    37,     0,    41,     0,     0,
      28,    30,     0,    90,    91,    29,     0,    67,    67,    15,
       0,     0,     0,     0,     0,    38,     0,     0,     3,     0,
      32,    42,     0,     0,     0,     0,     0,     0,    14,    19,
      20,     6,     0,    40,    39,     0,     0,     0,     0,    69,
      42,    21,    18,     0,     0,     0,    16,    80,    81,    82,
      83,    72,    75,     0,     0,     0,     0,    56,    65,     0,
       0,     5,     8,     0,    92,     0,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     4,     9,     0,    11,     0,    48,     0,     0,
      84,    84,     0,     0,    47,     0,     0,    12,    55,    93,
      26,    92,    13,    33,     0,     0,     0,    35,     0,    64,
      63,    62,    61,    60,    59,    58,    57,    49,    50,    51,
      52,    53,    54,    45,     0,    71,    70,    66,    85,     0,
       0,    87,    87,     0,     0,    44,    34,    94,    27,    31,
       0,    31,     0,    43,     0,    17,    88,     0,     0,     0,
      78,     0,    23,     0,    24,    46,    86,    87,    73,    76,
      84,    10,     0,    92,    89,    92,    92,     0,     0,     0,
       0,     0,    79,    92,    31,    74,    77,     0,    25,    31,
      22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    50,    32,    74,    33,    34,    35,   162,    70,
     116,   112,    54,    52,    37,   102,   175,   103,   176,    38,
      61,   139,   157,    39,    40,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
    -148,   172,  -148,   -45,  -148,    61,   -35,    -2,   -13,   -11,
    -148,  -148,   123,  -148,  -148,  -148,    -3,  -148,  -148,   383,
       2,     2,     0,    39,    18,    20,   383,   383,  -148,   383,
    -148,    21,    23,    17,    22,    17,   559,    27,  -148,  -148,
    -148,  -148,   383,  -148,  -148,   383,   383,   383,    40,  -148,
    -148,   401,    35,    68,    45,    47,   574,  -148,  -148,  -148,
    -148,  -148,  -148,    49,    53,   383,   383,    56,    56,   447,
     224,  -148,  -148,   383,    57,   383,    57,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   383,
     383,  -148,  -148,   574,   466,   574,   424,  -148,   329,    54,
     383,   383,    58,    59,  -148,   356,   523,   574,  -148,  -148,
    -148,    57,   574,    60,   485,   277,    62,   574,   277,   378,
      19,    -8,    -8,    -8,    -8,    -8,    -8,   -23,   -23,    56,
      56,    56,    56,  -148,   383,  -148,   574,  -148,   574,   -44,
     -42,   103,   103,    89,   541,    91,    60,  -148,  -148,  -148,
     383,  -148,   504,  -148,   383,  -148,    65,    70,    71,    76,
    -148,   383,  -148,    81,   116,  -148,   574,   103,  -148,  -148,
     383,   574,   383,    57,  -148,    57,    57,   -43,    83,   277,
     277,   277,  -148,    57,  -148,  -148,  -148,   277,  -148,  -148,
    -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,   135,   -68,   102,  -148,  -148,  -148,  -147,  -148,
    -141,    -1,   120,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
     118,  -100,  -137,  -148,  -148,   -59
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -69
static const yytype_int16 yytable[] =
{
      36,   140,   111,    41,   164,   158,    57,   182,   153,   163,
     155,    51,   154,   154,   154,   115,    45,   118,    56,    87,
      88,    89,    58,    59,    90,    67,    68,    46,    69,    60,
     174,   178,    85,    86,    87,    88,    89,   188,    47,    90,
      48,    93,   190,    64,    94,    95,    96,   149,    53,    66,
     151,    63,   146,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   106,   107,    90,    65,    73,    71,
     177,    72,   114,    75,   117,    92,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      42,    98,    97,    43,    44,    99,   100,   136,   101,   138,
     138,   104,   105,    90,   144,   109,   137,   156,   147,   141,
     142,   184,   185,   186,   179,   150,   180,   181,   159,   189,
     161,   167,   168,   169,   187,   170,     4,     5,     6,   173,
       7,     8,     9,   152,   172,   183,    31,    76,    55,    62,
       0,    49,    16,    17,     0,     0,     0,     0,    22,   117,
      24,    25,     0,   166,     0,     0,     0,     0,     0,     0,
     171,     0,     0,     0,    26,     0,     0,     0,    27,   138,
       0,   117,     2,     3,    29,     4,     5,     6,     0,     7,
       8,     9,     0,    10,    11,     0,    12,    13,    14,    15,
       0,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,    27,     0,     0,
      28,     0,     0,    29,     0,     0,    30,     4,     5,     6,
       0,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,    15,     0,    16,    17,    18,    19,     0,     0,    22,
      23,    24,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,    27,
       0,     0,   109,     0,     0,    29,     0,     0,    30,   110,
       4,     5,     6,     0,     7,     8,     9,     0,    10,    11,
       0,    12,    13,    14,    15,     0,    16,    17,    18,    19,
       0,     0,    22,    23,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    26,     0,
       0,     0,    27,     0,     0,   147,     0,     0,    29,     0,
       0,    30,     4,     5,     6,     0,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,   135,    16,    17,
       0,     0,     0,     0,    22,     0,    24,    25,     0,     4,
       5,     6,     0,     7,     8,     9,     0,     0,     0,     0,
      26,     0,     0,     0,    27,    16,    17,     0,     0,     0,
      29,    22,     0,    24,    25,     0,     4,     5,     6,     0,
       7,     8,     9,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    16,    17,     0,     0,   143,    29,    22,    78,
      24,    25,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,    26,    90,     0,     0,    27,     0,
       0,    77,    78,     0,    29,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,    90,     0,
       0,     0,     0,     0,    77,    78,     0,   -68,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90,     0,     0,     0,     0,     0,    77,    78,     0,
     134,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,    90,     0,    77,    78,     0,   108,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,    90,     0,    77,    78,     0,   133,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    90,     0,    77,    78,     0,   148,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90,     0,    77,    78,     0,   165,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
      90,    77,    78,   145,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,    90,    77,
      78,   160,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    77,    78,    90,    91,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,    90
};

static const yytype_int16 yycheck[] =
{
       1,   101,    70,    48,   151,   142,     4,    50,    52,   150,
      52,    12,    56,    56,    56,    74,    51,    76,    19,    42,
      43,    44,    20,    21,    47,    26,    27,    29,    29,    27,
     167,   172,    40,    41,    42,    43,    44,   184,    51,    47,
      51,    42,   189,     4,    45,    46,    47,   115,    51,    29,
     118,    51,   111,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    65,    66,    47,    49,    51,    48,
     170,    48,    73,    51,    75,    48,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      29,    56,    52,    32,    33,    27,    51,    98,    51,   100,
     101,    52,    49,    47,   105,    48,    52,     4,    48,    51,
      51,   179,   180,   181,   173,    53,   175,   176,    29,   187,
      29,    56,    52,    52,   183,    49,     3,     4,     5,    13,
       7,     8,     9,   134,    53,    52,     1,    35,    18,    21,
      -1,    18,    19,    20,    -1,    -1,    -1,    -1,    25,   150,
      27,    28,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,   170,
      -1,   172,     0,     1,    51,     3,     4,     5,    -1,     7,
       8,     9,    -1,    11,    12,    -1,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,
      48,    -1,    -1,    51,    -1,    -1,    54,     3,     4,     5,
      -1,     7,     8,     9,    -1,    11,    12,    -1,    14,    15,
      16,    17,    -1,    19,    20,    21,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    45,
      -1,    -1,    48,    -1,    -1,    51,    -1,    -1,    54,    55,
       3,     4,     5,    -1,     7,     8,     9,    -1,    11,    12,
      -1,    14,    15,    16,    17,    -1,    19,    20,    21,    22,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    54,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    -1,    27,    28,    -1,     3,
       4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    45,    19,    20,    -1,    -1,    -1,
      51,    25,    -1,    27,    28,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    19,    20,    -1,    -1,    50,    51,    25,    31,
      27,    28,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    41,    47,    -1,    -1,    45,    -1,
      -1,    30,    31,    -1,    51,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    56,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      56,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    30,    31,    -1,    52,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    30,    31,    -1,    52,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    47,    -1,    30,    31,    -1,    52,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    30,    31,    -1,    52,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    30,    31,    50,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    30,
      31,    50,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    30,    31,    47,    48,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    58,     0,     1,     3,     4,     5,     7,     8,     9,
      11,    12,    14,    15,    16,    17,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    41,    45,    48,    51,
      54,    59,    60,    62,    63,    64,    68,    71,    76,    80,
      81,    48,    29,    32,    33,    51,    29,    51,    51,    18,
      59,    68,    70,    51,    69,    69,    68,     4,    20,    21,
      27,    77,    77,    51,     4,    49,    29,    68,    68,    68,
      66,    48,    48,    51,    61,    51,    61,    30,    31,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      47,    48,    48,    68,    68,    68,    68,    52,    56,    27,
      51,    51,    72,    74,    52,    49,    68,    68,    52,    48,
      55,    60,    68,    82,    68,    82,    67,    68,    82,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    52,    56,    18,    68,    52,    68,    78,
      78,    51,    51,    50,    68,    50,    82,    48,    52,    60,
      53,    60,    68,    52,    56,    52,     4,    79,    79,    29,
      50,    29,    65,    67,    65,    52,    68,    56,    52,    52,
      49,    68,    53,    13,    79,    73,    75,    78,    67,    82,
      82,    82,    50,    52,    60,    60,    60,    82,    65,    60,
      65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 73 "hoc.y"
    {code3(prevset, (Inst)pop, STOP); return 1; ;}
    break;

  case 6:
#line 74 "hoc.y"
    {yyerrok; ;}
    break;

  case 7:
#line 75 "hoc.y"
    {code3(prevset, print, STOP); return 1; ;}
    break;

  case 8:
#line 76 "hoc.y"
    {code(STOP); return 1; ;}
    break;

  case 9:
#line 78 "hoc.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst); code3(varpush, (Inst)(yyvsp[(1) - (3)].sym), assign); ;}
    break;

  case 10:
#line 79 "hoc.y"
    {(yyval.inst) = (yyvsp[(6) - (6)].inst); code2(arrpush, (Inst)(yyvsp[(1) - (6)].sym)); ;}
    break;

  case 11:
#line 80 "hoc.y"
    {execerror("constant cant be changed",(yyvsp[(1) - (3)].sym)->name); ;}
    break;

  case 12:
#line 81 "hoc.y"
    {defnonly("$"); code2(argassign, (Inst)(yyvsp[(1) - (3)].narg)); (yyval.inst) = (yyvsp[(3) - (3)].inst); ;}
    break;

  case 13:
#line 83 "hoc.y"
    {code((Inst)pop); ;}
    break;

  case 15:
#line 85 "hoc.y"
    {defnonly("return"); code(procret); ;}
    break;

  case 16:
#line 86 "hoc.y"
    {defnonly("return"); (yyval.inst) = (yyvsp[(2) - (2)].inst); code(funcret); ;}
    break;

  case 17:
#line 87 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (5)].inst); code3(call, (Inst)(yyvsp[(1) - (5)].sym), (Inst)(yyvsp[(4) - (5)].narg)); ;}
    break;

  case 18:
#line 88 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (2)].inst); ;}
    break;

  case 21:
#line 91 "hoc.y"
    { code(prexpr); (yyval.inst) = (yyvsp[(2) - (2)].inst); ;}
    break;

  case 22:
#line 92 "hoc.y"
    {	((yyvsp[(1) - (11)].inst))[1] = (Inst)(yyvsp[(3) - (11)].inst); 
																															((yyvsp[(1) - (11)].inst))[2] = (Inst)(yyvsp[(5) - (11)].inst);
																															((yyvsp[(1) - (11)].inst))[3] = (Inst)(yyvsp[(7) - (11)].inst); 
																															((yyvsp[(1) - (11)].inst))[4] = (Inst)(yyvsp[(10) - (11)].inst);
																															((yyvsp[(1) - (11)].inst))[5] = (Inst)(yyvsp[(11) - (11)].inst); ;}
    break;

  case 23:
#line 98 "hoc.y"
    {((yyvsp[(1) - (5)].inst))[1] = (Inst)(yyvsp[(4) - (5)].inst); ((yyvsp[(1) - (5)].inst))[2] = (Inst)(yyvsp[(5) - (5)].inst); ;}
    break;

  case 24:
#line 99 "hoc.y"
    {((yyvsp[(1) - (5)].inst))[1] = (Inst)(yyvsp[(4) - (5)].inst); ((yyvsp[(1) - (5)].inst))[3] = (Inst)(yyvsp[(5) - (5)].inst); ;}
    break;

  case 25:
#line 100 "hoc.y"
    {((yyvsp[(1) - (9)].inst))[1] = (Inst)(yyvsp[(4) - (9)].inst); ((yyvsp[(1) - (9)].inst))[2] = (Inst)(yyvsp[(8) - (9)].inst); ((yyvsp[(1) - (9)].inst))[3] = (Inst)(yyvsp[(9) - (9)].inst); ;}
    break;

  case 26:
#line 101 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 27:
#line 104 "hoc.y"
    {code(STOP); (yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 28:
#line 106 "hoc.y"
    {(yyval.inst) = code3(whilecode, STOP, STOP); ;}
    break;

  case 29:
#line 109 "hoc.y"
    {(yyval.inst) = code3(forcode, STOP, STOP); code3(STOP,STOP,STOP);;}
    break;

  case 30:
#line 111 "hoc.y"
    {(yyval.inst) = code(ifcode); code3(STOP,STOP,STOP); ;}
    break;

  case 31:
#line 113 "hoc.y"
    {code(STOP); (yyval.inst) = progp; ;}
    break;

  case 32:
#line 115 "hoc.y"
    {(yyval.inst) = progp; ;}
    break;

  case 35:
#line 119 "hoc.y"
    {code(STOP); (yyval.inst) = (yyvsp[(1) - (1)].inst); ;}
    break;

  case 36:
#line 121 "hoc.y"
    {(yyval.inst) = code2(constpush, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 37:
#line 122 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (1)].sym), eval); ;}
    break;

  case 38:
#line 123 "hoc.y"
    {defnonly("$"); (yyval.inst) = code2(arg, (Inst)(yyvsp[(1) - (1)].narg)); ;}
    break;

  case 39:
#line 124 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (2)].sym), inc); ;}
    break;

  case 40:
#line 125 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (2)].sym), dec); ;}
    break;

  case 41:
#line 126 "hoc.y"
    {(yyval.inst) = code2(constpush, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 43:
#line 128 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (5)].inst); code3(call, (Inst)(yyvsp[(1) - (5)].sym), (Inst)(yyvsp[(4) - (5)].narg)); ;}
    break;

  case 44:
#line 129 "hoc.y"
    {(yyval.inst) = code2(arrpop, (Inst)(yyvsp[(1) - (4)].sym)); ;}
    break;

  case 45:
#line 130 "hoc.y"
    {(yyval.inst) = (yyvsp[(3) - (4)].inst); code2(bltin, (Inst)(yyvsp[(1) - (4)].sym)); ;}
    break;

  case 46:
#line 131 "hoc.y"
    {(yyval.inst) = (yyvsp[(5) - (6)].inst); code2(bltin, (Inst)(yyvsp[(1) - (6)].sym)); ;}
    break;

  case 47:
#line 132 "hoc.y"
    {(yyval.inst) = code(varread); ;}
    break;

  case 48:
#line 133 "hoc.y"
    {code2(bltin, (Inst)(yyvsp[(1) - (3)].sym)); ;}
    break;

  case 49:
#line 134 "hoc.y"
    {code(add); ;}
    break;

  case 50:
#line 135 "hoc.y"
    {code(sub); ;}
    break;

  case 51:
#line 136 "hoc.y"
    {code(mul); ;}
    break;

  case 52:
#line 137 "hoc.y"
    {code(div_); ;}
    break;

  case 53:
#line 138 "hoc.y"
    {code(mod); ;}
    break;

  case 54:
#line 139 "hoc.y"
    {code(power); ;}
    break;

  case 55:
#line 140 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 56:
#line 141 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (2)].inst); code(negate); ;}
    break;

  case 57:
#line 142 "hoc.y"
    {code(gt); ;}
    break;

  case 58:
#line 143 "hoc.y"
    {code(ge); ;}
    break;

  case 59:
#line 144 "hoc.y"
    {code(lt); ;}
    break;

  case 60:
#line 145 "hoc.y"
    {code(le); ;}
    break;

  case 61:
#line 146 "hoc.y"
    {code(eq); ;}
    break;

  case 62:
#line 147 "hoc.y"
    {code(ne); ;}
    break;

  case 63:
#line 148 "hoc.y"
    {code(and_); ;}
    break;

  case 64:
#line 149 "hoc.y"
    {code(or_); ;}
    break;

  case 65:
#line 150 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (2)].inst); code(not_); ;}
    break;

  case 66:
#line 151 "hoc.y"
    {(yyval.inst) = code2(arrlen, (Inst)(yyvsp[(3) - (4)].sym)); ;}
    break;

  case 67:
#line 153 "hoc.y"
    {(yyval.inst) = progp; ;}
    break;

  case 68:
#line 155 "hoc.y"
    {code(prexpr); ;}
    break;

  case 69:
#line 156 "hoc.y"
    {(yyval.inst) = code2(prstr, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 70:
#line 157 "hoc.y"
    {code(prexpr); ;}
    break;

  case 71:
#line 158 "hoc.y"
    {(yyval.inst) = code2(prstr, (Inst)(yyvsp[(3) - (3)].sym)); ;}
    break;

  case 72:
#line 160 "hoc.y"
    {(yyvsp[(2) - (2)].sym)->type = FUNCTION; indef = 1;  ;}
    break;

  case 73:
#line 160 "hoc.y"
    {code2(cnflush,(Inst)(yyvsp[(5) - (6)].narg)); ;}
    break;

  case 74:
#line 160 "hoc.y"
    {code(procret); define((yyvsp[(2) - (9)].sym)); indef = 0; ;}
    break;

  case 75:
#line 161 "hoc.y"
    {(yyvsp[(2) - (2)].sym)->type = PROCEDURE; indef = 1; ;}
    break;

  case 76:
#line 161 "hoc.y"
    {code2(cnflush,(Inst)(yyvsp[(5) - (6)].narg)); ;}
    break;

  case 77:
#line 161 "hoc.y"
    {code(procret); define((yyvsp[(2) - (9)].sym)); indef = 0; ;}
    break;

  case 78:
#line 163 "hoc.y"
    {(yyvsp[(2) - (5)].sym)->type = ARRAY; (yyval.inst) = code2(arrinit, (Inst)(yyvsp[(2) - (5)].sym)); ;}
    break;

  case 79:
#line 164 "hoc.y"
    {(yyvsp[(2) - (8)].sym)->type = ARRAY; (yyval.inst) = code3(arrassign, (Inst)(yyvsp[(2) - (8)].sym), (Inst)(yyvsp[(7) - (8)].narg)); ;}
    break;

  case 84:
#line 171 "hoc.y"
    {(yyval.narg) = 0; ;}
    break;

  case 85:
#line 172 "hoc.y"
    {(yyval.narg) = 1; ;}
    break;

  case 86:
#line 173 "hoc.y"
    {(yyval.narg) = (yyvsp[(1) - (3)].narg) + 1; ;}
    break;

  case 87:
#line 175 "hoc.y"
    {(yyval.narg) = 0; ;}
    break;

  case 88:
#line 176 "hoc.y"
    {(yyval.narg) = 1; code2(parassgn, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 89:
#line 177 "hoc.y"
    {(yyval.narg) = (yyvsp[(3) - (3)].narg) + 1; code2(parassgn, (Inst)(yyvsp[(1) - (3)].sym)); ;}
    break;

  case 90:
#line 179 "hoc.y"
    {(yyval.inst) = code(breakcode); ;}
    break;

  case 91:
#line 181 "hoc.y"
    {(yyval.inst) = code(contcode); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2077 "hoc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 186 "hoc.y"


int follow(int expect, int ifyes, int ifno)
{
	int c = getc(fin);
	if (c == expect) return ifyes;
	ungetc(c,fin);
	return ifno;
}

int backslash(int c)
{
	if (c != '\\') return c;
	c = getc(fin);

	switch (c)
	{
		case 'n': return '\n';
		case 'b': return '\b';
		case 'r': return '\r';
		case 't': return '\t';
		case 'f': return '\f';
		default:  return c;
	}
}

int yylex(void)
{
	int c; 
	while ((c = getc(fin)) == ' ' || c == '\t') ; //get rid of blanks
	if (isdigit(c) || c == '.') 
	{
		double d;
		ungetc(c,fin);
		fscanf(fin,"%lf",&d);
		yylval.sym = install("", NUMBER, d); //we are adding the number to the symbol table, we dont assign a name to it.
		return NUMBER;
	} 
	else if (isalpha(c))
	{
		symbol *s;
		char sbuf[100]; 
		char *p = sbuf;
		do
		{
			*p++ = c;
		} while ((c = getc(fin)) != EOF && (isalnum(c) || c == '_'));
		if (strcmp("sys",sbuf) == 0)
		{
			if (c == '-')
			{
				char buf[100];
				int i = 0,c;
				while((c = getc(fin)) != '\n')
				{
					buf[i++] = c;
				}
				buf[i] = '\0';
				ungetc(c,fin);
				symbol *s = install(buf, SYS, 0.0);
				yylval.sym = s;
				return SYS;
			}
			else execerror("sys is a builtin command","");
		}
		ungetc(c, fin);
		*p = '\0';
		if ((s = lookup(sbuf)) == 0) s =  install(sbuf, UNDEF, 0.0); //if sbuf is not present in the table, then we add it and set it to undef
		yylval.sym = s; 
		return s->type == UNDEF ? VAR : s->type; //if the type is undef, return VAR else return s->type (builtin or var)
	}
	else if (c == '_')
	{
		yylval.sym = lookup("_");
		return VAR;
	}
	else if (c == '/')
	{
		int checkcom = follow('/', 1, 0);
		if (checkcom)
		{
			while ((c = getc(fin)) != '\n' && c != EOF);
		}
	}
	else if (c == '$')
	{
		int n = 0,c;
		while (isdigit(c = getc(fin)))
		{
			n = n*10 + (c - '0');
		}
		ungetc(c,fin);
		if (n == 0) execerror("starange $","");
		yylval.narg = n;
		return ARG;
	}
	else if (c == '"')
	{
		char sbuf[100];
		int p;
		for (p = 0; (c = getc(fin)) != '"'; p++)
		{
			if (c == '\n' || c == EOF) execerror("missing quote","");
			if (p >= 100) execerror("size of string too long","");
			sbuf[p] = backslash(c); //checks for newline characters
		}
		sbuf[p] = '\0';
		yylval.sym = (symbol *)emalloc(strlen(sbuf) + 1); 
		strcpy(yylval.sym, sbuf); //rubbish if you ask me
		return STRING;
	}
	switch(c)
	{
	case '>': return follow('=',GE,GT);
	case '<': return follow('=',LE,LT);
	case '=': return follow('=',EQ,'=');
	case '!': return follow('=',NE,NOT);
	case '|': return follow('|',OR,'|');
	case '&': return follow('&',AND,'&');
	case '+': return follow ('+',INC,'+'); 
	case '-':  return follow ('-',DEC,'-'); 
	case '\n': lineno++; return '\n';
	default: return c;
	}
} 

void fpecatch()
{
	execerror("floating point error","");
}

void yyerror(char *s)
{
	execerror(s, "");
}

void warning(const char *s, const char *t)
{
	fprintf(stderr,"\033[0;31m line no:- %d|%s %s \033[0m\n",lineno, (strcmp(t,"") == 0) ? "":t, s);
}

void execerror(const char *s, const char *t)
{
	warning (s,t);
	longjmp(begin, 0);	
}

int main(int argc, char **argv)
{
		
	progname = argv[0];	
	if (argc == 2)
	{
		fin = fopen(argv[1],"r");
		if (!fin)
		{
			printf("%s- file not found",argv[1]);
			return 0;
		}
	}
	else fin = stdin;

	init();
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode()) execute(progbase); //yyparse() will return 0 at the end of file
	if (fin != stdin) fclose(fin);
	return 0;
}

