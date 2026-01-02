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
     OR = 273,
     AND = 274,
     DEC = 275,
     INC = 276,
     NE = 277,
     EQ = 278,
     LE = 279,
     LT = 280,
     GE = 281,
     GT = 282,
     NOT = 283,
     UNARYMINUS = 284
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
#define OR 273
#define AND 274
#define DEC 275
#define INC 276
#define NE 277
#define EQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define NOT 283
#define UNARYMINUS 284




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

int yylex(void); //for lexing, sending values through yylval and returning its token type
int lineno = 1; 
char *progname;

jmp_buf begin; //we define a jum_buf struct- begin which would hold the timestamps and the necesary details with we setjmp

//some error catching functions
void fpecatch(); //for floating point errors
void execerror(const char *s, const char *t); //resets the state and gives warning the parameters
void warning (const char *s, const char *t); //prints on stderr
void yyerror(char *s); //called upon by yylex for misc errors



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
#line 35 "hoc.y"
{
	Inst *inst; //machine instruction
	symbol *sym; //symbol table pointer type
}
/* Line 193 of yacc.c.  */
#line 192 "hoc.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 205 "hoc.tab.c"

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
#define YYLAST   342

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNRULES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      39,    40,    31,    29,    43,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    18,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      15,    16,    17,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    11,    15,    19,    23,    26,
      30,    34,    38,    42,    46,    50,    54,    56,    58,    60,
      63,    75,    81,    87,    97,   101,   105,   107,   109,   111,
     112,   113,   116,   120,   122,   124,   126,   129,   132,   134,
     136,   141,   148,   152,   156,   160,   164,   168,   172,   176,
     180,   183,   187,   191,   195,   199,   203,   207,   211,   215,
     218,   220,   222,   223,   225
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    -1,    45,    37,    -1,    45,    46,    37,
      -1,    45,     1,    37,    -1,    45,    55,    37,    -1,    45,
      47,    37,    -1,    45,    38,    -1,    45,    46,    38,    -1,
      45,     1,    38,    -1,    45,    55,    38,    -1,    45,    47,
      38,    -1,    45,    10,    37,    -1,     4,    18,    55,    -1,
       7,    18,    55,    -1,    55,    -1,    56,    -1,    57,    -1,
      14,    55,    -1,    50,    39,    54,    38,    54,    38,    54,
      40,    58,    47,    52,    -1,    49,    48,    58,    47,    52,
      -1,    51,    48,    58,    47,    52,    -1,    51,    48,    58,
      47,    52,    13,    58,    47,    52,    -1,    41,    53,    42,
      -1,    39,    55,    40,    -1,    11,    -1,    17,    -1,    12,
      -1,    -1,    -1,    53,    58,    -1,    53,    47,    58,    -1,
      55,    -1,     3,    -1,     4,    -1,     4,    22,    -1,     4,
      21,    -1,     7,    -1,    46,    -1,     5,    39,    55,    40,
      -1,     8,    39,    55,    43,    55,    40,    -1,     9,    39,
      40,    -1,    55,    29,    55,    -1,    55,    30,    55,    -1,
      55,    31,    55,    -1,    55,    32,    55,    -1,    55,    33,
      55,    -1,    55,    36,    55,    -1,    39,    55,    40,    -1,
      30,    55,    -1,    55,    28,    55,    -1,    55,    27,    55,
      -1,    55,    26,    55,    -1,    55,    25,    55,    -1,    55,
      24,    55,    -1,    55,    23,    55,    -1,    55,    20,    55,
      -1,    55,    19,    55,    -1,    34,    55,    -1,    15,    -1,
      16,    -1,    -1,    37,    -1,    58,    37,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    65,    66,    68,    69,    70,    71,
      72,    78,    79,    80,    81,    84,    86,    89,    91,    93,
      95,    96,    97,    99,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     128,   130,   132,   133,   134
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "VAR", "BLTIN", "UNDEF",
  "CNST", "BLTIN2", "BLTIN0", "SYS", "WHILE", "IF", "ELSE", "PRINT",
  "BREAK", "CONTINUE", "FOR", "'='", "OR", "AND", "DEC", "INC", "NE", "EQ",
  "LE", "LT", "GE", "GT", "'+'", "'-'", "'*'", "'/'", "'%'", "NOT",
  "UNARYMINUS", "'^'", "'\\n'", "';'", "'('", "')'", "'{'", "'}'", "','",
  "$accept", "list", "asgn", "stmt", "cond", "while", "for", "if", "end",
  "stmtlist", "fexpr", "expr", "break", "continue", "newl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,    61,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,    43,
      45,    42,    47,    37,   283,   284,    94,    10,    59,    40,
      41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    49,    50,    51,    52,
      53,    53,    53,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    57,    58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     2,
      11,     5,     5,     9,     3,     3,     1,     1,     1,     0,
       0,     2,     3,     1,     1,     1,     2,     2,     1,     1,
       4,     6,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     0,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    34,    35,     0,    38,     0,     0,
       0,    26,    28,     0,    60,    61,    27,     0,     0,     3,
       8,     0,    30,    39,     0,     0,     0,     0,     0,    17,
      18,     5,    10,     0,    37,    36,     0,     0,     0,     0,
      13,    39,    19,    50,    59,     0,     0,     4,     9,     7,
      12,     0,    62,     0,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
      11,    14,     0,    15,     0,    42,    49,    63,    24,    62,
      16,    31,     0,     0,     0,    33,     0,    58,    57,    56,
      55,    54,    53,    52,    51,    43,    44,    45,    46,    47,
      48,    40,     0,    32,    64,    25,    29,     0,    29,     0,
      21,     0,    22,    41,     0,    62,     0,     0,    62,    29,
       0,    23,    29,    20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    41,    24,    52,    25,    26,    27,   110,    46,
      84,    80,    29,    30,    81
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
     -99,    77,   -99,    10,   -99,     1,   -37,   -12,   -25,   -14,
      -8,   -99,   -99,     0,   -99,   -99,   -99,     0,     0,   -99,
     -99,     0,   -99,    31,    33,    -6,    12,    -6,   272,   -99,
     -99,   -99,   -99,     0,   -99,   -99,     0,     0,     0,    34,
     -99,   -99,   292,    17,    17,   200,   116,   -99,   -99,   -99,
     -99,     0,    36,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -99,
     -99,   292,   218,   292,   179,   -99,   -99,   -99,   -99,    36,
     292,    46,   236,   156,    52,   292,   156,   306,   111,    13,
      13,    13,    13,    13,    13,    -5,    -5,    17,    17,    17,
      17,   -99,     0,    46,   -99,   -99,   -99,     0,   -99,   254,
     -99,    57,    83,   -99,     0,    36,    58,   156,    36,   -99,
     156,   -99,   -99,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,    96,   -45,    72,   -99,   -99,   -99,   -98,   -99,
     -96,    -1,   -99,   -99,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      28,    79,    36,     4,     5,     6,    37,     7,     8,     9,
     112,   111,    42,    83,    38,    86,    43,    44,   116,    33,
      45,   121,    34,    35,   123,    39,    65,    66,    67,    40,
      17,    68,    71,    51,    18,    72,    73,    74,   106,    21,
     103,   108,    63,    64,    65,    66,    67,    31,    32,    68,
      82,    53,    85,    68,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    47,    48,
      49,    50,   119,    77,    75,   122,   117,     2,     3,   120,
       4,     5,     6,   104,     7,     8,     9,    10,    11,    12,
     107,    13,    14,    15,    16,   114,   115,    23,   118,    54,
       0,   109,     0,     0,     0,     0,    85,    17,     0,     0,
       0,    18,     0,    85,    19,    20,    21,     0,    22,     4,
       5,     6,     0,     7,     8,     9,     0,    11,    12,     0,
      13,    14,    15,    16,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    17,    68,     0,     0,
      18,     0,     0,    77,     0,    21,     0,    22,    78,     4,
       5,     6,     0,     7,     8,     9,     0,    11,    12,     0,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
      18,     0,     0,   104,     0,    21,     0,    22,    55,    56,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,     0,    68,     0,     0,     0,    55,
      56,     0,   102,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,     0,    68,    55,    56,     0,
      76,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,     0,    68,    55,    56,     0,   101,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,    68,    55,    56,     0,   105,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,     0,
      68,    55,    56,     0,   113,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,     0,    68,    69,
      70,    55,    56,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    56,     0,    68,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,     0,    68
};

