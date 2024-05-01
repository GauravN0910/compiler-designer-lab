/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "toylangparser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include<math.h>
    #include"lex.yy.c"
    
    int yyerror(const char *s);
    int yylex(void);
    int yywrap();
    float get_value(char *var);
    void set_value(char *var, float value);

    struct node* mknode(struct node *left, struct node *right, char *token,float value);
    void printBT(struct node*);
    void check_declaration(char *c);
    struct node *head;
    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
        float value;
    } symbol_table[40];
    char *get_ftype(char *);    
    void insert_type();
    void add(char c);
    void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
    int search (char* type);
    char type[10];
    int count=0;
    extern int line_no;
    int q;

    int sem_errors=0;
	int label=0;
    int line_label=0;
	char buff[100];
	char errors[10][100];
	char reserved[15][20] = {"tellme", "take", "checkif", "otherwise", "checktill", "return", "log", "exp", "right", "wrong", "number", "decimal", "letter", "boolean"};
    int ic_idx=0;
    int temp_var=0;
    int is_for=0;
    int is_array=0;
    char currentFuncName[100];
    char icg[1000][1000];

    struct node { 
        struct node *left; 
        struct node *right; 
        char *token; 
        float value;
    };
    int success = 1;
    int temp_arr_var = 0;

#line 131 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
#line 61 "toylangparser.y"
 
	struct var_name { 
		char name[100]; 
		struct node* nd;
        float value;
	} nd_obj; 

    struct var_name2 { 
        char name[100]; 
        struct node* nd;
        int temp_arr_var;
        char type[10];
        float value;
    } nd_obj2; 

    struct var_name3 { 
        char name[100]; 
        struct node* nd;
        char type[10];
        char if_body[5];
        char else_body[5];
        int temp_arr_var;
        char after_else_body[5];
        int tlist[10];
        int tlistsize;
        int flistsize;
        int flist[10];
        float value;
        int label_for_while_start;
    } nd_obj3;

    struct var_name4{
        int next_quad;
    } nd_obj4;

