%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  // to get the token types from Bison
  int newLine = 1;

%}
%%
[ \t]+ 
[\n]+ 								{++newLine;}
"main"                  		    { yylval.val = strdup(yytext);      return MAIN; } 
"print"     		  				{ yylval.val = strdup(yytext); 			return FUNCTION; }
"ENDFOR"                  { yylval.val = strdup(yytext); 			return ENDFOR; }


"for"       						{ yylval.val = strdup(yytext); 			return LOOP; }

"="									{ yylval.val = strdup(yytext); 				return EQ; }
">"									{ yylval.val = strdup(yytext); 				return GT; }
"<"									{ yylval.val = strdup(yytext); 				return LT; }
">="								{ yylval.val = strdup(yytext); 			return GT_EQ; }
"<="								{ yylval.val = strdup(yytext); 			return LT_EQ; }
	


['var']+							{ yylval.val = strdup(yytext); 			return VAR_DECLARATION; }
['a', 'b', 'c', 'd', 'e', 'f']+		{ yylval.val = strdup(yytext); 		return IDENTIFIER; }

"++" 								{ yylval.val = strdup(yytext); 		return INCREMENT; }
"--" 								{ yylval.val = strdup(yytext); 		return DECREMENT; }

[0-9]+          					{ yylval.val = strdup(yytext); 			return INTEGER; }
	
"("									{ yylval.val = strdup(yytext); 		return OPEN_ROUND; } 
")"									{ yylval.val = strdup(yytext); 		return CLOSE_ROUND; }
"{"									{ yylval.val = strdup(yytext); 		return OPEN_CURLY; }
"}"									{ yylval.val = strdup(yytext); 		return CLOSE_CURLY; }




['"']+  							{ yylval.val = strdup(yytext); 		return SPEECH_MARK; }
":="								{ yylval.val = strdup(yytext); 		return ASSIGNMENT; }
[a-zA-Z0-9]+   		  				{ yylval.val = strdup(yytext); 			return STRING; }
	

"+"									{ yylval.val = strdup(yytext); 			return PLUS; }
"-"									{ yylval.val = strdup(yytext); 			return MINUS; }
"/"									{ yylval.val = strdup(yytext); 			return DIVIDE; }
"*"									{ yylval.val = strdup(yytext); 			return TIMES; }

";"									{ yylval.val = strdup(yytext); 		return SEMI_COLON; }
%%