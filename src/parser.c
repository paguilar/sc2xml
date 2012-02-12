/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 19 "parser.y"


#include <stdio.h>
#include <libxml/tree.h>

#include "xml.h"



/* Line 268 of yacc.c  */
#line 81 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     STRING_LITERAL = 260,
     SIZEOF = 261,
     PTR_OP = 262,
     INC_OP = 263,
     DEC_OP = 264,
     LEFT_OP = 265,
     RIGHT_OP = 266,
     LE_OP = 267,
     GE_OP = 268,
     EQ_OP = 269,
     NE_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     MUL_ASSIGN = 273,
     DIV_ASSIGN = 274,
     MOD_ASSIGN = 275,
     ADD_ASSIGN = 276,
     SUB_ASSIGN = 277,
     LEFT_ASSIGN = 278,
     RIGHT_ASSIGN = 279,
     AND_ASSIGN = 280,
     XOR_ASSIGN = 281,
     OR_ASSIGN = 282,
     TYPE_NAME = 283,
     TYPEDEF = 284,
     EXTERN = 285,
     STATIC = 286,
     AUTO = 287,
     REGISTER = 288,
     CHAR = 289,
     SHORT = 290,
     INT = 291,
     LONG = 292,
     SIGNED = 293,
     UNSIGNED = 294,
     FLOAT = 295,
     DOUBLE = 296,
     CONST = 297,
     VOLATILE = 298,
     VOID = 299,
     STRUCT = 300,
     UNION = 301,
     ENUM = 302,
     ELLIPSIS = 303,
     CASE = 304,
     DEFAULT = 305,
     IF = 306,
     ELSE = 307,
     SWITCH = 308,
     WHILE = 309,
     DO = 310,
     FOR = 311,
     GOTO = 312,
     CONTINUE = 313,
     BREAK = 314,
     RETURN = 315
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define PTR_OP 262
#define INC_OP 263
#define DEC_OP 264
#define LEFT_OP 265
#define RIGHT_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define AND_OP 271
#define OR_OP 272
#define MUL_ASSIGN 273
#define DIV_ASSIGN 274
#define MOD_ASSIGN 275
#define ADD_ASSIGN 276
#define SUB_ASSIGN 277
#define LEFT_ASSIGN 278
#define RIGHT_ASSIGN 279
#define AND_ASSIGN 280
#define XOR_ASSIGN 281
#define OR_ASSIGN 282
#define TYPE_NAME 283
#define TYPEDEF 284
#define EXTERN 285
#define STATIC 286
#define AUTO 287
#define REGISTER 288
#define CHAR 289
#define SHORT 290
#define INT 291
#define LONG 292
#define SIGNED 293
#define UNSIGNED 294
#define FLOAT 295
#define DOUBLE 296
#define CONST 297
#define VOLATILE 298
#define VOID 299
#define STRUCT 300
#define UNION 301
#define ENUM 302
#define ELLIPSIS 303
#define CASE 304
#define DEFAULT 305
#define IF 306
#define ELSE 307
#define SWITCH 308
#define WHILE 309
#define DO 310
#define FOR 311
#define GOTO 312
#define CONTINUE 313
#define BREAK 314
#define RETURN 315




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 243 "parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1371

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  228
/* YYNRULES -- Number of states.  */
#define YYNSTATES  371

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    63,    68,    70,    72,    74,    76,    78,    80,    82,
      87,    89,    93,    97,   101,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   135,   139,   141,   145,   149,   151,
     155,   157,   161,   163,   167,   169,   173,   175,   179,   181,
     187,   189,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   221,   223,   226,   230,   232,
     235,   237,   240,   242,   245,   247,   250,   252,   256,   258,
     262,   264,   266,   268,   270,   272,   274,   276,   278,   280,
     282,   284,   286,   288,   290,   292,   294,   296,   297,   304,
     305,   311,   314,   316,   318,   320,   323,   327,   328,   332,
     334,   337,   339,   340,   344,   346,   349,   351,   354,   356,
     358,   362,   364,   367,   371,   376,   382,   385,   387,   390,
     394,   396,   400,   402,   404,   407,   409,   411,   415,   420,
     424,   425,   431,   436,   437,   442,   450,   452,   455,   458,
     462,   464,   467,   469,   473,   475,   479,   482,   485,   487,
     489,   493,   495,   498,   500,   502,   505,   509,   512,   516,
     520,   525,   528,   532,   536,   541,   543,   547,   552,   554,
     558,   560,   562,   564,   566,   568,   570,   574,   579,   583,
     586,   590,   594,   599,   601,   604,   606,   609,   611,   614,
     620,   628,   634,   640,   648,   655,   663,   667,   670,   673,
     676,   680,   682,   685,   687,   689,   694,   698,   702
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     153,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    61,
     105,    62,    -1,    86,    -1,    87,    63,   105,    64,    -1,
      87,    61,    62,    -1,    87,    61,    88,    62,    -1,    87,
      65,     3,    -1,    87,     7,     3,    -1,    87,     8,    -1,
      87,     9,    -1,   103,    -1,    88,    66,   103,    -1,    87,
      -1,     8,    89,    -1,     9,    89,    -1,    90,    91,    -1,
       6,    89,    -1,     6,    61,   139,    62,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,    -1,
      89,    -1,    61,   139,    62,    91,    -1,    91,    -1,    92,
      68,    91,    -1,    92,    73,    91,    -1,    92,    74,    91,
      -1,    92,    -1,    93,    69,    92,    -1,    93,    70,    92,
      -1,    93,    -1,    94,    10,    93,    -1,    94,    11,    93,
      -1,    94,    -1,    95,    75,    94,    -1,    95,    76,    94,
      -1,    95,    12,    94,    -1,    95,    13,    94,    -1,    95,
      -1,    96,    14,    95,    -1,    96,    15,    95,    -1,    96,
      -1,    97,    67,    96,    -1,    97,    -1,    98,    77,    97,
      -1,    98,    -1,    99,    78,    98,    -1,    99,    -1,   100,
      16,    99,    -1,   100,    -1,   101,    17,   100,    -1,   101,
      -1,   101,    79,   105,    80,   102,    -1,   102,    -1,    89,
     104,   103,    -1,    81,    -1,    18,    -1,    19,    -1,    20,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,   103,    -1,   105,    66,   103,
      -1,   102,    -1,   108,    82,    -1,   108,   109,    82,    -1,
     111,    -1,   111,   108,    -1,   112,    -1,   112,   108,    -1,
     128,    -1,   128,   108,    -1,     3,    -1,     3,   108,    -1,
     110,    -1,   109,    66,   110,    -1,   129,    -1,   129,    81,
     142,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    44,    -1,    34,    -1,    35,    -1,    36,    -1,
      37,    -1,    40,    -1,    41,    -1,    38,    -1,    39,    -1,
     113,    -1,   125,    -1,    28,    -1,    -1,   116,     3,   114,
      83,   117,    84,    -1,    -1,   116,   115,    83,   117,    84,
      -1,   116,     3,    -1,    45,    -1,    46,    -1,   118,    -1,
     117,   118,    -1,   119,   123,    82,    -1,    -1,   112,   120,
     122,    -1,   112,    -1,   128,   122,    -1,   128,    -1,    -1,
       3,   121,   133,    -1,     3,    -1,   112,   122,    -1,   112,
      -1,   128,   122,    -1,   128,    -1,   124,    -1,   123,    66,
     124,    -1,   129,    -1,    80,   106,    -1,   129,    80,   106,
      -1,    47,    83,   126,    84,    -1,    47,     3,    83,   126,
      84,    -1,    47,     3,    -1,   127,    -1,   126,    66,    -1,
     126,    66,   127,    -1,     3,    -1,     3,    81,   106,    -1,
      42,    -1,    43,    -1,   133,   130,    -1,   130,    -1,     3,
      -1,    61,   129,    62,    -1,   130,    63,   106,    64,    -1,
     130,    63,    64,    -1,    -1,   130,    61,   131,   135,    62,
      -1,   130,    61,   138,    62,    -1,    -1,   130,    61,   132,
      62,    -1,   130,    61,    61,     3,    62,    62,     3,    -1,
      68,    -1,    68,   134,    -1,    68,   133,    -1,    68,   134,
     133,    -1,   128,    -1,   134,   128,    -1,   136,    -1,   136,
      66,    48,    -1,   137,    -1,   136,    66,   137,    -1,   108,
     129,    -1,   108,   140,    -1,   108,    -1,     3,    -1,   138,
      66,     3,    -1,   122,    -1,   122,   140,    -1,   133,    -1,
     141,    -1,   133,   141,    -1,    61,   140,    62,    -1,    63,
      64,    -1,    63,   106,    64,    -1,   141,    63,    64,    -1,
     141,    63,   106,    64,    -1,    61,    62,    -1,    61,   135,
      62,    -1,   141,    61,    62,    -1,   141,    61,   135,    62,
      -1,   103,    -1,    83,   143,    84,    -1,    83,   143,    66,
      84,    -1,   142,    -1,   143,    66,   142,    -1,   145,    -1,
     146,    -1,   149,    -1,   150,    -1,   151,    -1,   152,    -1,
       3,    80,   144,    -1,    49,   106,    80,   144,    -1,    50,
      80,   144,    -1,    83,    84,    -1,    83,   148,    84,    -1,
      83,   147,    84,    -1,    83,   147,   148,    84,    -1,   107,
      -1,   147,   107,    -1,   144,    -1,   148,   144,    -1,    82,
      -1,   105,    82,    -1,    51,    61,   105,    62,   144,    -1,
      51,    61,   105,    62,   144,    52,   144,    -1,    53,    61,
     105,    62,   144,    -1,    54,    61,   105,    62,   144,    -1,
      55,   144,    54,    61,   105,    62,    82,    -1,    56,    61,
     149,   149,    62,   144,    -1,    56,    61,   149,   149,   105,
      62,   144,    -1,    57,     3,    82,    -1,    58,    82,    -1,
      59,    82,    -1,    60,    82,    -1,    60,   105,    82,    -1,
     154,    -1,   153,   154,    -1,   155,    -1,   107,    -1,   108,
     129,   147,   146,    -1,   108,   129,   146,    -1,   129,   147,
     146,    -1,   129,   146,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    44,    44,    45,    46,    47,    51,    52,    53,    54,
      55,    56,    57,    58,    62,    63,    67,    68,    69,    70,
      71,    72,    76,    77,    78,    79,    80,    81,    85,    86,
      90,    91,    92,    93,    97,    98,    99,   103,   104,   105,
     109,   110,   111,   112,   113,   117,   118,   119,   123,   124,
     128,   129,   133,   134,   138,   139,   143,   144,   148,   149,
     153,   154,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   172,   173,   177,   181,   182,   186,   187,
     188,   189,   190,   191,   192,   193,   197,   198,   202,   203,
     207,   208,   209,   210,   211,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   230,   230,   231,
     231,   232,   236,   237,   241,   242,   247,   251,   251,   252,
     253,   254,   255,   255,   256,   260,   261,   262,   263,   267,
     268,   272,   273,   274,   278,   279,   280,   284,   285,   286,
     290,   291,   295,   296,   300,   301,   305,   306,   307,   308,
     309,   309,   310,   311,   311,   312,   316,   317,   318,   319,
     323,   324,   329,   330,   334,   335,   339,   340,   341,   345,
     346,   350,   351,   355,   356,   357,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   373,   374,   375,   379,   380,
     384,   385,   386,   387,   388,   389,   393,   394,   395,   399,
     400,   401,   402,   406,   407,   411,   412,   416,   417,   421,
     422,   423,   427,   428,   429,   430,   434,   435,   436,   437,
     438,   442,   443,   447,   448,   452,   453,   454,   455
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "$@1", "$@2", "struct_or_union", "struct_declaration_list",
  "struct_declaration", "struct_specifier_qualifier_list", "$@3", "$@4",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "$@5", "$@6",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   107,   107,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   114,   113,   115,
     113,   113,   116,   116,   117,   117,   118,   120,   119,   119,
     119,   119,   121,   119,   119,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   125,   126,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   130,   130,
     131,   130,   130,   132,   130,   130,   133,   133,   133,   133,
     134,   134,   135,   135,   136,   136,   137,   137,   137,   138,
     138,   139,   139,   140,   140,   140,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   142,   142,   142,   143,   143,
     144,   144,   144,   144,   144,   144,   145,   145,   145,   146,
     146,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   151,   151,   151,   151,   152,   152,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   155,   155
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     5,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     0,
       5,     2,     1,     1,     1,     2,     3,     0,     3,     1,
       2,     1,     0,     3,     1,     2,     1,     2,     1,     1,
       3,     1,     2,     3,     4,     5,     2,     1,     2,     3,
       1,     3,     1,     1,     2,     1,     1,     3,     4,     3,
       0,     5,     4,     0,     4,     7,     1,     2,     2,     3,
       1,     2,     1,     3,     1,     3,     2,     2,     1,     1,
       3,     1,     2,     1,     1,     2,     3,     2,     3,     3,
       4,     2,     3,     3,     4,     1,     3,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     3,     4,     3,     2,
       3,     3,     4,     1,     2,     1,     2,     1,     2,     5,
       7,     5,     5,     7,     6,     7,     3,     2,     2,     2,
       3,     1,     2,     1,     1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    84,   106,    90,    91,    92,    93,    94,    96,    97,
      98,    99,   102,   103,   100,   101,   142,   143,    95,   112,
     113,     0,     0,   156,   224,     0,    78,    80,   104,   109,
     105,    82,     0,   145,     0,     0,   221,   223,    84,    85,
     136,     0,   146,     0,   160,   158,   157,    76,     0,    86,
      88,    79,    81,   111,     0,    83,     0,   203,     0,   228,
       0,   150,     0,   144,     1,   222,     0,   140,     0,   137,
     147,   161,   159,     0,    77,     0,   226,     0,     0,     0,
       2,     3,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    22,    23,
      24,    25,    26,    27,   207,   199,     6,    16,    28,     0,
      30,    34,    37,    40,    45,    48,    50,    52,    54,    56,
      58,    60,    73,     0,   205,   190,   191,     0,     0,   192,
     193,   194,   195,    88,   204,   227,   169,     0,     0,     0,
       0,     2,   149,    28,    75,     0,     0,     0,   138,   134,
      87,     0,   185,    89,   225,     0,   124,   117,     0,   114,
       0,   121,     0,     0,    20,     0,    17,    18,     0,     0,
       0,     0,     0,     2,     0,     0,     0,   217,   218,   219,
       0,     0,   126,   171,   128,     0,     0,    12,    13,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    62,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   201,     0,   200,   206,
       0,   168,     0,   162,   164,   154,   152,     0,   148,   135,
     141,   139,   188,     0,     0,     0,     0,   110,   115,     0,
       0,   129,   131,   120,   196,     0,     0,   198,     0,     0,
       0,     0,     0,   216,   220,     5,   125,     0,     0,   173,
     172,   174,   127,     0,    11,     8,     0,    14,     0,    10,
      61,    31,    32,    33,    35,    36,    38,    39,    43,    44,
      41,    42,    46,    47,    49,    51,    53,    55,    57,     0,
      74,   202,     0,     0,   166,   173,   167,   151,     0,   170,
       0,   186,   108,   123,   118,   132,     0,   116,     0,    21,
     197,     0,     0,     0,     0,     0,   181,     0,     0,   177,
       0,   175,     0,     0,    29,     9,     0,     7,     0,     0,
     163,   165,   187,   189,   130,   133,   209,   211,   212,     0,
       0,     0,   182,   176,   178,   183,     0,   179,     0,    15,
      59,   155,     0,     0,   214,     0,   184,   180,   210,   213,
     215
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   106,   107,   276,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   203,
     123,   145,    57,    58,    48,    49,    26,    27,    28,    78,
      54,    29,   158,   159,   160,   246,   245,   183,   250,   251,
      30,    68,    69,    31,    32,    33,   138,   139,    34,    46,
     327,   233,   234,   140,   185,   328,   271,   153,   243,   124,
     125,   126,    60,   128,   129,   130,   131,   132,    35,    36,
      37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -238