#line 288 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PRINTFF = 3,                    /* PRINTFF  */
  YYSYMBOL_SCANFF = 4,                     /* SCANFF  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_DECLARE = 9,                    /* DECLARE  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUBTRACT = 11,                  /* SUBTRACT  */
  YYSYMBOL_MULTIPLY = 12,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 13,                    /* DIVIDE  */
  YYSYMBOL_LOG = 14,                       /* LOG  */
  YYSYMBOL_POW = 15,                       /* POW  */
  YYSYMBOL_GTE = 16,                       /* GTE  */
  YYSYMBOL_LTE = 17,                       /* LTE  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_TRUE = 22,                      /* TRUE  */
  YYSYMBOL_FALSE = 23,                     /* FALSE  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_FLOAT = 27,                     /* FLOAT  */
  YYSYMBOL_CHAR = 28,                      /* CHAR  */
  YYSYMBOL_BOOL = 29,                      /* BOOL  */
  YYSYMBOL_NUMBER = 30,                    /* NUMBER  */
  YYSYMBOL_FLOAT_NUM = 31,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_STR = 33,                       /* STR  */
  YYSYMBOL_CHARACTER = 34,                 /* CHARACTER  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_42_ = 42,                       /* '='  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_entry = 48,                     /* entry  */
  YYSYMBOL_datatype = 49,                  /* datatype  */
  YYSYMBOL_body = 50,                      /* body  */
  YYSYMBOL_block = 51,                     /* block  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_55_5 = 55,                      /* $@5  */
  YYSYMBOL_56_6 = 56,                      /* $@6  */
  YYSYMBOL_57_7 = 57,                      /* $@7  */
  YYSYMBOL_58_8 = 58,                      /* $@8  */
  YYSYMBOL_59_9 = 59,                      /* $@9  */
  YYSYMBOL_typeArgs = 60,                  /* typeArgs  */
  YYSYMBOL_61_10 = 61,                     /* $@10  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_printparam = 63,                /* printparam  */
  YYSYMBOL_else = 64,                      /* else  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_M = 66,                         /* M  */
  YYSYMBOL_condition = 67,                 /* condition  */
  YYSYMBOL_68_12 = 68,                     /* $@12  */
  YYSYMBOL_69_13 = 69,                     /* $@13  */
  YYSYMBOL_statement = 70,                 /* statement  */
  YYSYMBOL_71_14 = 71,                     /* $@14  */
  YYSYMBOL_72_15 = 72,                     /* $@15  */
  YYSYMBOL_73_16 = 73,                     /* $@16  */
  YYSYMBOL_assign = 74,                    /* assign  */
  YYSYMBOL_init = 75,                      /* init  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_term = 77,                      /* term  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_base = 79,                      /* base  */
  YYSYMBOL_exponent = 80,                  /* exponent  */
  YYSYMBOL_mulops = 81,                    /* mulops  */
  YYSYMBOL_addops = 82,                    /* addops  */
  YYSYMBOL_relop = 83,                     /* relop  */
  YYSYMBOL_value = 84,                     /* value  */
  YYSYMBOL_array = 85,                     /* array  */
  YYSYMBOL_charbool = 86,                  /* charbool  */
  YYSYMBOL_valcharbool = 87,               /* valcharbool  */
  YYSYMBOL_bools = 88,                     /* bools  */
  YYSYMBOL_return = 89,                    /* return  */
  YYSYMBOL_90_17 = 90                      /* $@17  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      35,    36,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   106,   115,   117,   120,   121,   122,   123,
     126,   127,   130,   130,   130,   147,   147,   154,   147,   167,
     168,   168,   169,   169,   169,   175,   187,   187,   200,   211,
     214,   218,   222,   226,   231,   234,   238,   240,   240,   241,
     244,   254,   277,   300,   327,   339,   339,   340,   340,   343,
     343,   364,   364,   385,   385,   386,   391,   398,   403,   407,
     413,   414,   415,   432,   445,   448,   461,   464,   477,   478,
     481,   482,   486,   489,   490,   493,   494,   497,   498,   499,
     500,   501,   502,   505,   513,   521,   533,   536,   553,   554,
     557,   558,   561,   562,   565,   565,   566
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PRINTFF", "SCANFF",
  "IF", "ELSE", "WHILE", "RETURN", "DECLARE", "ADD", "SUBTRACT",
  "MULTIPLY", "DIVIDE", "LOG", "POW", "GTE", "LTE", "GT", "LT", "EQ", "NE",
  "TRUE", "FALSE", "AND", "OR", "INT", "FLOAT", "CHAR", "BOOL", "NUMBER",
  "FLOAT_NUM", "ID", "STR", "CHARACTER", "'('", "')'", "'{'", "'}'", "';'",
  "','", "'&'", "'='", "'['", "']'", "$accept", "program", "$@1", "entry",
  "datatype", "body", "block", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "typeArgs", "$@10", "args", "printparam", "else", "$@11",
  "M", "condition", "$@12", "$@13", "statement", "$@14", "$@15", "$@16",
  "assign", "init", "expression", "term", "factor", "base", "exponent",
  "mulops", "addops", "relop", "value", "array", "charbool", "valcharbool",
  "bools", "return", "$@17", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     119,   -88,   -88,   -88,   -88,    30,   -27,    -8,   -88,   119,
     -88,    10,    26,    27,   -88,     4,     9,   119,    46,   -88,
     -88,   -88,   -88,   -88,   119,    -9,    57,    46,    28,    35,
      45,    54,    75,    78,    72,    44,    44,    73,   136,   -88,
      90,   -88,   -88,    44,    86,   117,    68,    68,   -88,    97,
     -88,   -88,   122,    44,   106,     8,    24,   -88,   152,   -13,
     -88,    -4,   -88,    52,   -88,   -88,   -88,   -88,   -88,   -88,
      44,    99,   119,   151,   127,   -88,   -88,   -88,   -88,   132,
     -88,   -88,   -88,   -88,   129,    61,    69,    68,    87,   136,
     100,    14,   128,     5,   131,   -88,   -88,    44,    44,   -88,
     -88,    44,   -88,   109,    44,   -88,   -14,   -88,   151,   133,
     151,   134,   -88,   135,   130,   -88,   -88,   113,   -88,   -88,
     -88,    99,   -88,    38,   145,   -88,   137,   -88,   -88,   -88,
      24,   -88,   -88,   -88,    44,   -88,   -88,   144,   -88,    68,
      68,   141,   -88,   142,   151,   -88,   138,   128,   147,   -88,
     139,   139,    46,    46,   -88,   148,   -88,   149,   143,   150,
     -88,   153,   -88,   -88,   -88,   174,   -88,   -88,   154,    46,
     155,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     6,     7,     8,     9,     0,     0,     0,     1,    29,
       5,     0,     0,    26,     2,     0,     0,    29,    11,    27,
      20,    22,    15,    12,     0,    53,    96,    11,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,    94,
       0,    10,    19,     0,     0,     0,     0,     0,    49,     0,
      83,    84,    85,     0,     0,    32,    64,    66,    69,    70,
      86,     0,    70,     0,    80,    79,    78,    77,    81,    82,
       0,     0,     4,    55,    86,    92,    93,    36,    89,     0,
      90,    91,    35,    88,     0,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,    75,    76,    34,     0,    73,
      74,     0,    72,     0,    34,    87,    85,    52,    57,    86,
      54,     0,     3,     0,     0,    46,    48,     0,    40,    40,
      16,     0,    13,     0,     0,    50,     0,    71,    25,    30,
      63,    65,    67,    31,    34,    95,    21,     0,    44,     0,
       0,     0,    43,     0,    61,    60,     0,     0,     0,    23,
      41,    42,    11,    11,    62,     0,    59,     0,     0,     0,
      68,     0,    17,    14,    24,    39,    37,    18,     0,    11,
       0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   114,   -88,   -88,    11,   -26,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   170,   -88,   -87,   -88,   -88,
     -88,    70,   -44,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -31,    92,    93,    94,   -88,   -88,   -88,   107,   -33,
     -18,    76,   -40,   -88,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    16,     6,     7,    26,    27,    33,   143,    32,
     141,   165,    30,    31,   157,    12,    15,    54,    79,   167,
     168,   139,    88,   115,   116,    28,    91,    37,    38,   107,
     125,    55,    56,    57,    58,   103,   101,    98,    70,    62,
      60,    81,    89,    83,    40,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    41,    59,    90,    82,    61,    95,    96,     9,    29,
     129,    80,    73,    80,    80,    95,    96,   133,    95,    96,
      11,   134,    93,   -33,    10,    74,    35,   104,    11,    36,
       8,   111,   108,   -51,    36,    34,    99,   100,    80,   110,
     105,   127,    13,   117,    17,   109,    18,   148,    97,    20,
      21,    22,    49,    23,    80,    24,   123,   124,    49,   126,
      75,    76,    14,   -28,    59,    39,    49,    42,    50,    51,
      52,    59,    78,    53,    50,    51,    52,    43,    25,    53,
      44,   142,    50,    51,   106,   -45,   -45,    53,    80,    45,
      85,    86,   144,   -47,   -47,   150,   151,   -45,    50,    51,
      52,    59,    78,    87,    48,   -47,    80,    80,    75,    76,
      46,   118,   119,    47,   155,    63,    50,    51,    52,    77,
      78,    75,    76,   120,   118,   119,   158,   159,    72,    50,
      51,    52,    92,    78,    29,    29,   122,   118,   119,    50,
      51,    52,    94,   170,    53,     1,     2,     3,     4,   138,
      84,    29,    64,    65,    66,    67,    68,    69,    50,    51,
      52,    95,    96,   118,   119,    36,   -56,   102,   113,   114,
     128,   137,   -58,   135,   136,   146,   149,   147,   152,   153,
     166,   162,   154,   156,   160,   161,   112,    19,   163,   140,
     130,   169,   164,   171,   131,     0,   121,   132,     0,   145
};

static const yytype_int16 yycheck[] =
{
      18,    27,    35,    47,    44,    36,    10,    11,    35,    27,
      97,    44,    43,    46,    47,    10,    11,   104,    10,    11,
       9,    35,    53,    36,    32,    43,    35,    40,    17,    43,
       0,    71,    63,    42,    43,    24,    12,    13,    71,    70,
      44,    36,    32,    87,    40,    63,    37,   134,    40,     3,
       4,     5,    14,     7,    87,     9,    42,    43,    14,    92,
      22,    23,    36,    36,    97,     8,    14,    39,    30,    31,
      32,   104,    34,    35,    30,    31,    32,    42,    32,    35,
      35,   121,    30,    31,    32,    24,    25,    35,   121,    35,
      22,    23,   123,    24,    25,   139,   140,    36,    30,    31,
      32,   134,    34,    35,    32,    36,   139,   140,    22,    23,
      35,    24,    25,    35,   147,    42,    30,    31,    32,    33,
      34,    22,    23,    36,    24,    25,   152,   153,    38,    30,
      31,    32,    35,    34,   152,   153,    36,    24,    25,    30,
      31,    32,    36,   169,    35,    26,    27,    28,    29,    36,
      33,   169,    16,    17,    18,    19,    20,    21,    30,    31,
      32,    10,    11,    24,    25,    43,    39,    15,    36,    40,
      39,    41,    39,    39,    39,    30,    32,    40,    37,    37,
       6,    38,    44,    36,    36,    36,    72,    17,    38,   119,
      98,    37,    39,    38,   101,    -1,    89,   103,    -1,   123
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    27,    28,    29,    46,    48,    49,     0,    35,
      32,    49,    60,    32,    36,    61,    47,    40,    37,    60,
       3,     4,     5,     7,     9,    32,    50,    51,    70,    85,
      57,    58,    54,    52,    49,    35,    43,    72,    73,     8,
      89,    50,    39,    42,    35,    35,    35,    35,    32,    14,
      30,    31,    32,    35,    62,    76,    77,    78,    79,    84,
      85,    76,    84,    42,    16,    17,    18,    19,    20,    21,
      83,    90,    38,    76,    85,    22,    23,    33,    34,    63,
      84,    86,    87,    88,    33,    22,    23,    35,    67,    87,
      67,    71,    35,    76,    36,    10,    11,    40,    82,    12,
      13,    81,    15,    80,    40,    44,    32,    74,    76,    85,
      76,    87,    46,    36,    40,    68,    69,    67,    24,    25,
      36,    83,    36,    42,    43,    75,    84,    36,    39,    62,
      77,    78,    79,    62,    35,    39,    39,    41,    36,    66,
      66,    55,    87,    53,    76,    86,    30,    40,    62,    32,
      67,    67,    37,    37,    44,    84,    36,    59,    50,    50,
      36,    36,    38,    38,    39,    56,     6,    64,    65,    37,
      50,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    46,    48,    49,    49,    49,    49,
      50,    50,    52,    53,    51,    54,    55,    56,    51,    51,
      57,    51,    58,    59,    51,    51,    61,    60,    60,    60,
      62,    62,    62,    62,    62,    63,    63,    65,    64,    64,
      66,    67,    67,    67,    67,    68,    67,    69,    67,    71,
      70,    72,    70,    73,    70,    70,    70,    74,    74,    74,
      75,    75,    75,    76,    76,    77,    77,    78,    78,    78,
      79,    79,    80,    81,    81,    82,    82,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    84,    85,    86,    86,
      87,    87,    88,    88,    90,    89,    89
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,    10,     0,     2,     1,     1,     1,     1,
       2,     0,     0,     0,     9,     0,     0,     0,    11,     2,
       0,     6,     0,     0,    10,     5,     0,     5,     2,     0,
       3,     3,     1,     1,     0,     1,     1,     0,     5,     0,
       0,     4,     4,     3,     3,     0,     2,     0,     2,     0,
       5,     0,     4,     0,     4,     3,     3,     1,     1,     4,
       2,     2,     3,     3,     1,     3,     1,     3,     6,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     0,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 106 "toylangparser.y"
                                {
	sprintf(icg[ic_idx++], "\nFunction: %s\n", (yyvsp[-3].nd_obj).name);
}
#line 1752 "y.tab.c"
    break;

  case 3: /* program: entry '(' typeArgs ')' $@1 '{' body return '}' program  */
