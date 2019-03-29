%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  //to get the token types from Bison
  int newLine = 1;

%}
%%
[ \t]+ 								//tabs in the code
[\n]+ 								{++newLine;} //ignores new line
"main"                  		    { yylval.val = strdup(yytext);      return MAIN; } //identifies 'main' token
"print"     		  				{ yylval.val = strdup(yytext); 			return FUNCTION; }
"ENDFOR"                  { yylval.val = strdup(yytext); 			return ENDFOR; }


"for"       						{ yylval.val = strdup(yytext); 			return LOOP; } //identifies 'for' token

"="									{ yylval.val = strdup(yytext); 				return EQ; } //identifies 'equal' token
">"									{ yylval.val = strdup(yytext); 				return GT; } //identifies 'greater than' token
"<"									{ yylval.val = strdup(yytext); 				return LT; } //identifies 'less than' token
">="								{ yylval.val = strdup(yytext); 			return GT_EQ; } //identifies 'greater or equal' token
"<="								{ yylval.val = strdup(yytext); 			return LT_EQ; } //identifies 'less or equal' token
	


['var']+							{ yylval.val = strdup(yytext); 			return VAR_DECLARATION; } //identifies 'variable declararion' token
['a', 'b', 'c', 'd', 'e', 'f']+		{ yylval.val = strdup(yytext); 		return IDENTIFIER; } //identifies 'variable names' token

"++" 								{ yylval.val = strdup(yytext); 		return INCREMENT; } //identifies 'increment' token
"--" 								{ yylval.val = strdup(yytext); 		return DECREMENT; } //identifies 'decrement' token

[0-9]+          					{ yylval.val = strdup(yytext); 			return INTEGER; } //identifies 'integer values' token
	
"("									{ yylval.val = strdup(yytext); 		return OPEN_ROUND; } //identifies 'open brace' token
")"									{ yylval.val = strdup(yytext); 		return CLOSE_ROUND; } //identifies 'close' token
"{"									{ yylval.val = strdup(yytext); 		return OPEN_CURLY; } //identifies 'open curly' token
"}"									{ yylval.val = strdup(yytext); 		return CLOSE_CURLY; } //identifies 'close curly' token




['"']+  							{ yylval.val = strdup(yytext); 		return SPEECH_MARK; }
":="								{ yylval.val = strdup(yytext); 		return ASSIGNMENT; }
[a-zA-Z0-9]+   		  				{ yylval.val = strdup(yytext); 			return STRING; }
	

"+"									{ yylval.val = strdup(yytext); 			return PLUS; } //identifies 'addition' token
"-"									{ yylval.val = strdup(yytext); 			return MINUS; } //identifies 'subtraction' token
"/"									{ yylval.val = strdup(yytext); 			return DIVIDE; } //identifies 'divide' token
"*"									{ yylval.val = strdup(yytext); 			return TIMES; } //identifies 'multiplication' token

";"									{ yylval.val = strdup(yytext); 		return SEMI_COLON; } //identifies 'semi colon, end of statement' token
%%