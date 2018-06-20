/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "rust.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "union.h"
int yylex(void);
void yyerror(const char *s);

FILE *javafile;

struct content{
	char id[256];
	int ival;
	float fval;
	int bval;
	char sval[256];
	char type[256];
	char bigtype[256];
	int isGlobal;	// 0 = Global; 1 = Local;
	int storeVal;
};

struct content symbolTable[256][256];
int id_total=0;
int scope = 0;
bool isAdd = false;
int count = 0;
int storeNum = 0;
char typekeeper[256][256];
bool shouldGet = false;
char tempId[256];
char tempFuncId[256];
int tempNum = 0;
bool isInvoke = false;
int orderCount = 0;
char orderToFile[256][256];
int label = 0;
int iflabel1=0;
int iflabel2=0;
int whilelabel=0;

int insert(struct content a){
	bool inSymbolTable = false ;
	for(int i = 0 ; i < id_total; i++)
	{
		if(strcmp(a.id, symbolTable[scope][i].id)==0)
		{
			inSymbolTable = true ;
		}
	}
	if (!inSymbolTable)
	{
		if(strcmp("int",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			symbolTable[scope][id_total].ival = a.ival;
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else if(strcmp("float",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			symbolTable[scope][id_total].fval = a.fval;
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}
			id_total++;
			}
		}else if(strcmp("str",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].sval,a.sval);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else if(strcmp("bool",a.type)==0){
			if(strcmp("arrays",a.bigtype)==0){
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			id_total++;
			}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			symbolTable[scope][id_total].bval = a.bval;
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);
			
			if(scope == 0){
			symbolTable[scope][id_total].isGlobal = 0;
			}else{
			symbolTable[scope][id_total].isGlobal = 1;
			}

			id_total++;
			}
		}else{
			strcpy(symbolTable[scope][id_total].id,a.id);
			strcpy(symbolTable[scope][id_total].type,a.type);
			symbolTable[scope][id_total].ival = a.ival;
			strcpy(symbolTable[scope][id_total].bigtype,a.bigtype);

		}
	}
} 

int update(struct content a){
	for(int i = 0 ; i <= scope; i++)
	{
		for(int j = 0; j <=id_total;j++){
			if(strcmp(a.id, symbolTable[i][j].id)==0)
			{
	if(strcmp("const",symbolTable[i][j].bigtype)){
		printf("~~%s~not const~~~~~~~~~~~\n",symbolTable[i][j].id);
		if(strcmp("int",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].ival = a.ival;
			symbolTable[i][j].storeVal = a.storeVal;
			printf("~update~~~value:%d~~~istore~%d~~~~~~\n",symbolTable[i][j].ival,symbolTable[i][j].storeVal);
			}else{
			}
		}else if(strcmp("float",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].fval = a.fval;
			symbolTable[i][j].storeVal = a.storeVal;
			}else{
			}
		}else if(strcmp("str",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			strcpy(symbolTable[i][j].sval,a.sval);
			symbolTable[i][j].storeVal = a.storeVal;
			}else{
			
			}
		}else if(strcmp("bool",symbolTable[i][j].type)==0){
			if(strcmp("var",symbolTable[i][j].bigtype)==0){
			symbolTable[i][j].bval = a.bval;
			symbolTable[i][j].storeVal = a.storeVal;
			}else{		
			}
		}else{
		}
	}else{
		printf("----------%s----------\n","const can not change value!");
	}
			}
		}
	}
} 

int checkScope(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].isGlobal;
			}
		}
	}
}

int getStoreVal(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				printf("\t\tid:%s\n\t\tistore:%d\n",symbolTable[i][j].id,symbolTable[i][j].storeVal);
				return symbolTable[i][j].storeVal;
			}
		}
	}
}

int getInitScope(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return i;
			}
		}
	}
}

int getNowScope(char *c){
		for(int j=0;j<=id_total;j++)
		{
			if(strcmp(c,symbolTable[scope][j].id)==0){
			return scope; //true
			}
		}
}

char* getType(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j = 0 ; j<=id_total; j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].type;
			}
		}
	}
}

char* getBigType(char *c){
	for(int i = 0; i<= scope; i++)
	{
		for(int j = 0 ; j<=id_total; j++)
		{
			if(strcmp(c,symbolTable[i][j].id)==0)
			{
				return symbolTable[i][j].bigtype;
			}
		}
	}
}

int getValue(char *c){
	for (int i = 0; i <= scope; i++)
	{
		for(int j=0;j<=id_total;j++){
		if (strcmp(c , symbolTable[i][j].id)==0)
		{			
			if(strcmp(symbolTable[i][j].type,"int")==0){
				return symbolTable[i][j].ival;
			}else{
				
			}
		}else{
		}
		}
	}
}

int dump(){
	for (int i = 0; i <= scope; i++)
	{
		for (int j=0; j <= id_total ;j++)
		{
			if(strcmp("int",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*d\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].ival,10,i);
				}
			}else if(strcmp("float",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*f\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].fval,10,i);
				}
			}else if(strcmp("str",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);
				}else{
					printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,symbolTable[i][j].sval,10,i);
				}
			}else if(strcmp("bool",symbolTable[i][j].type)==0)
			{
				if(strcmp("arrays",symbolTable[i][j].bigtype)==0){
			printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10," ",10,i);

				}else{
				if(symbolTable[i][j].bval==0)
				{
				printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,"False",10,i);
				}else if(symbolTable[i][j].bval==1)
				{
				printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10,symbolTable[i][j].type,10,symbolTable[i][j].bigtype,10,"True",10,i);
				}
				}
			}else if(strcmp("null",symbolTable[i][j].type)==0)			{
			printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*d\n",10,symbolTable[i][j].id,10," ",10,symbolTable[i][j].bigtype,10," ",10,i);
			}else{

			}
		}
	}
}



