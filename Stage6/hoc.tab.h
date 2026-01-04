/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "hoc.y"
{
	Inst *inst; //machine instruction
	symbol *sym; //symbol table pointer type
	int narg; //number of arguments			
}
/* Line 1529 of yacc.c.  */
#line 135 "hoc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