#line 108 "toylangparser.y"
                              { 
	struct node *main = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-9].nd_obj).name,0); 
	struct node *args = mknode(NULL, (yyvsp[-7].nd_obj3).nd, "Func-Params",0); 
	struct node *wrapper = mknode(args, main, "Function",0);
	(yyval.nd_obj).nd = mknode( (yyvsp[0].nd_obj).nd, wrapper, "Program",0); 
	head = (yyval.nd_obj).nd; 
}
#line 1764 "y.tab.c"
    break;

  case 4: /* program: %empty  */
#line 115 "toylangparser.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1770 "y.tab.c"
    break;

  case 5: /* entry: datatype ID  */
#line 117 "toylangparser.y"
                   { printf("after here\n"); add('F'); strcpy((yyval.nd_obj).name, (yyvsp[0].nd_obj).name); strcpy(currentFuncName, (yyvsp[0].nd_obj).name); }
#line 1776 "y.tab.c"
    break;

  case 6: /* datatype: INT  */
#line 120 "toylangparser.y"
              { insert_type();  (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0);}
#line 1782 "y.tab.c"
    break;

  case 7: /* datatype: FLOAT  */
#line 121 "toylangparser.y"
         { insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0);}
#line 1788 "y.tab.c"
    break;

  case 8: /* datatype: CHAR  */
#line 122 "toylangparser.y"
       { insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0);}
#line 1794 "y.tab.c"
    break;

  case 9: /* datatype: BOOL  */
#line 123 "toylangparser.y"
       { insert_type(); (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0);}
#line 1800 "y.tab.c"
    break;

  case 10: /* body: block body  */
#line 126 "toylangparser.y"
                 {(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "body",0);}
#line 1806 "y.tab.c"
    break;

  case 11: /* body: %empty  */
#line 127 "toylangparser.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1812 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 130 "toylangparser.y"
             {add('K'); is_for=1; }
#line 1818 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 130 "toylangparser.y"
                                                      {
    sprintf(icg[ic_idx++], "LABEL L%d:\n", label++);
    for(int i=0;i<(yyvsp[-1].nd_obj3).tlistsize;i++){
        char gotha[20];
        sprintf(gotha, "GOTO L%d\n", label-1);
        strcat(icg[(yyvsp[-1].nd_obj3).tlist[i]], gotha);
    }
}
#line 1831 "y.tab.c"
    break;

  case 14: /* block: WHILE $@2 '(' condition ')' $@3 '{' body '}'  */
#line 137 "toylangparser.y"
               { 
    (yyval.nd_obj).nd = mknode((yyvsp[-5].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-8].nd_obj).name,0);
    sprintf(icg[ic_idx++], "JUMP TO L%d\n", (yyvsp[-5].nd_obj3).label_for_while_start);
    for(int i=0;i<(yyvsp[-5].nd_obj3).flistsize;i++){
        char gotha[20];
        sprintf(gotha, "GOTO L%d\n", label);
        strcat(icg[(yyvsp[-5].nd_obj3).flist[i]], gotha);
    }
	sprintf(icg[ic_idx++], "LABEL L%d:\n",label++);
}
#line 1846 "y.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 147 "toylangparser.y"
     {add('K'); is_for =0;}
#line 1852 "y.tab.c"
    break;

  case 16: /* $@5: %empty  */
