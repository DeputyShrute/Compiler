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
#line 1 "snazzle.y" /* yacc.c:339  */

  #include <cstdio>
  #include <iostream>
  #include <string>
    #include <string.h>
  using namespace std;



  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern int newLine;
  extern FILE *yyin;
   FILE *output=fopen("output.s", "w");
  void yyerror(const char *s);
  int loop = 0;
  int if_ = 0;
 

#line 87 "snazzle.tab.c" /* yacc.c:339  */

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
   by #include "snazzle.tab.h".  */
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
#line 23 "snazzle.y" /* yacc.c:355  */

  char* val;
  int integer;



#line 167 "snazzle.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SNAZZLE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 184 "snazzle.tab.c" /* yacc.c:358  */

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  6
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    88,    95,   102,   111,   117,   123,   129,
     135,   142,   145,   148,   149,   150,   151,   152,   157,   158,
     159,   163,   164,   168,   169,   172,   175,   181,   182,   184,
     185,   186,   187,   192,   197,   202,   209,   216,   221,   226,
     231,   238,   243,   248,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "FUNCTION", "LOOP", "ENDFOR",
  "ENDNESTFOR", "IF", "ENDIF", "ELSE", "EQ", "GT", "LT", "GT_EQ", "LT_EQ",
  "VAR_DECLARATION", "IDENTIFIER", "INCREMENT", "DECREMENT", "OPEN_ROUND",
  "CLOSE_ROUND", "OPEN_CURLY", "CLOSE_CURLY", "SPEECH_MARK", "ASSIGNMENT",
  "INTEGER", "STRING", "PLUS", "MINUS", "DIVIDE", "TIMES", "SEMI_COLON",
  "$accept", "stmt", "function_type", "compound_stmt",
  "variable_definition", "expr", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -17

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-17)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,    84,   -15,   -11,    12,    21,     0,   -16,   -17,   -16,
     -17,   -17,   -17,    45,    22,    44,    23,   106,   -17,    39,
      28,    52,    32,   -16,   -16,   -16,   -16,   -16,   345,   353,
     358,   366,    65,   150,   171,   -17,   -17,    -3,   -17,   -17,
     -16,   -16,   -16,   -16,   -16,   -17,   -17,   -16,   -16,   -16,
     -16,   -17,    41,   -16,    51,    56,   115,   371,    40,    40,
      40,    40,   318,    65,   388,    65,   388,    65,   339,    65,
     339,   -17,   -17,    42,    43,   -17,   -17,    40,    40,    40,
      40,   388,   388,   339,   339,   -17,   192,   -17,    66,   -16,
     -16,   -16,   -16,   -16,    49,   318,   -17,   -17,    69,    71,
     213,   234,   255,   276,   297,   -17,    67,   -17,   -17,   -17,
     -17,   -17,   -16,   128,     8,    70,    75,    77,    82,   -17,
     -17
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    23,     0,     0,    21,     0,
      27,    28,    17,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    15,     2,    22,    14,
       0,     0,     0,     0,     0,    44,    45,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,     0,    48,    46,
      49,    47,    26,    43,    39,    41,    37,    40,    36,    42,
      38,    29,    30,     0,     0,    11,    31,    52,    50,    53,
      51,    32,    33,    35,    34,    19,     0,    20,     0,     0,
       0,     0,     0,     0,    27,    24,     3,    12,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     8,     7,     6,
      10,     9,     0,     0,     0,     0,     0,     0,     0,     4,
       5
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,    38,   -17,   -17,   -17,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    16,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    32,    34,    73,     7,    19,    74,    75,     9,    20,
      10,    11,    23,    24,    25,    26,    58,    59,    60,    61,
      62,    64,    66,    68,    70,    27,   115,   116,    28,    29,
      30,    31,    21,    76,    77,    78,    79,    80,    22,    18,
      81,    82,    83,    84,    55,    35,    86,     1,     2,     3,
      95,    40,     4,    38,    36,    39,    52,    57,    45,    46,
       5,     6,    85,    53,     7,    54,     8,    37,     9,    56,
      10,    11,    87,    88,    96,    97,    12,    23,    24,    25,
      26,   -25,   100,   101,   102,   103,   104,     1,     2,     3,
     105,    99,     4,    28,    29,    30,    31,   106,   119,   112,
       5,     6,   117,   120,     7,   113,     8,   118,     9,     0,
      10,    11,     0,     0,     0,     0,    12,    40,    41,    42,
      43,    44,     0,     0,    45,    46,    89,    90,    91,    92,
      93,     0,     0,     0,    47,    48,    49,    50,    51,    40,
      41,    42,    43,    44,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,    49,    50,
     114,    40,    41,    42,    43,    44,     0,     0,    45,    46,
       0,    71,     0,     0,     0,     0,     0,     0,    47,    48,
      49,    50,    40,    41,    42,    43,    44,     0,     0,    45,
      46,     0,     0,     0,     0,    72,     0,     0,     0,    47,
      48,    49,    50,    40,    41,    42,    43,    44,     0,     0,
      45,    46,     0,     0,     0,     0,    98,     0,     0,     0,
      47,    48,    49,    50,    40,    41,    42,    43,    44,     0,
       0,    45,    46,     0,   107,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    40,    41,    42,    43,    44,
       0,     0,    45,    46,     0,   108,     0,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    40,    41,    42,    43,
      44,     0,     0,    45,    46,     0,   109,     0,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    40,    41,    42,
      43,    44,     0,     0,    45,    46,     0,   110,     0,     0,
       0,     0,     0,     0,    47,    48,    49,    50,    40,    41,
      42,    43,    44,     0,     0,    45,    46,     0,   111,     0,
       0,     0,     0,     0,     0,    47,    48,    49,    50,    40,
      41,    42,    43,    44,     0,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      40,    41,    42,    43,    44,     0,     0,    45,    46,     0,
       0,     0,    63,     0,     0,     7,     0,    47,    48,     9,
      65,    10,    11,     7,     0,    67,     0,     9,     7,    10,
      11,     0,     9,    69,    10,    11,     7,     0,    32,     0,
       9,     7,    10,    11,     0,     9,     0,    94,    11,    40,
      41,    42,    43,    44,     0,     0,    45,    46
};

