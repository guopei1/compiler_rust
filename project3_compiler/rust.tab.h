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

#ifndef YY_YY_RUST_TAB_H_INCLUDED
# define YY_YY_RUST_TAB_H_INCLUDED
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
    COMMA = 258,
    COLON = 259,
    SEMICOLON = 260,
    LP = 261,
    RP = 262,
    LSB = 263,
    RSB = 264,
    LCB = 265,
    RCB = 266,
    PLUS = 267,
    MINUS = 268,
    MULTIPLY = 269,
    DIVIDE = 270,
    INCREMENT = 271,
    DECREMENT = 272,
    MODULUS = 273,
    LT = 274,
    LE = 275,
    GE = 276,
    GT = 277,
    EQ = 278,
    NE = 279,
    AND = 280,
    OR = 281,
    NOR = 282,
    EQUALS = 283,
    PLUSEQUALS = 284,
    MINUSEQUALS = 285,
    MULTIPLYEQUALS = 286,
    DIVIDEEQUALS = 287,
    BREAK = 288,
    CHAR = 289,
    CONTINUE = 290,
    DO = 291,
    ELSE = 292,
    ENUM = 293,
    EXTERN = 294,
    FOR = 295,
    FN = 296,
    IF = 297,
    IN = 298,
    LET = 299,
    LOOP = 300,
    MATCH = 301,
    MUT = 302,
    PRINT = 303,
    PRINTLN = 304,
    PUB = 305,
    RETURN = 306,
    SELF = 307,
    STATIC = 308,
    STRUCT = 309,
    USE = 310,
    WHERE = 311,
    WHILE = 312,
    FALSE = 313,
    TRUE = 314,
    BOOL = 315,
    INT = 316,
    FLOAT = 317,
    STR = 318,
    IDENTIFIER = 319,
    INTEGERVAL = 320,
    STRINGVAL = 321,
    FLOATVAL = 322,
    TRUEVAL = 323,
    FALSEVAL = 324,
    UMINUS = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 329 "rust.y" /* yacc.c:1909  */

  char m_sId[256];
  int m_nInt;
  float m_float;
  char m_str[256];
  char type[256];
  struct s sdec;

#line 134 "rust.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RUST_TAB_H_INCLUDED  */