#line 147 "toylangparser.y"
                                              { 
    sprintf(icg[ic_idx++], "LABEL L%d:\n", label++); 
    for(int i=0;i<(yyvsp[-1].nd_obj3).tlistsize;i++){
        char gotha[20];
        sprintf(gotha, "GOTO L%d\n", label-1);
        strcat(icg[(yyvsp[-1].nd_obj3).tlist[i]], gotha);
    }
}
#line 1865 "y.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 154 "toylangparser.y"
               {  
    sprintf(icg[ic_idx++],"JUMP TO L%d\n", label+1);
    sprintf(icg[ic_idx++], "LABEL L%d:\n", label++);
    for(int i=0;i<(yyvsp[-5].nd_obj3).flistsize;i++){
        char gotha[20];
        sprintf(gotha, "GOTO L%d\n", label-1);
        sprintf(icg[(yyvsp[-5].nd_obj3).flist[i]],gotha);
    } 
    }
#line 1879 "y.tab.c"
    break;

  case 18: /* block: IF $@4 '(' condition ')' $@5 '{' body '}' $@6 else  */
#line 162 "toylangparser.y"
           { 
        struct node *iff = mknode((yyvsp[-7].nd_obj3).nd, (yyvsp[-3].nd_obj).nd, (yyvsp[-10].nd_obj).name,0); 
        (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else-block",0); 
        sprintf(icg[ic_idx++], "LABEL L%d:\n", label++);
    }
#line 1889 "y.tab.c"
    break;

  case 19: /* block: statement ';'  */
#line 167 "toylangparser.y"
                { (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd; }
#line 1895 "y.tab.c"
    break;

  case 20: /* $@7: %empty  */
#line 168 "toylangparser.y"
          { add('K'); }
#line 1901 "y.tab.c"
    break;

  case 21: /* block: PRINTFF $@7 '(' printparam ')' ';'  */
#line 168 "toylangparser.y"
                                               { (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, (yyvsp[-5].nd_obj).name,0); sprintf(icg[ic_idx++], "\nCALL print, 1 \n"); }
#line 1907 "y.tab.c"
    break;

  case 22: /* $@8: %empty  */
#line 169 "toylangparser.y"
         {add('K');}
#line 1913 "y.tab.c"
    break;

  case 23: /* $@9: %empty  */
#line 169 "toylangparser.y"
                                        { check_declaration((yyvsp[0].nd_obj).name); }
#line 1919 "y.tab.c"
    break;

  case 24: /* block: SCANFF $@8 '(' STR ',' '&' ID $@9 ')' ';'  */
#line 169 "toylangparser.y"
                                                                                { struct node* n1 = mknode(NULL,NULL,(yyvsp[-6].nd_obj).name,0); struct node* n2 = mknode(NULL,NULL,(yyvsp[-3].nd_obj).name,0); (yyval.nd_obj).nd = mknode(n1,n2,(yyvsp[-9].nd_obj).name,0);
    sprintf(icg[ic_idx++],"t%d = %s\n",temp_var++,(yyvsp[-6].nd_obj).name);
    sprintf(icg[ic_idx++],"PARAM t%d\n",temp_var-1);
    sprintf(icg[ic_idx++],"PARAM %s\n",(yyvsp[-3].nd_obj).name);
    sprintf(icg[ic_idx++],"CALL scanf , 2\n");
}
#line 1930 "y.tab.c"
    break;

  case 25: /* block: ID '(' args ')' ';'  */
#line 175 "toylangparser.y"
                      {
	printf("%s\n",get_ftype((yyvsp[-4].nd_obj).name));
	if(strcmp( get_ftype((yyvsp[-4].nd_obj).name) ,"Function") != 0 ){
		sprintf(errors[sem_errors], "Line %d: Unpermitted operation on not Function \"%s \"!\n", count+1, (yyvsp[-4].nd_obj).name);
		sem_errors++;	
	}
	struct node *args = mknode(NULL, (yyvsp[-2].nd_obj3).nd, "Func-Params",0); 
	(yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, args, "Func-Call",0);
	sprintf(icg[ic_idx++], "CALL: %s\n", (yyvsp[-4].nd_obj).name);
}
#line 1945 "y.tab.c"
    break;

  case 26: /* $@10: %empty  */
#line 187 "toylangparser.y"
                       {
    symbol_table[count].id_name=strdup((yyvsp[0].nd_obj).name);
    symbol_table[count].data_type=strdup((yyvsp[-1].nd_obj).name);
    symbol_table[count].line_no=line_no;
    symbol_table[count].type=strdup("Variable");   
    count++;  
}
#line 1957 "y.tab.c"
    break;

  case 27: /* typeArgs: datatype ID $@10 ',' typeArgs  */
#line 193 "toylangparser.y"
                { 
	sprintf(icg[ic_idx++], "\nArg: %s:%s\n", (yyvsp[-4].nd_obj).name,(yyvsp[-3].nd_obj).name);
	char temp[50]; 
	sprintf(temp, "%s:%s", (yyvsp[-4].nd_obj).name,(yyvsp[-3].nd_obj).name);
	struct node *tempNode = mknode(NULL,NULL,temp,0); 
	(yyval.nd_obj3).nd = mknode(tempNode, (yyvsp[0].nd_obj3).nd, "args",0); 
}
#line 1969 "y.tab.c"
    break;

  case 28: /* typeArgs: datatype ID  */
#line 200 "toylangparser.y"
               { 
    symbol_table[count].id_name=strdup((yyvsp[0].nd_obj).name);
    symbol_table[count].data_type=strdup((yyvsp[-1].nd_obj).name);
    symbol_table[count].line_no=line_no;
    symbol_table[count].type=strdup("Variable");   
    count++;
	sprintf(icg[ic_idx++], "\Arg: %s:%s\n", (yyvsp[-1].nd_obj).name,(yyvsp[0].nd_obj).name);
	char temp[50]; 
	sprintf(temp, "%s:%s", (yyvsp[-1].nd_obj).name,(yyvsp[0].nd_obj).name);
	(yyval.nd_obj3).nd = mknode(NULL,NULL,temp,0); 
}
#line 1985 "y.tab.c"
    break;

  case 29: /* typeArgs: %empty  */
#line 211 "toylangparser.y"
  { (yyval.nd_obj3).nd = NULL; }
#line 1991 "y.tab.c"
    break;

  case 30: /* args: expression ',' args  */
#line 214 "toylangparser.y"
                           { 
	sprintf(icg[ic_idx++], "PARAM: %s\n", (yyvsp[-2].nd_obj2).name); 
	(yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj3).nd, "args",0); 
}
#line 2000 "y.tab.c"
    break;

  case 31: /* args: value ',' args  */
#line 218 "toylangparser.y"
                 { 
	sprintf(icg[ic_idx++], "PARAM: %s\n", (yyvsp[-2].nd_obj2).name); 
	(yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj3).nd, "args",0); 
}
#line 2009 "y.tab.c"
    break;

  case 32: /* args: expression  */
