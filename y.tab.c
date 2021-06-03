/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "1705020.y"

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>
#include "SymbolTable.cpp"
// #define YYSTYPE SymbolInfo*
// #define YYSTYPE string

using namespace std;

int yyparse(void);
int yylex(void);

extern FILE* yyin;

int line_count = 1;  // NOTICE
int error_count = 0;
int scope_count = 1;

SymbolTable symbolTable(7);


// YYSTYPE symbol_Info;
FILE* input;
FILE* mylog;
ofstream logout;
ofstream error;
// std::ofstream logout;
// std::ofstream error;

/* auxiliary variables and structures and containers */
string type, type_final;  // basially for function declaration-definition
string name, name_final;  // basically for function declaration-definition


struct var{
	//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    string var_name;
    int var_size;  // it is set to -1 for variables
} temp_var;

struct fuclsym{
	SymbolInfo *fucksym;
	
};
vector<var> var_list;  // for identifier(variable, array) insertion into symbolTable

struct parameter {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    string param_type;
    string param_name;  // it is set to empty string "" for function declaration
} temp_parameter;

struct symbol_attribute{
		string key;
		char* value;
};
struct Symbol {
		char* key;
		char* value;
} *sym;


vector<parameter> param_list;  // parameter list for function declaration, definition

vector<string> arg_list;  // argument list for function call

/* auxiliary functions */

void insertVar(string _type, var var_in) {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    // /* symbolTable insertion for variable and array */
    // SymbolInfo* symbolInfo = new SymbolInfo(var_in.var_name, "ID");
    // symbolInfo->set_Type(_type);  // setting variable type
    // symbolInfo->set_arrSize(var_in.var_size);

    // symbolTable.insertSymbol(*symbolInfo);
    // return ;
}

void insertFunc(string _type, string name, int _size) {
    // /* symbolTable insertion for function(declaration and definition) */
    // SymbolInfo* symbolInfo = new SymbolInfo(name, "ID");
    // symbolInfo->set_Type(_type);  // setting return type
    // symbolInfo->set_arrSize(_size);  // NOTICE: for distinguishing between declaration and definition
    
    // for(int i=0; i<param_list.size(); i++) {
    //     symbolInfo->addParam(param_list[i].param_type, param_list[i].param_name);
    // }

    // symbolTable.insertSymbol(*symbolInfo);
    // return ;
}





/* yyerror function for reporting syntax error */
void yyerror(char*); 

#line 174 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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
		
	

