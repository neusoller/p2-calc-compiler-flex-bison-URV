/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "calculator.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	#include <math.h>
	#include <stdarg.h>
	#include "calculator.tab.h"

	#define MAX_QUADS 500
	#define ARRAY 3
	
	// taula de símbols pròpia
	#define CUSTOM_MAX_SYMBOLS 100
	CustomSymbol customSymtab[CUSTOM_MAX_SYMBOLS];  // Taula de símbols
	int customSymtabCount = 0;                      // Comptador d'entrades

	int errflag = 0;
	int temp = 1;

	quad *quad_list;

	int currQuad = 0;

	extern FILE* yyin;
	extern int yylineno;

	extern void yyerror(char *explanation);

	FILE* fInfo;
	
	// funcions
		
	variable arithmeticCalc(variable v1, char* op, variable v2);
	variable powFunction(variable v1, variable v2, char* assign_name);
	
	char *newTemp(const char *prefix);
	
	void addQuad(int num_args, ...);
	void printQuads();
	void mostrarSymtab();
	
	// el meu "symtab"
	void customSymEnter(char *name, char *value, int type);
	void mostrarCustomSymtab();
	CustomSymbol *customSymLookup(char *name);
	
	

#line 121 "calculator.tab.c"

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

#include "calculator.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FL = 3,                         /* FL  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_A_ID = 6,                       /* A_ID  */
  YYSYMBOL_ADD = 7,                        /* ADD  */
  YYSYMBOL_SUB = 8,                        /* SUB  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_MOD = 11,                       /* MOD  */
  YYSYMBOL_POW = 12,                       /* POW  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_LPAREN = 14,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 15,                    /* RPAREN  */
  YYSYMBOL_EOL = 16,                       /* EOL  */
  YYSYMBOL_END = 17,                       /* END  */
  YYSYMBOL_SCOMMENT = 18,                  /* SCOMMENT  */
  YYSYMBOL_MCOMMENT = 19,                  /* MCOMMENT  */
  YYSYMBOL_LERR = 20,                      /* LERR  */
  YYSYMBOL_REPEAT = 21,                    /* REPEAT  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_DONE = 23,                      /* DONE  */
  YYSYMBOL_LB = 24,                        /* LB  */
  YYSYMBOL_RB = 25,                        /* RB  */
  YYSYMBOL_PC = 26,                        /* PC  */
  YYSYMBOL_COMA = 27,                      /* COMA  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_program = 29,                   /* program  */
  YYSYMBOL_statement_list = 30,            /* statement_list  */
  YYSYMBOL_iniciar_loop = 31,              /* iniciar_loop  */
  YYSYMBOL_acabar_loop = 32,               /* acabar_loop  */
  YYSYMBOL_statement = 33,                 /* statement  */
  YYSYMBOL_id = 34,                        /* id  */
  YYSYMBOL_exp = 35,                       /* exp  */
  YYSYMBOL_arithmetic = 36,                /* arithmetic  */
  YYSYMBOL_arithmetic_op1 = 37,            /* arithmetic_op1  */
  YYSYMBOL_arithmetic_op2 = 38,            /* arithmetic_op2  */
  YYSYMBOL_arithmetic_op3 = 39             /* arithmetic_op3  */
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  65

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    65,    65,    67,    67,    67,    67,    67,    69,    92,
     115,   127,   145,   152,   167,   168,   169,   170,   171,   172,
     173,   178,   178,   180,   182,   183,   184,   185,   186,   196,
     197,   198,   199,   201,   202,   204,   205,   208,   211,   224,
     237,   238,   239
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FL", "INT", "ID",
  "A_ID", "ADD", "SUB", "MUL", "DIV", "MOD", "POW", "ASSIGN", "LPAREN",
  "RPAREN", "EOL", "END", "SCOMMENT", "MCOMMENT", "LERR", "REPEAT", "DO",
  "DONE", "LB", "RB", "PC", "COMA", "$accept", "program", "statement_list",
  "iniciar_loop", "acabar_loop", "statement", "id", "exp", "arithmetic",
  "arithmetic_op1", "arithmetic_op2", "arithmetic_op3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282
};
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-43)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      71,   -13,   -16,   -16,    -4,    -3,   104,   104,    92,   -16,
     -16,   -16,   -16,   105,    92,     8,    50,   -16,   -16,    -1,
     -16,    -2,    93,   -16,     7,    51,     6,   -16,   -16,    16,
      93,   -16,    29,    72,   -16,   -16,    12,   -16,   -16,    92,
      31,   104,   104,   104,   104,   104,   104,   -16,   -16,   -16,
      36,   -16,    20,    93,    93,   -16,   -16,   -16,   -16,    71,
      34,    10,    92,   -16,   -16
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    37,    36,    39,    38,     0,     0,     0,    14,
      17,    15,    16,    19,     0,     0,     0,     6,     4,     0,
      11,    23,    24,    29,    33,    20,     0,    39,    38,    41,
      27,    28,     0,    18,     8,     1,     5,     7,     3,     0,
       0,     0,     0,     0,     0,     0,     0,    42,    40,    35,
       0,    10,     0,    25,    26,    30,    31,    32,    34,     0,
      12,     0,     0,     9,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,     0,   -15,   -16,   -12,   -16,   -14,    57,     1,
      -5,   -16
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    37,    18,    19,    20,    21,    22,
      23,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    36,    31,    25,    38,    41,    42,    30,    35,   -21,
     -22,     1,    39,     2,     3,     4,     5,     6,     7,    46,
     -21,   -22,    47,    40,     8,    51,     9,    10,    11,    12,
      13,    14,    48,    63,    50,    52,    41,    42,    55,    56,
      57,    58,    53,    54,    49,    60,    36,    62,    64,    38,
      -2,     1,    59,     2,     3,     4,     5,     6,     7,    61,
     -42,   -42,   -42,   -42,     8,    32,     9,    10,    11,    12,
      13,    14,     1,     0,     2,     3,     4,     5,     6,     7,
       0,   -40,   -40,   -40,   -40,     8,     0,     9,    10,    11,
      12,    13,    14,    26,     0,     2,     3,    27,    28,     6,
       7,     0,    43,    44,    45,    26,     8,     2,     3,    27,
      28,     0,    29,     0,   -41,   -41,   -41,   -41,     8,     0,
       0,    33,     0,     0,    29
};

