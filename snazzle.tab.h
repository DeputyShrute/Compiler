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
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    FUNCTION = 259,
    LOOP = 260,
    ENDFOR = 261,
    ENDNESTFOR = 262,
    IF = 263,
    ENDIF = 264,
    ELSE = 265,
    EQ = 266,
    GT = 267,
    LT = 268,
    GT_EQ = 269,
    LT_EQ = 270,
    VAR_DECLARATION = 271,
    IDENTIFIER = 272,
    INCREMENT = 273,
    DECREMENT = 274,
    OPEN_ROUND = 275,
    CLOSE_ROUND = 276,
    OPEN_CURLY = 277,
    CLOSE_CURLY = 278,
    SPEECH_MARK = 279,
    ASSIGNMENT = 280,
    INTEGER = 281,
    STRING = 282,
    PLUS = 283,
    MINUS = 284,
    DIVIDE = 285,
    TIMES = 286,
    SEMI_COLON = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 26 "snazzle.y" /* yacc.c:1909  */

  char* val;
  int integer;



#line 94 "snazzle.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SNAZZLE_TAB_H_INCLUDED  */
