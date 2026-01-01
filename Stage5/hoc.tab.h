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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "hoc.y"
{
	Inst *inst; //machine instruction
	symbol *sym; //symbol table pointer type
}
/* Line 1529 of yacc.c.  */
#line 112 "hoc.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

