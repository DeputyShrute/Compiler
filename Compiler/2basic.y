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
  int if_ = 0;
  int functionIndex = 0;
  int functionRetIndex = 0;
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
%token <val> ELSEIF
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
%token <val> PROCEDURE
%token <val> ENDFUNCTION
%token<val> ENDPROJECT
%token<val> RET
%token<val> RETMAIN
%token<val> NAMESPACE
%token<val> CALLFUNCTION
%token<val> NAME

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

                        /*end of for loop*/
stmt:                   compound_stmt CLOSE_CURLY

                        | compound_stmt CLOSE_CURLY ENDFOR SEMI_COLON     
                            {fprintf(output, "popl %%ecx\n");
                            fprintf(output, "addl $1, %%ecx\n");
                            fprintf(output, "jmp loop_start_%d\n",loop);
                            fprintf(output, "end_loop_%d:\n", loop );}

                        | compound_stmt CLOSE_CURLY ENDNESTFOR SEMI_COLON     
                            {fprintf(output, "popl %%ecx\n");
                            fprintf(output, "addl $1, %%ecx\n");
                            fprintf(output, "jmp loop_start_%d\n",loop);
                            fprintf(output, "end_loop_%d:\n", loop );loop--;}
                        /*for loops*/
                        | LOOP OPEN_ROUND VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER SEMI_COLON expr SEMI_COLON INCREMENT SEMI_COLON CLOSE_ROUND    
                            {loop++;fprintf(output, "movl $%s, %%ecx\n", $6);
                            fprintf(output, "loop_start_%d:\n",loop);
                            fprintf(output, "cmpl $%s, %%ecx\n", $8);
                            fprintf(output, "je end_loop_%d\n",loop);
                            fprintf(output, "pushl %%ecx\n");}

                        | LOOP OPEN_ROUND VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER SEMI_COLON expr SEMI_COLON DECREMENT SEMI_COLON CLOSE_ROUND 
                            {loop++;fprintf(output, "movl $%s, %%ecx\n", $6);
                            fprintf(output, "loop_start_%d:\n", loop);
                            fprintf(output, "subl $1, %%ecx\n");
                            fprintf(output, "cmpl $%s, %%ecx\n", $8);
                            fprintf(output, "je end_loop_%d\n", loop);
                            fprintf(output, "pushl %%ecx\n"); }

                        /*If statements*/
                        | IF OPEN_ROUND IDENTIFIER LT expr CLOSE_ROUND 
                            {fprintf(output,"cmpl $%s, %s\n",$5,$3 );
                            fprintf(output, "jl if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;}

                        | IF OPEN_ROUND IDENTIFIER GT expr CLOSE_ROUND 
                            {fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "jg if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;} 

                        | IF OPEN_ROUND IDENTIFIER EQ expr CLOSE_ROUND 
                            {fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "je if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;} 

                        | IF OPEN_ROUND IDENTIFIER LT_EQ expr CLOSE_ROUND 
                            {fprintf(output,"cmpl $%s, %s\n",$5,$3 );
                            fprintf(output, "jle if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;} 

                        | IF OPEN_ROUND IDENTIFIER GT_EQ expr CLOSE_ROUND 
                            {fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "jge if%d\n",if_);
                            fprintf(output, "jmp else%d\n",if_);
                            fprintf(output, "if%d:\n",if_);if_++;} 

                        /*Else statement*/
                        | compound_stmt CLOSE_CURLY ELSE 
                            {if_--;fprintf(output,"jmp end%d\nelse%d:\n",if_,if_ );if_++;} 
                            
                        | compound_stmt CLOSE_CURLY ENDIF SEMI_COLON
                             {if_--;fprintf(output,"end%d:\n",if_);if_++;}

                        | ELSEIF OPEN_ROUND IDENTIFIER LT expr CLOSE_ROUND
                            {if_ --;fprintf(output,"cmpl $%s, %s\n",$5,$3 );
                            fprintf(output, "jl else%d\n",if_);
                            fprintf(output, "jmp end%d\n",if_);
                            fprintf(output, "else%d:\n",if_);if_++;}

                        | ELSEIF OPEN_ROUND IDENTIFIER GT expr CLOSE_ROUND
                            {if_--; fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "jg else%d\n",if_);
                            fprintf(output, "jmp end%d\n",if_);
                            fprintf(output, "else%d:\n",if_);if_++;} 

                        | ELSEIF OPEN_ROUND IDENTIFIER EQ expr CLOSE_ROUND
                            {if_--;fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "je else%d\n",if_);
                            fprintf(output, "jmp end%d\n",if_);
                            fprintf(output, "else%d:\n",if_);if_++;}

                        | ELSEIF OPEN_ROUND IDENTIFIER LT_EQ expr CLOSE_ROUND
                            {if_--; fprintf(output,"cmpl $%s, %s\n",$5,$3 );
                            fprintf(output, "jle else%d\n",if_);
                            fprintf(output, "jmp end%d\n",if_);
                            fprintf(output, "else%d:\n",if_);if_++;} 

                        | ELSEIF OPEN_ROUND IDENTIFIER GT_EQ expr CLOSE_ROUND
                            {if_--;fprintf(output,"cmpl $%s, %s\n",$5,$3);
                            fprintf(output, "jge else%d\n",if_);
                            fprintf(output, "jmp end%d\n",if_);
                            fprintf(output, "else%d:\n",if_);if_++;} 

                        | MAIN 
                       

                        | NAMESPACE stmt

                        | CALLFUNCTION IDENTIFIER SEMI_COLON
                        {fprintf(output, "jmp %s\n", $2);}
                        {fprintf(output, "cont%d:\n", functionIndex); functionIndex++;}
                        | PROCEDURE IDENTIFIER
                           {fprintf(output, "%s:\n", $2); functionIndex++;}

                        | compound_stmt CLOSE_CURLY ENDPROJECT SEMI_COLON 

                        | RET 
                        {fprintf (output, "jmp cont%d\n",functionRetIndex); functionRetIndex++;}

                        | RETMAIN 
                        {fprintf(output, "jmp end\n");}

                        | variable_definition SEMI_COLON
                        | function_type SEMI_COLON
                        | expr SEMI_COLON
                        | SEMI_COLON   
                                                               
                        ;



function_type:            FUNCTION OPEN_ROUND SPEECH_MARK expr SPEECH_MARK CLOSE_ROUND { }
                        | FUNCTION OPEN_ROUND IDENTIFIER CLOSE_ROUND                   { }
                        | FUNCTION OPEN_ROUND INTEGER CLOSE_ROUND                      { }
                        ;


compound_stmt:            OPEN_CURLY                                  { }
                        | compound_stmt stmt                          { }
                        ;


variable_definition:     VAR_DECLARATION {$$ = $1;} 
                        | VAR_DECLARATION IDENTIFIER ASSIGNMENT expr 
                            { fprintf(output, "movl %%ebx, %s\n", $2);}

                        | VAR_DECLARATION IDENTIFIER ASSIGNMENT INTEGER 
                            {fprintf(output, "movl $%s, %s\n",$4, $2);}

                        | IDENTIFIER ASSIGNMENT expr 
                            { fprintf(output, "movl %%ebx, %s\n", $1);} 
                        ;



expr:                     INTEGER                      
                        | STRING 
                                                         
                        | OPEN_ROUND expr CLOSE_ROUND                 { }
                        | SPEECH_MARK expr SPEECH_MARK                { }
                        | expr EQ expr                                
                        | expr PLUS expr                              
                          {fprintf(output, "movl $%s, %%eax\n",$1);
                          fprintf(output, "movl $%s, %%ebx\n",$3);
                          fprintf(output, "addl %%eax, %%ebx\n"); }

                        | expr MINUS expr                             
                          {fprintf(output, "movl $%s, %%eax\n",$3);
                          fprintf(output, "movl $%s, %%ebx\n",$1);
                          fprintf(output, "subl %%eax, %%ebx\n");}

                        | expr TIMES expr                           
                          {fprintf(output, "movl $%s, %%eax\n",$1);
                           fprintf(output, "movl $%s, %%ebx\n",$3);
                           fprintf(output, "imull %%eax, %%ebx\n");}

                        | expr DIVIDE expr                            
                           {fprintf(output, "movl $%s, %%eax\n",$1);
                           fprintf(output, "movl $0, %%edx\n");
                           fprintf(output, "movl $%s, %%ebx\n",$3);
                           fprintf(output, "divl %%ebx\n");
                           fprintf(output, "movl %%eax, %%ebx\n");}

                        | IDENTIFIER DIVIDE expr                            
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl $0, %%edx\n");
                            fprintf(output, "movl $%s, %%ebx\n",$3);
                            fprintf(output, "divl %%ebx\n");
                            fprintf(output, "movl %%eax, %%ebx\n");} 

                        | IDENTIFIER MINUS expr                         
                            {fprintf(output, "movl $%s, %%eax\n",$3);
                            fprintf(output, "movl %s, %%ebx\n",$1);
                            fprintf(output, "subl %%eax, %%ebx\n");}

                        | IDENTIFIER TIMES expr                       
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl $%s, %%ebx\n",$3);
                            fprintf(output, "imull %%eax, %%ebx\n");}

                        | IDENTIFIER PLUS expr                         
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl $%s, %%ebx\n",$3);
                            fprintf(output, "addl %%eax, %%ebx\n");}

                        | IDENTIFIER DIVIDE IDENTIFIER                            
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl $0, %%edx\n");
                            fprintf(output, "movl %s, %%ebx\n",$3);
                            fprintf(output, "divl %%ebx\n");
                            fprintf(output, "movl %%eax, %%ebx\n");}

                        | IDENTIFIER MINUS IDENTIFIER                
                            {fprintf(output, "movl %s, %%eax\n",$3);
                            fprintf(output, "movl %s, %%ebx\n",$1);
                            fprintf(output, "subl %%eax, %%ebx\n");}

                        | IDENTIFIER TIMES IDENTIFIER                  
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl %s, %%ebx\n",$3);
                            fprintf(output, "imull %%eax, %%ebx\n");}

                        | IDENTIFIER PLUS IDENTIFIER                   
                            {fprintf(output, "movl %s, %%eax\n",$1);
                            fprintf(output, "movl %s, %%ebx\n",$3);
                            fprintf(output, "addl %%eax, %%ebx\n"); } 
                        | expr INCREMENT                              {$$ = $2;}
                        | expr DECREMENT                              {$$ = $2;}
                        | IDENTIFIER LT expr                          {$$ = $3;}
                        | IDENTIFIER LT_EQ expr                       {$$ = $3;}
                        | IDENTIFIER GT expr                          {$$ = $3;}
                        | IDENTIFIER GT_EQ expr                       {$$ = $3;}
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
  FILE *myfile = fopen("a.2b", "r");
  // Make sure it is valid:
  if (!myfile) {
    cout << "Unable to open file" << endl;
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
  fprintf(output, "g:\n.long 0\n"); 
  fprintf(output, "h:\n.long 0\n");
  fprintf(output, "i:\n.long 0\n"); 
  fprintf(output, "j:\n.long 0\n");
  fprintf(output, "k:\n.long 0\n");
  fprintf(output, "l:\n.long 0\n"); 
  fprintf(output, "m:\n.long 0\n");
  fprintf(output, "n:\n.long 0\n"); 
  fprintf(output, "o:\n.long 0\n");
  fprintf(output, "p:\n.long 0\n");
  fprintf(output, "q:\n.long 0\n"); 
  fprintf(output, "r:\n.long 0\n");
  fprintf(output, "s:\n.long 0\n"); 
  fprintf(output, "t:\n.long 0\n");
  fprintf(output, "u:\n.long 0\n");
  fprintf(output, "v:\n.long 0\n"); 
  fprintf(output, "w:\n.long 0\n");
  fprintf(output, "x:\n.long 0\n"); 
  fprintf(output, "y:\n.long 0\n");

  fprintf(output, "z:\n.long 0\n"); 
  fprintf(output, "space:\n.ascii \" \"\n");
  fprintf(output, ".globl _start\n");
  fprintf(output, "_start:\n"); 
  

  // Parse through the input:
  yyparse();

 //ending code to add each digit to a stack and print each variabl


{fprintf(output, "end:\n");}

  fprintf(output, "movl z, %%eax\n");
  fprintf(output, "xorl %%esi, %%esi\n");
    
  fprintf(output, "printz:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movey\n");
  fprintf(output, "jmp printz\n");

  fprintf(output, "movey:\n");
  fprintf(output, "movl y, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp printy\n");

  fprintf(output, "printy:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movex\n");
  fprintf(output, "jmp printy\n");

  fprintf(output, "movex:\n");
  fprintf(output, "movl x, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printx\n");

  fprintf(output, "printx:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movew\n");
  fprintf(output, "jmp printx\n");

  fprintf(output, "movew:\n");
  fprintf(output, "movl w, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printw\n");

  fprintf(output, "printw:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movev\n");
  fprintf(output, "jmp printw\n");

  fprintf(output, "movev:\n");
  fprintf(output, "movl v, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printv\n");

  fprintf(output, "printv:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveu\n");
  fprintf(output, "jmp printv\n");

  fprintf(output, "moveu:\n");
  fprintf(output, "movl u, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printu\n");

  fprintf(output, "printu:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movet\n");
  fprintf(output, "jmp printu\n");

  fprintf(output, "movet:\n");
  fprintf(output, "movl t, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp printt\n");

  fprintf(output, "printt:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moves\n");
  fprintf(output, "jmp printt\n");

  fprintf(output, "moves:\n");
  fprintf(output, "movl s, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");  
  fprintf(output, "jmp prints\n");

  fprintf(output, "prints:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz mover\n");
  fprintf(output, "jmp prints\n");

  fprintf(output, "mover:\n");
  fprintf(output, "movl r, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printr\n");

  fprintf(output, "printr:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveq\n");
  fprintf(output, "jmp printr\n");

  fprintf(output, "moveq:\n");
  fprintf(output, "movl q, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printq\n");

  fprintf(output, "printq:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movep\n");
  fprintf(output, "jmp printq\n");

  fprintf(output, "movep:\n");
  fprintf(output, "movl p, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printp\n");

  fprintf(output, "printp:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveo\n");
  fprintf(output, "jmp printp\n");

  fprintf(output, "moveo:\n");
  fprintf(output, "movl o, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printo\n");

  fprintf(output, "printo:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moven\n");
  fprintf(output, "jmp printo\n");

  fprintf(output, "moven:\n");
  fprintf(output, "movl n, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printn\n");

  fprintf(output, "printn:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movem\n");
  fprintf(output, "jmp printn\n");

  fprintf(output, "movem:\n");
  fprintf(output, "movl m, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printm\n");

  fprintf(output, "printm:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movel\n");
  fprintf(output, "jmp printm\n");

  fprintf(output, "movel:\n");
  fprintf(output, "movl l, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printl\n");

  fprintf(output, "printl:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movek\n");
  fprintf(output, "jmp printl\n");

  fprintf(output, "movek:\n");
  fprintf(output, "movl k, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printk\n");

  fprintf(output, "printk:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movej\n");
  fprintf(output, "jmp printk\n");

  fprintf(output, "movej:\n");
  fprintf(output, "movl j, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printj\n");

  fprintf(output, "printj:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movei\n");
  fprintf(output, "jmp printj\n");

  fprintf(output, "movei:\n");
  fprintf(output, "movl i, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printi\n");

  fprintf(output, "printi:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveh\n");
  fprintf(output, "jmp printi\n");

  fprintf(output, "moveh:\n");
  fprintf(output, "movl h, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printh\n");

  fprintf(output, "printh:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveg\n");
  fprintf(output, "jmp printh\n");

  fprintf(output, "moveg:\n");
  fprintf(output, "movl g, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printg\n");

  fprintf(output, "printg:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movef\n");
  fprintf(output, "jmp printg\n");

  fprintf(output, "movef:\n");
  fprintf(output, "movl f, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printf\n");

  fprintf(output, "printf:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movee\n");
  fprintf(output, "jmp printf\n");

  fprintf(output, "movee:\n");
  fprintf(output, "movl e, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printe\n");

  fprintf(output, "printe:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moved\n");
  fprintf(output, "jmp printe\n");

  fprintf(output, "moved:\n");
  fprintf(output, "movl d, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printd\n");

  fprintf(output, "printd:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movec\n");
  fprintf(output, "jmp printd\n");

  fprintf(output, "movec:\n");
  fprintf(output, "movl c, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printc\n");

  fprintf(output, "printc:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz moveb\n");
  fprintf(output, "jmp printc\n");

  fprintf(output, "moveb:\n");
  fprintf(output, "movl b, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printb\n");

  fprintf(output, "printb:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz movea\n");
  fprintf(output, "jmp printb\n");

  fprintf(output, "movea:\n");
  fprintf(output, "movl a, %%eax\n");
  fprintf(output, "pushl space\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "jmp printa\n");

  fprintf(output, "printa:\n");
  fprintf(output, "movl $0, %%edx\n");
  fprintf(output, "movl $10, %%ebx\n");
  fprintf(output, "divl %%ebx\n");
  fprintf(output, "addl $48, %%edx\n");
  fprintf(output, "pushl %%edx\n");
  fprintf(output, "incl %%esi\n");
  fprintf(output, "cmpl $0, %%eax\n");
  fprintf(output, "jz next\n");
  fprintf(output, "jmp printa\n");

  fprintf(output, "next:\n");
  fprintf(output, "cmpl $0, %%esi\n");
  fprintf(output, "jz exit\n");
  fprintf(output, "decl %%esi\n");
  fprintf(output, "movl $4, %%eax\n");
  fprintf(output, "movl %%esp, %%ecx\n");
  fprintf(output, "movl $1, %%ebx\n");
  fprintf(output, "movl $1, %%edx\n");
  fprintf(output, "int $0x80\n");
  fprintf(output, "addl $4, %%esp\n");
  fprintf(output, "jmp next\n");

  fprintf(output, "exit:\n");
  fprintf(output, "movl $1, %%eax\n");
  fprintf(output, "int $0x80\n"); 

}

void yyerror(const char *s) {
  cout << "Parse error!" << endl;
  cout << "Message: " << s << " on line: " << newLine << endl;
  exit(-1);
}