#line 395 "rust.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "rust.tab.h".  */
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
#line 329 "rust.y" /* yacc.c:355  */

  char m_sId[256];
  int m_nInt;
  float m_float;
  char m_str[256];
  char type[256];
  struct s sdec;

#line 515 "rust.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_RUST_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 532 "rust.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   369,   369,   371,   376,   379,   381,   385,   399,   398,
     421,   420,   451,   467,   475,   477,   479,   481,   486,   488,
     493,   520,   546,   606,   654,   711,   729,   749,   750,   766,
     773,   779,   785,   791,   801,   807,   813,   820,   827,   833,
     839,   855,   879,   897,   914,   930,   946,   963,   979,   988,
     992,   996,  1003,  1008,  1013,  1018,  1023,  1028,  1033,  1041,
    1045,  1052,  1068,  1085,  1084,  1091,  1090,  1097,  1101,  1110,
    1114,  1109,  1121,  1129,  1134,  1128,  1147,  1149,  1154,  1156,
    1158,  1160,  1162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "SEMICOLON", "LP",
  "RP", "LSB", "RSB", "LCB", "RCB", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "INCREMENT", "DECREMENT", "MODULUS", "LT", "LE", "GE", "GT", "EQ", "NE",
  "AND", "OR", "NOR", "EQUALS", "PLUSEQUALS", "MINUSEQUALS",
  "MULTIPLYEQUALS", "DIVIDEEQUALS", "BREAK", "CHAR", "CONTINUE", "DO",
  "ELSE", "ENUM", "EXTERN", "FOR", "FN", "IF", "IN", "LET", "LOOP",
  "MATCH", "MUT", "PRINT", "PRINTLN", "PUB", "RETURN", "SELF", "STATIC",
  "STRUCT", "USE", "WHERE", "WHILE", "FALSE", "TRUE", "BOOL", "INT",
  "FLOAT", "STR", "IDENTIFIER", "INTEGERVAL", "STRINGVAL", "FLOATVAL",
  "TRUEVAL", "FALSEVAL", "UMINUS", "$accept", "program",
  "external_declaration", "func_expression", "function_definition", "$@1",
  "$@2", "block_start", "block_end", "block_statement", "declaration_list",
  "declaration", "func_inv_list", "value_declaration", "operation_exp",
  "relational_exp", "expression", "type_specifier", "parameter_list",
  "parameter_declaration", "simple_statment", "$@3", "$@4",
  "selection_statement", "$@5", "$@6", "else_statement",
  "iteration_statement", "$@7", "$@8", "statement_list", "statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,  -117,   -38,  -117,  -117,    -1,     6,    11,  -117,   -28,
    -117,     1,  -117,  -117,   -17,     4,    20,    20,  -117,    26,
    -117,  -117,    55,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
     157,  -117,    65,    20,  -117,  -117,    70,  -117,    14,   129,
     119,    75,    76,  -117,    80,    20,    26,    26,    26,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,  -117,
      78,     7,   129,  -117,   129,   119,  -117,  -117,  -117,  -117,
      79,    98,  -117,  -117,   105,    87,    87,    80,    80,    36,
      36,    36,    36,    36,    36,    36,    36,    36,  -117,  -117,
     108,    28,  -117,    16,   106,   109,   119,  -117,    20,   112,
     129,    51,   103,  -117,   119,    53,  -117,   115,   117,  -117,
    -117,    62,  -117,  -117,  -117,   111,   120,   122,  -117,  -117,
    -117,    90,   130,  -117,  -117,  -117,    62,  -117,  -117,  -117,
    -117,    86,  -117,   129,  -117,   135,  -117,    20,   136,  -117,
      86,  -117,  -117,  -117,  -117,   137,    20,  -117,   112,  -117,
     138,  -117,    90,  -117,  -117,    90,   114,  -117,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,    63,    65,     0,     0,     0,     2,     0,
       4,     5,    18,     6,     0,     0,     0,     0,    67,     0,
      51,    50,    41,    32,    29,    33,    30,    31,    54,    40,
      52,    53,     0,     0,     1,     3,     0,    19,     0,     0,
       0,     0,     0,    41,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,    25,     0,     0,    55,    58,    57,    56,
       0,     0,    64,    66,     0,    38,    39,    35,    36,    37,
      42,    44,    45,    43,    46,    47,    48,    49,    62,     8,
       0,     0,    59,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,    23,     0,     0,    24,     0,     0,    27,
      12,     0,     9,    61,    60,     0,     0,     0,    21,    28,
      13,     0,     0,    73,    17,    79,     0,    78,    80,    81,
      82,     0,    76,     0,    22,     0,    72,     0,     0,    15,
       0,    14,    77,    10,    26,     0,     0,    16,     0,    69,
       0,    11,     0,    74,    70,     0,     0,    75,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   139,  -117,  -117,  -117,  -117,  -117,  -116,   -92,
      37,    -9,    54,   -27,   110,  -117,   -16,   -59,  -117,    48,
      46,  -117,  -117,  -117,  -117,  -117,    -3,  -117,  -117,  -117,
      29,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    99,   148,   111,   124,   125,
      11,    12,    28,    29,    30,    31,    32,    70,    91,    92,
     127,    16,    17,   128,   152,   156,   129,   130,   138,   155,
     131,   132
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    42,    37,    93,    18,    94,   136,   112,    39,    14,
     139,    34,    19,    71,    89,   141,   142,    60,    62,    63,
       1,   103,    64,     2,   147,   142,    15,     3,     4,    74,
       5,   101,    40,    19,    33,   102,    36,   154,    95,    19,
     157,   113,    65,     6,   104,     2,    13,    38,    46,    47,
      48,    49,     1,    13,    50,     2,   151,    20,    21,     3,
       4,    45,     5,    22,    23,    24,    25,    26,    27,   107,
      59,    90,   110,   120,   143,     6,    61,   116,    20,    21,
      72,    73,   109,    88,    22,    23,    24,    25,    26,    27,
      43,    23,    24,    25,    26,    27,   110,   120,    50,   121,
     110,    48,    49,    97,   122,    50,     2,    96,    98,   105,
       3,     4,   100,     5,   106,    90,   115,    37,   117,   123,
     118,   145,   110,   121,   119,   134,     6,   121,   122,    44,
     150,   135,   122,   133,     3,     4,   137,     5,     3,     4,
     144,     5,   146,   123,   149,   153,    35,   123,   126,   114,
       6,   121,   108,   158,     6,   140,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    46,
      47,    48,    49,     0,     0,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    23,    24,    25,    26,    27,    66,
      67,    68,    69
};