#line 304 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   172

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   135,   141,   149,   155,   161,   171,   177,
     185,   191,   203,   210,   216,   222,   231,   244,   256,   277,
     285,   291,   297,   305,   324,   330,   336,   342,   350,   356,
     364,   370,   376,   382,   388,   394,   401,   407,   413,   419,
     432,   438,   447,   453,   462,   468,   478,   483,   490,   496,
     504,   510,   518,   525,   533,   539,   545,   553,   559,   565,
     571,   577,   583,   589,   596,   602,   607,   612
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST_INT", "CONST_FLOAT", "ID", "INT",
  "CHAR", "DOUBLE", "TAB", "FLOAT", "VOID", "IF", "ELSE", "FOR", "WHILE",
  "PRINTLN", "RETURN", "ASSIGNOP", "NOT", "INCOP", "DECOP", "LOGICOP",
  "RELOP", "ADDOP", "MULOP", "LPAREN", "RPAREN", "LCURL", "RCURL",
  "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "SYMBOLA", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement", "embedded_in",
  "var_declaration", "type_specifier", "id", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF (-67)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,   -67,   -67,   -67,    39,    13,   -67,   -67,   -67,   -67,
       8,   -67,   -67,    24,    18,   -12,     6,    49,    57,   -67,
      -6,    22,    59,    43,   -67,    46,   -67,   -67,   -67,    35,
      13,   -67,   -67,    82,    67,   -67,   -67,    83,    61,   -67,
     -67,    73,    79,    80,    81,   146,   146,   146,   146,   129,
     -67,   -67,   -67,   -67,    57,     2,    98,   -67,   -67,    69,
      78,   -67,    94,    37,    93,   -67,   -67,   -67,   -67,   146,
      32,   146,   114,    87,    77,   -67,   -67,    96,   -67,   146,
     146,   -67,   -67,   146,   -67,   -67,   -67,   146,   146,   146,
     146,   101,    32,   102,   103,   -67,   -67,   -67,   109,    89,
     106,   -67,   -67,   118,    93,   -67,   129,   146,   129,   105,
     -67,   146,   -67,   134,   -67,   -67,   -67,   -67,   129,   -67
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,    21,    22,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    23,    26,     0,     0,     0,     0,    19,
       0,     0,    15,     0,    23,    24,    18,     9,    11,     0,
       0,    14,    27,     0,     0,     8,    10,    13,     0,    60,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,    40,    32,    30,     0,    42,     0,    28,    31,    57,
       0,    44,    46,    48,    50,    52,    56,    12,    25,     0,
       0,     0,     0,     0,    57,    55,    54,     0,    34,    65,
       0,    16,    29,     0,    62,    63,    41,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    59,    67,     0,    64,
       0,    45,    47,    49,    51,    53,     0,     0,     0,     0,
      58,     0,    43,    35,    33,    37,    38,    66,     0,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   147,   -67,   -67,   -67,   -14,   -67,    75,
      25,    -7,   -67,   -67,   -49,   -66,   -45,   -40,   -65,    71,
      66,    70,   -37,   -67,   -67,   -67
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    21,    52,    34,    53,
      54,    55,    15,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    98,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      78,    74,    74,    14,    92,    73,    28,    82,    77,    75,
      76,    25,     1,    13,    97,    36,     2,     3,   101,     1,
      18,    19,    26,     2,     3,    10,   107,    27,    79,    91,
      10,    93,    80,    20,    74,    39,    40,    24,    74,    11,
     100,    22,    74,    74,    74,    74,   117,    14,    17,    29,
      16,    46,    23,   105,    30,    37,    47,   113,    48,   115,
      88,    89,    24,    26,    31,    51,    74,   114,    35,   119,
      39,    40,    24,     1,    32,     9,    33,     2,     3,    41,
       9,    42,    43,    44,    45,    38,    46,    83,    67,    84,
      85,    47,    68,    48,    49,    26,    50,    84,    85,    69,
      51,    39,    40,    24,     1,    70,    71,    72,     2,     3,
      41,    86,    42,    43,    44,    45,    87,    46,    90,    94,
      95,   111,    47,    96,    48,    49,    26,    81,   106,   108,
     109,    51,    39,    40,    24,     1,   110,   112,   116,     2,
       3,    41,    89,    42,    43,    44,    45,   118,    46,    39,
      40,    24,    12,    47,   103,    48,    49,    26,   102,   104,
       0,     0,    51,     0,     0,    46,     0,     0,     0,     0,
      47,     0,    48
};

