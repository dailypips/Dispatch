
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
   Foundation, Inc.
   
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

// Take the name prefix into account.
#define yylex   config::lex

/* First part of user declarations.  */


#include "config_nodes.h"
#include <alloca.h>
namespace dispatch{namespace config{
	class parseDriver;
}}
using namespace ::dispatch::config;




#include "config_y.tab.H"

/* User implementation prologue.  */


#include "driver.h"

#undef yylex
#define yylex driver.lex



#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace dispatch {

#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  config_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  config_parser::config_parser (class config::parseDriver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {
  }

  config_parser::~config_parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  config_parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  config_parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  config_parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  config_parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  config_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  config_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  config_parser::debug_level_type
  config_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  config_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  config_parser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    
{
// start
	// void
 yylloc.begin.filename = yylloc.end.filename = driver.getFileNamePtr(); //new string(driver.getFileName());
/* @$.begin.line = @$.end.line = 0;
 @$.begin.column = @$.end.column = 0;
*/
}


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

    { driver.addBlockList((yysemantic_stack_[(1) - (1)].gc_block_list)); }
    break;

  case 4:

    { (yyval.gc_block_list) = new GConfigBlockList((yysemantic_stack_[(1) - (1)].gc_block)); }
    break;

  case 5:

    { (yysemantic_stack_[(2) - (1)].gc_block_list)->appendBlock((yysemantic_stack_[(2) - (2)].gc_block)); (yyval.gc_block_list) = (yysemantic_stack_[(2) - (1)].gc_block_list); }
    break;

  case 6:

    { (yyval.gc_block_header) = new GConfigBlockHeader((yysemantic_stack_[(5) - (1)].str_val), (yysemantic_stack_[(5) - (3)].gc_identifier), (yylocation_stack_[(5) - (1)])); free((yysemantic_stack_[(5) - (1)].str_val)); }
    break;

  case 7:

    { (yyval.gc_block_header) = new GConfigBlockHeader((yysemantic_stack_[(2) - (1)].str_val), (yylocation_stack_[(2) - (1)])); free((yysemantic_stack_[(2) - (1)].str_val)); }
    break;

  case 8:

    { (yyval.gc_block) = new GConfigBlock((yysemantic_stack_[(3) - (1)].gc_block_header), (yysemantic_stack_[(3) - (2)].gc_statement_list)); }
    break;

  case 9:

    { (yyval.gc_identifier) = new GConfigIdentifier((yysemantic_stack_[(1) - (1)].str_val), (yylocation_stack_[(1) - (1)])); free((yysemantic_stack_[(1) - (1)].str_val)); }
    break;

  case 10:

    { (yysemantic_stack_[(3) - (1)].gc_identifier)->appendString((yysemantic_stack_[(3) - (3)].str_val), (yylocation_stack_[(3) - (3)])); free((yysemantic_stack_[(3) - (3)].str_val)); (yyval.gc_identifier) = (yysemantic_stack_[(3) - (1)].gc_identifier); }
    break;

  case 11:

    { (yyval.gc_statement_list) = new GConfigStatementList((yysemantic_stack_[(1) - (1)].gc_statement)); }
    break;

  case 12:

    { (yysemantic_stack_[(2) - (1)].gc_statement_list)->appendStatement((yysemantic_stack_[(2) - (2)].gc_statement)); (yyval.gc_statement_list) = (yysemantic_stack_[(2) - (1)].gc_statement_list); }
    break;

  case 13:

    { (yyval.gc_statement) = (yysemantic_stack_[(1) - (1)].gc_block); }
    break;

  case 14:

    { (yyval.gc_statement) = (yysemantic_stack_[(1) - (1)].gc_function); }
    break;

  case 15:

    { (yyval.gc_statement) = (yysemantic_stack_[(1) - (1)].gc_variable); }
    break;

  case 16:

    { (yyval.gc_statement) = (yysemantic_stack_[(1) - (1)].gc_define); }
    break;

  case 17:

    { (yyval.gc_variable) = new GConfigVariableStatement((yysemantic_stack_[(4) - (1)].gc_identifier), (yysemantic_stack_[(4) - (3)].gc_argument)); }
    break;

  case 18:

    { (yyval.gc_define) = new GConfigDefineStatement((yysemantic_stack_[(2) - (1)].gc_identifier)); }
    break;

  case 19:

    { (yyval.gc_function) = new GConfigFunctionStatement((yysemantic_stack_[(5) - (1)].gc_identifier), (yysemantic_stack_[(5) - (3)].gc_argument_list)); }
    break;

  case 20:

    { (yyval.gc_argument) = new GConfigArgument((yysemantic_stack_[(1) - (1)].gc_scalar_val)); }
    break;

  case 21:

    { (yyval.gc_argument) = new GConfigArgument((yysemantic_stack_[(3) - (2)].gc_argument_list)); }
    break;

  case 22:

    { (yyval.gc_argument_list) = new GConfigArgumentList((yysemantic_stack_[(1) - (1)].gc_scalar_val)); }
    break;

  case 23:

    { (yysemantic_stack_[(3) - (1)].gc_argument_list)->appendArgument((yysemantic_stack_[(3) - (3)].gc_scalar_val)); (yyval.gc_argument_list) = (yysemantic_stack_[(3) - (1)].gc_argument_list); }
    break;

  case 24:

    { (yyval.gc_scalar_val) = new GConfigScalarVal((yysemantic_stack_[(1) - (1)].long_val), (yylocation_stack_[(1) - (1)])); }
    break;

  case 25:

    { (yyval.gc_scalar_val) = new GConfigScalarVal((yysemantic_stack_[(1) - (1)].double_val), (yylocation_stack_[(1) - (1)])); }
    break;

  case 26:

    { (yyval.gc_scalar_val) = new GConfigScalarVal((yysemantic_stack_[(1) - (1)].str_val), (yylocation_stack_[(1) - (1)])); free((yysemantic_stack_[(1) - (1)].str_val)); }
    break;

  case 27:

    { (yyval.gc_scalar_val) = new GConfigScalarVal((yysemantic_stack_[(1) - (1)].gc_identifier)); }
    break;



	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  config_parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char config_parser::yypact_ninf_ = -25;
  const signed char
  config_parser::yypact_[] =
  {
        12,   -25,     2,     8,    11,    15,   -25,   -25,    19,   -25,
     -25,     2,   -25,    -2,    28,   -25,   -25,   -25,   -25,   -25,
      14,    22,    26,   -25,    16,   -25,   -25,    18,   -25,   -25,
     -25,    23,    -1,   -25,   -25,    22,    24,   -25,   -25,    25,
      22,     0,   -25,   -25,   -25,   -25
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  config_parser::yydefact_[] =
  {
         0,     3,     0,     0,     2,     0,     4,     7,     0,     1,
       5,     9,    13,     0,     0,    11,    15,    16,    14,     9,
       0,     0,     0,    18,     0,     8,    12,     0,    24,    25,
      26,    27,     0,    22,    10,     0,     0,    20,     6,     0,
       0,     0,    17,    19,    23,    21
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  config_parser::yypgoto_[] =
  {
       -25,   -25,   -25,   -25,     6,    -3,   -25,    29,   -25,   -25,
     -25,   -25,     4,   -24
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  config_parser::yydefgoto_[] =
  {
        -1,     3,     4,     5,    12,    31,    14,    15,    16,    17,
      18,    36,    32,    33
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char config_parser::yytable_ninf_ = -1;
  const unsigned char
  config_parser::yytable_[] =
  {
        37,    21,    13,    39,    45,    20,     6,     7,     9,     8,
      10,    13,     1,    22,    23,    24,    44,    40,    40,    35,
       2,     2,    27,    38,    11,    19,    28,    29,    19,    22,
      30,    19,    28,    29,    25,    34,    30,    11,    22,    41,
      42,    43,     0,    26
  };

  /* YYCHECK.  */
  const signed char
  config_parser::yycheck_[] =
  {
        24,     3,     5,     4,     4,     8,     0,     5,     0,     7,
       4,    14,     0,    15,    16,    17,    40,    18,    18,     3,
       9,     9,     8,     5,     9,     9,    10,    11,     9,    15,
      14,     9,    10,    11,     6,     9,    14,     9,    15,    35,
      16,    16,    -1,    14
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  config_parser::yystos_[] =
  {
         0,     0,     9,    20,    21,    22,    23,     5,     7,     0,
      23,     9,    23,    24,    25,    26,    27,    28,    29,     9,
      24,     3,    15,    16,    17,     6,    26,     8,    10,    11,
      14,    24,    31,    32,     9,     3,    30,    32,     5,     4,
      18,    31,    16,    16,    32,     4
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  config_parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  config_parser::yyr1_[] =
  {
         0,    19,    20,    20,    21,    21,    22,    22,    23,    24,
      24,    25,    25,    26,    26,    26,    26,    27,    28,    29,
      30,    30,    31,    31,    32,    32,    32,    32
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  config_parser::yyr2_[] =
  {
         0,     2,     1,     1,     1,     2,     5,     2,     3,     1,
       3,     1,     2,     1,     1,     1,     1,     4,     2,     5,
       1,     3,     1,     3,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const config_parser::yytname_[] =
  {
    "\"end of file\"", "error", "$undefined", "T_LPARAN", "T_RPARAN",
  "T_LBRACE", "T_RBRACE", "T_LBRACKET", "T_RBRACKET", "T_STRING", "T_LONG",
  "T_DOUBLE", "T_COMMENT", "T_WHITESPACE", "T_QUOTED_STRING", "T_DOT",
  "T_STMT_TERM", "T_ASSIGN", "T_COMMA", "$accept", "start", "block_list",
  "block_start", "block", "identifier", "inner_statement_list",
  "inner_statement", "variable_assignment", "define_statement",
  "function_statement", "argument", "argument_list", "scalar_val", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const config_parser::rhs_number_type
  config_parser::yyrhs_[] =
  {
        20,     0,    -1,    21,    -1,     0,    -1,    23,    -1,    21,
      23,    -1,     9,     7,    24,     8,     5,    -1,     9,     5,
      -1,    22,    25,     6,    -1,     9,    -1,    24,    15,     9,
      -1,    26,    -1,    25,    26,    -1,    23,    -1,    29,    -1,
      27,    -1,    28,    -1,    24,    17,    30,    16,    -1,    24,
      16,    -1,    24,     3,    31,     4,    16,    -1,    32,    -1,
       3,    31,     4,    -1,    32,    -1,    31,    18,    32,    -1,
      10,    -1,    11,    -1,    14,    -1,    24,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  config_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     7,     9,    12,    18,    21,    25,
      27,    31,    33,    36,    38,    40,    42,    44,    49,    52,
      58,    60,    64,    66,    70,    72,    74,    76
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  config_parser::yyrline_[] =
  {
         0,   156,   156,   156,   159,   160,   163,   164,   167,   171,
     172,   175,   176,   179,   180,   181,   182,   185,   188,   191,
     195,   196,   199,   200,   203,   204,   205,   206
  };

  // Print the state stack on the debug stream.
  void
  config_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  config_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  config_parser::token_number_type
  config_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
      15,    16,    17,    18
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int config_parser::yyeof_ = 0;
  const int config_parser::yylast_ = 43;
  const int config_parser::yynnts_ = 14;
  const int config_parser::yyempty_ = -2;
  const int config_parser::yyfinal_ = 9;
  const int config_parser::yyterror_ = 1;
  const int config_parser::yyerrcode_ = 256;
  const int config_parser::yyntokens_ = 19;

  const unsigned int config_parser::yyuser_token_number_max_ = 273;
  const config_parser::token_number_type config_parser::yyundef_token_ = 2;


} // dispatch





    void dispatch::config_parser::error (const location_type& loc, const std::string& msg) {
		driver.error(loc, msg);
	}