static const yytype_int16 yycheck[] =
{
      16,    17,    11,    62,     5,    64,   121,    99,     4,    47,
     126,     0,    13,    40,     7,   131,   131,    33,     4,     5,
      41,     5,     8,    44,   140,   140,    64,    48,    49,    45,
      51,     3,    28,    13,    28,     7,    64,   152,    65,    13,
     155,   100,    28,    64,    28,    44,     0,    64,    12,    13,
      14,    15,    41,     7,    18,    44,   148,    58,    59,    48,
      49,     6,    51,    64,    65,    66,    67,    68,    69,    96,
       5,    64,    10,    11,   133,    64,     6,   104,    58,    59,
       5,     5,    98,     5,    64,    65,    66,    67,    68,    69,
      64,    65,    66,    67,    68,    69,    10,    11,    18,    37,
      10,    14,    15,     5,    42,    18,    44,    28,     3,     3,
      48,    49,     4,    51,     5,    64,    13,   126,    65,    57,
       5,   137,    10,    37,     7,     5,    64,    37,    42,    19,
     146,     9,    42,    22,    48,    49,     6,    51,    48,    49,
       5,    51,     6,    57,     7,     7,     7,    57,   111,   101,
      64,    37,    98,   156,    64,   126,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    65,    66,    67,    68,    69,    60,
      61,    62,    63
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    44,    48,    49,    51,    64,    72,    73,    74,
      75,    81,    82,    91,    47,    64,    92,    93,     5,    13,
      58,    59,    64,    65,    66,    67,    68,    69,    83,    84,
      85,    86,    87,    28,     0,    73,    64,    82,    64,     4,
      28,    87,    87,    64,    85,     6,    12,    13,    14,    15,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     5,
      87,     6,     4,     5,     8,    28,    60,    61,    62,    63,
      88,    84,     5,     5,    87,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,     5,     7,
      64,    89,    90,    88,    88,    84,    28,     5,     3,    76,
       4,     3,     7,     5,    28,     3,     5,    84,    83,    87,
      10,    78,    80,    88,    90,    13,    84,    65,     5,     7,
      11,    37,    42,    57,    79,    80,    81,    91,    94,    97,
      98,   101,   102,    22,     5,     9,   102,     6,    99,    79,
     101,    79,   102,    88,     5,    87,     6,    79,    77,     7,
      87,    80,    95,     7,   102,   100,    96,   102,    97
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    72,    73,    73,    73,    74,    76,    75,
      77,    75,    78,    79,    80,    80,    80,    80,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    89,
      89,    90,    91,    92,    91,    93,    91,    91,    91,    95,
      96,    94,    97,    99,   100,    98,   101,   101,   102,   102,
     102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     0,     6,
       0,    10,     1,     1,     3,     3,     4,     2,     1,     2,
       5,     7,     8,     6,     6,     4,     9,     1,     6,     1,
       1,     1,     1,     1,     2,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     0,     4,     0,     4,     2,     3,     0,
       0,     8,     2,     0,     0,     7,     1,     2,     1,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 370 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [program]");}
#line 1739 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 372 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [program]");}
#line 1745 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 377 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [external_declaration]");}
#line 1751 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 380 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [external_declaration]");}
#line 1757 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 382 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [external_declaration]");}
#line 1763 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 386 "rust.y" /* yacc.c:1646  */
    {
				isAdd = false;
				scope++;
				printf("~~~~~~~~~~scope++ %d times~~~~~~~~~~\n",scope);
				printf("~~~~~FN~~~~~isAdd %d false~~~~~~~~~~\n",isAdd);
				//strcpy(orderToFile[0],"\tmethod public static ");
				fprintf(javafile,"\tmethod public static ");
				printf("%s\n","Reducing to [func_expression]");
			}
#line 1777 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 399 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-2].m_sId));
			strcpy(a.bigtype,"func");
			strcpy(a.type,"null");
			strcpy(a.sval,"null");
			insert(a);
			//sprintf(orderToFile[1],"void %s(java.lang.String[])\n",$2);
			fprintf(javafile,"void %s(java.lang.String[])\n",(yyvsp[-2].m_sId));
			//sprintf(orderToFile[2],"\tmax_stack 15\n\tmax_locals 15\n");
			//sprintf(orderToFile[3],"\t{\n");
			fprintf(javafile,"\tmax_stack 15\n");
			fprintf(javafile,"\tmax_locals 15\n");
			fprintf(javafile,"\t{\n");
			
			
			printf("%s\n","Reducing to [function_definition]");
		}
