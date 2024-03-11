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
#line 1 "B083040010.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int yylex();
int max=0, can_in=1, tempnum=0, temp_size, temp_isarray=0, findit=0;
char* temp_id[256], temp_t; 
extern int position, line, pre_p, ok, pre_l; // For recording previous token's "position" and "line", for finding the "ERROR position".
char* output;
char* temp;
char* temp2;
void yyerror(const char* msg){ // used to deal with ERROR msgs.
	ok=0;
	printf("\rLine %d, at char %d, ",pre_l,pre_p);
	printf("%s                    \n",msg);
};
struct table{ // ID table : for Error of "ID".
	char* id;
	char* type;
	int isarray;
	int arraysize;
}idtable[256];
void insert(char* temp_type){ // For inserting ID or type etc into the idtable[].
	for (int k=0;k<tempnum;k++){
		for (int j=0 ; j < max ; j++){
			if (idtable[j].id==temp_id[k]){
				can_in=0;break;
			}
		}
		if (can_in==1){
			if (temp_isarray==1){
				idtable[max].isarray=1;
				idtable[max].arraysize=temp_size;
			}
			idtable[max].id=temp_id[k];
			for (int l=0;l<strlen(temp_type);l++) temp_type[l]=tolower(temp_type[l]);
			idtable[max++].type=temp_type;
		}
		else { // Repeated Declaration.
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Duplicate identifier '%s'                    \n",temp_id[k]);
			can_in=1;break;
		}
	}
	temp_isarray=0;tempnum=0;
};
char* find(char* findid){ // To find "type".(expected)
	for (int l=0;l<strlen(findid);l++) findid[l]=tolower(findid[l]);
	for (int i=0;i<max;i++) if (strcmp(idtable[i].id,findid)==0) return idtable[i].type;
	return "";
}
char* findexp(char* findid){ // what we got.
	if (strcmp(findid,"ntype")==0) return "ntype";
	for (int i=0;i<strlen(findid);i++) if (findid[i]=='.') return "real";
	for (int i=0;i<strlen(findid);i++) if (findid[i]>=48&&findid[i]<=57) return "integer";
	for (int l=0;l<strlen(findid);l++) findid[l]=tolower(findid[l]);
	for (int i=0;i<max;i++) if (strcmp(idtable[i].id,findid)==0) return idtable[i].type;
	return "";
}

#line 129 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 64 "B083040010.y" /* yacc.c:355  */

	char* name;

