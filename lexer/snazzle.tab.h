/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_SNAZZLE_TAB_H_INCLUDED
# define YY_YY_SNAZZLE_TAB_H_INCLUDED
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
    FUNCTION = 258,
    LOOP = 259,
    EQ = 260,
    GT = 261,
    LT = 262,
    GT_EQ = 263,
    LT_EQ = 264,
    VAR_DECLARATION = 265,
    IDENTIFIER = 266,
    INCREMENT = 267,
    DECREMENT = 268,
    INTEGER = 269,
    OPEN_ROUND = 270,
    CLOSE_ROUND = 271,
    OPEN_CURLY = 272,
    CLOSE_CURLY = 273,
    SPEECH_MARK = 274,
    ASSIGNMENT = 275,
    STRING = 276,
    PLUS = 277,
    MINUS = 278,
    DIVIDE = 279,
    TIMES = 280,
    SEMI_COLON = 281
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 17 "snazzle.y" /* yacc.c:1909  */

  char* func;

  char* loop;

  char* EQ;
  char* GT;
  char* LT;
  char* GT_EQ;
  char* LT_EQ;

  char* var_dec;
  char* var_name;

  char* increment;
  char* decrement;
  
  int integer;

  char* open_round;
  char* close_round;
  char* open_curly;
  char* close_curly;

  char* speech_mark;
  char* assignment;
  char* string;

  char* plus;
  char* minus;
  char* divide;
  char* times;


  char* semi_colon;

#line 118 "snazzle.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SNAZZLE_TAB_H_INCLUDED  */