#line 1800 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 416 "rust.y" /* yacc.c:1646  */
    {
			fprintf(javafile,"\t\treturn\n\t}\n");
		}
#line 1808 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 421 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-6].m_sId));
			strcpy(a.bigtype,"func");
			strcpy(a.type,(yyvsp[0].type));
			a.ival = 0;
			insert(a);
			strcpy(tempFuncId,(yyvsp[-6].m_sId));
			fprintf(javafile,"%s %s(",(yyvsp[0].type),(yyvsp[-6].m_sId));
			for(int i = 0; i < count; i++) {
				if(i != count-1)
					fprintf(javafile,"%s,",typekeeper[i]);
				else
					fprintf(javafile,"%s)\n",typekeeper[i]);
			}
			
			fprintf(javafile,"\tmax_stack 15\n");
			fprintf(javafile,"\tmax_locals 15\n");
			fprintf(javafile,"\t{\n");
			for(int i =0 ;i<count ; i++){
			fprintf(javafile,"\t\tiload %d\n",i);
			}
			printf("%s\n","Reducing to [function_definition]");
		}
#line 1837 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 446 "rust.y" /* yacc.c:1646  */
    {
			fprintf(javafile,"\t\tireturn\n\t}\n");
		}
#line 1845 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 452 "rust.y" /* yacc.c:1646  */
    {
			printf("*!!**********isAdd:::%d\n",isAdd);
			if (isAdd == 1)
			{		
				scope++;
				printf("~~~~~~~~~~scope touched %d ~~~~~~~~~\n",scope);
			}else{
				isAdd = true;
printf("~~~~~~~~~~isAdd %d touched~~~~~~~~~~\n",isAdd);
			}
			printf("***********scope:::%d\n",scope);
			printf("%s\n","Reducing to [block_start]");
		}
#line 1863 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 468 "rust.y" /* yacc.c:1646  */
    {
			printf("***********when } come out:::%d\n",scope);
			printf("%s\n","Reducing to [block_end]");
		}
#line 1872 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 476 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [block_statement]");}
#line 1878 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 478 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [block_statement]");}
#line 1884 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 480 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [block_statement]");}
#line 1890 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 482 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [block_statement]");}
#line 1896 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 487 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [declaration_list]");}
#line 1902 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 489 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [declaration_list]");}
#line 1908 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 494 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-3].m_sId));
			strcpy(a.bigtype,"const");
			if((yyvsp[-1].sdec).type == 0){
			strcpy(a.type,"int");
			a.ival = (yyvsp[-1].sdec).uval.ival;
			}else if((yyvsp[-1].sdec).type == 1){
			strcpy(a.type,"float");
			a.fval = (yyvsp[-1].sdec).uval.fval;
			}else if((yyvsp[-1].sdec).type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,(yyvsp[-1].sdec).uval.sval);
			}else if((yyvsp[-1].sdec).type == 3){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;
			}else if((yyvsp[-1].sdec).type == 4){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;	
			}
			insert(a);
		
			fprintf(javafile,"\t\tsipush %d\n",(yyvsp[-1].sdec).uval.ival);			

			printf("%s\n","Reducing to [declaration]");
		}
#line 1939 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 521 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-5].m_sId));
			strcpy(a.bigtype,"const");
			if((yyvsp[-1].sdec).type == 0){
			strcpy(a.type,"int");
			a.ival = (yyvsp[-1].sdec).uval.ival;
			}else if((yyvsp[-1].sdec).type == 1){
			strcpy(a.type,"float");
			a.fval = (yyvsp[-1].sdec).uval.fval;
			}else if((yyvsp[-1].sdec).type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,(yyvsp[-1].sdec).uval.sval);
			}else if((yyvsp[-1].sdec).type == 3){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;
			}else if((yyvsp[-1].sdec).type == 4){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;	
			}
			insert(a);
			fprintf(javafile,"\t\tsipush %d\n",(yyvsp[-1].sdec).uval.ival);
			printf("%s\n","Reducing to [declaration]");

		}