#line 222 "toylangparser.y"
             { 
	sprintf(icg[ic_idx++], "PARAM: %s\n", (yyvsp[0].nd_obj2).name); 
	(yyval.nd_obj3).nd = (yyvsp[0].nd_obj2).nd; 
}
#line 2018 "y.tab.c"
    break;

  case 33: /* args: value  */
#line 226 "toylangparser.y"
        { 
	sprintf(icg[ic_idx++], "PARAM: %s\n", (yyvsp[0].nd_obj2).name); 
	char temp[50]; sprintf(temp, "%s", (yyvsp[0].nd_obj2).name);
	(yyval.nd_obj3).nd = mknode(NULL,NULL,temp,0); 
}
#line 2028 "y.tab.c"
    break;

  case 34: /* args: %empty  */
#line 231 "toylangparser.y"
  { (yyval.nd_obj3).nd = NULL; }
#line 2034 "y.tab.c"
    break;

  case 35: /* printparam: valcharbool  */
#line 234 "toylangparser.y"
                        { 
    (yyval.nd_obj).nd = (yyvsp[0].nd_obj2).nd;  
    sprintf(icg[ic_idx++], "PARAM %s\n", (yyvsp[0].nd_obj2).name);
}
#line 2043 "y.tab.c"
    break;

  case 36: /* printparam: STR  */
#line 238 "toylangparser.y"
      { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0); sprintf(icg[ic_idx++], "\n t0 = %s\n PARAM t0\n", (yyvsp[0].nd_obj).name); }
#line 2049 "y.tab.c"
    break;

  case 37: /* $@11: %empty  */
#line 240 "toylangparser.y"
           {add('K');}
#line 2055 "y.tab.c"
    break;

  case 38: /* else: ELSE $@11 '{' body '}'  */
#line 240 "toylangparser.y"
                                    { (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name,0); }
#line 2061 "y.tab.c"
    break;

  case 39: /* else: %empty  */
#line 241 "toylangparser.y"
   { (yyval.nd_obj).nd = NULL; }
#line 2067 "y.tab.c"
    break;

  case 40: /* M: %empty  */
#line 244 "toylangparser.y"
   { 
    (yyval.nd_obj4).next_quad = ic_idx; 
    char new1[100];
    sprintf(new1, "%d:\n", ic_idx);
    char new2[100];
    sprintf(new2, "LABEL S");
    strcat(new2, new1);
    strcpy(icg[ic_idx], new2);
 }
#line 2081 "y.tab.c"
    break;

  case 41: /* condition: condition AND M condition  */
#line 254 "toylangparser.y"
                                     {
    (yyval.nd_obj3).nd = mknode((yyvsp[-3].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "AND",0);
    for (int i = 0; i < (yyvsp[-3].nd_obj3).tlistsize; i++) {
        char chumma[10];
        sprintf(chumma, "%d\n", (yyvsp[-1].nd_obj4).next_quad);
        char chumma2[100];
        sprintf(chumma2,"GOTO S");
        strcat(chumma2,chumma);
        strcat(icg[(yyvsp[-3].nd_obj3).tlist[i]], chumma2);
    }
    (yyval.nd_obj3).tlistsize = 0;
    (yyval.nd_obj3).flistsize = 0;
    for (int i = 0; i < (yyvsp[0].nd_obj3).tlistsize; i++) {
        (yyval.nd_obj3).tlist[(yyval.nd_obj3).tlistsize++] = (yyvsp[0].nd_obj3).tlist[i];
    }
    for (int i = 0; i < (yyvsp[-3].nd_obj3).flistsize; i++) {
        (yyval.nd_obj3).flist[(yyval.nd_obj3).flistsize++] = (yyvsp[-3].nd_obj3).flist[i];
    }
    for(int i=0;i<(yyvsp[0].nd_obj3).flistsize;i++){
        (yyval.nd_obj3).flist[(yyval.nd_obj3).flistsize++] = (yyvsp[0].nd_obj3).flist[i];
    }
    (yyval.nd_obj3).label_for_while_start = (yyvsp[-3].nd_obj3).label_for_while_start;
}
#line 2109 "y.tab.c"
    break;

  case 42: /* condition: condition OR M condition  */
#line 277 "toylangparser.y"
                           {
    (yyval.nd_obj3).nd = mknode((yyvsp[-3].nd_obj3).nd, (yyvsp[0].nd_obj3).nd, "OR",0);
    for (int i = 0; i < (yyvsp[-3].nd_obj3).flistsize; i++) {
        char chumma[10];
        sprintf(chumma, "%d\n", (yyvsp[-1].nd_obj4).next_quad);
        char chumma2[100];
        sprintf(chumma2,"GOTO S");
        strcat(chumma2,chumma);
        strcat(icg[(yyvsp[-3].nd_obj3).flist[i]], chumma2);
    }
    (yyval.nd_obj3).tlistsize = 0;
    (yyval.nd_obj3).flistsize = 0;
    for (int i = 0; i < (yyvsp[-3].nd_obj3).tlistsize; i++) {
        (yyval.nd_obj3).tlist[(yyval.nd_obj3).tlistsize++] = (yyvsp[-3].nd_obj3).tlist[i];
    }
    for (int i = 0; i < (yyvsp[0].nd_obj3).tlistsize; i++) {
        (yyval.nd_obj3).tlist[(yyval.nd_obj3).tlistsize++] = (yyvsp[0].nd_obj3).tlist[i];
    }
    for(int i=0;i<(yyvsp[0].nd_obj3).flistsize;i++){
        (yyval.nd_obj3).flist[(yyval.nd_obj3).flistsize++] = (yyvsp[0].nd_obj3).flist[i];
    }
    (yyval.nd_obj3).label_for_while_start = (yyvsp[-3].nd_obj3).label_for_while_start;
}
#line 2137 "y.tab.c"
    break;

  case 43: /* condition: valcharbool relop valcharbool  */
#line 300 "toylangparser.y"
                                {
    if(strcmp((yyvsp[-2].nd_obj2).type,(yyvsp[0].nd_obj2).type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    }
    strcpy((yyval.nd_obj3).type,"boolean");
    (yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name,0);  
    char ifstt[400];
    if(is_for){
        (yyval.nd_obj3).label_for_while_start = label;
        sprintf(icg[ic_idx++], "LABEL L%d:\n", label++);
        is_for=0;
    }
    if(is_array==0){
        sprintf(ifstt, "if %s %s %s \n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    }
    else{
        sprintf(ifstt,"if u%d %s u%d\n",(yyvsp[-2].nd_obj2).temp_arr_var,(yyvsp[-1].nd_obj).name,(yyvsp[0].nd_obj2).temp_arr_var);
        is_array = 0;
    }
    strcat(icg[ic_idx++], ifstt);
    (yyval.nd_obj3).tlistsize = 0;
    (yyval.nd_obj3).flistsize = 0;
    (yyval.nd_obj3).tlist[(yyval.nd_obj3).tlistsize++] = ic_idx-1;
    (yyval.nd_obj3).flist[(yyval.nd_obj3).flistsize++] = ic_idx++;
}
#line 2169 "y.tab.c"
    break;

  case 44: /* condition: '(' condition ')'  */
#line 327 "toylangparser.y"
                    { 
    (yyval.nd_obj3).nd = (yyvsp[-1].nd_obj3).nd; 
    (yyval.nd_obj3).tlistsize = (yyvsp[-1].nd_obj3).tlistsize;
    (yyval.nd_obj3).flistsize = (yyvsp[-1].nd_obj3).flistsize;
    for(int i=0;i<(yyvsp[-1].nd_obj3).tlistsize;i++){
        (yyval.nd_obj3).tlist[i] = (yyvsp[-1].nd_obj3).tlist[i];
    }
    for(int i=0;i<(yyvsp[-1].nd_obj3).flistsize;i++){
        (yyval.nd_obj3).flist[i] = (yyvsp[-1].nd_obj3).flist[i];
    }
    (yyval.nd_obj3).label_for_while_start = (yyvsp[-1].nd_obj3).label_for_while_start;
}
#line 2186 "y.tab.c"
    break;

  case 45: /* $@12: %empty  */
#line 339 "toylangparser.y"
       {add('K');}
#line 2192 "y.tab.c"
    break;

  case 46: /* condition: TRUE $@12  */
#line 339 "toylangparser.y"
                   { (yyval.nd_obj3).nd = NULL; strcpy((yyval.nd_obj3).type,"boolean"); }
#line 2198 "y.tab.c"
    break;

  case 47: /* $@13: %empty  */
#line 340 "toylangparser.y"
        {add('K');}
#line 2204 "y.tab.c"
    break;

  case 48: /* condition: FALSE $@13  */
#line 340 "toylangparser.y"
                    { (yyval.nd_obj3).nd = NULL; strcpy((yyval.nd_obj3).type,"boolean"); }
#line 2210 "y.tab.c"
    break;

  case 49: /* $@14: %empty  */
#line 343 "toylangparser.y"
                               { add('V'); }
#line 2216 "y.tab.c"
    break;

  case 50: /* statement: DECLARE datatype ID $@14 init  */
#line 343 "toylangparser.y"
                                                  { (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name,0);  
        if(check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type)) { 
            success=0;
            sprintf(errors[sem_errors], "Line %d: Variable \"%s\" has a different type than expected!\n", line_no, (yyvsp[-2].nd_obj).name);
            sem_errors++;
        } 
        else { 
            (yyvsp[-4].nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-2].nd_obj).nd, (yyvsp[-4].nd_obj).name,0);
        } 
        (yyval.nd_obj).nd = mknode((yyvsp[-4].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "DECLARE",0);
        (yyvsp[-2].nd_obj).value = (yyvsp[0].nd_obj2).value;
        (yyvsp[-2].nd_obj).nd->value = (yyvsp[0].nd_obj2).value;
        set_value((yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj2).value);
        if(is_array==0){
            sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj2).name);
        }
        else{
            is_array=0;
            sprintf(icg[ic_idx++], "%s = int %s\n",(yyvsp[-2].nd_obj).name,(yyvsp[0].nd_obj2).name);
        }
    }