static const yytype_int8 yycheck[] =
{
       7,    17,     9,     6,    20,    20,     9,    10,    24,    20,
      26,    27,    12,    13,    14,    15,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    25,    18,    19,    28,    29,
      30,    31,    20,    40,    41,    42,    43,    44,    17,     1,
      47,    48,    49,    50,    16,     0,    53,     3,     4,     5,
      57,    11,     8,    15,    32,    32,    17,    25,    18,    19,
      16,    17,    21,    24,    20,    26,    22,    23,    24,    17,
      26,    27,    21,    17,    32,    32,    32,    12,    13,    14,
      15,    32,    89,    90,    91,    92,    93,     3,     4,     5,
      21,    25,     8,    28,    29,    30,    31,    26,    21,    32,
      16,    17,    32,    21,    20,   112,    22,    32,    24,    -1,
      26,    27,    -1,    -1,    -1,    -1,    32,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    28,    29,    30,    31,    32,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    11,    12,    13,    14,    15,    -1,    -1,    18,
      19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,    28,
      29,    30,    31,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    11,    12,    13,    14,    15,    -1,
      -1,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    31,    11,    12,    13,    14,
      15,    -1,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    30,    31,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    11,    12,
      13,    14,    15,    -1,    -1,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      11,    12,    13,    14,    15,    -1,    -1,    18,    19,    -1,
      -1,    -1,    17,    -1,    -1,    20,    -1,    28,    29,    24,
      17,    26,    27,    20,    -1,    17,    -1,    24,    20,    26,
      27,    -1,    24,    17,    26,    27,    20,    -1,    17,    -1,
      24,    20,    26,    27,    -1,    24,    -1,    26,    27,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     8,    16,    17,    20,    22,    24,
      26,    27,    32,    34,    35,    36,    37,    38,    34,    20,
      20,    20,    17,    12,    13,    14,    15,    25,    28,    29,
      30,    31,    17,    38,    38,     0,    32,    23,    34,    32,
      11,    12,    13,    14,    15,    18,    19,    28,    29,    30,
      31,    32,    17,    24,    26,    16,    17,    25,    38,    38,
      38,    38,    38,    17,    38,    17,    38,    17,    38,    17,
      38,    21,    24,     6,     9,    10,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    21,    38,    21,    17,    11,
      12,    13,    14,    15,    26,    38,    32,    32,    24,    25,
      38,    38,    38,    38,    38,    21,    26,    21,    21,    21,
      21,    21,    32,    38,    32,    18,    19,    32,    32,    21,
      21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    35,    35,
      35,    36,    36,    37,    37,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,    12,    12,     6,     6,     6,     6,
       6,     3,     4,     2,     2,     2,     2,     1,     6,     4,
       4,     1,     2,     1,     4,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3
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
        case 3:
#line 89 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "popl %%ecx\n");
                            fprintf(output, "addl $1, %%ecx\n");
                            fprintf(output, "jmp loop_start_%d\n",loop);
                            fprintf(output, "end_loop_%d:\n", loop );loop--;}