#line 1969 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 547 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-5].m_sId));
			strcpy(a.bigtype,"var");
			if(strcmp("int",(yyvsp[-3].type))==0)
			{
			strcpy(a.type,"int");
			a.ival = (yyvsp[-1].sdec).uval.ival;
			}else if(strcmp("float",(yyvsp[-3].type))==0)
			{
			strcpy(a.type,"float");
			a.fval = (yyvsp[-1].sdec).uval.fval;
			}else if(strcmp("str",(yyvsp[-3].type))==0)
			{
			strcpy(a.type,"str");
			strcpy(a.sval,(yyvsp[-1].sdec).uval.sval);
			}else if(strcmp("bool",(yyvsp[-3].type))==0)
			{
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;
			}else{
			printf("%s","ERROR!!!");
			}
			insert(a);
			if(checkScope((yyvsp[-5].m_sId))==0)
			{
				if(strcmp("int",(yyvsp[-3].type))==0)
				{
				fprintf(javafile,"\tfield static int %s = %d ", (yyvsp[-5].m_sId),(yyvsp[-1].sdec).uval.ival );
				}else if(strcmp("float",(yyvsp[-3].type))==0)
				{
				fprintf(javafile,"\tfield static float %s = %f ", (yyvsp[-5].m_sId),(yyvsp[-1].sdec).uval.fval );
				}else if(strcmp("str",(yyvsp[-3].type))==0)
				{
				fprintf(javafile,"\tfield static string %s = %s ", (yyvsp[-5].m_sId),(yyvsp[-1].sdec).uval.sval );
				}else if(strcmp("bool",(yyvsp[-3].type))==0)
				{
					if((yyvsp[-1].sdec).uval.bval == 0)
					{
					fprintf(javafile,"\tfield static bool %s = true ", (yyvsp[-5].m_sId) );		
					}else{
					fprintf(javafile,"\tfield static bool %s = false ", (yyvsp[-5].m_sId));

					}	
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				fprintf(javafile,"\t\tsipush %d\n",(yyvsp[-1].sdec).uval.ival);
				fprintf(javafile,"\t\tistore %d\n",storeNum);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal((yyvsp[-5].m_sId)));
				storeNum++;
			}

			printf("%s\n","Reducing to [declaration]");

		}
#line 2033 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 607 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-3].m_sId));
			strcpy(a.bigtype,"var");
			if(strcmp("int",(yyvsp[-1].type))==0){
				strcpy(a.type,"int");
				a.ival = 0 ;
			}else if(strcmp("float",(yyvsp[-1].type))==0){
				strcpy(a.type,"float");
				a.fval = 0 ;
			}else if(strcmp("str",(yyvsp[-1].type))==0){
				strcpy(a.type,"string");
				strcpy(a.sval ,"NULL") ;
			}else if(strcmp("bool",(yyvsp[-1].type))==0){
				strcpy(a.type,"bool");
				a.bval = 0 ;
			}
			insert(a);

			if(checkScope((yyvsp[-3].m_sId))==0)
			{
				if(strcmp("int",(yyvsp[-1].type))==0)
				{
				fprintf(javafile,"\tfield static integer %s ", (yyvsp[-3].m_sId));
				}else if(strcmp("float",(yyvsp[-1].type))==0)
				{
				fprintf(javafile,"\tfield static float %s ", (yyvsp[-3].m_sId));
				}else if(strcmp("str",(yyvsp[-1].type))==0)
				{
				fprintf(javafile,"\tfield static string %s ", (yyvsp[-3].m_sId));
				}else if(strcmp("bool",(yyvsp[-1].type))==0)
				{
				fprintf(javafile,"\tfield static bool %s ", (yyvsp[-3].m_sId) );			
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				fprintf(javafile,"\t\tsipush 0\n");
				fprintf(javafile,"\t\tistore %d\n",storeNum);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal((yyvsp[-3].m_sId)));
				storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");

		}
#line 2085 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 655 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-3].m_sId));
			strcpy(a.bigtype,"var");
			if((yyvsp[-1].sdec).type == 0){
			strcpy(a.type,"int");
			a.ival = (yyvsp[-1].sdec).uval.ival;
			}else if((yyvsp[-1].sdec).type == 1){
			strcpy(a.type,"float");
			a.fval = (yyvsp[-1].sdec).uval.fval;
			}else if((yyvsp[-1].sdec).type == 2){
			strcpy(a.type,"str");
			strcpy(a.sval,(yyvsp[-1].sdec).uval.sval);
			}else if((yyvsp[-1].sdec).type == 3){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;
			}else if((yyvsp[-1].sdec).type == 4){
			strcpy(a.type,"bool");
			a.bval = (yyvsp[-1].sdec).uval.bval;	
			}
			insert(a);

			if(checkScope((yyvsp[-3].m_sId))==0)
			{
				if((yyvsp[-1].sdec).type==0)
				{
				fprintf(javafile,"\tfield static int %s = %d \n", (yyvsp[-3].m_sId),(yyvsp[-1].sdec).uval.ival );
				}else if((yyvsp[-1].sdec).type==1)
				{
				fprintf(javafile,"\tfield static float %s = %f \n", (yyvsp[-3].m_sId),(yyvsp[-1].sdec).uval.fval );
				}else if((yyvsp[-1].sdec).type==2)
				{
				fprintf(javafile,"\tfield static string %s = %s \n", (yyvsp[-3].m_sId),(yyvsp[-1].sdec).uval.sval );
				}else if((yyvsp[-1].sdec).type==3)
				{
					if((yyvsp[-1].sdec).uval.bval == 0)
					{
					fprintf(javafile,"\tfield static bool %s = true \n", (yyvsp[-3].m_sId) );		
					}else{
					fprintf(javafile,"\tfield static bool %s = false \n", (yyvsp[-3].m_sId));

					}	
				}else{
				printf("%s","ERROR!!!");
				}
			}else{
				a.storeVal = storeNum;
				update(a);
				fprintf(javafile,"\t\tsipush %d\n",(yyvsp[-1].sdec).uval.ival);
				fprintf(javafile,"\t\tistore %d\n",storeNum);
				printf("\t\t\t'getStoreVal''%d\n",getStoreVal((yyvsp[-3].m_sId)));
				storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");

		}