#line 2242 "y.tab.c"
    break;

  case 51: /* $@15: %empty  */
#line 364 "toylangparser.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 2248 "y.tab.c"
    break;

  case 52: /* statement: ID $@15 '=' assign  */
#line 364 "toylangparser.y"
                                                {
        if(is_array == 0){
            char *id_type = get_type((yyvsp[-3].nd_obj).name);
            if(id_type!=NULL && strcmp(id_type,(yyvsp[0].nd_obj2).type)){
                success=0;
                sprintf(errors[sem_errors], "Line %d: Variable \"%s\" has a different type than expected!\n", line_no, (yyvsp[-3].nd_obj).name);
                sem_errors++;
            }
            (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name,0); 
            (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "=",0); 
            (yyvsp[-3].nd_obj).value = (yyvsp[0].nd_obj2).value;
            (yyvsp[-3].nd_obj).nd->value = (yyvsp[0].nd_obj2).value;
            set_value((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).value);
            sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).name);
        }
        else{
            is_array = 0;
            (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd,(yyvsp[0].nd_obj2).nd,"=",0);
            sprintf(icg[ic_idx++],"%s = u%d\n", (yyvsp[-3].nd_obj).name,(yyvsp[0].nd_obj2).temp_arr_var);
        }
    }
#line 2274 "y.tab.c"
    break;

  case 53: /* $@16: %empty  */
#line 385 "toylangparser.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 2280 "y.tab.c"
    break;

  case 54: /* statement: ID $@16 relop expression  */
#line 385 "toylangparser.y"
                                                      { (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name,0); (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name,0); }
#line 2286 "y.tab.c"
    break;

  case 55: /* statement: array '=' expression  */
#line 386 "toylangparser.y"
                       {
    is_array=0;
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd,(yyvsp[0].nd_obj2).nd,"=",0);
    sprintf(icg[ic_idx++],"u%d = %s\n", (yyvsp[-2].nd_obj2).temp_arr_var, (yyvsp[0].nd_obj2).name);
}
#line 2296 "y.tab.c"
    break;

  case 56: /* statement: array '=' array  */
#line 391 "toylangparser.y"
                  {
    is_array = 0;
    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj2).nd,(yyvsp[0].nd_obj2).nd,"=",0);
    sprintf(icg[ic_idx++],"u%d = u%d\n", (yyvsp[-2].nd_obj2).temp_arr_var,(yyvsp[0].nd_obj2).temp_arr_var);
}
#line 2306 "y.tab.c"
    break;

  case 57: /* assign: expression  */
#line 398 "toylangparser.y"
                   {
    strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type);
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd;
    (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value;
}
#line 2316 "y.tab.c"
    break;

  case 58: /* assign: array  */
#line 403 "toylangparser.y"
        {
    (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd;
    (yyval.nd_obj2).temp_arr_var = (yyvsp[0].nd_obj2).temp_arr_var;
}
#line 2325 "y.tab.c"
    break;

  case 59: /* assign: ID '(' args ')'  */
#line 407 "toylangparser.y"
                  {
    strcpy((yyval.nd_obj2).type,"number");
    (yyval.nd_obj2).nd = mknode((yyvsp[-3].nd_obj).nd,(yyvsp[-1].nd_obj3).nd,"call",0);
    (yyval.nd_obj2).value = 0;
}
#line 2335 "y.tab.c"
    break;

  case 60: /* init: '=' charbool  */
#line 413 "toylangparser.y"
                    { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value; }
#line 2341 "y.tab.c"
    break;

  case 61: /* init: '=' expression  */
#line 414 "toylangparser.y"
                 { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); strcpy((yyval.nd_obj2).name,(yyvsp[0].nd_obj2).name); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value; }
