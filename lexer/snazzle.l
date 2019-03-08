%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  // to get the token types from Bison

%}
%%
[ \t\n]           ;
['for', 'print']+        { yylval.mval = strdup(yytext); return FUNCTION;}
['=','>','<','<=','>=']+		{yylval.con = strdup(yytext); return CONDITIONAL;}
['var']+\ [a-z]+  { yylval.dval = strdup(yytext); return DECLAREVAR;}
[a-z]+\ [':=']+ { yylval.tar = strdup(yytext); return TARGET;}
[a-z]+\ ['inc']+ { yylval.incr = strdup(yytext); return INCREMENT;}
[a-z]+\ ['dec']+ { yylval.decr = strdup(yytext); return DECREMENT;}
[0-9]+          { yylval.ival = atoi(yytext); return INT; }
['(', ')', '{', '}']+    { yylval.gval = strdup(yytext); return BRACKET;}
['"']+  { yylval.qval = strdup(yytext); return QUOTELITERAL;}
[':=']+		{yylval.aval = strdup(yytext); return ASSIGN;}
[a-zA-Z0-9]+      { yylval.sval = strdup(yytext); return STRING;}
['+','/','*']+ { yylval.arith = strdup(yytext); return ARITHMETIC;}
[-]+ { yylval.arith = strdup(yytext); return ARITHMETIC;}
[;]+ { yylval.endval = strdup(yytext); return END;}
%%


