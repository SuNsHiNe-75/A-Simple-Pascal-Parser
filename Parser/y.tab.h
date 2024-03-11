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
    ABSOLUTE = 258,
    AND = 259,
    BBEGIN = 260,
    BREAK = 261,
    CASE = 262,
    CONST = 263,
    CONTINUE = 264,
    DO = 265,
    ELSE = 266,
    END = 267,
    FOR = 268,
    FUNCTION = 269,
    IF = 270,
    MOD = 271,
    NIL = 272,
    NOT = 273,
    OBJECT = 274,
    OF = 275,
    OR = 276,
    PROGRAM = 277,
    THEN = 278,
    TO = 279,
    VAR = 280,
    WHILE = 281,
    ARRAY = 282,
    INTEGER = 283,
    DOUBLE = 284,
    WRITE = 285,
    WRITELN = 286,
    STRING = 287,
    CHAR = 288,
    FLOAT = 289,
    READ = 290,
    REALTYPE = 291,
    ASSIGNMENT = 292,
    COLON = 293,
    COMMA = 294,
    DOT = 295,
    EQUAL = 296,
    GE = 297,
    GT = 298,
    LBRAC = 299,
    LE = 300,
    LPAREN = 301,
    LT = 302,
    MINUS = 303,
    NOTEQUAL = 304,
    PLUS = 305,
    RBRAC = 306,
    RPAREN = 307,
    SEMICOLON = 308,
    SLASH = 309,
    STAR = 310,
    UPARROW = 311,
    INT = 312,
    REAL = 313,
    STR = 314,
    ID = 315,
    IOI = 316,
    IOR = 317,
    ROI = 318,
    ROR = 319,
    IDOI = 320,
    IDOR = 321
  };
#endif
/* Tokens.  */
#define ABSOLUTE 258
#define AND 259
#define BBEGIN 260
#define BREAK 261
#define CASE 262
#define CONST 263
#define CONTINUE 264
#define DO 265
#define ELSE 266
#define END 267
#define FOR 268
#define FUNCTION 269
#define IF 270
#define MOD 271
#define NIL 272
#define NOT 273
#define OBJECT 274
#define OF 275
#define OR 276
#define PROGRAM 277
#define THEN 278
#define TO 279
#define VAR 280
#define WHILE 281
#define ARRAY 282
#define INTEGER 283
#define DOUBLE 284
#define WRITE 285
#define WRITELN 286
#define STRING 287
#define CHAR 288
#define FLOAT 289
#define READ 290
#define REALTYPE 291
#define ASSIGNMENT 292
#define COLON 293
#define COMMA 294
#define DOT 295
#define EQUAL 296
#define GE 297
#define GT 298
#define LBRAC 299
#define LE 300
#define LPAREN 301
#define LT 302
#define MINUS 303
#define NOTEQUAL 304
#define PLUS 305
#define RBRAC 306
#define RPAREN 307
#define SEMICOLON 308
#define SLASH 309
#define STAR 310
#define UPARROW 311
#define INT 312
#define REAL 313
#define STR 314
#define ID 315
#define IOI 316
#define IOR 317
#define ROI 318
#define ROR 319
#define IDOI 320
#define IDOR 321

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "B083040010.y" /* yacc.c:1909  */

	char* name;

#line 190 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
