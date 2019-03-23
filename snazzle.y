  %{
  #include <cstdio>
  #include <iostream>
    #include <string.h>
  using namespace std;



  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  
  extern FILE *yyin;
   FILE *output=fopen("output.s", "w");
  void yyerror(const char *s);
%}


%union {
  char* val;
  int integer;


}


// The lower the rule, the higher the precedence
// Specify the tokens and precedence


%token <val> MAIN
%token <val> FUNCTION

%token <val> LOOP

 
%token <val> EQ
%token <val> GT
%token <val> LT
%token <val> GT_EQ
%token <val> LT_EQ

%token <val> VAR_DECLARATION
%token IDENTIFIER

%token <val> INCREMENT
%token <val> DECREMENT

//%token <integer> INTEGER

%token <val> OPEN_ROUND
%token <val> CLOSE_ROUND
%token <val> OPEN_CURLY
%token <val> CLOSE_CURLY

%token <val> SPEECH_MARK
%token <val> ASSIGNMENT
%token INTEGER
%token STRING
%token <val> PLUS
%token <val> MINUS
%token <val> DIVIDE
%token <val> TIMES

%token <val> SEMI_COLON

%left TIMES DIVIDE
%left PLUS MINUS
%left LT LT_EQ GT GT_EQ
%right INCREMENT DECREMENT
%left EQ

%type<integer> intExpr INTEGER
%type<val> strExpr STRING
%type<val> idenExpr IDENTIFIER


%%


stmt:                     compound_stmt CLOSE_CURLY
                        | LOOP OPEN_ROUND stmt stmt stmt CLOSE_ROUND stmt 
                        | MAIN stmt
                        | variable_definition SEMI_COLON
                        | function_type SEMI_COLON
                        | expr SEMI_COLON
                        | SEMI_COLON
                        ;


function_type:            FUNCTION OPEN_ROUND SPEECH_MARK expr SPEECH_MARK CLOSE_ROUND 
                        | FUNCTION OPEN_ROUND IDENTIFIER CLOSE_ROUND
                        ;


compound_stmt:            OPEN_CURLY
                        | compound_stmt stmt
                        ;


variable_definition:      VAR_DECLARATION IDENTIFIER ASSIGNMENT expr
                        | IDENTIFIER ASSIGNMENT expr
                        ;



expr:                     strExpr
                        | idenExpr
                        | intExpr
                        ; 


strExpr:                STRING 
                        | SPEECH_MARK strExpr SPEECH_MARK { fprintf(output, "Test: %s \n", $2); }
                        | OPEN_ROUND strExpr CLOSE_ROUND 
                        ;


idenExpr:                 IDENTIFIER     
                        | IDENTIFIER INCREMENT  {}  
                        | IDENTIFIER DECREMENT  {}
                        | IDENTIFIER LT INTEGER {}
                        | IDENTIFIER LT_EQ INTEGER {}
                        | IDENTIFIER GT INTEGER {}
                        | IDENTIFIER GT_EQ INTEGER {}                
                        ; 


intExpr:                  INTEGER {$$ = $1;} 
                        | intExpr EQ intExpr {}
                        | intExpr PLUS intExpr { $$ = $1 + $3; fprintf(output, "Test: %d = %d + %d \n", $$, $1, $3); }
                        | intExpr MINUS intExpr  { $$ = $1 - $3; fprintf(output, "Test: %d = %d - %d \n", $$, $1, $3); }
                        | intExpr TIMES intExpr { $$ = $1 * $3; fprintf(output, "Test: %d = %d * %d \n", $$, $1, $3); }
                        | intExpr DIVIDE intExpr  { $$ = $1 / $3; fprintf(output, "Test: %d = %d / %d \n", $$, $1, $3); }
                        ;  

%%


int main(int, char**) {
  #ifdef YYDEBUG
  yydebug = 1;
  #endif

  // Open a file handle to a particular file:
  FILE *myfile = fopen("a.snazzle.file", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open a.snazzle.file!" << endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;

  /*
  fprintf(output, ".section .text");
  fprintf(output, ".section .data\n");
  fprintf(output, "a:\n.long 0\n");
  fprintf(output, "b:\n.long 0\n"); 
  fprintf(output, "c:\n.long 0\n");
  fprintf(output, "d:\n.long 0\n"); 
  fprintf(output, "e:\n.long 0\n");
  fprintf(output, "f:\n.long 0\n"); 

  fprintf(output, ".globl _start\n");
  fprintf(output, "_start"); 
  */

  // Parse through the input:
  yyparse();
  
}

void yyerror(const char *s) {
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}