#line 2146 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 712 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-1].m_sId));
			strcpy(a.type,"int");
			strcpy(a.bigtype,"var");
			a.ival = 0 ;
			insert(a);
			if(checkScope((yyvsp[-1].m_sId))==0)
			{
			fprintf(javafile,"\tfield static int %s \n", (yyvsp[-1].m_sId));
			}else{
			a.storeVal = storeNum;
			update(a);
			storeNum++;
			}
			printf("%s\n","Reducing to [declaration]");
		}
#line 2168 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 730 "rust.y" /* yacc.c:1646  */
    {
			struct content a;
			strcpy(a.id,(yyvsp[-6].m_sId));
			strcpy(a.bigtype,"arrays");
			if(strcmp("int",(yyvsp[-4].type))==0){
				strcpy(a.type,"int");
			}else if(strcmp("float",(yyvsp[-4].type))==0){
				strcpy(a.type,"float");
			}else if(strcmp("str",(yyvsp[-4].type))==0){
				strcpy(a.type,"str");
			}else if(strcmp("bool",(yyvsp[-4].type))==0){
				strcpy(a.type,"bool");
			}
			insert(a);
			printf("%s\n","Reducing to [declaration]");
		}
#line 2189 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 751 "rust.y" /* yacc.c:1646  */
    {
			(yyvsp[-3].m_nInt),(yyvsp[-1].m_nInt);
			fprintf(javafile,"\t\tinvokestatic %s test.%s(",getType((yyvsp[-5].m_sId)),(yyvsp[-5].m_sId));
				for(int i = 0; i<count ; i++){
				if(i != count -1){
					fprintf(javafile,"%s,",typekeeper[i]);
				}else{
					fprintf(javafile,"%s)\n",typekeeper[i]);
					}
				}
			printf("%s\n","Reducing to [func_inv_list]");
		}
#line 2206 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 767 "rust.y" /* yacc.c:1646  */
    {
  			(yyval.sdec).type = 2;
			strcpy((yyval.sdec).uval.sval,(yyvsp[0].m_str));
			printf("%s\n","Reducing to [value_declaration]");

		}
#line 2217 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 774 "rust.y" /* yacc.c:1646  */
    {
			(yyval.sdec).type = 3;
			(yyval.sdec).uval.bval = 1;
			printf("%s\n","Reducing to [value_declaration]");
		}
#line 2227 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 780 "rust.y" /* yacc.c:1646  */
    {
			(yyval.sdec).type = 4;
			(yyval.sdec).uval.bval = 0;
			printf("%s\n","Reducing to [value_declaration]");
		}
#line 2237 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 786 "rust.y" /* yacc.c:1646  */
    {
			(yyval.sdec).type = 0;
			(yyval.sdec).uval.ival = (yyvsp[0].m_nInt);
			printf("%s\n","Reducing to [value_declaration]");
		}
#line 2247 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 792 "rust.y" /* yacc.c:1646  */
    {	
			(yyval.sdec).type = 1;
			(yyval.sdec).uval.fval = (yyvsp[0].m_float);
			printf("%s\n","Reducing to [value_declaration]");
		}
#line 2257 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 802 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = -(yyvsp[0].m_nInt);
			fprintf(javafile,"\t\tineg\n");
		printf("%s\n","Reducing to [unary_expression]");
		}
#line 2267 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 808 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = (yyvsp[-2].m_nInt) * (yyvsp[0].m_nInt) ;
			fprintf(javafile,"\t\timul\n");
		printf("%s\n","Reducing to [multiplicative_expression]");
		}
#line 2277 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 814 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = (yyvsp[-2].m_nInt) / (yyvsp[0].m_nInt) ;
			fprintf(javafile,"\t\tidiv\n");
			printf("%s\n","Reducing to [multiplicative_expression]");

		}
#line 2288 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 821 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = (yyvsp[-2].m_nInt) % (yyvsp[0].m_nInt);
			fprintf(javafile,"\t\tirem\n");
			printf("%s\n","Reducing to [multiplicative_expression]");

		}
#line 2299 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 828 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = (yyvsp[-2].m_nInt) + (yyvsp[0].m_nInt) ;
			fprintf(javafile,"\t\tiadd\n");
			printf("%s\n","Reducing to [additive_expression]");
		}
#line 2309 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 834 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = (yyvsp[-2].m_nInt) - (yyvsp[0].m_nInt);
			fprintf(javafile,"\t\tisub\n");
			printf("%s\n","Reducing to [additive_expression]");
		}