#line 2347 "y.tab.c"
    break;

  case 62: /* init: '[' NUMBER ']'  */
#line 415 "toylangparser.y"
                 { 
    char temp[100] = "";
    char gomma[2];
    char gomma1[2];
    sprintf(gomma,"[");
    sprintf(gomma1,"]");
    strcat(temp,gomma);
    strcat(temp,(yyvsp[-1].nd_obj).name);
    strcat(temp,gomma1);
    strcpy((yyval.nd_obj2).name,temp);
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyval.nd_obj2).name,0);
    sprintf((yyval.nd_obj2).type,"number");
    is_array=1;
}
#line 2366 "y.tab.c"
    break;

  case 63: /* expression: expression addops term  */
#line 432 "toylangparser.y"
                                    {
        if(strcmp((yyvsp[-2].nd_obj2).type,(yyvsp[0].nd_obj2).type)){
            success=0;
            sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
            sem_errors++;
        }
        sprintf((yyval.nd_obj2).name,"t%d",temp_var++);
        strcpy((yyval.nd_obj2).type,(yyvsp[-2].nd_obj2).type);
        (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name,0);
        (yyval.nd_obj2).value = (yyvsp[-2].nd_obj2).value + (yyvsp[0].nd_obj2).value;
        (yyval.nd_obj2).nd->value = (yyval.nd_obj2).value;
        sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    }
#line 2384 "y.tab.c"
    break;

  case 64: /* expression: term  */
#line 445 "toylangparser.y"
       { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value;}
#line 2390 "y.tab.c"
    break;

  case 65: /* term: term mulops factor  */
#line 448 "toylangparser.y"
                          {
    if(strcmp((yyvsp[-2].nd_obj2).type,(yyvsp[0].nd_obj2).type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    } 
    strcpy((yyval.nd_obj2).type,(yyvsp[-2].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name,0); 
    sprintf((yyval.nd_obj2).name,"t%d",temp_var++);
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    (yyval.nd_obj2).value = (yyvsp[-2].nd_obj2).value * (yyvsp[0].nd_obj2).value;
    (yyval.nd_obj2).nd->value = (yyval.nd_obj2).value;
    }
#line 2408 "y.tab.c"
    break;

  case 66: /* term: factor  */
#line 461 "toylangparser.y"
         { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value;}
#line 2414 "y.tab.c"
    break;

  case 67: /* factor: base exponent base  */
#line 464 "toylangparser.y"
                            {
    if(strcmp((yyvsp[-2].nd_obj2).type,(yyvsp[0].nd_obj2).type)){
        success=0;
        sprintf(errors[sem_errors], "Line %d: Conflicting type operations \n", line_no);
        sem_errors++;
    }
    strcpy((yyval.nd_obj2).type,(yyvsp[-2].nd_obj2).type);
    (yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name,0); 
    sprintf((yyval.nd_obj2).name,"t%d",temp_var++);
    sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
    (yyval.nd_obj2).value = pow((yyvsp[-2].nd_obj2).value, (yyvsp[0].nd_obj2).value);
    (yyval.nd_obj2).nd->value = (yyval.nd_obj2).value;
    }
#line 2432 "y.tab.c"
    break;

  case 68: /* factor: LOG '(' value ',' value ')'  */
#line 477 "toylangparser.y"
                              { (yyval.nd_obj2).nd = mknode((yyvsp[-3].nd_obj2).nd, (yyvsp[-1].nd_obj2).nd, (yyvsp[-5].nd_obj).name,0); }
#line 2438 "y.tab.c"
    break;

  case 69: /* factor: base  */
#line 478 "toylangparser.y"
       { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value; }
#line 2444 "y.tab.c"
    break;

  case 70: /* base: value  */
#line 481 "toylangparser.y"
             { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); (yyval.nd_obj2).value = (yyvsp[0].nd_obj2).value; (yyval.nd_obj2).nd->value = (yyvsp[0].nd_obj2).value;}
#line 2450 "y.tab.c"
    break;

  case 71: /* base: '(' expression ')'  */
#line 482 "toylangparser.y"
                     { (yyval.nd_obj2).nd = (yyvsp[-1].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[-1].nd_obj2).type); }
#line 2456 "y.tab.c"
    break;

  case 83: /* value: NUMBER  */
#line 505 "toylangparser.y"
              { 
        strcpy(type, "number");
        add('C'); 
        strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
        strcpy((yyval.nd_obj2).type, "number");
        (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name, atoi((yyvsp[0].nd_obj).name));
        (yyval.nd_obj2).value = atoi((yyvsp[0].nd_obj).name);
    }
#line 2469 "y.tab.c"
    break;

  case 84: /* value: FLOAT_NUM  */
#line 513 "toylangparser.y"
            { 
    strcpy(type, "decimal");
    add('C');
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
    strcpy((yyval.nd_obj2).type, "decimal"); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,atof((yyvsp[0].nd_obj).name)); 
    (yyval.nd_obj2).value = atof((yyvsp[0].nd_obj).name);
    }
#line 2482 "y.tab.c"
    break;

  case 85: /* value: ID  */
#line 521 "toylangparser.y"
     {
    check_declaration((yyvsp[0].nd_obj).name);
    strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name);
    char *id_type = get_type((yyvsp[0].nd_obj).name);
    if(id_type!=NULL) strcpy((yyval.nd_obj2).type,id_type); 
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0); 
    q = search((yyvsp[0].nd_obj).name);
    if(q==-1) {
        (yyval.nd_obj2).value = get_value((yyvsp[0].nd_obj).name);
        (yyval.nd_obj2).nd->value = (yyval.nd_obj2).value;
    }
    }
#line 2499 "y.tab.c"
    break;

  case 86: /* value: array  */
#line 533 "toylangparser.y"
        { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); strcpy((yyval.nd_obj2).name,(yyvsp[0].nd_obj2).name); (yyval.nd_obj2).temp_arr_var = (yyvsp[0].nd_obj2).temp_arr_var; }
#line 2505 "y.tab.c"
    break;

  case 87: /* array: ID '[' expression ']'  */
