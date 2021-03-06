
%{

#include "config_nodes.h"
#include "pre_driver.h"
#include "config_y.tab.H"
#include "driver.h"

typedef dispatch::config_parser::token_type token_type;
typedef dispatch::config_parser::token	token;
typedef	dispatch::config_parser::semantic_type	semantic_type;
typedef	dispatch::config_parser::location_type	location_type;
int colnum = 0;
int prev_lineno = 0;
char* comment_start = 0;
int comment_start_line = 0;
int comment_start_col = 0;
#define yyterminate() return token::END

# define YY_DECL	token_type dispatch::config::configScanner::lex (semantic_type* yylval, location_type* yylloc)


#ifdef yywrap
#	undef yywrap
#endif

#define yywrap() 1


%}

%option c++

/*
%option prefix="config"
*/
%option batch

%option nounput

%option debug

%option yylineno

%option nodefault

%x	CONFIG
%x	COMMENT

%{
	
#define YY_USER_ACTION { handlePosition(*yylloc, yytext, yyleng); }

/*{ \
		yylloc->end.line = yylloc->begin.line = yylineno; \
		yylloc->begin.column = colnum; \
		yylloc->end.column = colnum; \
		do { \
			for (int _nl_i = 0; _nl_i < yyleng; ++_nl_i ) {\
				++(yylloc->end.column); \
				if ( yytext[_nl_i] == '\n' ) { \
					yylloc->end.column = 0; \
					++yylineno; \
				} \
			} \
			yylloc->end.line = yylineno; \
			colnum = yylloc->end.column; \
		}while(0); \
	}
*/

/* #define YY_USER_ACTION  yylloc->columns(yyleng); */

%}


%% /** Regler for tokenisering **/
%{
//	colnum = 0;
//	std::cout << "Setting colnum to zero" << std::endl;
	BEGIN CONFIG;
	yylloc->step();
%}

<CONFIG>"{"		{ return token::T_LBRACE; }
<CONFIG>"}"		{ return token::T_RBRACE; }
<CONFIG>"("		{ return token::T_LPARAN; }
<CONFIG>")"		{ return token::T_RPARAN; }
<CONFIG>"["		{ return token::T_LBRACKET; }
<CONFIG>"]"		{ return token::T_RBRACKET; }
<CONFIG>"."		{ return token::T_DOT; }
<CONFIG>"="		{ return token::T_ASSIGN; }
<CONFIG>";"		{ return token::T_STMT_TERM; }
<CONFIG>","		{ return token::T_COMMA; }


<CONFIG>([0-9]+\.[0-9]+)		{
									yylval->double_val = atof(yytext);
									return token::T_DOUBLE;
								}

<CONFIG>([0-9]+)				{ 
									yylval->long_val = atol(yytext);
									return token::T_LONG;
								}
<CONFIG>([a-zA-Z_][a-zA-Z0-9_]*)	{
										yylval->str_val = strdup(yytext);
										return token::T_STRING;
							}
<CONFIG>([ \t\r\n]+) 			{
										return token::T_WHITESPACE;
							}

<CONFIG>(\"[^\"]*?\")				{

										int t_len = yyleng; //strlen(yytext);
										if (t_len > 2) {
											t_len--;
											char tmp = yytext[t_len];
											yytext[t_len] = '\0';
											yylval->str_val = strdup(yytext+1);
											yytext[t_len] = tmp;
										} else {
											yylval->str_val = strdup("");
										}

										return token::T_QUOTED_STRING;
						}
						
<CONFIG>(\/\*)			{
							comment_start = yytext;
							comment_start_line = yylloc->begin.line;
							comment_start_col = yylloc->begin.column;
							BEGIN COMMENT;
						}

<COMMENT>(\*\/)			{
							yylval->str_val = strdup(comment_start);
							yylloc->begin.line = comment_start_line;
							yylloc->begin.column = comment_start_col;
							BEGIN CONFIG;
							return token::T_COMMENT;
						}

<COMMENT>(.|\n)			{}

%%
namespace dispatch {
namespace config {

configScanner::configScanner(std::istream* in, std::ostream* out) : 
	configFlexLexer(in, out),
	line(1),
	col(0)
{

}

configScanner::~configScanner() {}

} // end namespace config
} // end namepspace dispatch

int configFlexLexer::yylex() {
	return 0;
}
#ifdef yywrap 
#undef yywrap
#endif
int configFlexLexer::yywrap() {
	return 0;
	// void
}
