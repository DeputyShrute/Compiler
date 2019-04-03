  %{
  #include <cstdio>
  #include <iostream>
  #include <string>
    #include <string.h>
  using namespace std;



  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern int newLine;
  extern FILE *yyin;
   FILE *output=fopen("output.s", "w");
  void yyerror(const char *s);
  int loop = 0;
  int temp = 2;
  int numTimes = 0;
  int numDiv = 0;
  char reg = 'c';
  char reg2 = 'x';
%}


%union {
  char* val;
  int integer;


}

//Tokens are converted to integer and string in assmebly. 


%token <val> MAIN
%token <val> FUNCTION
%token <val> LOOP
%token <val> ENDFOR
%token <val> ENDNESTFOR

%token <val> IF
%token <val> ENDIF
%token <val> ELSE
 
%token <val> EQ
%token <val> GT
%token <val> LT
%token <val> GT_EQ
%token <val> LT_EQ

%token <val> VAR_DECLARATION
%token <val> IDENTIFIER

%token <val> INCREMENT
%token <val> DECREMENT



%token <val> OPEN_ROUND
%token <val> CLOSE_ROUND
%token <val> OPEN_CURLY
%token <val> CLOSE_CURLY

%token <val> SPEECH_MARK
%token <val> ASSIGNMENT
%token <val> INTEGER
%token <val> STRING
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


%type<val> stmt
%type<val> function_type
%type<val> compound_stmt
%type<val> variable_definition 
%type<val> expr



%%


stmt:                   compound_stmt CLOSE_CURLY
                        | compound_stmt CLOSE_CURLY ENDFOR SEMI_COLON     
                            {fprintf(output, "addl $1, %%e%c%c\njmp loop_start_%d\nend_loop_%d:\n",reg, reg2,loop, loop );loop++; if(reg = 'd'){reg--;reg2=='x';}}
                        | compound_stmt  CLOSE_CURLY ENDNESTFOR SEMI_COLON     
                            { reg2='x';reg--;fprintf(output, "addl $1, %%edi\njmp loop_start_%d\nend_loop_%d:\n",loop, loop ); loop--; reg--;}
                    
                        | LOOP OPEN_ROUND VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER SEMI_COLON expr SEMI_COLON INCREMENT SEMI_COLON CLOSE_ROUND    
                            {loop++;fprintf(output, "movl $%s, %%e%c%c\nloop_start_%d:\ncmpl $%s, %%e%c%c\nje end_loop_%d\n", $6,reg,reg2, loop, $8,reg, reg2,loop);reg++;reg2='i';}

                        | LOOP OPEN_ROUND VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER SEMI_COLON expr SEMI_COLON DECREMENT SEMI_COLON CLOSE_ROUND 
                            {loop++; fprintf(output, "movl $%s, %%ecx\nloop_start_%d:\nsubl $1, %%ecx\ncmpl $%s, %%ecx\nje end_loop_%d\n", $6, loop, $8, loop);reg++;}

                        | IF OPEN_ROUND IDENTIFIER LT expr CLOSE_ROUND {fprintf(output,"cmpl $%s, %s\njl if\njmp else\nif:\n",$5,$3 );} 
                        | IF OPEN_ROUND IDENTIFIER GT expr CLOSE_ROUND {fprintf(output,"cmpl $%s, %s\njg if\njmp else\nif:\n",$5,$3 );} 
                        | IF OPEN_ROUND IDENTIFIER EQ expr CLOSE_ROUND {fprintf(output,"cmpl $%s, %s\nje if\njmp else\nif:\n",$5,$3 );} 
                        | IF OPEN_ROUND IDENTIFIER LT_EQ expr CLOSE_ROUND {fprintf(output,"cmpl $%s, %s\njle if\njmp else\nif:\n",$5,$3 );} 
                        | IF OPEN_ROUND IDENTIFIER GT_EQ expr CLOSE_ROUND {fprintf(output,"cmpl $%s, %s\njge if\njmp else\nif:\n",$5,$3 );} 
                        | compound_stmt CLOSE_CURLY ELSE {fprintf(output,"jmp end\nelse:\n" );} 
                        | compound_stmt CLOSE_CURLY ENDIF SEMI_COLON {fprintf(output,"end:\n");}
                        | MAIN stmt
                        | variable_definition SEMI_COLON
                        | function_type SEMI_COLON
                        | expr SEMI_COLON
                        | SEMI_COLON                                                   
                        ;



function_type:            FUNCTION OPEN_ROUND SPEECH_MARK expr SPEECH_MARK CLOSE_ROUND  { fprintf(output, "\n PRINT STRING      : print ( ' %s ' )"       ,$4);}
                        | FUNCTION OPEN_ROUND IDENTIFIER CLOSE_ROUND                    { fprintf(output, "\n PRINT VARIABLE    : print (  %s  )"       ,$3);}
                        | FUNCTION OPEN_ROUND INTEGER CLOSE_ROUND                       { fprintf(output, "\n PRINT INTEGER     : print (  %s  )"       ,$3);}
                        ;


compound_stmt:            OPEN_CURLY                                  { }
                        | compound_stmt stmt                          { }
                        ;


