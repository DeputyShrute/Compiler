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

#ifndef YY_YY_2BASIC_TAB_H_INCLUDED
# define YY_YY_2BASIC_TAB_H_INCLUDED
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
    ELSEIF = 265,
    ELSE = 266,
    EQ = 267,
    GT = 268,
    LT = 269,
    GT_EQ = 270,
    LT_EQ = 271,
    VAR_DECLARATION = 272,
    IDENTIFIER = 273,
    INCREMENT = 274,
    DECREMENT = 275,
    OPEN_ROUND = 276,
    CLOSE_ROUND = 277,
    OPEN_CURLY = 278,
    CLOSE_CURLY = 279,
    SPEECH_MARK = 280,
    ASSIGNMENT = 281,
    INTEGER = 282,
    STRING = 283,
    PLUS = 284,
    MINUS = 285,
    DIVIDE = 286,
    TIMES = 287,
    SEMI_COLON = 288,
    PROCEDURE = 289,
    ENDFUNCTION = 290,
    ENDPROJECT = 291,
    RET = 292,
    RETMAIN = 293,
    NAMESPACE = 294,
    CALLFUNCTION = 295,
    NAME = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "2basic.y" /* yacc.c:1909  */

  char* val;
  int integer;



#line 103 "2basic.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_2BASIC_TAB_H_INCLUDED  */