#line 1394 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "snazzle.y" /* yacc.c:1646  */
    {loop++;fprintf(output, "movl $%s, %%ecx\n", (yyvsp[-6].val));
                            fprintf(output, "loop_start_%d:\n",loop);
                            fprintf(output, "cmpl $%s, %%ecx\n", (yyvsp[-4].val));
                            fprintf(output, "je end_loop_%d\n",loop);
                            fprintf(output, "pushl %%ecx\n");}
#line 1404 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 103 "snazzle.y" /* yacc.c:1646  */
    {loop++; fprintf(output, "movl $%s, %%ecx\n", (yyvsp[-6].val));
                            fprintf(output, "loop_start_%d:\n", loop);
                            fprintf(output, "subl $1, %%ecx\n");
                            fprintf(output, "cmpl $%s, %%ecx\n", (yyvsp[-4].val));
                            fprintf(output, "je end_loop_%d\n", loop);
                            fprintf(output, "pushl %%ecx\n");}
#line 1415 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 112 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output,"cmpl $%s, %s\n",(yyvsp[-1].val),(yyvsp[-3].val) );
                            fprintf(output, "jl if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}
#line 1424 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 118 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output,"cmpl $%s, %s\n",(yyvsp[-1].val),(yyvsp[-3].val));
                            fprintf(output, "jg if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}
#line 1433 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output,"cmpl $%s, %s\n",(yyvsp[-1].val),(yyvsp[-3].val));
                            fprintf(output, "je if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}
#line 1442 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 130 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output,"cmpl $%s, %s\n",(yyvsp[-1].val),(yyvsp[-3].val) );
                            fprintf(output, "jle if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}
#line 1451 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 136 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output,"cmpl $%s, %s\n",(yyvsp[-1].val),(yyvsp[-3].val));
                            fprintf(output, "jge if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}
#line 1460 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 143 "snazzle.y" /* yacc.c:1646  */
    {if_--;fprintf(output,"jmp end%d\nelse%d:\n",if_,if_ );if_++;}
#line 1466 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 146 "snazzle.y" /* yacc.c:1646  */
    {if_--;fprintf(output,"end%d:\n",if_);if_++;}
#line 1472 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 157 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1478 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1484 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 159 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1490 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 163 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1496 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 164 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1502 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1508 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 170 "snazzle.y" /* yacc.c:1646  */
    { fprintf(output, "movl %%ebx, %s\n", (yyvsp[-2].val));}
#line 1514 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 173 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %s\n",(yyvsp[0].val), (yyvsp[-2].val));}
#line 1520 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "snazzle.y" /* yacc.c:1646  */
    { fprintf(output, "movl %%ebx, %s\n", (yyvsp[-2].val));}
#line 1526 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 184 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1532 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 185 "snazzle.y" /* yacc.c:1646  */
    { }
#line 1538 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 188 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "addl %%eax, %%ebx\n"); }
#line 1546 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 193 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %%eax\n",(yyvsp[0].val));
                            fprintf(output, "movl $%s, %%ebx\n",(yyvsp[-2].val));
                            fprintf(output, "subl %%eax, %%ebx\n");}
#line 1554 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %%eax\n",(yyvsp[-2].val));
                           fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                           fprintf(output, "imull %%eax, %%ebx\n");}
#line 1562 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 203 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %%eax\n",(yyvsp[-2].val));
                           fprintf(output, "movl $0, %%edx\n");
                           fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                           fprintf(output, "divl %%ebx\n");
                           fprintf(output, "movl %%eax, %%ebx\n");}
#line 1572 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 210 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl $0, %%edx\n");
                            fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "divl %%ebx\n");
                            fprintf(output, "movl %%eax, %%ebx\n");}
#line 1582 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 217 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl $%s, %%eax\n",(yyvsp[0].val));
                            fprintf(output, "movl %s, %%ebx\n",(yyvsp[-2].val));
                            fprintf(output, "subl %%eax, %%ebx\n");}
#line 1590 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 222 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "imull %%eax, %%ebx\n");}
#line 1598 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 227 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl $%s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "addl %%eax, %%ebx\n");}
#line 1606 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 232 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl $0, %%edx\n");
                            fprintf(output, "movl %s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "divl %%ebx\n");
                            fprintf(output, "movl %%eax, %%ebx\n");}
