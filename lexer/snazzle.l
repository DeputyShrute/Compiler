%{
  #include <cstdio>
  #include <string.h>
  #include "snazzle.tab.h"  // to get the token types from Bison

%}
%%
[ \t\n]           ;
['main', 'for', 'return', 'print']+        { yylval.mval = strdup(yytext); return FUNCTION;}
['=','>','<','<=','>=','<']+		{yylval.con = strdup(yytext); return CONDITIONAL;}
['var']+\ [a-z]+  { yylval.dval = strdup(yytext); return DECLAREVAR;}
[a-z]+\ [':=']+ { yylval.tar = strdup(yytext); return TARGET;}
[0-9]+            { yylval.ival = atoi(yytext); return INT; }
['"', '(', ')', '{', '}']+    { yylval.gval = strdup(yytext); return BRACKET;}
[':=']+		{yylval.aval = strdup(yytext); return ASSIGN;}
[a-zA-Z0-9]+      { yylval.sval = strdup(yytext); return STRING;}
['+','/','*','-']+ { yylval.arith = strdup(yytext); return ARITHMETIC;}

%%


 // We have to strdup yytext because Flex will change it for the next token.
  // Note that this memory must be freed somewhere, so that's why we call
  // free() above in the Bison section.  (Aside: we use free() instead of
  // delete because strdup is a C function that uses malloc, not a C++
  // function that uses new.)


