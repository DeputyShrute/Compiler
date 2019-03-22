%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  // to get the token types from Bison
  

%}
%%
[ \t\n]+           																;
"print"     		  				{ yylval.func = strdup(yytext); 			return FUNCTION; }

"for"       						{ yylval.loop = strdup(yytext); 			return LOOP; }

"="									{ yylval.EQ = strdup(yytext); 				return EQ; }
">"									{ yylval.GT = strdup(yytext); 				return GT; }
"<"									{ yylval.LT = strdup(yytext); 				return LT; }
">="								{ yylval.GT_EQ = strdup(yytext); 			return GT_EQ; }
"<="								{ yylval.LT_EQ = strdup(yytext); 			return LT_EQ; }
	


['var']+							{ yylval.var_dec = strdup(yytext); 			return VAR_DECLARATION; }
['a', 'b', 'c', 'd', 'e', 'f']+		{ yylval.var_name = strdup(yytext); 		return IDENTIFIER; }

"++" 								{ yylval.increment = strdup(yytext); 		return INCREMENT; }
"--" 								{ yylval.decrement = strdup(yytext); 		return DECREMENT; }

[0-9]+          					{ yylval.integer = atoi(yytext); 			return INTEGER; }
	
"("									{ yylval.open_round = strdup(yytext); 		return OPEN_ROUND; } 
")"									{ yylval.close_round = strdup(yytext); 		return CLOSE_ROUND; }
"{"									{ yylval.open_curly = strdup(yytext); 		return OPEN_CURLY; }
"}"									{ yylval.close_curly = strdup(yytext); 		return CLOSE_CURLY; }




['"']+  							{ yylval.speech_mark = strdup(yytext); 		return SPEECH_MARK; }
":="								{ yylval.assignment = strdup(yytext); 		return ASSIGNMENT; }
[a-zA-Z0-9]+   		  				{ yylval.string = strdup(yytext); 			return STRING; }
	

"+"									{ yylval.plus = strdup(yytext); 			return PLUS; }
"-"									{ yylval.minus = strdup(yytext); 			return MINUS; }
"/"									{ yylval.divide = strdup(yytext); 			return DIVIDE; }
"*"									{ yylval.times = strdup(yytext); 			return TIMES; }

";"									{ yylval.semi_colon = strdup(yytext); 		return SEMI_COLON; }
%%