#line 1616 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 239 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[0].val));
                            fprintf(output, "movl %s, %%ebx\n",(yyvsp[-2].val));
                            fprintf(output, "subl %%eax, %%ebx\n");}
#line 1624 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 244 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl %s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "imull %%eax, %%ebx\n");}
#line 1632 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 249 "snazzle.y" /* yacc.c:1646  */
    {fprintf(output, "movl %s, %%eax\n",(yyvsp[-2].val));
                            fprintf(output, "movl %s, %%ebx\n",(yyvsp[0].val));
                            fprintf(output, "addl %%eax, %%ebx\n"); }
#line 1640 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 252 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1646 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 253 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1652 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 254 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1658 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 255 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1664 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 256 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1670 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 257 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1676 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 258 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1682 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 259 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1688 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 260 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1694 "snazzle.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 261 "snazzle.y" /* yacc.c:1646  */
    {(yyval.val) = (yyvsp[0].val);}
#line 1700 "snazzle.tab.c" /* yacc.c:1646  */
    break;


#line 1704 "snazzle.tab.c" /* yacc.c:1646  */
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
#line 264 "snazzle.y" /* yacc.c:1906  */



int main(int, char**) {
  #ifdef YYDEBUG
  yydebug = 1;
  #endif

  // Open a file handle to a particular file:
  FILE *myfile = fopen("a.snazzle.file", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open a.snazzle.file!" << endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;

  fprintf(output, ".code32\n");
  fprintf(output, ".section .text\n");
  fprintf(output, ".section .data\n");
  fprintf(output, "a:\n.long 0\n");
  fprintf(output, "b:\n.long 0\n"); 
  fprintf(output, "c:\n.long 0\n");
  fprintf(output, "d:\n.long 0\n"); 
  fprintf(output, "e:\n.long 0\n");
  fprintf(output, "f:\n.long 0\n");
  fprintf(output, "g:\n.long 0\n"); 
  fprintf(output, "h:\n.long 0\n");
  fprintf(output, "i:\n.long 0\n"); 
  fprintf(output, "j:\n.long 0\n");
  fprintf(output, "k:\n.long 0\n");
  fprintf(output, "l:\n.long 0\n"); 
  fprintf(output, "m:\n.long 0\n");
  fprintf(output, "n:\n.long 0\n"); 
  fprintf(output, "o:\n.long 0\n");
  fprintf(output, "p:\n.long 0\n");
  fprintf(output, "q:\n.long 0\n"); 
  fprintf(output, "r:\n.long 0\n");
  fprintf(output, "s:\n.long 0\n"); 
  fprintf(output, "t:\n.long 0\n");
  fprintf(output, "u:\n.long 0\n");
  fprintf(output, "v:\n.long 0\n"); 
  fprintf(output, "w:\n.long 0\n");
  fprintf(output, "x:\n.long 0\n"); 
  fprintf(output, "y:\n.long 0\n");

  fprintf(output, "z:\n.long 0\n"); 
  fprintf(output, "space:\n.ascii \" \"\n");
  fprintf(output, ".globl _start\n");
  fprintf(output, "_start:\n"); 
  

  // Parse through the input:
  yyparse();

 //ending code to add each digit to a stack and print each variabl
  fprintf(output, "movl z, %%eax\n");
  fprintf(output, "xorl %%esi, %%esi\n");
    
  fprintf(output, "printz:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movey\n");
  fprintf(output, "jmp printz\n");

  fprintf(output, "movey:\n");
  fprintf(output, "movl y, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp printy\n");

  fprintf(output, "printy:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movex\n");
  fprintf(output, "jmp printy\n");

  fprintf(output, "movex:\n");
  fprintf(output, "movl x, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printx\n");

  fprintf(output, "printx:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movew\n");
  fprintf(output, "jmp printx\n");

  fprintf(output, "movew:\n");
  fprintf(output, "movl w, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printw\n");

  fprintf(output, "printw:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movev\n");
  fprintf(output, "jmp printw\n");

  fprintf(output, "movev:\n");
  fprintf(output, "movl v, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printv\n");

  fprintf(output, "printv:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveu\n");
  fprintf(output, "jmp printv\n");

  fprintf(output, "moveu:\n");
  fprintf(output, "movl u, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printu\n");

  fprintf(output, "printu:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movet\n");
  fprintf(output, "jmp printu\n");

  fprintf(output, "movet:\n");
  fprintf(output, "movl t, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp printt\n");

  fprintf(output, "printt:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moves\n");
  fprintf(output, "jmp printt\n");

  fprintf(output, "moves:\n");
  fprintf(output, "movl s, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp prints\n");

  fprintf(output, "prints:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz mover\n");
  fprintf(output, "jmp prints\n");

  fprintf(output, "mover:\n");
  fprintf(output, "movl r, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printr\n");

  fprintf(output, "printr:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveq\n");
  fprintf(output, "jmp printr\n");

  fprintf(output, "moveq:\n");
  fprintf(output, "movl q, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printq\n");

  fprintf(output, "printq:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movep\n");
  fprintf(output, "jmp printq\n");

  fprintf(output, "movep:\n");
  fprintf(output, "movl p, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printp\n");

  fprintf(output, "printp:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveo\n");
  fprintf(output, "jmp printp\n");

  fprintf(output, "moveo:\n");
  fprintf(output, "movl o, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printo\n");

  fprintf(output, "printo:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moven\n");
  fprintf(output, "jmp printo\n");

  fprintf(output, "moven:\n");
  fprintf(output, "movl n, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printn\n");

  fprintf(output, "printn:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movem\n");
  fprintf(output, "jmp printn\n");

  fprintf(output, "movem:\n");
  fprintf(output, "movl m, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printm\n");

  fprintf(output, "printm:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movel\n");
  fprintf(output, "jmp printm\n");

  fprintf(output, "movel:\n");
  fprintf(output, "movl l, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printl\n");

  fprintf(output, "printl:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movek\n");
  fprintf(output, "jmp printl\n");

  fprintf(output, "movek:\n");
  fprintf(output, "movl k, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printk\n");

  fprintf(output, "printk:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movej\n");
  fprintf(output, "jmp printk\n");

  fprintf(output, "movej:\n");
  fprintf(output, "movl j, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printj\n");

  fprintf(output, "printj:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movei\n");
  fprintf(output, "jmp printj\n");

  fprintf(output, "movei:\n");
  fprintf(output, "movl i, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printi\n");

  fprintf(output, "printi:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveh\n");
  fprintf(output, "jmp printi\n");

  fprintf(output, "moveh:\n");
  fprintf(output, "movl h, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printh\n");

  fprintf(output, "printh:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveg\n");
  fprintf(output, "jmp printh\n");

  fprintf(output, "moveg:\n");
  fprintf(output, "movl g, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printg\n");

  fprintf(output, "printg:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movef\n");
  fprintf(output, "jmp printg\n");

  fprintf(output, "movef:\n");
  fprintf(output, "movl f, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printf\n");

  fprintf(output, "printf:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movee\n");
  fprintf(output, "jmp printf\n");

  fprintf(output, "movee:\n");
  fprintf(output, "movl e, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printe\n");

  fprintf(output, "printe:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moved\n");
  fprintf(output, "jmp printe\n");

  fprintf(output, "moved:\n");
  fprintf(output, "movl d, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printd\n");

  fprintf(output, "printd:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movec\n");
  fprintf(output, "jmp printd\n");

  fprintf(output, "movec:\n");
  fprintf(output, "movl c, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printc\n");

  fprintf(output, "printc:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveb\n");
  fprintf(output, "jmp printc\n");

  fprintf(output, "moveb:\n");
  fprintf(output, "movl b, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printb\n");

  fprintf(output, "printb:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movea\n");
  fprintf(output, "jmp printb\n");

  fprintf(output, "movea:\n");
  fprintf(output, "movl a, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printa\n");

  fprintf(output, "printa:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz next\n");
  fprintf(output, "jmp printa\n");

  fprintf(output, "next:\n");
  fprintf(output, "cmpl $0, %%esi\n");
  fprintf(output, "jz exit\n");
  fprintf(output, "decl %%esi\n");
  fprintf(output, "movl $4, %%eax\n");
  fprintf(output, "movl %%esp, %%ecx\n");
  fprintf(output, "movl $1, %%ebx\n");
  fprintf(output, "movl $1, %%edx\n");
  fprintf(output, "int $0x80\n");
  fprintf(output, "addl $4, %%esp\n");
  fprintf(output, "jmp next\n");

  fprintf(output, "exit:\n");
  fprintf(output, "movl $1, %%eax\n");
  fprintf(output, "int $0x80\n"); 

}

void yyerror(const char *s) {
  cout << "Parse error!" << endl;
  cout << "Message: " << s << " on line: " << newLine << endl;
  exit(-1);
}