static const yytype_int8 yycheck[] =
{
       1,    46,    39,     3,     4,     5,    18,     7,     8,     9,
     108,   107,    13,    52,    39,    54,    17,    18,   114,    18,
      21,   119,    21,    22,   122,    39,    31,    32,    33,    37,
      30,    36,    33,    39,    34,    36,    37,    38,    83,    39,
      79,    86,    29,    30,    31,    32,    33,    37,    38,    36,
      51,    39,    53,    36,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    37,    38,
      37,    38,   117,    37,    40,   120,   115,     0,     1,   118,
       3,     4,     5,    37,     7,     8,     9,    10,    11,    12,
      38,    14,    15,    16,    17,    38,    13,     1,    40,    27,
      -1,   102,    -1,    -1,    -1,    -1,   107,    30,    -1,    -1,
      -1,    34,    -1,   114,    37,    38,    39,    -1,    41,     3,
       4,     5,    -1,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    30,    36,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    -1,    41,    42,     3,
       4,     5,    -1,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    -1,    -1,    37,    -1,    39,    -1,    41,    19,    20,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,    19,
      20,    -1,    43,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    36,    19,    20,    -1,
      40,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    36,    19,    20,    -1,    40,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    19,    20,    -1,    40,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      36,    19,    20,    -1,    40,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    36,    37,
      38,    19,    20,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    20,    -1,    36,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,     0,     1,     3,     4,     5,     7,     8,     9,
      10,    11,    12,    14,    15,    16,    17,    30,    34,    37,
      38,    39,    41,    46,    47,    49,    50,    51,    55,    56,
      57,    37,    38,    18,    21,    22,    39,    18,    39,    39,
      37,    46,    55,    55,    55,    55,    53,    37,    38,    37,
      38,    39,    48,    39,    48,    19,    20,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    36,    37,
      38,    55,    55,    55,    55,    40,    40,    37,    42,    47,
      55,    58,    55,    58,    54,    55,    58,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    40,    43,    58,    37,    40,    47,    38,    47,    55,
      52,    54,    52,    40,    38,    13,    54,    58,    40,    47,
      58,    52,    47,    52
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
        case 4:
#line 54 "hoc.y"
    {code3(prevset, (Inst)pop, STOP); return 1; ;}
    break;

  case 5:
#line 55 "hoc.y"
    {yyerrok; ;}
    break;

  case 6:
#line 56 "hoc.y"
    {code3(prevset, print, STOP); return 1; ;}
    break;

  case 7:
#line 57 "hoc.y"
    {code(STOP); return 1; ;}
    break;

  case 10:
#line 60 "hoc.y"
    {yyerrok; ;}
    break;

  case 11:
#line 61 "hoc.y"
    {code(prevset);;}
    break;

  case 12:
#line 62 "hoc.y"
    {code(STOP); return 1; ;}
    break;

  case 13:
#line 63 "hoc.y"
    {code3(varpush, (Inst)(yyvsp[(2) - (3)].sym) ,sys); ;}
    break;

  case 14:
#line 65 "hoc.y"
    {(yyval.inst) = (yyvsp[(3) - (3)].inst); code3(varpush, (Inst)(yyvsp[(1) - (3)].sym), assign); ;}
    break;

  case 15:
#line 66 "hoc.y"
    {execerror("constant cant be changed",(yyvsp[(1) - (3)].sym)->name); ;}
    break;

  case 16:
#line 68 "hoc.y"
    {code((Inst)pop); ;}
    break;

  case 19:
#line 71 "hoc.y"
    {code(prexpr); (yyval.inst) = (yyvsp[(2) - (2)].inst); ;}
    break;

  case 20:
#line 72 "hoc.y"
    {	((yyvsp[(1) - (11)].inst))[1] = (Inst)(yyvsp[(3) - (11)].inst); 
																															((yyvsp[(1) - (11)].inst))[2] = (Inst)(yyvsp[(5) - (11)].inst);
																															((yyvsp[(1) - (11)].inst))[3] = (Inst)(yyvsp[(7) - (11)].inst); 
																															((yyvsp[(1) - (11)].inst))[4] = (Inst)(yyvsp[(10) - (11)].inst);
																															((yyvsp[(1) - (11)].inst))[5] = (Inst)(yyvsp[(11) - (11)].inst); ;}
    break;

  case 21:
#line 78 "hoc.y"
    {((yyvsp[(1) - (5)].inst))[1] = (Inst)(yyvsp[(4) - (5)].inst); ((yyvsp[(1) - (5)].inst))[2] = (Inst)(yyvsp[(5) - (5)].inst); ;}
    break;

  case 22:
#line 79 "hoc.y"
    {((yyvsp[(1) - (5)].inst))[1] = (Inst)(yyvsp[(4) - (5)].inst); ((yyvsp[(1) - (5)].inst))[3] = (Inst)(yyvsp[(5) - (5)].inst); ;}
    break;

  case 23:
#line 80 "hoc.y"
    {((yyvsp[(1) - (9)].inst))[1] = (Inst)(yyvsp[(4) - (9)].inst); ((yyvsp[(1) - (9)].inst))[2] = (Inst)(yyvsp[(8) - (9)].inst); ((yyvsp[(1) - (9)].inst))[3] = (Inst)(yyvsp[(9) - (9)].inst); ;}
    break;

  case 24:
#line 81 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 25:
#line 84 "hoc.y"
    {code(STOP); (yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 26:
#line 86 "hoc.y"
    {(yyval.inst) = code3(whilecode, STOP, STOP); ;}
    break;

  case 27:
#line 89 "hoc.y"
    {(yyval.inst) = code3(forcode, STOP, STOP); code3(STOP,STOP,STOP);;}
    break;

  case 28:
#line 91 "hoc.y"
    {(yyval.inst) = code(ifcode); code3(STOP,STOP,STOP); ;}
    break;

  case 29:
#line 93 "hoc.y"
    {code(STOP); (yyval.inst) = progp; ;}
    break;

  case 30:
#line 95 "hoc.y"
    {(yyval.inst) = progp; ;}
    break;

  case 33:
#line 99 "hoc.y"
    {code(STOP); (yyval.inst) = (yyvsp[(1) - (1)].inst); ;}
    break;

  case 34:
#line 101 "hoc.y"
    {(yyval.inst) = code2(constpush, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 35:
#line 102 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (1)].sym), eval); ;}
    break;

  case 36:
#line 103 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (2)].sym), inc); ;}
    break;

  case 37:
#line 104 "hoc.y"
    {(yyval.inst) = code3(varpush, (Inst)(yyvsp[(1) - (2)].sym), dec); ;}
    break;

  case 38:
#line 105 "hoc.y"
    {(yyval.inst) = code2(constpush, (Inst)(yyvsp[(1) - (1)].sym)); ;}
    break;

  case 40:
#line 107 "hoc.y"
    {(yyval.inst) = (yyvsp[(3) - (4)].inst); code2(bltin, (Inst)(yyvsp[(1) - (4)].sym)); ;}
    break;

  case 41:
#line 108 "hoc.y"
    {(yyval.inst) = (yyvsp[(5) - (6)].inst); code2(bltin, (Inst)(yyvsp[(1) - (6)].sym)); ;}
    break;

  case 42:
#line 109 "hoc.y"
    {code2(bltin, (Inst)(yyvsp[(1) - (3)].sym)); ;}
    break;

  case 43:
#line 110 "hoc.y"
    {code(add); ;}
    break;

  case 44:
#line 111 "hoc.y"
    {code(sub); ;}
    break;

  case 45:
#line 112 "hoc.y"
    {code(mul); ;}
    break;

  case 46:
#line 113 "hoc.y"
    {code(div_); ;}
    break;

  case 47:
#line 114 "hoc.y"
    {code(mod); ;}
    break;

  case 48:
#line 115 "hoc.y"
    {code(power); ;}
    break;

  case 49:
#line 116 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (3)].inst); ;}
    break;

  case 50:
#line 117 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (2)].inst); code(negate); ;}
    break;

  case 51:
#line 118 "hoc.y"
    {code(gt); ;}
    break;

  case 52:
#line 119 "hoc.y"
    {code(ge); ;}
    break;

  case 53:
#line 120 "hoc.y"
    {code(lt); ;}
    break;

  case 54:
#line 121 "hoc.y"
    {code(le); ;}
    break;

  case 55:
#line 122 "hoc.y"
    {code(eq); ;}
    break;

  case 56:
#line 123 "hoc.y"
    {code(ne); ;}
    break;

  case 57:
#line 124 "hoc.y"
    {code(and_); ;}
    break;

  case 58:
#line 125 "hoc.y"
    {code(or_); ;}
    break;

  case 59:
#line 126 "hoc.y"
    {(yyval.inst) = (yyvsp[(2) - (2)].inst); code(not_); ;}
    break;

  case 60:
#line 128 "hoc.y"
    {(yyval.inst) = code(breakcode); ;}
    break;

  case 61:
#line 130 "hoc.y"
    {(yyval.inst) = code(contcode); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1807 "hoc.tab.c"
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


#line 135 "hoc.y"


int follow(int expect, int ifyes, int ifno)
{
	int c = getchar();
	if (c == expect) return ifyes;
	ungetc(c,stdin);
	return ifno;
}

int yylex(void)
{
	int c; 
	while ((c = getchar()) == ' ' || c == '\t') ; //get rid of blanks
	if (isdigit(c) || c == '.') 
	{
		double d;
		ungetc(c,stdin);
		scanf("%lf",&d);
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
		} while ((c = getchar()) != EOF && isalnum(c));
		if (strcmp("sys",sbuf) == 0)
		{
			if (c == '-')
			{
				char buf[100];
				int i = 0,c;
				while((c = getchar()) != '\n')
				{
					buf[i++] = c;
				}
				buf[i] = '\0';
				ungetc(c,stdin);
				symbol *s = install(buf, SYS, 0.0);
				yylval.sym = s;
				return SYS;
			}
			else execerror("sys is a builtin command","");
		}
		ungetc(c, stdin);
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
	if (c == '/')
	{
		int checkcom = follow('/', 1, 0);
		if (checkcom)
		{
			while ((c = getchar()) != '\n' && c != EOF);
		}
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
	init();
	setjmp(begin);
	signal(SIGFPE, fpecatch);
	for (initcode(); yyparse(); initcode()) execute(prog); //yyparse() will return 0 at the end of file
	return 0;
}