static const yytype_int16 yypact[] =
{
    1168,   693,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,     7,   143,     9,  -238,    55,  1279,  1279,  -238,    31,
    -238,  1279,   750,    98,    13,  1032,  -238,  -238,  1279,  -238,
     -64,   100,  -238,    49,  -238,  -238,     9,  -238,   -10,  -238,
     671,  -238,  -238,   -34,    62,  -238,   330,  -238,    55,  -238,
     750,    88,   754,    98,  -238,  -238,   100,    51,   -44,  -238,
    -238,  -238,  -238,   143,  -238,    57,  -238,   750,    77,  1324,
     808,  -238,  -238,   970,   982,   982,  1019,   105,   133,   139,
     145,   612,   161,   224,   155,   165,   248,   855,  -238,  -238,
    -238,  -238,  -238,  -238,  -238,  -238,  -238,   225,   326,  1019,
    -238,   124,   174,   252,    24,   264,   178,   187,   193,   257,
      -3,  -238,  -238,    -9,  -238,  -238,  -238,   400,   470,  -238,
    -238,  -238,  -238,   200,  -238,  -238,  -238,   280,  1279,   232,
      86,  -238,  -238,  -238,  -238,   223,   -36,  1019,   100,  -238,
    -238,    57,  -238,  -238,  -238,  1324,   230,    75,   459,  -238,
     141,  1300,   612,   855,  -238,  1019,  -238,  -238,   226,   612,
    1019,  1019,  1019,   227,   256,   738,   229,  -238,  -238,  -238,
      16,   125,  1300,   121,  1300,   250,   310,  -238,  -238,   867,
    1019,   311,  -238,  -238,  -238,  -238,  -238,  -238,  -238,  -238,
    -238,  -238,  -238,  1019,  -238,  1019,  1019,  1019,  1019,  1019,
    1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,  1019,
    1019,  1019,  1019,  1019,  1019,  -238,  -238,   506,  -238,  -238,
     259,    90,   260,   258,  -238,  -238,  -238,   320,  -238,  -238,
    -238,  -238,  -238,   -13,   565,   261,  1300,  -238,  -238,  1019,
      19,  -238,   245,  -238,  -238,   265,   612,  -238,   151,   152,
     154,   267,   738,  -238,  -238,  -238,  -238,  1078,   900,   140,
    -238,   167,  -238,  1019,  -238,  -238,   157,  -238,   172,  -238,
    -238,  -238,  -238,  -238,   124,   124,   174,   174,   252,   252,
     252,   252,    24,    24,   264,   178,   187,   193,   257,    42,
    -238,  -238,   269,  1123,  -238,    56,  -238,  -238,  1258,  -238,
     576,  -238,  -238,  -238,  -238,  -238,   141,  -238,  1019,  -238,
    -238,   612,   612,   612,  1019,   937,  -238,   275,   278,  -238,
     262,   167,  1213,   949,  -238,  -238,  1019,  -238,  1019,   338,
    -238,  -238,  -238,  -238,  -238,  -238,   290,  -238,  -238,   163,
     612,   173,  -238,  -238,  -238,  -238,   281,  -238,   292,  -238,
    -238,  -238,   612,   272,  -238,   612,  -238,  -238,  -238,  -238,
    -238
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -238,  -238,  -238,  -238,   -42,  -238,   -92,    91,    94,    46,
      85,   160,   175,   162,   171,   188,  -238,   -53,   -68,  -238,
     -84,   -63,    15,     0,  -238,   322,  -238,   -51,  -238,  -238,
    -238,  -238,   238,  -147,  -238,  -238,  -238,  -137,  -238,    80,
    -238,   345,   268,   111,   -19,   -30,  -238,  -238,   -21,  -238,
    -133,  -238,   107,  -238,   254,  -162,  -237,  -122,  -238,   -73,
    -238,    70,    14,   291,  -167,  -238,  -238,  -238,  -238,   384,
    -238
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -154
static const yytype_int16 yytable[] =
{
      25,    39,    45,    43,    63,   232,    50,   152,   262,   144,
      40,   248,   180,   181,   222,    24,    42,   204,   174,    66,
     143,   270,   148,   168,   253,    72,    51,    52,   157,   242,
     148,    55,   331,   144,    53,    25,   212,   213,    39,   133,
     149,   164,   166,   167,   143,   266,   182,   272,   239,  -107,
      24,    16,    17,   310,   133,   229,    73,   224,    42,    42,
     141,    81,    82,    83,    77,    84,    85,   143,   331,   306,
     127,   311,    74,   225,    22,   134,   223,    23,  -119,   181,
      39,   181,   224,   152,   240,   316,   258,   259,   260,   254,
      41,   136,   134,    42,   144,   325,   257,   248,   264,   214,
     215,   317,    59,    67,   157,   143,   278,   157,   224,   314,
     182,    70,   182,   281,   282,   283,    22,   303,    97,   268,
      76,   277,   338,    23,    98,    99,   100,   101,   102,   103,
     135,   182,   147,   182,    44,   280,  -119,    47,   231,   299,
     151,   252,   134,  -119,    42,    79,    42,   154,   236,   137,
    -153,   303,   237,   268,   229,  -119,   300,    71,    23,    61,
     155,    62,   269,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   334,   267,   320,   268,   169,   315,   265,   343,    23,
     161,   224,   205,   157,   170,   182,   144,   206,   207,   356,
     171,   267,    22,   268,    22,   330,   172,   143,   184,    23,
     305,    23,   304,   321,   322,   144,   323,   224,   224,   335,
     224,   249,   175,   336,   313,   363,   143,   176,   332,   224,
     333,   143,   186,   187,   188,   365,   337,   177,   224,   224,
     349,   351,   152,   208,   209,   218,   269,   178,   346,   347,
     348,   141,    81,    82,    83,   345,    84,    85,   288,   289,
     290,   291,   210,   211,   219,   144,   161,   231,   359,   161,
     358,   220,   184,   221,   184,    63,   143,   364,   216,   217,
     144,    75,   305,   230,    43,   360,   189,   238,   190,   368,
     191,   143,   370,   184,   235,   184,   143,   252,  -122,   284,
     285,   292,   293,   231,   286,   287,   256,   162,   231,    97,
     261,   263,   273,   274,   279,    98,    99,   100,   101,   102,
     103,   302,   307,   309,   308,   318,   354,   319,   324,    23,
     179,   339,   231,    80,    81,    82,    83,   352,    84,    85,
     353,   361,   362,   366,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   369,   161,   367,   184,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   294,    86,
      87,    88,   296,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   297,   244,   295,   150,   344,    98,    99,   100,
     101,   102,   103,    80,    81,    82,    83,   202,    84,    85,
     298,   146,   104,    56,   105,   341,   241,   255,   227,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    86,
      87,    88,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,   156,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   173,    81,    82,    83,     0,    84,    85,
       0,     0,   104,    56,   226,     0,     0,     2,     0,     0,
       0,     0,     0,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,     0,     0,   173,
      81,    82,    83,     0,    84,    85,     0,     0,     0,    86,
      87,    88,     0,    89,    90,    91,    92,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   247,     0,     0,     0,     0,     0,     0,
       0,     0,   104,    56,   228,    86,    87,    88,     0,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   156,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   141,
      81,    82,    83,     0,    84,    85,     0,     0,   104,    56,
     301,     0,     0,     2,     0,     0,     0,     0,     0,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     0,     0,   173,    81,    82,    83,     0,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
     342,    86,    87,    88,     0,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    38,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,    56,    38,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   141,    81,    82,    83,     0,    84,    85,     0,     0,
       0,     0,    75,    38,    56,     0,     0,   141,    81,    82,
      83,     0,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -146,     0,     2,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    97,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,    38,     0,     0,     0,    97,     0,     0,   142,     0,
     104,    98,    99,   100,   101,   102,   103,     0,     0,     0,
       0,     0,     0,    56,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     0,     0,   141,    81,
      82,    83,     0,    84,    85,     0,     0,     0,     0,     0,
     141,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,     0,   162,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   141,    81,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,    97,   275,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     141,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,     0,   141,    81,    82,    83,     0,    84,    85,     0,
       0,    97,     0,     0,   329,     0,     0,    98,    99,   100,
     101,   102,   103,   141,    81,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,   141,    81,    82,    83,     0,
      84,    85,     0,     0,     0,     0,     0,     0,    97,   350,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
      97,     0,     0,   357,     0,     0,    98,    99,   100,   101,
     102,   103,   141,    81,    82,    83,     0,    84,    85,     0,
       0,   163,    64,     0,     0,     1,     0,    98,    99,   100,
     101,   102,   103,   165,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      97,    38,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
     326,   268,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   303,   326,   268,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   340,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   156,     2,     0,
       0,     0,     0,     0,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     2,     0,     0,     0,     0,     0,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-238))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,     1,    23,    22,    34,   138,    25,    75,   175,    62,
       3,   158,    96,    97,    17,     0,     3,   109,    91,    83,
      62,   183,    66,    86,   161,    46,    26,    27,    79,   151,
      66,    31,   269,    86,     3,    35,    12,    13,    38,    58,
      84,    83,    84,    85,    86,   182,    97,   184,    84,    83,
      35,    42,    43,    66,    73,   128,    66,    66,     3,     3,
       3,     4,     5,     6,    50,     8,     9,   109,   305,   231,
      56,    84,    82,    82,    61,    60,    79,    68,     3,   163,
      80,   165,    66,   151,   147,    66,   170,   171,   172,   162,
      83,     3,    77,     3,   147,   262,   169,   244,    82,    75,
      76,    82,    32,     3,   155,   147,   190,   158,    66,   246,
     161,    62,   163,   205,   206,   207,    61,    61,    61,    63,
      50,   189,    80,    68,    67,    68,    69,    70,    71,    72,
      60,   182,    81,   184,    23,   203,    61,    82,   138,   223,
      83,   160,   127,    68,     3,    83,     3,    77,    62,    61,
      62,    61,    66,    63,   227,    80,   224,    46,    68,    61,
      83,    63,   183,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   273,    61,   256,    63,    80,   249,    62,   310,    68,
      79,    66,    68,   244,    61,   246,   249,    73,    74,   332,
      61,    61,    61,    63,    61,   268,    61,   249,    97,    68,
     231,    68,   231,    62,    62,   268,    62,    66,    66,    62,
      66,    80,    61,    66,   245,    62,   268,     3,    61,    66,
      63,   273,     7,     8,     9,    62,    64,    82,    66,    66,
     324,   325,   310,    69,    70,    67,   267,    82,   321,   322,
     323,     3,     4,     5,     6,   318,     8,     9,   212,   213,
     214,   215,    10,    11,    77,   318,   155,   267,   336,   158,
     333,    78,   161,    16,   163,   305,   318,   350,    14,    15,
     333,    81,   303,     3,   303,   338,    61,    64,    63,   362,
      65,   333,   365,   182,    62,   184,   338,   316,    68,   208,
     209,   216,   217,   303,   210,   211,    80,    80,   308,    61,
      54,    82,    62,     3,     3,    67,    68,    69,    70,    71,
      72,    62,    62,     3,    66,    80,    64,    62,    61,    68,
      82,    62,   332,     3,     4,     5,     6,    62,     8,     9,
      62,     3,    52,    62,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    82,   244,    64,   246,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,   218,    49,
      50,    51,   220,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   221,   155,   219,    73,   316,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    81,     8,     9,
     222,    66,    82,    83,    84,   308,   148,   163,   127,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     3,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    82,    83,    84,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    49,
      50,    51,    -1,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    49,    50,    51,    -1,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     3,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    82,    83,
      84,    -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      84,    49,    50,    51,    -1,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     3,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    83,     3,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    -1,    81,     3,    83,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,
      72,     3,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,
      82,    67,    68,    69,    70,    71,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,    80,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    61,    -1,    -1,    64,    -1,    -1,    67,    68,    69,
      70,    71,    72,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      61,    -1,    -1,    64,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    61,     0,    -1,    -1,     3,    -1,    67,    68,    69,
      70,    71,    72,    61,    -1,    -1,    -1,    -1,    -1,    67,
      68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      61,     3,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,     3,    28,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    61,    68,   107,   108,   111,   112,   113,   116,
     125,   128,   129,   130,   133,   153,   154,   155,     3,   108,
       3,    83,     3,   129,   128,   133,   134,    82,   109,   110,
     129,   108,   108,     3,   115,   108,    83,   107,   108,   146,
     147,    61,    63,   130,     0,   154,    83,     3,   126,   127,
      62,   128,   133,    66,    82,    81,   146,   147,   114,    83,
       3,     4,     5,     6,     8,     9,    49,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    67,    68,
      69,    70,    71,    72,    82,    84,    86,    87,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   105,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   129,   107,   146,     3,    61,   131,   132,
     138,     3,    64,    89,   102,   106,   126,    81,    66,    84,
     110,    83,   103,   142,   146,    83,     3,   112,   117,   118,
     119,   128,    80,    61,    89,    61,    89,    89,   106,    80,
      61,    61,    61,     3,   144,    61,     3,    82,    82,    82,
     105,   105,   112,   122,   128,   139,     7,     8,     9,    61,
      63,    65,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    81,   104,    91,    68,    73,    74,    69,    70,
      10,    11,    12,    13,    75,    76,    14,    15,    67,    77,
      78,    16,    17,    79,    66,    82,    84,   148,    84,   144,
       3,   108,   135,   136,   137,    62,    62,    66,    64,    84,
     106,   127,   142,   143,   117,   121,   120,    84,   118,    80,
     123,   124,   129,   122,   144,   139,    80,   144,   105,   105,
     105,    54,   149,    82,    82,    62,   122,    61,    63,   133,
     140,   141,   122,    62,     3,    62,    88,   103,   105,     3,
     103,    91,    91,    91,    92,    92,    93,    93,    94,    94,
      94,    94,    95,    95,    96,    97,    98,    99,   100,   105,
     103,    84,    62,    61,   129,   133,   140,    62,    66,     3,
      66,    84,    84,   133,   122,   106,    66,    82,    80,    62,
     144,    62,    62,    62,    61,   149,    62,   135,   140,    64,
     106,   141,    61,    63,    91,    62,    66,    64,    80,    62,
      48,   137,    84,   142,   124,   106,   144,   144,   144,   105,
      62,   105,    62,    62,    64,    62,   135,    64,   106,   103,
     102,     3,    52,    62,   144,    62,    62,    64,   144,    82,
     144
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 90:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    { xml_typedef_set(); }
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    { xml_struct_open(); }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 230 "parser.y"
    { xml_struct_prepare_close(); }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    { xml_struct_open(); }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    { xml_struct_prepare_close(); }
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 236 "parser.y"
    { xml_struct_union_set(0); }
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 237 "parser.y"
    { xml_struct_union_set(1); }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 251 "parser.y"
    { xml_datatype_add(); }
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 252 "parser.y"
    { xml_single_datatype_add(); }
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 253 "parser.y"
    { /* printf("Got DATA qualifier list\n"); */ xml_single_datatype_add(); }
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 255 "parser.y"
    { xml_single_datatype_add(); }
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 256 "parser.y"
    { xml_user_datatype_add(); }
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 305 "parser.y"
    { xml_id_add(); }
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 306 "parser.y"
    { xml_func_ptr_add(); }
    break;

  case 148:

/* Line 1806 of yacc.c  */
#line 307 "parser.y"
    { xml_array_size_add(1); }
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 308 "parser.y"
    { xml_array_size_add(0); }
    break;

  case 150:

/* Line 1806 of yacc.c  */
#line 309 "parser.y"
    { xml_func_ptr_args_start(); }
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 309 "parser.y"
    { xml_func_ptr_args_end(); }
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 311 "parser.y"
    { xml_func_ptr_args_start(); }
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 311 "parser.y"
    { xml_func_ptr_args_end(); }
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 312 "parser.y"
    { xml_nested_st_attr_name(); /* FIXME: Hack */ }
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 316 "parser.y"
    { xml_ptr_add(); }
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 318 "parser.y"
    { xml_ptr_add(); }
    break;



/* Line 1806 of yacc.c  */
#line 2217 "parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 458 "parser.y"

#include <stdio.h>

extern char yytext[];
extern int column;

void yyerror(char *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

void enable_yacc_debug() {
    #if YYDEBUG != 0
        yydebug = 1;
    #endif
}

