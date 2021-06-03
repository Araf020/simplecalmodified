/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    CONST_INT = 258,
    CONST_FLOAT = 259,
    ID = 260,
    INT = 261,
    CHAR = 262,
    DOUBLE = 263,
    TAB = 264,
    FLOAT = 265,
    VOID = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    WHILE = 270,
    PRINTLN = 271,
    RETURN = 272,
    ASSIGNOP = 273,
    NOT = 274,
    INCOP = 275,
    DECOP = 276,
    LOGICOP = 277,
    RELOP = 278,
    ADDOP = 279,
    MULOP = 280,
    LPAREN = 281,
    RPAREN = 282,
    LCURL = 283,
    RCURL = 284,
    LTHIRD = 285,
    RTHIRD = 286,
    COMMA = 287,
    SEMICOLON = 288,
    SYMBOLA = 289,
    LOWER_THAN_ELSE = 290
  };
#endif
/* Tokens.  */
#define CONST_INT 258
#define CONST_FLOAT 259
#define ID 260
#define INT 261
#define CHAR 262
#define DOUBLE 263
#define TAB 264
#define FLOAT 265
#define VOID 266
#define IF 267
#define ELSE 268
#define FOR 269
#define WHILE 270
#define PRINTLN 271
#define RETURN 272
#define ASSIGNOP 273
#define NOT 274
#define INCOP 275
#define DECOP 276
#define LOGICOP 277
#define RELOP 278
#define ADDOP 279
#define MULOP 280
#define LPAREN 281
#define RPAREN 282
#define LCURL 283
#define RCURL 284
#define LTHIRD 285
#define RTHIRD 286
#define COMMA 287
#define SEMICOLON 288
#define SYMBOLA 289
#define LOWER_THAN_ELSE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 107 "1705020.y"

		char *str;
		struct symbol_attribute *fs;
		// struct Symbol *symbol;
		
	

#line 135 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