#line 536 "toylangparser.y"
                             { 
    check_declaration((yyvsp[-3].nd_obj).name);
    char *id_type = get_type((yyvsp[-3].nd_obj).name);
    if(id_type!=NULL) strcpy((yyval.nd_obj2).type,id_type); 
    char temp[100] = "";
    strcat(temp, (yyvsp[-3].nd_obj).name);
    strcat(temp, "[");
    strcat(temp, (yyvsp[-1].nd_obj2).name);
    strcat(temp, "]");
    strcpy((yyval.nd_obj2).name, temp);
    (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyval.nd_obj2).name,0); 
    is_array = 1;
    (yyval.nd_obj2).temp_arr_var = temp_arr_var++;
    sprintf(icg[ic_idx++],"t%d = 4 * %s\n",temp_var++,(yyvsp[-1].nd_obj2).name);
    sprintf(icg[ic_idx++],"u%d = %s[t%d]\n",(yyval.nd_obj2).temp_arr_var,(yyvsp[-3].nd_obj).name,temp_var-1);
}
#line 2526 "y.tab.c"
    break;

  case 88: /* charbool: bools  */
#line 553 "toylangparser.y"
                { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,"boolean");  }
#line 2532 "y.tab.c"
    break;

  case 89: /* charbool: CHARACTER  */
#line 554 "toylangparser.y"
            { add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0); strcpy((yyval.nd_obj2).type,"letter"); }
#line 2538 "y.tab.c"
    break;

  case 90: /* valcharbool: value  */
#line 557 "toylangparser.y"
                   { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); strcpy((yyval.nd_obj2).name,(yyvsp[0].nd_obj2).name); (yyval.nd_obj2).temp_arr_var = (yyvsp[0].nd_obj2).temp_arr_var; }
#line 2544 "y.tab.c"
    break;

  case 91: /* valcharbool: charbool  */
#line 558 "toylangparser.y"
           { (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj2).name,0); strcpy((yyval.nd_obj2).type,(yyvsp[0].nd_obj2).type); }
#line 2550 "y.tab.c"
    break;

  case 92: /* bools: TRUE  */
#line 561 "toylangparser.y"
            { strcpy(type,"boolean"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0); strcpy((yyval.nd_obj2).type,"boolean");}
#line 2556 "y.tab.c"
    break;

  case 93: /* bools: FALSE  */
#line 562 "toylangparser.y"
        { strcpy(type,"boolean"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name,0); strcpy((yyval.nd_obj2).type,"boolean");}
#line 2562 "y.tab.c"
    break;

  case 94: /* $@17: %empty  */
#line 565 "toylangparser.y"
               {add('K');}
#line 2568 "y.tab.c"
    break;

  case 95: /* return: RETURN $@17 valcharbool ';'  */
#line 565 "toylangparser.y"
                                           { check_return_type((yyvsp[-1].nd_obj2).type);  (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj2).nd,NULL,(yyvsp[-3].nd_obj).name,0); }
#line 2574 "y.tab.c"
    break;

  case 96: /* return: %empty  */
#line 566 "toylangparser.y"
  { (yyval.nd_obj).nd = NULL; }
#line 2580 "y.tab.c"
    break;


#line 2584 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 569 "toylangparser.y"


int yyerror(const char *msg)
{
    extern int yylineno;
    printf("Parsing Failed\nLine Number: %d %s\n",yylineno,msg);
    success = 0;
    return 0;
}

int main() {
    extern FILE *yyin, *yyout;
    int p = 0;
    p = yyparse();
    printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else { printf("Parsing Successful\n");
        printf("\n\n");
        printf("PARSE TREE");
        printf("\n\n");
        printBT(head);
        printf("\n\n");
    }

    printf("\n\n");
	printf("INTERMEDIATE CODE GENERATION \n\n");
	for(int i=0; i<ic_idx; i++){
		printf("%s",icg[i]);
	}
	printf("\n\n");


    return p;
}

void check_declaration(char *c) {    
    q = search(c);    
    if(!q || q==-2) {        
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", line_no, c);  
        sem_errors++;    
    }
}

int check_types(char *type1, char *type2){
    if(strcmp(type1,type2)){
        return 1;
    }
    return 0;
}

void check_return_type(char *value) {
	char *main_datatype = get_type(currentFuncName);
	if(strcmp(main_datatype, value)) {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", line_no);
		sem_errors++;
    }
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
    return NULL;
}

float get_value(char *var){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            return symbol_table[i].value;
        }
    }
    return 0;
}

void set_value(char *var, float value){
    for(int i=0; i<count; i++) {
        if(!strcmp(symbol_table[i].id_name, var)) {
            symbol_table[i].value = value;
            return;
        }
    }
}

char *get_ftype(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].type;
		}
	}
}

int search(char *type) { 
    int i; 
    for(i=count-1; i>=0; i--) {
         if(strcmp(symbol_table[i].id_name, type)==0) {

            if(!strcmp(symbol_table[i].type,"Function")){

                return -2;

            }   

            return -1;

            break;  

        }
    } 
    return 0;
}

void insert_type() {
    strcpy(type, yytext);
}

void add(char c) {
  q=search(yytext);
  if(c == 'V' && q) {
    sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", line_no, yytext);  
    sem_errors++;    
  }
  if(c == 'V') {  
        for(int i=0; i<10; i++) {   
            if(!strcmp(reserved[i], strdup(yytext))) {
                sprintf(errors[sem_errors], "Line %d: Variable name  \"%s\" is a reserved keyword!\n", line_no, yytext);
                sem_errors++;    
                return;
            }  
        } 
  }
  if(!q) {
        if(c == 'K') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup("N/A");
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Keyword\t");   
        count++;  
        }  else if(c == 'V') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Variable");   
        count++;  
        }  else if(c == 'C') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Constant");   
        count++;  
        }  else if(c == 'F') {
        symbol_table[count].id_name=strdup(yytext);
        symbol_table[count].data_type=strdup(type);
        symbol_table[count].line_no=line_no;
        symbol_table[count].type=strdup("Function");   
        count++;  
        }
    }
}


void printBTHelper(char* prefix, struct node* ptr, int isLeft) {
    if( ptr != NULL ) {
        printf("%s",prefix);
        if(isLeft) { printf("○→  "); } 
		else { printf("●→  "); }
        printf("%s (%0.1f)",ptr->token,ptr->value);
		printf("\n");
		char* addon = isLeft ? "│   " : "    ";
    	int len2 = strlen(addon);
    	int len1 = strlen(prefix);
    	char* result = (char*)malloc(len1 + len2 + 1);
    	strcpy(result, prefix);
    	strcpy(result + len1, addon);
		printBTHelper(result, ptr->left, 1);
		printBTHelper(result, ptr->right, 0);
    	free(result);
    }
}

void printBT(struct node* ptr) {
	printf("\n");
    printBTHelper("", ptr, 0);
}

struct node* mknode(struct node *left, struct node *right, char *token,float value) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
    newnode->value = value;
	return(newnode);
}
