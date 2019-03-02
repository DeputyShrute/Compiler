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

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  Initially (by default), yystype
// is merely a typedef of "int", but for non-trivial projects, tokens could
// be of any arbitrary data type.  So, to deal with that, the idea is to
// override yystype's default typedef to be a C union instead.  Unions can
// hold all of the types of tokens that Flex could return, and this this means
// we can return ints or floats or strings cleanly.  Bison implements this
// mechanism with the %union directive:
%union {
  char *mval;
  char *gval;
  int ival;
  float fval;
  char *sval;
  char* aval;
  char *con;
  char* dval;
  char* arith;
  char* tar;

  
}

// Define the "terminal symbol" token types I'm going to use (in CAPS
// by convention), and associate each with a field of the %union:
%token <mval> FUNCTION
%token <gval> BRACKET
%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <aval> ASSIGN
%token <con> CONDITIONAL
%token <dval> DECLAREVAR
%token <arith> ARITHMETIC
%token <tar> TARGET




%%
// This is the actual grammar that bison will parse, but for right now it's just
// something silly to echo to the screen what bison gets from flex.  We'll
// make a real one shortly:
snazzle:
    FUNCTION snazzle {
    cout << "bison found a function: " << $1 << endl; free($1);
    }
  | BRACKET snazzle {
    cout << "Bison found a bracket: " << $1 << endl; free($1);
    }
  | DECLAREVAR snazzle {
    cout << "Bison found a a decleration: " << $1 << endl; free($1);
    }    
  | TARGET snazzle {
    cout << "Bison found a a target : " << $1 << endl; free($1);
    } 
  | INT snazzle      {
      cout << "bison found an int: " << $1 << endl;
    }
  | FLOAT snazzle  {
      cout << "bison found a float: " << $1 << endl;
    }
  | STRING snazzle {
      cout << "bison found a string: " << $1 << endl; free($1);
    }
  | ASSIGN snazzle {
      cout << "bison found a assignment op: " << $1 << endl; free($1);
    }
  | CONDITIONAL snazzle {
      cout << "bison found a CONDITIONAL op: " << $1 << endl; free($1);
    }
  | ARITHMETIC snazzle {
      cout << "bison found a ARITHMETIC: " << $1 << endl; free($1);
    } 
 
  | FUNCTION       {
    cout << "bison found a function: " << $1 << endl; free($1);
    } 
   | BRACKET       {
    cout << "Bison found a bracket: " << $1 << endl; free($1);
    }  
  | TARGET       {
    cout << "Bison found a TARGET: " << $1 << endl; free($1);
    } 
  | DECLAREVAR            {
      cout << "Bison found a a decleration: " << $1 << endl; free($1);
    }  
  | INT            {
      cout << "bison found an int: " << $1 << endl;
    }
  | FLOAT          {
      cout << "bison found a float: " << $1 << endl;
    }
  | STRING         {
      cout << "bison found a string: " << $1 << endl; free($1);
    }
  | ASSIGN         {
      cout << "bison found a Assignment : " << $1 << endl; free($1);
    }  
  | CONDITIONAL         {
      cout << "bison found a CONDITIONAL op: " << $1 << endl; free($1);
    }
   | ARITHMETIC     {
      cout << "bison found a an ARITHMETIC: " << $1 << endl; free($1);
    }

  ;
%%

int main(int, char**) {
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
  cout << "EEK, parse error!  Message: " << s << endl;
  // might as well halt now:
  exit(-1);
}