static const yytype_int8 yycheck[] =
{
      49,    46,    47,    10,    70,    45,    20,    56,    48,    46,
      47,    18,     6,     5,    79,    29,    10,    11,    83,     6,
      32,    33,    28,    10,    11,     0,    92,    33,    26,    69,
       5,    71,    30,    27,    79,     3,     4,     5,    83,     0,
      80,    16,    87,    88,    89,    90,   111,    54,    30,    27,
      26,    19,     3,    90,    32,    30,    24,   106,    26,   108,
      23,    24,     5,    28,     5,    33,   111,   107,    33,   118,
       3,     4,     5,     6,    31,     0,    30,    10,    11,    12,
       5,    14,    15,    16,    17,     3,    19,    18,     5,    20,
      21,    24,    31,    26,    27,    28,    29,    20,    21,    26,
      33,     3,     4,     5,     6,    26,    26,    26,    10,    11,
      12,    33,    14,    15,    16,    17,    22,    19,    25,     5,
      33,    32,    24,    27,    26,    27,    28,    29,    27,    27,
      27,    33,     3,     4,     5,     6,    27,    31,    33,    10,
      11,    12,    24,    14,    15,    16,    17,    13,    19,     3,
       4,     5,     5,    24,    88,    26,    27,    28,    87,    89,
      -1,    -1,    33,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      24,    -1,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    10,    11,    37,    38,    39,    40,    41,    45,
      46,     0,    39,     5,    47,    48,    26,    30,    32,    33,
      27,    42,    46,     3,     5,    47,    28,    33,    43,    27,
      32,     5,    31,    30,    44,    33,    43,    46,     3,     3,
       4,    12,    14,    15,    16,    17,    19,    24,    26,    27,
      29,    33,    43,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,     5,    31,    26,
      26,    26,    26,    53,    52,    58,    58,    53,    50,    26,
      30,    29,    50,    18,    20,    21,    33,    22,    23,    24,
      25,    53,    51,    53,     5,    33,    27,    54,    60,    61,
      53,    54,    55,    56,    57,    58,    27,    51,    27,    27,
      27,    32,    31,    50,    53,    50,    33,    54,    13,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      41,    41,    42,    42,    42,    42,    43,    43,    44,    45,
      46,    46,    46,    47,    48,    48,    48,    48,    49,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     4,     3,     0,     3,
       1,     1,     1,     1,     3,     6,     1,     4,     1,     2,
       1,     1,     1,     5,     2,     5,     7,     5,     5,     3,
       1,     2,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     2,     2,     1,     1,     4,     3,
       1,     1,     2,     2,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 128 "1705020.y"
               {
	fprintf(mylog,"At line No.%d start: program\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" start: program"<<"\n";

	//incomplete
}
#line 1576 "y.tab.c"
    break;

  case 3:
#line 135 "1705020.y"
                      {
	fprintf(mylog,"At line No.%d program: program unit\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" program: program unit"<<"\n";

	}
#line 1587 "y.tab.c"
    break;

  case 4:
#line 141 "1705020.y"
               {
		fprintf(mylog,"At line No.%d program: unit\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" program: unit"<<"\n";


	}
#line 1598 "y.tab.c"
    break;

  case 5:
#line 149 "1705020.y"
                      {
	fprintf(mylog,"At line No.%d unit: var declaration\n\n",line_count);
	//incomplete		
	//logout<<"At line no: "<<line_count<<" unit: var_declaration"<<"\n";

	}
#line 1609 "y.tab.c"
    break;

  case 6:
#line 155 "1705020.y"
                          {
		fprintf(mylog,"At line No.%d unit: func_declaration\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" unit: func_declaration"<<"\n";

	//incomplete
	}
#line 1620 "y.tab.c"
    break;

  case 7:
#line 161 "1705020.y"
                         {
		fprintf(mylog,"At line No.%d unit: func_definition\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" unit: func_definition"<<"\n";

	}
#line 1631 "y.tab.c"
    break;

  case 8:
#line 171 "1705020.y"
                                                                           {
	fprintf(mylog,"At line No.%d func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON \n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON "<<"\n";

	}
#line 1642 "y.tab.c"
    break;

  case 9:
#line 177 "1705020.y"
                                                    {
		fprintf(mylog,"At line No.%d func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON \n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<"  func_declaration: type_specifier ID LPAREN RPAREN SEMICOLON"<<"\n";

	}
#line 1653 "y.tab.c"
    break;

  case 10:
#line 185 "1705020.y"
                                                                                   {
	fprintf(mylog,"At line No.%d func_definition: type_specifier ID LPAREN param_list RPAREN compound_statement\n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<"  funct_definition: type_specifier ID LPAREN param_list RPAREN compound_statement"<<"\n";

	}
#line 1664 "y.tab.c"
    break;

  case 11:
#line 191 "1705020.y"
                                                             {
		fprintf(mylog,"At line No.%d func_definition:type_specifier ID LPAREN RPAREN compound_statement\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<"  funct_definition:type_specifier ID LPAREN RPAREN compound_statement"<<"\n";

	}
#line 1675 "y.tab.c"
    break;

  case 12:
#line 203 "1705020.y"
                                                       {
	fprintf(mylog,"At line No.%d parameter_list: parameter_list COMMA type_specifier ID\n\n",line_count);
	//incomplete
		//logout<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier ID"<<"\n";

	}
#line 1686 "y.tab.c"
    break;

  case 13:
#line 210 "1705020.y"
                                            {
		fprintf(mylog,"At line No.%d  parameter_list: parameter_list COMMA type_specifier\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" parameter_list: parameter_list COMMA type_specifier"<<"\n";

	}
#line 1697 "y.tab.c"
    break;

  case 14:
#line 216 "1705020.y"
                            {
		fprintf(mylog,"At line No.%d  parameter_list:  type_specifier ID\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" parameter_list:  type_specifier ID"<<"\n";

	}
#line 1708 "y.tab.c"
    break;

  case 15:
#line 222 "1705020.y"
                         {
		fprintf(mylog,"At line No.%d parameter_list:  type_specifier\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" parameter_list:  COMMA type_specifier"<<"\n";

		//incomplete
	}
#line 1719 "y.tab.c"
    break;

  case 16:
#line 231 "1705020.y"
                                                       {
	fprintf(mylog,"At line No.%d compound_statement: LCURL statements RCURL\n\n",line_count);
	// printf("%g\n",$1);
	//fprintf(mylog,"{\n%s\n}",$3);
	//incomplete
		//logout<<"At line no: "<<line_count<<" compound_statement: LCURL statements RCURL"<<"\n";

	
		/*** scoptable exiting******/
		symbolTable.printAllScopeTable(mylog);
		symbolTable.pop();

	}
#line 1737 "y.tab.c"
    break;

  case 17:
#line 244 "1705020.y"
                                  {
		fprintf(mylog,"At line No.%d compound_statement:  LCURL RCURL\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" compound_statement:  LCURL RCURL "<<"\n";

		//incomplete
		symbolTable.printAllScopeTable(mylog);
		symbolTable.pop();
	}
#line 1750 "y.tab.c"
    break;

  case 18:
#line 256 "1705020.y"
             {
            /* NOTICE: embedded action */
            symbolTable.EnterScope(mylog);   // #bucket_in_each_scopeTable = 7

            // /* add parameters (if exists) to symbolTable */
            // if(param_list.size()==1 && param_list[0].param_type=="void") {
            //     /* only parameter is void */
            // } else {
            //     for(int i=0; i<param_list.size(); i++) {
            //         temp_var.var_name = param_list[i].param_name;
            //         temp_var.var_size = -1;

            //         insertVar(param_list[i].param_type, temp_var);
            //     }
            // }

            // param_list.clear();  // NOTICE
    }
#line 1773 "y.tab.c"
    break;

  case 19:
#line 277 "1705020.y"
                                                           {
	fprintf(mylog,"At line No.%d var_declaration: type_specifier declaration_list SEMICOLON\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" var_declaration: type_specifier declaration_list SEMICOLON"<<"\n";

	}
#line 1784 "y.tab.c"
    break;

  case 20:
#line 285 "1705020.y"
                    {
	fprintf(mylog,"At line No.%d  type_specifier: INT\n\n",line_count);
	//incomplete
		// logout<<"At line no: "<<line_count<<" type_specifier: INT"<<"\n";
        // fprintf(mylog,"At line no:%d type_specifier: INT\n",line_count);
	}
#line 1795 "y.tab.c"
    break;

  case 21:
#line 291 "1705020.y"
                {
		fprintf(mylog,"At line No.%d type_specifier: FLOAT\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" type_specifier: FLOAT"<<"\n";

		//incomplete
	}
#line 1806 "y.tab.c"
    break;

  case 22:
#line 297 "1705020.y"
               {
		fprintf(mylog,"At line No.%d type_specifier: VOID\n\n",line_count);
	//logout<<"At line no: "<<line_count<<" type_specifier: VOID"<<"\n";

		//incomplete
	}
#line 1817 "y.tab.c"
    break;

  case 23:
#line 305 "1705020.y"
       {
	fprintf(mylog,"At line No.%d  id: ID\n\n",line_count);
	fprintf(mylog,"%s\n\n",yylval.str);
	string value(yylval.str);
	SymbolInfo sss("ID",value);
	symbolTable.push(sss);	
	// string value(yylval);
	// SymbolInfo sym("ID",value);
	// symbolTable.push(sym,mylog);
	//std::cout<<"At line No."<<line_count<<"  id: ID\n\n";
	//std::cout<<$1->getKey()<<":"<<$1->getValue();
	//incomplete
		//logout<<"At line no: "<<line_count<<" id: ID"<<"\n";
                // fprintf(mylog,"At line no:%d id: ID\n",line_count);
                // fprintf(mylog,$$);


	}
#line 1840 "y.tab.c"
    break;

  case 24:
#line 324 "1705020.y"
                                            {
	fprintf(mylog,"At line No.%d  declaration_list:  declaration_list COMMA id\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id"<<"\n";

	}
#line 1851 "y.tab.c"
    break;

  case 25:
#line 330 "1705020.y"
                                                            {
		fprintf(mylog,"At line No.%d declaration_list:  declaration_list COMMA id LTHIRD CONS RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" declaration_list:  declaration_list COMMA id LTHIRD CONS RTHIRD"<<"\n";

	}
#line 1862 "y.tab.c"
    break;

  case 26:
#line 336 "1705020.y"
             {
		fprintf(mylog,"At line No.%d  declaration_list: id \n\n",line_count);
		//incomplete
	//logout<<"At line no: "<<line_count<<" declaration_list: id"<<"\n";

	}
#line 1873 "y.tab.c"
    break;

  case 27:
#line 342 "1705020.y"
                                     {
		fprintf(mylog,"At line No.%d  declaration_list: id LTHIRD CONST_INT RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" declaration_list: id LTHIRD CONST_INT RTHIRD"<<"\n";

	}
#line 1884 "y.tab.c"
    break;

  case 28:
#line 350 "1705020.y"
                      {
	fprintf(mylog,"At line No.%d statements: statement\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" statements: statement"<<"\n";

	}
#line 1895 "y.tab.c"
    break;

  case 29:
#line 356 "1705020.y"
                               {
		fprintf(mylog,"At line No.%d statement: statements statement\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: statements statement "<<"\n";

	}
#line 1906 "y.tab.c"
    break;

  case 30:
#line 364 "1705020.y"
                           {
	fprintf(mylog,"At line No.%d  statement: var_declaration\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" statement: var_declaration "<<"\n";

	}
#line 1917 "y.tab.c"
    break;

  case 31:
#line 370 "1705020.y"
                               {
		fprintf(mylog,"At line No.%d  statement: expression_statement\n\n",line_count);
				//logout<<"At line no: "<<line_count<<" statement: expression_statement"<<"\n";

		//incomplete
	}
#line 1928 "y.tab.c"
    break;

  case 32:
#line 376 "1705020.y"
                             {
		fprintf(mylog,"At line No.%d statement: compound_statement\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" statement: compound_statement"<<"\n";

		//incomplete
	}
#line 1939 "y.tab.c"
    break;

  case 33:
#line 382 "1705020.y"
                                                                          {
		fprintf(mylog,"At line No.%d  statement: FOR LPAREN expression_statement expression_statement expression\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" statement: FOR LPAREN expression_statement expression_statement expression"<<"\n";

	}
#line 1950 "y.tab.c"
    break;

  case 34:
#line 388 "1705020.y"
                           {
		fprintf(mylog,"At line No.%d statement:RPAREN statement\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" statement:RPAREN statement "<<"\n";

	}
#line 1961 "y.tab.c"
    break;

  case 35:
#line 394 "1705020.y"
                                                {
		fprintf(mylog,"At line No.%d statement: IF LPAREN expression RPAREN statement \n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement "<<"\n";


	}
#line 1973 "y.tab.c"
    break;

  case 36:
#line 401 "1705020.y"
                                                               {
		fprintf(mylog,"At line No.%d statement: IF LPAREN expression RPAREN statement ELSE statement\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" statement: IF LPAREN expression RPAREN statement ELSE statement "<<"\n";

		//incomplete
	}
#line 1984 "y.tab.c"
    break;

  case 37:
#line 407 "1705020.y"
                                                   {
		fprintf(mylog,"At line No.%d statement: WHILE LPAREN expression RPAREN statement\n\n",line_count);
			//incomplete
			//logout<<"At line no: "<<line_count<<" statement: WHILE LPAREN expression RPAREN statement"<<"\n";

	}
#line 1995 "y.tab.c"
    break;

  case 38:
#line 413 "1705020.y"
                                             {
		fprintf(mylog,"At line No.%d  statement: PRINTLN LPAREN ID RPAREN SEMICOLON\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" statement: PRINTLN LPAREN ID RPAREN SEMICOLON"<<"\n";

	}
#line 2006 "y.tab.c"
    break;

  case 39:
#line 419 "1705020.y"
                                      {
		fprintf(mylog,"At line No.%d  statement: RETURN expression SEMICOLON\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" statement: RETURN expression SEMICOLON"<<"\n";

		//incomplete
	}
#line 2017 "y.tab.c"
    break;

  case 40:
#line 432 "1705020.y"
                                {
	fprintf(mylog,"At line No.%d expression_statement: SEMICOLONd\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" expression_statement: SEMICOLONd"<<"\n";

	}
#line 2028 "y.tab.c"
    break;

  case 41:
#line 438 "1705020.y"
                               {
		fprintf(mylog,"At line No.%d expression_statement: expression SEMICOLON\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" expression_statement: expression SEMICOLONd"<<"\n";

		//incomplete
	}
#line 2039 "y.tab.c"
    break;

  case 42:
#line 447 "1705020.y"
             {
	fprintf(mylog,"At line No.%d  variable: id\n\n",line_count);
		//incomplete
				//logout<<"At line no: "<<line_count<<" variable: id"<<"\n";

	}
#line 2050 "y.tab.c"
    break;

  case 43:
#line 453 "1705020.y"
                                      {
		fprintf(mylog,"At line No.%d variable: id LTHIRD expression RTHIRD\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" variable: id LTHIRD expression RTHIRD"<<"\n";

	}
#line 2061 "y.tab.c"
    break;

  case 44:
#line 462 "1705020.y"
                             {
	fprintf(mylog,"At line No.%d expression: logic_expression\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" expression: logic_expression"<<"\n";

	//incomplete
	}
#line 2072 "y.tab.c"
    break;

  case 45:
#line 468 "1705020.y"
                                             {
		fprintf(mylog,"At line No.%d expression: variable ASSIGNOP logic_expression\n\n",line_count);
		//incomplete
				//logout<<"At line no: "<<line_count<<" expression: variable ASSIGNOP logic_expression"<<"\n";

	}
#line 2083 "y.tab.c"
    break;

  case 46:
#line 478 "1705020.y"
                                 {
	fprintf(mylog,"At line No.%d expression: rel_expression\n\n",line_count);
	//incomplete
			//logout<<"At line no: "<<line_count<<" expression: rel_expression"<<"\n";
	}
#line 2093 "y.tab.c"
    break;

  case 47:
#line 483 "1705020.y"
                                                {
		fprintf(mylog,"At line No.%d logic_expression: rel_expression\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";
		//incomplete
	}
#line 2103 "y.tab.c"
    break;

  case 48:
#line 490 "1705020.y"
                                  {
	fprintf(mylog,"At line No.%d logic_expression: rel_expression\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" logic_expression: rel_expression"<<"\n";

	//incomplete
	}
#line 2114 "y.tab.c"
    break;

  case 49:
#line 496 "1705020.y"
                                                    {
		fprintf(mylog,"At line No.%d logic_expression:  simple_expression RELOP simple_expression\n\n",line_count);
		//incomplete
			//logout<<"At line no: "<<line_count<<" logic_expression:  simple_expression RELOP simple_expression"<<"\n";

	}
#line 2125 "y.tab.c"
    break;

  case 50:
#line 504 "1705020.y"
                        {
	fprintf(mylog,"At line No.%d  simple_expression: term\n\n",line_count);
				//logout<<"At line no: "<<line_count<<" simple_expression: term"<<"\n";

		//incomplete
	}
#line 2136 "y.tab.c"
    break;

  case 51:
#line 510 "1705020.y"
                                       {
		fprintf(mylog,"At line No.%d simple_expression: simple_expression ADDOP term\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" simple_expression: simple_expression ADDOP term"<<"\n";

	}
#line 2147 "y.tab.c"
    break;

  case 52:
#line 518 "1705020.y"
                       {
	fprintf(mylog,"At line No.%d  term: unary_expressionm\n\n",line_count);
	//incomplete
	//logout<<"At line no: "<<line_count<<" term: unary_expressionm"<<"\n";

	
	}
#line 2159 "y.tab.c"
    break;

  case 53:
#line 525 "1705020.y"
                                      {
		fprintf(mylog,"At line No.%d term:  term MULOP unary_expression\n\n",line_count);
		//incomplete
	//logout<<"At line no: "<<line_count<<" term:  term MULOP unary_expression"<<"\n";

	}
#line 2170 "y.tab.c"
    break;

  case 54:
#line 533 "1705020.y"
                                         {
	fprintf(mylog,"At line No.%d unary_expression: ADDOP unary_expression\n\n",line_count);
	//logout<<"At line no: "<<line_count<<" unary_expression: ADDOP unary_expression "<<"\n";

	//incomplete
	}
#line 2181 "y.tab.c"
    break;

  case 55:
#line 539 "1705020.y"
                               {
		fprintf(mylog,"At line No.%d unary_expression: NOT unary_expression\n\n",line_count);
			//logout<<"At line no: "<<line_count<<" unary_expression: NOT unary_expression "<<"\n";

		//incomplete
	}
#line 2192 "y.tab.c"
    break;

  case 56:
#line 545 "1705020.y"
                 {
		fprintf(mylog,"At line No.%d unary_expression: factor\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" unary_expression: factor"<<"\n";

		//incomplete
	}
#line 2203 "y.tab.c"
    break;

  case 57:
#line 553 "1705020.y"
                 {
	fprintf(mylog,"At line No.%d factor: variable\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: variable"<<"\n";

	//incomplete
	}
#line 2214 "y.tab.c"
    break;

  case 58:
#line 559 "1705020.y"
                                         {
		fprintf(mylog,"At line No.%d factor: id LPAREN argument_list RPAREN\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: id LPAREN argument_list RPAREN"<<"\n";

		//incomplete
	}
#line 2225 "y.tab.c"
    break;

  case 59:
#line 565 "1705020.y"
                                   {
		fprintf(mylog,"At line No.%d factor: LPAREN expression RPAREN\n\n",line_count);
		//incomplete
		//logout<<"At line no: "<<line_count<<" factor: LPAREN expression RPAREN"<<"\n";

	}
#line 2236 "y.tab.c"
    break;

  case 60:
#line 571 "1705020.y"
                    {
		fprintf(mylog,"At line No.%d  factor:CONST_INT\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:CONST_INT"<<"\n";

		//incomplete
	}
#line 2247 "y.tab.c"
    break;

  case 61:
#line 577 "1705020.y"
                      {
		fprintf(mylog,"At line No.%d  factor:CONST_FLOAT\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:CONST_FLOAT"<<"\n";

		//incomplete
	}
#line 2258 "y.tab.c"
    break;

  case 62:
#line 583 "1705020.y"
                         {
		fprintf(mylog,"At line No.%d factor: variable INCOP\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor:variable INCOP"<<"\n";

		//incomplete
	}
#line 2269 "y.tab.c"
    break;

  case 63:
#line 589 "1705020.y"
                         {
		fprintf(mylog,"At line No.%d factor: DECOP\n\n",line_count);
		//logout<<"At line no: "<<line_count<<" factor: DECOP"<<"\n";

		//incomplete
	}
#line 2280 "y.tab.c"
    break;

  case 64:
#line 596 "1705020.y"
                         {
	fprintf(mylog,"At line No.%d argument_list: arguments\n\n",line_count);
	//incomplete
			//logout<< "\narguments mathed at line No: "<<line_count<<"\n";<<"\n";

	}
#line 2291 "y.tab.c"
    break;

  case 65:
#line 602 "1705020.y"
          {
		fprintf(mylog,"At line No.%d argument_list: empty_string \n\n",line_count);
		//incomplete
		//empty production
	}
#line 2301 "y.tab.c"
    break;

  case 66:
#line 607 "1705020.y"
                                            {
	fprintf(mylog,"At line No.%d arguments: arguments COMMA logic_expression \n\n",line_count);
	//logout<<"\narguments COMMA logic_expression mathced at line No.:"<<line_count<<"\n";<<"\n";
	//incomplete
	}
#line 2311 "y.tab.c"
    break;

  case 67:
#line 612 "1705020.y"
                          {
		fprintf(mylog,"At line No.%d arguments: logic_expression\n\n",line_count);
		//logout<< "\nlogic_expression mathed at line No: "<<line_count<<"\n";<<"\n";
		//incomplete
	}
#line 2321 "y.tab.c"
    break;


#line 2325 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 620 "1705020.y"




int main(int argc, char* argv[]) {
	//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	if(argc != 2) {
		fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
		cout << "input file name not provided, terminating program..." << endl;
		return 0;
	}

    input = fopen(argv[1], "r");
    mylog = fopen("logfile_1705020.txt","w");
    
    logout.open("1705020_log.txt", ios::out);
	error.open("1705020_error.txt", ios::out);
   
    if(input == NULL) {
		//fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
		cout << "input file not opened properly, terminating program..." << endl;
		exit(EXIT_FAILURE);
	}

	// symbol_Info = new SymbolInfo("dummy","dummy");
	//std::cout<<symbol_Info->getKey()<<endl;
	// logout.open("1605023_log.txt", ios::out);
	// error.open("1605023_error.txt", ios::out);
	
	// if(logout.is_open() != true) {
		// fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	// 	cout << "logout file not opened properly, terminating program..." << endl;
	// 	fclose(input);
		
	// 	exit(EXIT_FAILURE);
	// }
	
	// if(error.is_open() != true) {
		// fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
	// 	cout << "error file not opened properly, terminating program..." << endl;
	// 	fclose(input);
	// 	logout.close();
		
	// 	exit(EXIT_FAILURE);
	// }
	
	// //symbolTable.enterScope(scope_count++, 7, logout);   // #bucket_in_each_scopeTable = 7
	
	yyin = input;
	symbolTable.EnterScope();
    yyparse();  // processing starts

   // logout << endl;
	//symbolTable.printAll(logout);
	//symbolTable.exitScope(logout);

	// logout << "Total Lines: " << (--line_count) << endl;  // NOTICE here: line_count changed (July 19) -> works for sample
	// logout << "\n" << "Total Errors: " << error_count << endl;
    // error << "\n" << "Total Errors: " << error_count << endl;
	
	fclose(yyin);
	// logout.close();
	// error.close();
	
	return 0;
} 


void yyerror(char* s) {
//	fprintf(mylog,"At line No.%d term: unary expression\n\n",line_count);
    /* it may be modified later */
 //logout << "At line no: " << line_count << " " << s << endl;

    line_count++;
    error_count++;
    
    return ;
}

/*
    yaccFile=1605023.y
    lexFile=1605023.l
    inputFile=input.txt
    ####################################################################
    #Created by Mir Mahathir Mohammad 1605011
    ####################################################################
    DIR="$(cd "$(dirname "$0")" && pwd)"
    cd $DIR
    bison -d -y -v ./$yaccFile
    g++ -w -c -o ./y.o ./y.tab.c
    flex -o ./lex.yy.c ./$lexFile
    g++ -fpermissive -w -c -o ./l.o ./lex.yy.c
    g++ -o ./a.out ./y.o ./l.o -lfl -ly	
    ./a.out ./input.txt
*/
