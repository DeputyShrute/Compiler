%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  // to get the token types from Bison
  int newLine = 1;

%}
%%
[ \t]+ 
[\n]+ 								                                              {++newLine;}

"main"                  		                                        { yylval.val = strdup(yytext);      return MAIN; } 
"print"     		  			                                          	{ yylval.val = strdup(yytext); 			return FUNCTION; }
"function"									  		                                  { yylval.val = strdup(yytext); 			return PROCEDURE; }
"project"+\ [a-z]+                                                	{ yylval.val = strdup(yytext); 			return NAMESPACE; }

"ENDPROJECT"                                                        {  yylval.val = strdup(yytext); 			return ENDPROJECT; }
"for"       					                                              { yylval.val = strdup(yytext); 			return LOOP; }
"ENDFOR"                                                  			 	  { yylval.val = strdup(yytext); 			return ENDFOR; }
"ENDNESTFOR"                                                  			 	  { yylval.val = strdup(yytext); 			return ENDNESTFOR; }

"end"                                                               { yylval.val = strdup(yytext); 			return RET; }
"endMain"                                                           { yylval.val = strdup(yytext); 			return RETMAIN; }

"CALL"                                                              { yylval.val = strdup(yytext); 			return CALLFUNCTION; }
"if"       						                                             	{ yylval.val = strdup(yytext); 			return IF; }
"ENDIF"                                                             { yylval.val = strdup(yytext); 			return ENDIF; }
"else"	                                                            { yylval.val = strdup(yytext); 			return ELSE; }
"else_if"					                                                 	{ yylval.val = strdup(yytext); 			return ELSEIF; }

"="								                                                	{ yylval.val = strdup(yytext); 			return EQ; }
">"								                                                	{ yylval.val = strdup(yytext); 			return GT; }
"<"								                                                 	{ yylval.val = strdup(yytext); 			return LT; }
">="							                                                 	{ yylval.val = strdup(yytext); 			return GT_EQ; }
"<="								                                                { yylval.val = strdup(yytext); 			return LT_EQ; }
	
['var']+							                                              { yylval.val = strdup(yytext); 			return VAR_DECLARATION; }
['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm']+	{ yylval.val = strdup(yytext); 		  return IDENTIFIER; }
['n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']+  { yylval.val = strdup(yytext); 		  return IDENTIFIER; }

"++" 							                                                	{ yylval.val = strdup(yytext); 		  return INCREMENT; }
"--" 							                                                	{ yylval.val = strdup(yytext); 		  return DECREMENT; }

[0-9]+          			                                          		{ yylval.val = strdup(yytext); 			return INTEGER; }
	
"("								                                                	{ yylval.val = strdup(yytext); 		  return OPEN_ROUND; } 
")"								                                                	{ yylval.val = strdup(yytext); 		  return CLOSE_ROUND; }
"{"								                                                	{ yylval.val = strdup(yytext); 		  return OPEN_CURLY; }
"}"								                                                	{ yylval.val = strdup(yytext); 		  return CLOSE_CURLY; }

['"']+  						                                              	{ yylval.val = strdup(yytext); 		  return SPEECH_MARK; }
":="							                                                	{ yylval.val = strdup(yytext); 		  return ASSIGNMENT; }
[a-zA-Z0-9]+   		  		                                        		{ yylval.val = strdup(yytext); 			return STRING; }
	
"+"									                                                { yylval.val = strdup(yytext); 			return PLUS; }
"-"									                                                { yylval.val = strdup(yytext); 			return MINUS; }
"/"								                                                	{ yylval.val = strdup(yytext); 			return DIVIDE; }
"*"								                                                	{ yylval.val = strdup(yytext); 			return TIMES; }

";"									                                                { yylval.val = strdup(yytext); 		  return SEMI_COLON; }
%%