static const yytype_int8 yycheck[] =
{
      14,    16,     7,    16,    16,     7,     8,     6,     0,    13,
      13,     1,    13,     3,     4,     5,     6,     7,     8,    12,
      24,    24,    16,    24,    14,    39,    16,    17,    18,    19,
      20,    21,    16,    23,    22,     4,     7,     8,    43,    44,
      45,    46,    41,    42,    15,    25,    61,    13,    62,    61,
       0,     1,    16,     3,     4,     5,     6,     7,     8,    59,
       9,    10,    11,    12,    14,     8,    16,    17,    18,    19,
      20,    21,     1,    -1,     3,     4,     5,     6,     7,     8,
      -1,     9,    10,    11,    12,    14,    -1,    16,    17,    18,
      19,    20,    21,     1,    -1,     3,     4,     5,     6,     7,
       8,    -1,     9,    10,    11,     1,    14,     3,     4,     5,
       6,    -1,    20,    -1,     9,    10,    11,    12,    14,    -1,
      -1,    16,    -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    14,    16,
      17,    18,    19,    20,    21,    29,    30,    31,    33,    34,
      35,    36,    37,    38,    39,    16,     1,     5,     6,    20,
      37,    38,    36,    16,    35,     0,    31,    32,    33,    13,
      24,     7,     8,     9,    10,    11,    12,    16,    16,    15,
      22,    35,     4,    37,    37,    38,    38,    38,    38,    16,
      25,    30,    13,    23,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    30,    30,    30,    31,    32,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    34,    34,    35,    36,    36,    36,    36,    36,    37,
      37,    37,    37,    38,    38,    39,    39,    39,    39,    39,
      39,    39,    39
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     2,     5,
       3,     1,     4,     6,     1,     1,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     3,     3,     2,     2,     1,
       3,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
  case 8: /* iniciar_loop: REPEAT exp  */
#line 69 "calculator.y"
                          {	if((yyvsp[0].var).type == UNDEFINED){
						fprintf(fInfo, "ERROR: Condició no vàlida en el bucle REPEAT a la línia %d\n", yylineno);
						(yyval.var).type = UNDEFINED;
						yyerror((yyvsp[0].var).place);
						yylineno++;
				} else {
					if((yyvsp[0].var).type == FLOAT){
						fprintf(fInfo, "ERROR: La condició del bucle REPEAT ha de ser de tipus ENTER a la línia %d\n", yylineno);
						(yyval.var).type = UNDEFINED;
						yyerror("SEMANTIC ERROR\n");
						yylineno++;
					} else {
						
						yylineno++;
						(yyval.var) = (yyvsp[0].var);
						(yyval.var).ctr = (char *)malloc(100);
						strcpy((yyval.var).ctr, newTemp(NULL));
						addQuad(2, (yyval.var).ctr, "0");
						(yyval.var).repeat = currQuad +1;
					}
				}											
			}
#line 1226 "calculator.tab.c"
    break;

  case 9: /* acabar_loop: iniciar_loop DO EOL statement_list DONE  */
#line 92 "calculator.y"
                                                     { 
				fprintf(fInfo, "Línia %d: --- FINAL LOOP ---\n", yylineno);
				if((yyvsp[-4].var).type == UNDEFINED){}
				else if((yyvsp[-1].var).type == UNDEFINED){
					(yyval.var).type = UNDEFINED;
					yyerror("SEMANTIC ERROR\n");
					fprintf(fInfo, "SEMANTIC ERROR: Error in loop error detected.%d\n", yylineno);
				} else{
					if((yyvsp[-4].var).type == INTEGER) addQuad(4, (yyvsp[-4].var).ctr, "ADDI", (yyvsp[-4].var).ctr, "1");
					else addQuad(4, (yyvsp[-4].var).ctr, "ADDF", (yyvsp[-4].var).ctr, "1");
					
					char str[20];
					sprintf(str, "%d", (yyvsp[-4].var).repeat);
					if ((yyvsp[-4].var).type == INTEGER)	{
						addQuad(4, (yyvsp[-4].var).ctr, "LTI", (yyvsp[-4].var).place, str);
					} else {
						addQuad(4, (yyvsp[-4].var).ctr, "LTF", (yyvsp[-4].var).place, str);
					}
				}
			}
#line 1251 "calculator.tab.c"
    break;

  case 10: /* statement: id ASSIGN exp  */
#line 115 "calculator.y"
                                {	
					if((yyvsp[0].var).type == UNDEFINED){
						fprintf(fInfo, "SEMANTIC ERROR: Assignació no vàlida a la línia %d\n", yylineno);
						yyerror((yyvsp[0].var).place);
					} else {
						customSymEnter((yyvsp[-2].var).name, (yyvsp[0].var).place, (yyvsp[0].var).type);

						addQuad(3, (yyvsp[-2].var).name, ":=", (yyvsp[0].var).place);
						yylineno++; 
						
					}
				}
#line 1268 "calculator.tab.c"
    break;

  case 11: /* statement: exp  */
#line 127 "calculator.y"
                        {	
					if((yyvsp[0].var).type == UNDEFINED){
						yyerror((yyvsp[0].var).place);
					} else {	
						if(sym_lookup((yyvsp[0].var).name, &(yyvsp[0].var)) == SYMTAB_NOT_FOUND) {	
							yyerror("SEMANTIC ERROR: VARIABLE NOT FOUND.\n"); errflag = 1; YYERROR;
						} else { 
							addQuad(2, "PARAM", (yyvsp[0].var).name);
														
							if((yyvsp[0].var).type == INTEGER){
								addQuad(3, "CALL", "PUTI", "1");	
							} else {
								addQuad(3, "CALL", "PUTF", "1");	
							}
						}
					}	
					yylineno++;
				}
#line 1291 "calculator.tab.c"
    break;

  case 12: /* statement: id LB INT RB  */
#line 145 "calculator.y"
                               {
				    	char *size_str = (char *)malloc(50);
				    	sprintf(size_str, "%s", (yyvsp[-1].var).place);

				    	customSymEnter((yyvsp[-3].var).name, size_str, ARRAY);
				    	addQuad(3, (yyvsp[-3].var).name, ":= ARRAY", size_str);
				}
#line 1303 "calculator.tab.c"
    break;

  case 13: /* statement: id LB INT RB ASSIGN exp  */
#line 152 "calculator.y"
                                          {
				    	CustomSymbol *sym = customSymLookup((yyvsp[-5].var).name);
				    	if (sym == NULL || sym->type != ARRAY) {
						yyerror("ERROR: La variable no és una taula o no està definida.");
				    	} else {

						char *index = newTemp((yyvsp[-5].var).name);
						addQuad(4, index, "SUBI", (yyvsp[-3].var).place, "1"); // Calcula l'índex correcte (base 1)

						char *addr = newTemp((yyvsp[-5].var).name);
						addQuad(4, addr, "ADDI", sym->name, index); // Adreça base + desplaçament

						addQuad(3, addr, ":=", (yyvsp[0].var).place);
				    	}
				}
#line 1323 "calculator.tab.c"
    break;

  case 14: /* statement: EOL  */
#line 167 "calculator.y"
                                { yylineno++; }
#line 1329 "calculator.tab.c"
    break;

  case 15: /* statement: SCOMMENT  */
#line 168 "calculator.y"
                                { yylineno++; }
#line 1335 "calculator.tab.c"
    break;

  case 16: /* statement: MCOMMENT  */
#line 169 "calculator.y"
                                { yylineno++; }
#line 1341 "calculator.tab.c"
    break;

  case 17: /* statement: END  */
#line 170 "calculator.y"
                                { YYABORT; }
#line 1347 "calculator.tab.c"
    break;

  case 18: /* statement: LERR EOL  */
#line 171 "calculator.y"
                                { yyerror("Error lèxic: caràcter invàlid. (LERR EOL)\n"); yylineno++; }
#line 1353 "calculator.tab.c"
    break;

  case 19: /* statement: LERR  */
#line 172 "calculator.y"
                                { yyerror("Error lèxic: caràcter invàlid. (LERR)\n"); }
#line 1359 "calculator.tab.c"
    break;

  case 20: /* statement: error EOL  */
#line 173 "calculator.y"
                                {	if (errflag == 1) errflag = 0;
					else fprintf(fInfo,"\nLínia %d: Error síntàctic: No hi ha cap regla que coicideixi. (error EOL)\n", yylineno);
					yylineno++;
				}
#line 1368 "calculator.tab.c"
    break;

  case 25: /* arithmetic: arithmetic ADD arithmetic_op1  */
#line 183 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "+", (yyvsp[0].var)); }
#line 1374 "calculator.tab.c"
    break;

  case 26: /* arithmetic: arithmetic SUB arithmetic_op1  */
#line 184 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "-", (yyvsp[0].var)); }
#line 1380 "calculator.tab.c"
    break;

  case 27: /* arithmetic: ADD arithmetic_op1  */
#line 185 "calculator.y"
                                                        { ((yyval.var) = (yyvsp[0].var)); }
#line 1386 "calculator.tab.c"
    break;

  case 28: /* arithmetic: SUB arithmetic_op2  */
#line 186 "calculator.y"
                                                        {	(yyval.var).type = (yyvsp[0].var).type;
								(yyval.var).place = newTemp(NULL);
								
								if ((yyvsp[0].var).type == INTEGER) sprintf((yyval.var).place, "-%s", (yyvsp[0].var).place);
							    	else sprintf((yyval.var).place, "-%s", (yyvsp[0].var).place);

								if((yyvsp[0].var).type == INTEGER) addQuad(3, (yyval.var).place, "CHSI", (yyvsp[0].var).place);
								else addQuad(3, (yyval.var).place, "CHSF", (yyvsp[0].var).place);
							}
#line 1400 "calculator.tab.c"
    break;

  case 30: /* arithmetic_op1: arithmetic_op1 MUL arithmetic_op2  */
#line 197 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "*", (yyvsp[0].var)); }
#line 1406 "calculator.tab.c"
    break;

  case 31: /* arithmetic_op1: arithmetic_op1 DIV arithmetic_op2  */
#line 198 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "/", (yyvsp[0].var)); }
#line 1412 "calculator.tab.c"
    break;

  case 32: /* arithmetic_op1: arithmetic_op1 MOD arithmetic_op2  */
#line 199 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "%", (yyvsp[0].var)); }
#line 1418 "calculator.tab.c"
    break;

  case 34: /* arithmetic_op2: arithmetic_op3 POW arithmetic_op2  */
#line 202 "calculator.y"
                                                        { (yyval.var) = arithmeticCalc((yyvsp[-2].var), "**", (yyvsp[0].var)); }
#line 1424 "calculator.tab.c"
    break;

  case 35: /* arithmetic_op3: LPAREN arithmetic RPAREN  */
#line 204 "calculator.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 1430 "calculator.tab.c"
    break;

  case 36: /* arithmetic_op3: INT  */
#line 205 "calculator.y"
                                                {	if((yyvsp[0].var).type == UNDEFINED) yyerror((yyvsp[0].var).name);
							else (yyval.var) = (yyvsp[0].var);
						}
#line 1438 "calculator.tab.c"
    break;

  case 37: /* arithmetic_op3: FL  */
#line 208 "calculator.y"
                                                { 	if((yyvsp[0].var).type == UNDEFINED) yyerror((yyvsp[0].var).name);
							else (yyval.var) = (yyvsp[0].var);
						}
#line 1446 "calculator.tab.c"
    break;

  case 38: /* arithmetic_op3: A_ID  */
#line 211 "calculator.y"
                                                { 	
							CustomSymbol *sym = customSymLookup((yyvsp[0].var).name);
							if (sym == NULL) {
								yyerror("Error Semàntic: Variable not found (ID).");
							      	(yyval.var) = (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
							} else {
							      	(yyval.var) = (variable){
								 	.type = sym->type,
								  	.place = strdup(sym->value),
								 	.name = strdup((yyvsp[0].var).name)
							      	};
							}
						}
#line 1464 "calculator.tab.c"
    break;

  case 39: /* arithmetic_op3: ID  */
#line 224 "calculator.y"
                                                { 	
							CustomSymbol *sym = customSymLookup((yyvsp[0].var).name);
							if (sym == NULL) {
								yyerror("Error Semàntic: Variable not found (ID).");
							      	(yyval.var) = (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
							} else {
							      	(yyval.var) = (variable){
								  	.type = sym->type,
								  	.place = strdup(sym->value),
								  	.name = strdup((yyvsp[0].var).name)
							      };
							}
						}
#line 1482 "calculator.tab.c"
    break;

  case 40: /* arithmetic_op3: LERR EOL  */
#line 237 "calculator.y"
                                                { (yyval.var).type = UNDEFINED; yyerror("Error lèxic: caràcter invàlid. (LERR EOL 2)\n"); yylineno++; }
#line 1488 "calculator.tab.c"
    break;

  case 41: /* arithmetic_op3: LERR  */
#line 238 "calculator.y"
                                                { (yyval.var).type = UNDEFINED; yyerror("Error lèxic: caràcter invàlid. (LERR 2)\n"); }
#line 1494 "calculator.tab.c"
    break;

  case 42: /* arithmetic_op3: error EOL  */
#line 239 "calculator.y"
                                                {	(yyval.var).type = UNDEFINED;
							if (errflag == 1) errflag = 0;
							else fprintf(fInfo,"\t Error síntàctic: No hi ha cap regla que coicideixi. (error EOL 2)\n");	
							yylineno++;
						}
#line 1504 "calculator.tab.c"
    break;


#line 1508 "calculator.tab.c"

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
      yyerror (YY_("syntax error"));
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 244 "calculator.y"


void yyerror(char *explanation) {
	if (strcmp(explanation, "--- FINAL DE FITXER --- Execució completada :)\n") == 0)	fprintf(fInfo,"%s", explanation);
	else 	fprintf(fInfo,"Línia %d\t%s", yylineno, explanation);
}

void addQuad(int num_args, ...) {
	va_list args;
	va_start(args, num_args);
	
	quad q;
	q.one = (char *)malloc(100);
	q.two = (char *)malloc(100);
	q.three = (char *)malloc(100);
	q.four = (char *)malloc(100);
	  
	if (num_args > 0) strcpy(q.one, va_arg(args, char*));
	if (num_args > 1) strcpy(q.two, va_arg(args, char*));
	if (num_args > 2) strcpy(q.three, va_arg(args, char*));
	if (num_args > 3) strcpy(q.four, va_arg(args, char*));

	quad_list[currQuad] = q;
		
	currQuad++;
	va_end(args);
}

char *newTemp(const char *prefix) {
   	char *tempPointer = (char *)malloc(50);
	
    	if (prefix) sprintf(tempPointer, "$%s_t%d", prefix, temp++);
     	else sprintf(tempPointer, "$t%d", temp++);

    	return tempPointer;
}


variable arithmeticCalc(variable v1, char *op, variable v2) {
    	variable result = {.type = UNDEFINED};
    	result.place = (char *)malloc(100);
    
    	if(strcmp(op, "**")==0) return powFunction(v1, v2, v1.name);
    	
	// Busca els valors a la taula de símbols
	CustomSymbol *sym1 = customSymLookup(v1.place);
	CustomSymbol *sym2 = customSymLookup(v2.place);

    	if (sym1 != NULL) v1.place = sym1->value;
    	if (sym2 != NULL) v2.place = sym2->value;

    	// Tractament per a tipus enters
    	if (v1.type == INTEGER && v2.type == INTEGER) {
        	result.type = INTEGER;
        	strcpy(result.place, newTemp(NULL));

		int val1 = atoi(v1.place);
		int val2 = atoi(v2.place);
		char tempValue[50];
		if (strcmp(op, "+") == 0) {		
			addQuad(4, result.place, "ADDI", v1.place, v2.place);		// SUMA
			sprintf(tempValue, "%d", val1 + val2);
		} else if (strcmp(op, "-") == 0) {
			addQuad(4, result.place, "SUBI", v1.place, v2.place);		// RESTA
			sprintf(tempValue, "%d", val1 - val2);
		} else if (strcmp(op, "*") == 0) {
			addQuad(4, result.place, "MULI", v1.place, v2.place);		// MULT
			sprintf(tempValue, "%d", val1 * val2);
		} else if (strcmp(op, "/") == 0) {
			if (strcmp(v2.place, "0") == 0) {
				fprintf(fInfo, "ERROR: Division by zero a la línia %d\n", yylineno);
       				return (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" };
		    	}
			addQuad(4, result.place, "DIVI", v1.place, v2.place);
		    	sprintf(tempValue, "%d", val1 / val2);				// DIV
		} else if (strcmp(op, "%") == 0) {		
			if (strcmp(v2.place, "0") == 0) {
				fprintf(fInfo, "ERROR: Modulo by zero a la línia %d\n", yylineno);
        			return (variable){ .type = UNDEFINED, .place = "SEMANTIC ERROR" }; 
			}     
			sprintf(result.place, "%d", val1 % val2);
			addQuad(4, result.place, "MODI", v1.place, v2.place);		// MOD
		}

		customSymEnter(result.place, tempValue, INTEGER);
    	} else if ((v1.type == INTEGER || v1.type == FLOAT) && (v2.type == INTEGER || v2.type == FLOAT)) {
        	result.type = FLOAT;

		float val1 = atof(v1.place);
		float val2 = atof(v2.place);
		char tempValue[50];

        	if (v1.type == INTEGER) {
			char *temp = newTemp(NULL);
			addQuad(3, temp, "I2F", v1.place);
		    	sprintf(temp, "%.2f", atof(v1.place)); // Conversió
		    	v1.place = temp;
		    	v1.type = FLOAT;
        	}
        	if (v2.type == INTEGER) {
            		char *temp = newTemp(NULL);
            		addQuad(3, temp, "I2F", v2.place);
            		sprintf(temp, "%.2f", atof(v2.place)); // Conversió
            		v2.place = temp;
            		v2.type = FLOAT;
        	}

        	strcpy(result.place, newTemp(NULL));

        	if (strcmp(op, "+") == 0) {
        		addQuad(4, result.place, "ADDF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 + val2);
        	} else if (strcmp(op, "-") == 0) {
        		addQuad(4, result.place, "SUBF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 - val2);
        	} else if (strcmp(op, "*") == 0) {
        		addQuad(4, result.place, "MULF", v1.place, v2.place);
        		sprintf(tempValue, "%.2f", val1 * val2);
        	} else if (strcmp(op, "/") == 0) {
           		if (atof(v2.place) == 0.0) {
				strcpy(result.place, "SEMANTIC ERROR: Division by zero");
				return result;
            		}
            		addQuad(4, result.place, "DIVF", v1.place, v2.place);
            		sprintf(tempValue, "%.2f", val1 / val2);
        	}

        	customSymEnter(result.place, tempValue, FLOAT);
	} else {
		result.type = UNDEFINED;
		strcpy(result.place, "SEMANTIC ERROR: Invalid operation");
    	}
    	return result;
}

long potenciaRecursiva(long base, long exponent) {
	if (exponent == 0) return 1;
    	else return base * potenciaRecursiva(base, exponent - 1);
}

variable powFunction(variable v1, variable v2, char* assign_name) {
    	variable result;
    	result.place = (char *)malloc(100);

    	if (v2.type != INTEGER) {
        	result.type = UNDEFINED;
        	strcpy(result.place, "SEMANTIC ERROR: L'exponent ha de ser enter.");
        	return result;
    	}

    	long base = atol(v1.place);
    	long exponent = atol(v2.place);

    	if (exponent < 0) {
        	result.type = UNDEFINED;
        	strcpy(result.place, "SEMANTIC ERROR: Exponent negatiu no suportat.");
        	return result;
    	}

    	long result_value = potenciaRecursiva(base, exponent); // Calcula la potència

	result.type = v1.type;
    	sprintf(result.place, "%ld", result_value);

    	addQuad(4, assign_name, "POWI", v1.place, v2.place);

    	customSymEnter(assign_name, result.place, result.type);

    	return result;
}

void printQuads() {
    	if (currQuad == 0) {
        	printf("quad_list is empty\n");
        	return;
    	}

    	int i = 0;
    	for (int i = 0; i < currQuad; i++) {
        	quad *q = &quad_list[i];

        	// Manté el nom original de q->one i busca el seu valor real
		char *destValue = q->one;
		CustomSymbol *symOne = customSymLookup(q->one);
		if (symOne != NULL) destValue = symOne->value;

		// Busca els valors reals dels operands de la dreta (q->three i q->four)
		char *valueThree = q->three;
		char *valueFour = q->four;

		CustomSymbol *symThree = customSymLookup(q->three);
		if (symThree != NULL) valueThree = symThree->value;

		CustomSymbol *symFour = customSymLookup(q->four);
		if (symFour != NULL) valueFour = symFour->value;

		// Maneig de quads segons el tipus
		if (strcmp(q->one, "PARAM") == 0)		printf("%d: PARAM %s\n", i + 1, q->two);
		else if (strcmp(q->one, "CALL") == 0)		printf("%d: CALL %s, %s\n", i + 1, q->two, q->three);
		else if (strcmp(q->two, "I2F") == 0)		printf("%d: %s := I2F %s\n", i + 1, q->one, valueThree);
		else if (strcmp(q->two, "CHSI") == 0)		printf("%d: %s := CHSI %s\n", i + 1, q->one, valueThree);
		else if (strcmp(q->two, "MODI") == 0)		printf("%d: %s := MODI %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, "MODF") == 0)		printf("%d: %s := MODF %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, ":=") == 0)		printf("%d: %s := %s\n", i + 1, q->one, q->three);
		else if (q->one[0] == '$')			printf("%d: %s := %s %s %s\n", i + 1, q->one, q->two, q->three, q->four);
		else if (strcmp(q->two, "POWI") == 0)		printf("%d: %s := POWI %s, %s\n", i + 1, q->one, valueThree, valueFour);
		else if (strcmp(q->two, "ADDI") == 0)		printf("%d: %s := ADDI %s, %s\n", i + 1, q->one, q->three, q->four); // pel comptador del bucle
		else if (strcmp(q->one, "GOTO") == 0)		printf("%d: GOTO %s\n", i + 1, q->two);
		/*else if (strcmp(q->one, "IF_FALSE") == 0) {
			CustomSymbol *cond = customSymLookup(q->two);
			if (cond != NULL && strcmp(cond->value, "0") == 0) {
				// La condició és falsa, saltem a l'etiqueta
				//printf("DEBUG: Saltant a %s (condició falsa)\n", q->three);
				for (int j = 0; j < currQuad; j++) {
				    if (strcmp(quad_list[j].one, q->three) == 0) {
					i = j - 1;  // Ajusta l'índex per continuar l'execució des de l'etiqueta
					break;
				    }
				}
			}
		} */ 
		else if (strcmp(q->two, "LTI") == 0) {
			printf("%d: %s := LTI %s, %s\n", i + 1, q->one, q->three, q->four);
		
		    	int v1 = atoi(q->three);
		    	int v2 = atoi(q->four);

		   	if (v1 < v2)	customSymEnter(q->one, "1", INTEGER);	// Afegeix l'entrada a la taula de símbols amb resultat 1 (true)
		    	else 	customSymEnter(q->one, "0", INTEGER);	// Afegeix l'entrada a la taula de símbols amb resultat 0 (false)
		
		} else if (strcmp(q->two, ":= ARRAY") == 0)	printf("%d: %s := ARRAY [%s]\n", i + 1, q->one, q->three);
		else printf("%d: %s := %s\n", i + 1, q->one, destValue);
   	}
    	printf("%d: HALT\n", i + 1);
}


void customSymEnter(char *name, char *value, int type) {
	
	// Comprova si és una variable temporal i la ignora
	if (name[0] == '$' && strstr(name, "_t") != NULL) {
		return; // No afegir temporals
	}
	
	for (int i = 0; i < customSymtabCount; i++) {
        	if (strcmp(customSymtab[i].name, name) == 0) {
            		free(customSymtab[i].value);
            		customSymtab[i].value = strdup(value);
			customSymtab[i].type = type;
			
            		// Detecta si el nom té un prefix associat a una taula i ajusta el tipus
            		/*if (type == INTEGER && strstr(name, "_t") != NULL)	customSymtab[i].type = ARRAY;
            		else customSymtab[i].type = type;*/
            		return;
        	}
    	}

    	if (customSymtabCount < CUSTOM_MAX_SYMBOLS) {
        	customSymtab[customSymtabCount].name = strdup(name);
        	customSymtab[customSymtabCount].value = strdup(value);
		customSymtab[customSymtabCount].type = type;
		
		// Detecta si el nom té un prefix associat a una taula i ajusta el tipus
		/*if (type == INTEGER && strstr(name, "_t") != NULL) {
		    customSymtab[customSymtabCount].type = ARRAY;
		} else {
		    customSymtab[customSymtabCount].type = type;
		}*/

        	customSymtabCount++;
	} else {
		printf("Error: Taula de símbols plena!\n");
	}
}

CustomSymbol *customSymLookup(char *name) {
	for (int i = 0; i < customSymtabCount; i++) {
        	if (strcmp(customSymtab[i].name, name) == 0)	return &customSymtab[i];
    	}
    	return NULL;
}

void mostrarCustomSymtab() {
    fprintf(fInfo, "Mostrant la taula de símbols personalitzada:\n");
    for (int i = 0; i < customSymtabCount; i++) {
        fprintf(fInfo, "Variable %s:\n\t->Valor: %s\n\t->Tipus: %s\n",
       customSymtab[i].name,
       customSymtab[i].value,
       customSymtab[i].type == INTEGER ? "INTEGER" :
       customSymtab[i].type == FLOAT ? "FLOAT" :
       customSymtab[i].type == ARRAY ? "ARRAY" : "UNDEFINED");
    }
}

int main(int argc, char** argv) {

    fInfo = fopen("sortida_proves.txt", "w");
    
    if (fInfo == NULL) {
        printf("Error: Unable to open log file sortida_proves.txt\n");
        return 1;
    }

    // Comprova si s'ha passat un fitxer d'entrada
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("Error: Unable to open file %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("Error: No input file specified\n");
        return 1;
    }

    quad_list = (quad *)malloc(sizeof(quad) * MAX_QUADS);
    if (quad_list == NULL) {
    	printf("Error: No s'ha pogut al·locar memòria per a quad_list\n");
    	exit(1);
    }
    yyparse();

    mostrarCustomSymtab();
    printQuads();
    free(quad_list);

    if (fclose(fInfo) != 0) {
        printf("Error: Unable to close log file sortida_proves.txt\n");
        return 1;
    }

    return 0;
}