#line 2319 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 840 "rust.y" /* yacc.c:1646  */
    {
			if((yyvsp[0].sdec).type == 0){
				(yyval.m_nInt) = (yyvsp[0].sdec).uval.ival;
				tempNum = (yyval.m_nInt);
				fprintf(javafile,"\t\tsipush %d\n",(yyval.m_nInt));
				printf("!!!!!Number %d : sipush!!!!!\n",orderCount);
				//sprintf(orderToFile[orderCount],"\t\tsipush %d\n",$$);
				//orderCount++;
			}else if((yyvsp[0].sdec).type == 1){
				(yyval.m_nInt) = (yyvsp[0].sdec).uval.fval;
			}else{

			}
			printf("%s\n","Reducing to [func_inv]");
		}
#line 2339 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 856 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt)=getValue((yyvsp[0].m_sId));
			printf("Id : %s\nNow Scope : %d\nwhatScopeWeCreate: %d\ninNowscope: %d\nvalue:%d\nstoreVal:%d\n",(yyvsp[0].m_sId),scope,getInitScope((yyvsp[0].m_sId)),getNowScope((yyvsp[0].m_sId)),(yyval.m_nInt),getStoreVal((yyvsp[0].m_sId)));
			if(getInitScope((yyvsp[0].m_sId))!=scope){
				if(checkScope((yyvsp[0].m_sId))==0){								fprintf(javafile,"\t\tgetstatic %s test.%s\n",getType((yyvsp[0].m_sId)),(yyvsp[0].m_sId));	
				}else{
				printf("????????%s and istore:%d\n",(yyvsp[0].m_sId),getStoreVal((yyvsp[0].m_sId)));
				fprintf(javafile,"\t\tiload %d\n",getStoreVal((yyvsp[0].m_sId)));
				}
			}else{
				if(checkScope((yyvsp[0].m_sId))==1 && strcmp("var",getBigType((yyvsp[0].m_sId)))==0){
				printf("~~~!!!!%s\n~~~!!!!%d\n",(yyvsp[0].m_sId),getStoreVal((yyvsp[0].m_sId)));
				fprintf(javafile,"\t\tiload %d\n",getStoreVal((yyvsp[0].m_sId)));
				}else if(checkScope((yyvsp[0].m_sId))==1 && strcmp("const",getBigType((yyvsp[0].m_sId)))==0){
				fprintf(javafile,"\t\tsipush %d\n",getValue((yyvsp[0].m_sId)));
			}
			printf("%s\n","Reducing to [operation_exp]");
		}
	}
#line 2363 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 880 "rust.y" /* yacc.c:1646  */
    {
		//<
		if((yyvsp[-2].m_nInt) < (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1 ;
		}else{	
			(yyval.m_nInt) = 0 ;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tiflt L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
#line 2385 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 898 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt)>(yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1 ;
		}else{
			(yyval.m_nInt) = 0 ;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifgt L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);	
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
#line 2406 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 915 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt) <= (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1;
		}else{
			(yyval.m_nInt) = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifle L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
#line 2426 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 931 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt) >= (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1;
		}else{
			(yyval.m_nInt) = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifge L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
#line 2446 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 947 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt) == (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1;
		}else{
			(yyval.m_nInt) = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifeq L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");
		}
#line 2467 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 964 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt) != (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1;
		}else{
			(yyval.m_nInt) = 0;
		}
		fprintf(javafile,"\t\tisub\n");
		fprintf(javafile,"\t\tifne L%d\n",label);
		fprintf(javafile,"\t\ticonst_0\n");
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		fprintf(javafile,"\tL%d:\n",label);
		fprintf(javafile,"\t\ticonst_1\n");
		fprintf(javafile,"\tL%d:\n",label+1);
		label+=2;
		printf("%s\n","Reducing to [relational_expression]");}
#line 2487 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 980 "rust.y" /* yacc.c:1646  */
    {
		if((yyvsp[-2].m_nInt) && (yyvsp[0].m_nInt)){
			(yyval.m_nInt) = 1;
		}else{
			(yyval.m_nInt) = 0;
		}
		fprintf(javafile,"\t\tiand\n");
		}
#line 2500 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 989 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tior\n");
		printf("%s\n","Reducing to [relational_expression]");}
#line 2508 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 993 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = 1 ;//true
		}
#line 2516 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 997 "rust.y" /* yacc.c:1646  */
    {
			(yyval.m_nInt) = 0; //false
		}
#line 2524 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1004 "rust.y" /* yacc.c:1646  */
    {
		(yyval.m_nInt)=(yyvsp[0].m_nInt);
		printf("%s\n","Reducing to [expression]");
		}
#line 2533 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1009 "rust.y" /* yacc.c:1646  */
    {
		(yyval.m_nInt)=(yyvsp[0].m_nInt);
		printf("%s\n","Reducing to [expression]");
		}
#line 2542 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 1019 "rust.y" /* yacc.c:1646  */
    {
			strcpy((yyval.type),"bool");
			printf("%s\n","Reducing to [type_specifier]");
		}
#line 2551 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1024 "rust.y" /* yacc.c:1646  */
    {
			strcpy((yyval.type),"str");
			printf("%s\n","Reducing to [type_specifier]");
		}
#line 2560 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1029 "rust.y" /* yacc.c:1646  */
    {
			strcpy((yyval.type),"float");
			printf("%s\n","Reducing to [type_specifier]");
		}
