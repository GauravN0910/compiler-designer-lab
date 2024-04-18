/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PRINTFF = 258,                 /* PRINTFF  */
    SCANFF = 259,                  /* SCANFF  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    WHILE = 262,                   /* WHILE  */
    RETURN = 263,                  /* RETURN  */
    DECLARE = 264,                 /* DECLARE  */
    ADD = 265,                     /* ADD  */
    SUBTRACT = 266,                /* SUBTRACT  */
    MULTIPLY = 267,                /* MULTIPLY  */
    DIVIDE = 268,                  /* DIVIDE  */
    LOG = 269,                     /* LOG  */
    POW = 270,                     /* POW  */
    GTE = 271,                     /* GTE  */
    LTE = 272,                     /* LTE  */
    GT = 273,                      /* GT  */
    LT = 274,                      /* LT  */
    EQ = 275,                      /* EQ  */
    NE = 276,                      /* NE  */
    TRUE = 277,                    /* TRUE  */
    FALSE = 278,                   /* FALSE  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    INT = 281,                     /* INT  */
    FLOAT = 282,                   /* FLOAT  */
    CHAR = 283,                    /* CHAR  */
    BOOL = 284,                    /* BOOL  */
    NUMBER = 285,                  /* NUMBER  */
    FLOAT_NUM = 286,               /* FLOAT_NUM  */
    ID = 287,                      /* ID  */
    STR = 288,                     /* STR  */
    CHARACTER = 289                /* CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PRINTFF 258
#define SCANFF 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define RETURN 263
#define DECLARE 264
#define ADD 265
#define SUBTRACT 266
#define MULTIPLY 267
#define DIVIDE 268
#define LOG 269
#define POW 270
#define GTE 271
#define LTE 272
#define GT 273
#define LT 274
#define EQ 275
#define NE 276
#define TRUE 277
#define FALSE 278
#define AND 279
#define OR 280
#define INT 281
#define FLOAT 282
#define CHAR 283
#define BOOL 284
#define NUMBER 285
#define FLOAT_NUM 286
#define ID 287
#define STR 288
#define CHARACTER 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 54 "toylangparser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
        float value;
	} nd_obj; 

    struct var_name2 { 
        char name[100]; 
        struct node* nd;
        char type[5];
        float value;
    } nd_obj2; 

    struct var_name3 { 
        char name[100]; 
        struct node* nd;
        char type[10];
        char if_body[5];
        char else_body[5];
        char after_else_body[5];
        float value;
    } nd_obj3;

#line 160 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