variable_definition:     VAR_DECLARATION {$$ = $1;} 
                        | VAR_DECLARATION IDENTIFIER ASSIGNMENT expr { fprintf(output, "movl %%ebx, %s\nmovl %s, %%ebx\n", $2, $2);}
                        | VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER { fprintf(output, "movl $%s, %s\nmovl %s, %%ebx\n", $4, $2, $2);}
                        | IDENTIFIER ASSIGNMENT expr { fprintf(output, "movl %%ebx, %s\nmovl %s, %%ebx\n", $1, $1);} 
                        ;



expr:                     INTEGER                      
                        | STRING                                  
                        | OPEN_ROUND expr CLOSE_ROUND                 { $$ = $2;fprintf(output, "\n CR expr CR        : ( %s ) "    , $1);}
                        | SPEECH_MARK expr SPEECH_MARK                { $$ = $2; fprintf(output, "\n SM expr SM        : ' %s ' "    , $1);}
                        | expr EQ expr                                
                        | expr PLUS expr                              {  fprintf(output, "movl $%s, %%eax\nmovl $%s, %%ebx\naddl %%eax, %%ebx\n",$1,$3); }
                        | expr MINUS expr                             { fprintf(output, "movl $%s, %%eax\nmovl $%s, %%ebx\nsubl %%eax, %%ebx\n",$3,$1);}
                        | expr TIMES expr                           
                          {  fprintf(output, "movl $%s, %%eax\nmovl $%s, %%ebx\nimull %%eax, %%ebx\n",$1,$3); }
                        | expr DIVIDE expr                            
                        {  fprintf(output, "movl $%s, %%eax\nmovl $0, %%edx\nmovl $%s, %%ebx\ndivl %%ebx\nmovl %%eax, %%ebx\n",$1,$3); }



                        | IDENTIFIER DIVIDE expr                            
                        {  fprintf(output, "movl %s, %%eax\nmovl $0, %%edx\nmovl $%s, %%ebx\ndivl %%ebx\nmovl %%eax, %%ebx\n",$1,$3); }     
                        | IDENTIFIER MINUS expr                         
                            { fprintf(output, "movl $%s, %%eax\nmovl %s, %%ebx\nsubl %%eax, %%ebx\n",$3,$1); }
                        | IDENTIFIER TIMES expr                       
                             { numTimes++; fprintf(output, "movl %s, %%eax\nmovl $%s, %%ebx\nimull %%eax, %%ebx\n",$1,$3); } 
                        | IDENTIFIER PLUS expr                         
                            { fprintf(output, "movl %s, %%eax\nmovl $%s, %%ebx\naddl %%eax, %%ebx\n",$1,$3); } 
                      | IDENTIFIER DIVIDE IDENTIFIER                            
                        {  fprintf(output, "movl %s, %%eax\nmovl $0, %%edx\nmovl %s, %%ebx\ndivl %%ebx\nmovl %%eax, %%ebx\n",$1,$3); }
                        | IDENTIFIER MINUS IDENTIFIER                
                            { fprintf(output, "movl %s, %%eax\nmovl %s, %%ebx\nsubl %%eax, %%ebx\n",$3,$1); }
                        | IDENTIFIER TIMES IDENTIFIER                  
                            {numTimes++; fprintf(output, "movl %s, %%eax\nmovl %s, %%ebx\nimull %%eax, %%ebx\n",$1,$3); } 
                        | IDENTIFIER PLUS IDENTIFIER                   { fprintf(output, "movl %s, %%eax\nmovl %s, %%ebx\naddl %%eax, %%ebx\n",$1,$3); } 
                        | expr INCREMENT                              {$$ = $2;}
                        | expr DECREMENT                              {$$ = $2;}
                        | IDENTIFIER LT expr                          {$$ = $3;}
                        | IDENTIFIER LT_EQ expr                        {$$ = $3;}
                        | IDENTIFIER GT expr                           {$$ = $3;}
                        | IDENTIFIER GT_EQ expr                        {$$ = $3;}
                        | expr LT expr                                {$$ = $3;}
                        | expr LT_EQ expr                             {$$ = $3;}
                        | expr GT expr                                {$$ = $3;}
                        | expr GT_EQ expr                             {$$ = $3;}
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

  fprintf(output, ".code32\n");
  fprintf(output, ".section .text\n");
  fprintf(output, ".section .data\n");
  fprintf(output, "a:\n.long 0\n");
  fprintf(output, "b:\n.long 0\n"); 
  fprintf(output, "c:\n.long 0\n");
  fprintf(output, "d:\n.long 0\n"); 
  fprintf(output, "e:\n.long 0\n");
  fprintf(output, "f:\n.long 0\n"); 

  fprintf(output, ".globl _start\n");
  fprintf(output, "_start:\n"); 
  

  // Parse through the input:
  yyparse();

  fprintf(output, "movl $1, %%eax\n");
  fprintf(output, "int $0x80\n"); 

}

void yyerror(const char *s) {
  cout << "Parse error!" << endl;
  cout << "Message: " << s << " on line: " << newLine << endl;
  exit(-1);
}