#line 305 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 322 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

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
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    74,    78,    80,    82,    83,    85,    86,
      88,    89,    91,    92,    93,    94,    96,    98,    99,   100,
     102,   103,   105,   106,   107,   108,   109,   110,   112,   134,
     145,   157,   168,   170,   172,   179,   197,   198,   199,   200,
     201,   202,   203,   204,   210,   220,   221,   229,   237,   246,
     247,   248,   249,   251,   253,   260,   261,   268,   269,   270,
     277,   278,   285,   286,   287,   288,   289,   301,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSOLUTE", "AND", "BBEGIN", "BREAK",
  "CASE", "CONST", "CONTINUE", "DO", "ELSE", "END", "FOR", "FUNCTION",
  "IF", "MOD", "NIL", "NOT", "OBJECT", "OF", "OR", "PROGRAM", "THEN", "TO",
  "VAR", "WHILE", "ARRAY", "INTEGER", "DOUBLE", "WRITE", "WRITELN",
  "STRING", "CHAR", "FLOAT", "READ", "REALTYPE", "ASSIGNMENT", "COLON",
  "COMMA", "DOT", "EQUAL", "GE", "GT", "LBRAC", "LE", "LPAREN", "LT",
  "MINUS", "NOTEQUAL", "PLUS", "RBRAC", "RPAREN", "SEMICOLON", "SLASH",
  "STAR", "UPARROW", "INT", "REAL", "STR", "ID", "IOI", "IOR", "ROI",
  "ROR", "IDOI", "IDOR", "$accept", "prog", "prog_name", "dec_list", "dec",
  "type", "standtype", "arraytype", "id_list", "stmt_list", "stmt",
  "assign", "ifstmt", "exp", "relop", "simpexp", "term", "factor", "read",
  "read_list", "write", "write_list", "for", "index_exp", "varid", "body", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      46,   -54,   -53,    18,   -54,   -28,   -54,     7,     3,     6,
     -54,    20,   -54,   -25,     1,   102,   -20,    47,   -54,    27,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    -9,
      29,    34,   -54,    39,    75,    70,   -54,   -54,   -54,   -54,
     -54,   -54,    69,     9,   117,   105,    30,    -4,    49,    30,
       4,   -37,   -54,   -54,   -54,   -54,   -54,   -54,    45,   106,
      23,    30,    30,   -54,   -54,    79,   -40,   -13,   -54,   -54,
     -54,    -2,   -54,   -54,    13,   -54,    44,   113,   -54,   -54,
     -40,   -54,   -40,   114,    47,   -54,   -54,    22,    65,   132,
      30,    30,    30,    30,    30,    30,    73,   -54,    77,   -54,
     -54,   -54,    99,   104,    30,   -54,    23,   -40,   -13,   -13,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   107,    14,    98,
     -54,   139,   -54,   116,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     5,     0,     1,     0,     0,    19,
      17,     0,     6,     0,     0,     0,     0,     0,     7,     0,
      12,    14,    15,    13,     8,    10,    11,    18,    32,     0,
       0,     0,    27,     0,    65,     0,    20,    22,    26,    23,
      24,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,    38,    36,    39,    37,    40,     0,     0,
       0,     0,     0,    50,    51,     0,    34,    42,    45,    49,
      60,     0,    59,    55,     0,    54,     0,     3,    21,    30,
      28,    31,    29,     0,     0,    67,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,     0,    53,
      66,     2,     0,     0,     0,    52,     0,    35,    44,    43,
      48,    47,    46,    62,    61,    57,    56,     0,     0,    64,
      33,     0,    68,     0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -54,   -54,   -54,   -54,   146,   -54,    38,   -54,   -54,    78,
     -49,   -54,   -54,    60,   121,    35,    59,     5,   -54,   -54,
     -54,   -54,   -54,   -54,   -17,    61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     5,    11,    12,    24,    25,    26,    13,    35,
      36,    37,    38,    65,    90,    66,    67,    68,    39,    74,
      40,    71,    41,    44,    69,    86
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      42,    78,     9,    93,     9,    28,    17,     4,    91,    62,
      92,    85,    45,    15,    16,    28,    77,    29,     6,    30,
      63,    64,    79,    34,    28,     7,   122,    29,    84,    30,
      72,    75,     8,    42,    31,    32,    29,    96,    30,    33,
      27,    94,    95,    42,    31,    32,   104,     1,    28,    33,
      97,    34,    98,    31,    32,    70,    34,    85,    33,    -9,
      29,    10,    30,    10,    34,    99,    59,    42,     2,    78,
      91,    43,    92,    14,    34,    46,    62,    31,    32,   114,
      47,   116,    33,    34,    76,    48,    80,    63,    64,    42,
      34,    62,    91,    82,    92,   100,    87,    88,   110,   111,
     112,    42,    63,    64,    81,    34,    51,    34,    73,    34,
      52,    53,    54,    91,    55,    92,    56,   105,    57,    49,
      52,    53,    54,    50,    55,   107,    56,    60,    57,    19,
      20,    89,   113,    34,    21,    22,   115,    34,    23,    52,
      53,    54,    61,    55,    20,    56,    83,    57,    21,    22,
     108,   109,    23,   101,   102,   106,   117,   118,   121,   123,
      18,   124,   103,    58,   119,     0,     0,   120
};