#line 2569 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1034 "rust.y" /* yacc.c:1646  */
    {
			strcpy((yyval.type),"int");
			printf("%s\n","Reducing to [type_specifier]");
		}
#line 2578 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1042 "rust.y" /* yacc.c:1646  */
    {
		printf("%s\n","Reducing to [parameter_list]");
		}
#line 2586 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1046 "rust.y" /* yacc.c:1646  */
    {
		printf("%s\n","Reducing to [parameter_list]");
		}
#line 2594 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1053 "rust.y" /* yacc.c:1646  */
    {
			struct content a;	
			strcpy(a.id,(yyvsp[-2].m_sId));
			strcpy(a.type,(yyvsp[0].type));
			strcpy(a.bigtype,"func_parameter");
			a.ival = 0;
			insert(a);
			//fprintf(javafile,"\t\t%s\n",$3);
			strcpy(typekeeper[count],(yyvsp[0].type));
			count++;
			printf("%s\n","Reducing to [parameter_declaration]");
		}
#line 2611 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1069 "rust.y" /* yacc.c:1646  */
    {
		struct content a;	
		strcpy(a.id,(yyvsp[-3].m_sId));
		a.ival = (yyvsp[-1].m_nInt);
		printf("..id---(%s)...value(%d)...storeVal(%d)\n",(yyvsp[-3].m_sId),getValue((yyvsp[-3].m_sId)),getStoreVal((yyvsp[-3].m_sId)));
		a.storeVal = getStoreVal((yyvsp[-3].m_sId));
		update(a);
		printf("..id---(%s)...value(%d)...storeVal(%d)\n",(yyvsp[-3].m_sId),getValue((yyvsp[-3].m_sId)),getStoreVal((yyvsp[-3].m_sId)));
		if(checkScope((yyvsp[-3].m_sId))==0){
		fprintf(javafile,"\t\tputstatic %s test.%s\n",getType((yyvsp[-3].m_sId)),(yyvsp[-3].m_sId));
		}else{
			fprintf(javafile,"\t\tistore %d\n",getStoreVal((yyvsp[-3].m_sId)));
		}
		printf("%s\n","Reducing to [simple_statment]");
		}
#line 2631 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1085 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		}
#line 2639 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1087 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tinvokevirtual void java.io.PrintStream.print(int)\n");
		}
#line 2647 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1091 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
		printf("%s\n","Reducing to [simple_statment]");
		}
#line 2656 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1094 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tinvokevirtual void java.io.PrintStream.println(int)\n");
		}
#line 2664 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1098 "rust.y" /* yacc.c:1646  */
    {
		printf("%s\n","Reducing to [simple_statment]");
		}
#line 2672 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1102 "rust.y" /* yacc.c:1646  */
    {
		printf("~~~~~~~scope:::%d~~~~~~~~~\n",scope);
		printf("%s\n","Reducing to [simple_statment]");
		}
#line 2681 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1110 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tifeq L%d\n",label);
		iflabel1=label;
		printf("%s\n","Reducing to [selection_statment]");
		}
#line 2691 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1114 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tgoto L%d\n",label+1);
		iflabel2=label+1;
		fprintf(javafile,"\tL%d:\n",iflabel1);
		}
#line 2701 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1122 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\tL%d:\n",iflabel2);
		}
#line 2709 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1129 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\tL%d:\n",label);
		label++;
		}
#line 2718 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1134 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tifeq L%d\n",label);
		whilelabel=label;
		label++;
		}
#line 2728 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1140 "rust.y" /* yacc.c:1646  */
    {
		fprintf(javafile,"\t\tgoto L0\n");
		fprintf(javafile,"\tL%d:\n",whilelabel);
		printf("%s\n","Reducing to [iteration_statment]");}
#line 2737 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1148 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment_list]");}
#line 2743 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1150 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment_list]");}
#line 2749 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1155 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment]");}
#line 2755 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1157 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment]");}
#line 2761 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1159 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment]");}
#line 2767 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1161 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment]");}
#line 2773 "rust.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1163 "rust.y" /* yacc.c:1646  */
    {printf("%s\n","Reducing to [statment]");}
#line 2779 "rust.tab.c" /* yacc.c:1646  */
    break;


#line 2783 "rust.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1167 "rust.y" /* yacc.c:1906  */


void yyerror(const char *s)
{
	printf("%s\n",s);
}

int main()
{
	isAdd = false;
	scope = 0;
	storeNum =0;
	

	javafile = fopen("test.jasm","w");

	fprintf(javafile,"%s\n", "/*-------------------------------------------------*/");
	fprintf(javafile,"%s\n", "/*              Java Assembly Code                 */");
 	fprintf(javafile,"%s\n", "/*-------------------------------------------------*/");   	

	fprintf(javafile,"class test\n{\n");
	yyparse();
	printf("\n\n%s\n", "-----------------------------Symbol Table:-----------------------------");
	printf("%-*s\t%-*s\t%-*s\t%-*s\t%-*s\n",10,"Identifier",10,"Type",10,"Belong",10,"Value",10,"Scope");
        dump();
	fprintf(javafile,"}\n");
	fclose(javafile);
	for(int i  = 0; i< sizeof(orderToFile)/sizeof(orderToFile[0]); i++){
		printf("%s",orderToFile[i]);
	}
	return 0 ;
}
