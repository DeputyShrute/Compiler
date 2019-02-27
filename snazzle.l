%{
  #include <cstdio>

  #include "snazzle.tab.h"  // to get the token types from Bison

%}
%%
[ \t\n]           ;
['main', 'for', 'return', 'print']+        { yylval.mval = strdup(yytext); return FUNCTION;}
[0-9]+\.[0-9]+    { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+            { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+      { yylval.sval = strdup(yytext); return STRING;}
['"', '(', ')', '{', '}']      { yylval.gval = strdup(yytext); return BRACKET;}

%%


 // We have to strdup yytext because Flex will change it for the next token.
  // Note that this memory must be freed somewhere, so that's why we call
  // free() above in the Bison section.  (Aside: we use free() instead of
  // delete because strdup is a C function that uses malloc, not a C++
  // function that uses new.)

