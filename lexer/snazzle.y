  %{
  #include <cstdio>
  #include <iostream>
  using namespace std;



  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
 
  void yyerror(const char *s);
%}


%union {
  char* func;

  char* loop;

  char* EQ;
  char* GT;
  char* LT;
  char* GT_EQ;
  char* LT_EQ;

  char* var_dec;
  char* var_name;

  char* increment;
  char* decrement;
  
  int integer;

  char* open_round;
  char* close_round;
  char* open_curly;
  char* close_curly;

  char* speech_mark;
  char* assignment;
  char* string;

  char* plus;
  char* minus;
  char* divide;
  char* times;


  char* semi_colon;
}


// The lower the rule, the higher the precedence
// Specify the tokens and precedence

%token <func> FUNCTION

%token <loop> LOOP

 
%token <EQ> EQ
%token <GT> GT
%token <LT> LT
%token <GT_EQ> GT_EQ
%token <LT_EQ> LT_EQ

%token <var_dec> VAR_DECLARATION
%token <var_name> IDENTIFIER

%token <increment> INCREMENT
%token <decrement> DECREMENT

%token <integer> INTEGER

%token <open_round> OPEN_ROUND
%token <close_round> CLOSE_ROUND
%token <open_curly> OPEN_CURLY
%token <close_curly> CLOSE_CURLY

%token <speech_mark> SPEECH_MARK
%token <assignment> ASSIGNMENT
%token <string> STRING

%token <plus> PLUS
%token <minus> MINUS
%token <divide> DIVIDE
%token <times> TIMES

%token <semi_colon> SEMI_COLON

%left '*' '/'
%left '+' '-'
%left '<' "<=" '>' ">="
%right "++" "--"
%left '='


%%

// bison tutorial : http://www.eecg.toronto.edu/~jzhu/csc467/readings/csc467-bison-tut.pdf
// Copy of the duude in the compiler vid https://www.youtube.com/watch?v=eF9qWbuQLuw

stmt:                     compound_stmt '}'
                        | "for" '(' expr ')' stmt
                        | variable_definition ';'
                        | expr ';'
                        | ';'
                        ;

compound_stmt:            '{'
                        | compound_stmt stmt
                        ;

variable_definition:      "var" IDENTIFIER ":=" expr
                        ;

expr:                     INTEGER
                        | STRING
                        | IDENTIFIER
                        | '(' expr ')'
                        | expr '=' expr {cout <<"1" << endl; }
                        | expr '+' expr
                        | expr '-' expr  
                        | expr '*' expr
                        | expr '/' expr
                        | expr "++" 
                        | expr "--"   
                        | expr '<' expr
                        | expr "<=" expr
                        | expr '>' expr
                        | expr ">=" expr
                        ;  
%%

int main(int, char**) {
  //#ifdef YYDEBUG
  //yydebug = 1;
  //#endif
  // Open a file handle to a particular file:
  FILE *myfile = fopen("a.snazzle.file", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "I can't open a.snazzle.file!" << endl;
    return -1;
  }
  // Set Flex to read from it instead of defaulting to STDIN:
  yyin = myfile;
  
  // Parse through the input:
  yyparse();
  
}

void yyerror(const char *s) {

  fprinf (stderr, "%s\n", s);
  
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}