static const yytype_int8 yycheck[] =
{
      17,    50,     1,    16,     1,     1,     5,    60,    48,    46,
      50,    60,    29,    38,    39,     1,    12,    13,     0,    15,
      57,    58,    59,    60,     1,    53,    12,    13,     5,    15,
      47,    48,    25,    50,    30,    31,    13,    39,    15,    35,
      60,    54,    55,    60,    30,    31,    24,     1,     1,    35,
      52,    60,    39,    30,    31,    59,    60,   106,    35,    53,
      13,    60,    15,    60,    60,    52,    57,    84,    22,   118,
      48,    44,    50,    53,    60,    46,    46,    30,    31,    96,
      46,    98,    35,    60,    49,    46,    51,    57,    58,   106,
      60,    46,    48,    58,    50,    51,    61,    62,    93,    94,
      95,   118,    57,    58,    59,    60,    37,    60,    59,    60,
      41,    42,    43,    48,    45,    50,    47,    52,    49,    44,
      41,    42,    43,    53,    45,    90,    47,    10,    49,    27,
      28,    52,    59,    60,    32,    33,    59,    60,    36,    41,
      42,    43,    37,    45,    28,    47,    40,    49,    32,    33,
      91,    92,    36,    40,    40,    23,    57,    53,    51,    20,
      14,   123,    84,    42,   104,    -1,    -1,   106
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    22,    68,    60,    69,     0,    53,    25,     1,
      60,    70,    71,    75,    53,    38,    39,     5,    71,    27,
      28,    32,    33,    36,    72,    73,    74,    60,     1,    13,
      15,    30,    31,    35,    60,    76,    77,    78,    79,    85,
      87,    89,    91,    44,    90,    91,    46,    46,    46,    44,
      53,    37,    41,    42,    43,    45,    47,    49,    81,    57,
      10,    37,    46,    57,    58,    80,    82,    83,    84,    91,
      59,    88,    91,    59,    86,    91,    82,    12,    77,    59,
      82,    59,    82,    40,     5,    77,    92,    82,    82,    52,
      81,    48,    50,    16,    54,    55,    39,    52,    39,    52,
      51,    40,    40,    76,    24,    52,    23,    82,    83,    83,
      84,    84,    84,    59,    91,    59,    91,    57,    53,    80,
      92,    51,    12,    20,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    68,    68,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    73,    74,    75,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    79,    80,    80,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    83,    83,    83,    83,    84,
      84,    84,    84,    85,    86,    86,    86,    86,    87,    88,
      88,    88,    88,    89,    90,    91,    91,    92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    11,    10,     1,     1,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     9,     1,     3,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     1,     6,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     3,     1,
       1,     1,     3,     4,     1,     1,     3,     3,     4,     1,
       1,     3,     3,     4,     5,     1,     4,     1,     4
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
#line 74 "B083040010.y" /* yacc.c:1646  */
    {	
		ok=0;
		printf("\rLine %d, at char %d, ",pre_l,pre_p+3);
		printf("syntax error, unexpected $end, expecting DOT\n");
	}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "B083040010.y" /* yacc.c:1646  */
    {insert((yyvsp[0].name));}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 96 "B083040010.y" /* yacc.c:1646  */
    {temp_size=(yyvsp[-3].name)-(yyvsp[-6].name)-91;temp_isarray=1;insert((yyvsp[0].name));}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 98 "B083040010.y" /* yacc.c:1646  */
    {temp_id[tempnum++] = (yyvsp[0].name);}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 99 "B083040010.y" /* yacc.c:1646  */
    {temp_id[tempnum++] = (yyvsp[0].name);}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 112 "B083040010.y" /* yacc.c:1646  */
    { // Error of ASSIGNMENT.
		if (find((yyvsp[-2].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-2].name));
		}
		else if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}
		else if (findexp((yyvsp[0].name))=="ntype"){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",temp,temp2);
		}
		else if (strcmp(find((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0 && strcmp(findexp((yyvsp[0].name)),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),find((yyvsp[-2].name)));
		}
	}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 134 "B083040010.y" /* yacc.c:1646  */
    { // Error of ":=".
		ok=0;
		if (find((yyvsp[-2].name))==""){
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-2].name));
		}
		else{
			printf("\rLine %d, ",pre_l);
			printf("syntax error, unexpected '%s', expecting ':='\n",(yyvsp[-1].name));
		}
	}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 145 "B083040010.y" /* yacc.c:1646  */
    { // Error of "STR(string)".
		if (find((yyvsp[-2].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-2].name));
		}
		else if (strcmp(find((yyvsp[-2].name)),"string")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected 'string'\n",find((yyvsp[-2].name)));
		}
	}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 157 "B083040010.y" /* yacc.c:1646  */
    {
		ok=0;
		if (find((yyvsp[-2].name))==""){
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-2].name));
		}
		else{
			printf("\rLine %d, ",pre_l);
			printf("syntax error, unexpected '%s', expecting ':='\n",(yyvsp[-1].name));
		}
	}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 172 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}
	}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[-2].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-2].name));
		}
		else if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}
		else if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0 && strcmp(findexp((yyvsp[0].name)),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),findexp((yyvsp[-2].name)));
		}
	}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 204 "B083040010.y" /* yacc.c:1646  */
    {
		temp=strdup(findexp((yyvsp[0].name)));
		temp2=strdup(findexp((yyvsp[-2].name)));
		if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0) (yyval.name)=strdup("ntype");
		else (yyval.name)=(yyvsp[-2].name);
	}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 210 "B083040010.y" /* yacc.c:1646  */
    {
		if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0 && strcmp(findexp((yyvsp[0].name)),"ntype")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),findexp((yyvsp[-2].name)));(yyval.name)=strdup("ntype");
		}
		else if (strcmp(findexp((yyvsp[0].name)),"ntype")==0) {(yyval.name)="ntype";}
		else (yyval.name)=(yyvsp[-2].name);
	}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 221 "B083040010.y" /* yacc.c:1646  */
    {
		if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),findexp((yyvsp[-2].name)));(yyval.name)=strdup("ntype");
		}
		else (yyval.name)=(yyvsp[-2].name);
	}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 229 "B083040010.y" /* yacc.c:1646  */
    {
		if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),findexp((yyvsp[-2].name)));(yyval.name)=strdup("ntype");
		}
		else (yyval.name)=(yyvsp[-2].name);
	}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 237 "B083040010.y" /* yacc.c:1646  */
    {
		if (strcmp(findexp((yyvsp[-2].name)),findexp((yyvsp[0].name)))!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s', expected '%s'                    \n",findexp((yyvsp[0].name)),findexp((yyvsp[-2].name)));(yyval.name)=strdup("ntype");
		}
		else (yyval.name)=(yyvsp[-2].name);
	}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 253 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}temp_isarray=0;tempnum=0;
	}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 261 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}temp_isarray=0;tempnum=0;
	}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 270 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}temp_isarray=0;tempnum=0;
	}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 278 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[0].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[0].name));
		}temp_isarray=0;tempnum=0;
	}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 289 "B083040010.y" /* yacc.c:1646  */
    {
		if (findexp((yyvsp[-1].name))==""){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("identifier not found '%s'                    \n",(yyvsp[-1].name));
		}
		else if (strcmp(findexp((yyvsp[-1].name)),"integer")!=0){
			ok=0;
			printf("\rLine %d, ",pre_l);
			printf("Incompatible types: got '%s'                     ,expected 'integer'\n",findexp((yyvsp[-1].name)));
		}
	}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1771 "y.tab.c" /* yacc.c:1646  */
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
#line 303 "B083040010.y" /* yacc.c:1906  */

int main(){
	yyparse();
	return 0;
}
