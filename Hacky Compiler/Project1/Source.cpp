//http://cpprocks.com/files/c++11-regex-cheatsheet.pdf
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;
void regex_search(string code);
int *func_variable(string code, int *variables)//takes string, translates letter and number and changes the value at the correct spot in an array
{
	//intx=2;
	int num; int space;
	space = code[3] - 97;
	num = code[5] - 48;
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	
	outfile<< "addl $"<<code[5]<<", "<<code[3]<<endl;//writes code to save a variable in a slot
	outfile<<"movl "<<code[3]<<", %ebx"<<endl; //writes variable to ebx so it can be outputted

	//outfile << "movl $" << num << ", %ebx" << endl; //writes variable save to file
	*(variables + space) = num; //not neccessary
	return variables;
}
int *func_numbers(string code, int *variables)
{
	//x=x+1
	//writes simple arithmetic function - addition, subtraction, multiplication, modulus 
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	int destination_letter = code[0]-97; 
	int add_letter = code[2]-48; 
	int num = code[4] - 48;
	//takes each operator and writes assembly code for function
	//mult & div use for loops to repeatedly add/subtract
	if (code[3] == '+')
	{
		outfile<<"movl $"<<code[4]<<", %ebx"<<endl;
		outfile << "addl $"<<code[2]<<", %ebx"<<endl;
	}
	else if (code[3] == '-')
	{
		outfile<<"movl $"<<code[2]<<", %ebx"<<endl;
		outfile << "subl $"<<code[4]<<", %ebx"<<endl;
	}
	else if (code[3] == '*')//multiplication is addition in a loop
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<num* add_letter<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $"<<add_letter<<", %ecx"<<endl;
		outfile<<"addl $"<<code[2]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;

	}
	else if(code[3] == '/')//division = subtraction in a loop, technically finds modulus (only works in ints)
	{
		//outfile<<"movl $"<<*(variables+add_letter)/num <<", %ecx"<<endl;
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $"<<add_letter<<", %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"addl $"<<code[4]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;

		//outfile<<"div_loop_start:\ncmpl $"<<*(variables+add_letter)/code[4]<<", %ecx\nje div_end_loop\nsubl "<<code[4]<< ", %ebx\naddl $1, %ecx\njmp div_loop_start" <<endl;
		//outfile << "div_end_loop:" << endl;
		//outfile << "movl %ecx, %ebx"<<endl;
		//outfile << "movl %ecx,"<<code[4]<<endl;
	}
	
	return variables;
}
int *func_arithmetic(string code, int *variables)
{
	//cout << code;
	//x=x+1
	//writes simple arithmetic function - addition, subtraction, multiplication, modulus 
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	int destination_letter = code[0]-97; 
	int add_letter = code[2]-97; 
	int num = code[4] - 48;
	//takes each operator and writes assembly code for function
	//mult & div use for loops to repeatedly add/subtract
	if (code[3] == '+')
	{
		outfile << "addl $"<< code[4]<<", "<<code[2] << endl;
		outfile << "movl "<<code[2]<< ", %ebx"<< endl;
		outfile << "movl %ebx, "<<code[0]<<endl;
		outfile<< "movl "<< code[0]<<", %ebx"<<endl;
	}
	else if (code[3] == '-')
	{
		outfile << "subl $"<< code[4]<<", "<<code[2] << endl;
		outfile << "movl "<<code[2]<< ", %ebx"<< endl;
		outfile << "movl %ebx, "<<code[0]<<endl;
		outfile<< "movl "<< code[0]<<", %ebx"<<endl;
	}
	else if (code[3] == '*')//multiplication is addition in a loop
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<num* *(variables+add_letter)<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $"<<*(variables+add_letter)<<", %ecx"<<endl;
		outfile<<"addl "<<code[2]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;

	}
	else if(code[3] == '/')//division = subtraction in a loop, technically finds modulus (only works in ints)
	{
		//outfile<<"movl $"<<*(variables+add_letter)/num <<", %ecx"<<endl;
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $"<<*(variables+add_letter)<<", %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"addl $"<<code[4]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;

		//outfile<<"div_loop_start:\ncmpl $"<<*(variables+add_letter)/code[4]<<", %ecx\nje div_end_loop\nsubl "<<code[4]<< ", %ebx\naddl $1, %ecx\njmp div_loop_start" <<endl;
		//outfile << "div_end_loop:" << endl;
		//outfile << "movl %ecx, %ebx"<<endl;
		//outfile << "movl %ecx,"<<code[4]<<endl;
	}
	
	return variables;
}
int *func_for(string code, int * variables)
{
	unsigned first = code.find("for");//removes all code that is not included in the for loop
	unsigned last = code.find("end_for");
	string for_code = code.substr(first, last - first);
	unsigned x = code.find(")"); //removed all code not included in the for statement
	unsigned y = code.find("end_for");
	string body = code.substr(x, y-x);
	//for(inti=0,i<4,i++)x=x+1, 
	int destination_letter = for_code[19] - 97; //junk code?
	int add_letter = for_code[21] - 97;
	int num = for_code[23] - 48;
	int for_num = for_code[20] - 48;
	
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	
	if(for_code[16]=='+'&&for_code[17]== '+') //allows for incrementation or reduction
	{
		outfile <<"movl $"<<for_code[9]<<", %ecx"<<endl;//assembly code being written for for loop

		outfile << "loop_start:"<<endl;
		outfile << "addl $1, %ecx"<<endl;
		outfile << "cmpl $"<<for_code[13]<<", %ecx"<<endl;
	
		outfile<<"je end_loop" << endl;
		regex_search(body); //calls function to sort through body of for for all arithmetic statements
	
	
		outfile<< "jmp loop_start"<<endl;
		outfile<< "end_loop:"<<endl;
	}
	if(for_code[17]=='-'&&for_code[17]=='-')
	{
		outfile <<"movl $"<<for_code[13]<<", %ecx"<<endl;

		outfile << "loop_start:"<<endl;
		outfile << "cmpl $"<<for_num<<", %ecx"<<endl;
		outfile << "je end_loop"<<endl;
	
		regex_search(body);
	
		outfile << "subl $1, %ecx"<<endl;
		outfile<< "jmp loop_start"<<endl;
		outfile<< "end_loop:"<<endl;
	}
	
	return variables;
}
int *func_if(string code, int * variables)
{
	//if(x<3)x=x+1,elsex=x-1,end_if
	unsigned first = code.find("if");
	unsigned last = code.find("end_if");
	string if_code= code.substr(first, last-first);
	regex reg_else("else"); string else_statement;
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	smatch match;

	outfile<<"cmpl $"<<if_code[5]<<", "<<if_code[3] <<endl;

	if (regex_search(code, match, reg_else))
	{
		if(if_code[4]=='=')
		{
			outfile<<"je if" << endl;
			
		}
		else if(if_code[4]=='<')
		{
			outfile<<"jl if" << endl;
			
		}
		else if(if_code[4]=='>')
		{
			outfile<<"jg if" << endl;
			
		}
		outfile<<"jmp else"<<endl;
		outfile<<"if:"<<endl;
		unsigned x = code.find(")");
		unsigned y = code.find("else");
		string if_state = code.substr(x, y-x);
		regex_search(if_state);
		x = code.find("else");
		y = code.find("end_if");
		if_state = code.substr(x, y-x);
		outfile<<"jmp end"<<endl;
		outfile<<"else:"<<endl;
		regex_search(if_state);
		outfile<< "end:"<<endl;
	}
	else
	{
		if(if_code[4]=='=')
		{
			outfile<<"je if" << endl;
		}
		else if(if_code[4]=='<')
		{
			outfile<<"jl if" << endl;
		}
		else if(if_code[4]=='>')
		{
			outfile<<"jg if" << endl;
		}
		outfile<<"jmp end"<<endl;
		outfile<<"if:"<<endl;
		
		regex_search(if_code);
		outfile<<"end:"<<endl;

	}

	return variables;
}
void regex_search(string code)
{
	int variables[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //variable array (not neccessary for final compiler but nice for error checking)
	//string code = "int x = 3 for (int i = 0, i = 3, i++) x = x + 5, end_for";
	regex reg_variable("(int[a-z]=[[:digit:]]+;)"); string variable; //regex statements - to be changed as language evolves
	regex reg_add_numbers("(int [a-z]=[0-9][+-][0-9];)"); string add_numbers;
	regex reg_add_subtract("([a-z]=[a-z][+-][0-9],)"); string add_subtract;
	regex reg_multiply("([a-z]=[a-z][*][0-9],)"); string multiply;
	regex reg_divide("([a-z]=[a-z][/][0-9],)"); string divide;
	regex reg_for("for"); string for_loop;
	regex reg_if("if"); string if_statement;
	smatch match;

	string::const_iterator searchStart(code.cbegin());
	while(regex_search(searchStart, code.cend(),match, reg_add_subtract))
	{
		//cout << ( searchStart == code.cbegin() ? "" : " " ) << match[0];  
		searchStart=match.suffix().first;
		add_subtract = match.str(1);
		func_arithmetic(add_subtract, variables);
	}
	while(regex_search(searchStart, code.cend(),match, reg_add_subtract))
	{
		//cout << ( searchStart == code.cbegin() ? "" : " " ) << match[0];  
		searchStart=match.suffix().first;
		add_numbers = match.str(1);
		func_numbers(add_numbers, variables);
	}
	while(regex_search(searchStart,code.cend(),match, reg_multiply ))
	{
		searchStart=match.suffix().first;
		multiply = match.str(1);
		func_arithmetic(multiply, variables);
	}
	while(regex_search(searchStart,code.cend(),match, reg_divide ))
	{
		searchStart=match.suffix().first;
		divide = match.str(1);
		func_arithmetic(divide, variables);
	}
	while(regex_search(searchStart,code.cend(),match, reg_variable ))
	{
		searchStart=match.suffix().first;
		variable = match.str(1);
		func_variable(variable, variables);
	}
	while(regex_search(searchStart,code.cend(),match, reg_for ))
	{
		searchStart=match.suffix().first;
		for_loop = match.str(1);
		func_for(for_loop, variables);
	}
	while(regex_search(searchStart,code.cend(),match, reg_if ))
	{
		searchStart=match.suffix().first;
		if_statement = match.str(1);
		func_variable(if_statement, variables);
	}

}
void regex_search()
{
	//ifstream file("code.txt"); //input file for code
	//string code;
	//getline(file, code);
	
	ifstream file;
	file.open("code.txt");

	stringstream strstream;
	strstream << file.rdbuf();
	string code = strstream.str();

	code.erase( remove( code.begin(), code.end(), ' ' ), code.end() );
	code.erase( remove( code.begin(), code.end(), '\t' ), code.end() );
	code.erase( remove( code.begin(), code.end(), '\n' ), code.end() );
		
	int variables[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //variable array (not neccessary for final compiler but nice for error checking)
	//string code = "int x = 3 for (int i = 0, i = 3, i++) x = x + 5, end_for";
	regex reg_variable("(int[a-z]=[[:digit:]]+;)"); string variable; //regex statements - to be changed as language evolves
	regex reg_add_subtract("([a-z]=[a-z][+-][0-9];)"); string add_subtract;
	regex reg_add_numbers("([a-z]=[0-9][+-][0-9];)"); string add_numbers;
	regex reg_mult_numbers("([a-z]=[0-9][*][0-9];)"); string mult_numbers;
	regex reg_div_numbers("([a-z]=[0-9][/][0-9];)"); string div_numbers;
	regex reg_multiply("([a-z]=[a-z][*][0-9];)"); string multiply;
	regex reg_divide("([a-z]=[a-z][/][0-9];)"); string divide;
	regex reg_for("for"); string for_loop;
	regex reg_if("if"); string if_statement;
	smatch match;
	//calls various functions if the regex statements are a match
	if (regex_search(code, match, reg_variable))
	{
		variable = match.str(1);
		func_variable(variable, variables );
	}
	if (regex_search(code, match, reg_add_numbers))
	{
		add_numbers = match.str(1);
		func_numbers(add_numbers, variables );
	}
	if (regex_search(code, match, reg_mult_numbers))
	{
		mult_numbers = match.str(1);
		func_numbers(mult_numbers, variables );
	}
	if (regex_search(code, match, reg_div_numbers))
	{
		div_numbers = match.str(1);
		func_numbers(div_numbers, variables );
	}
	if (regex_search(code, match, reg_add_subtract))
	{
		add_subtract = match.str(1);
		func_arithmetic(add_subtract, variables);
	}
	if (regex_search(code, match, reg_multiply))
	{
		multiply = match.str(1);
		func_arithmetic(multiply, variables);
	}
	if(regex_search(code, match, reg_divide))
	{
		divide = match.str(1);
		func_arithmetic(divide, variables);
	}
	if (regex_search(code, match, reg_for))
	{
		for_loop = match.str(1);
		func_for(code, variables);
	}
	if (regex_search(code, match, reg_if))
	{
		if_statement = match.str(1);
		func_if(code, variables);
	}
}
int main()
{
	ofstream myfile ("assembly_code.s");//announces outout file for assembly code
	if (myfile.is_open()) //starts off assembly code - writes text that every program will use & variables
	{
		myfile << ".section .text" << endl;
		myfile << ".section .data" << endl;
		myfile<< "a:\n.long 0"<< endl; //saving variables
		myfile<< "b:\n.long 0"<< endl;
		myfile<< "c:\n.long 0"<< endl;
		myfile<< "d:\n.long 0"<< endl;
		myfile<< "e:\n.long 0"<< endl;
		myfile<< "f:\n.long 0"<< endl;
		myfile<< "g:\n.long 0"<< endl;
		myfile<< "h:\n.long 0"<< endl;
		myfile<< "i:\n.long 0"<< endl;
		myfile<< "j:\n.long 0"<< endl;
		myfile<< "k:\n.long 0"<< endl;
		myfile<< "l:\n.long 0"<< endl;
		myfile<< "m:\n.long 0"<< endl;
		myfile<< "n:\n.long 0"<< endl;
		myfile<< "o:\n.long 0"<< endl;
		myfile<< "p:\n.long 0"<< endl;
		myfile<< "q:\n.long 0"<< endl;
		myfile<< "r:\n.long 0"<< endl;
		myfile<< "s:\n.long 0"<< endl;
		myfile<< "t:\n.long 0"<< endl;
		myfile<< "u:\n.long 0"<< endl;
		myfile<< "v:\n.long 0"<< endl;
		myfile<< "w:\n.long 0"<< endl;
		myfile<< "x:\n.long 0"<< endl;
		myfile<< "y:\n.long 0"<< endl;
		myfile<< "z:\n.long 0"<< endl;

		myfile << ".globl _start\n";
		myfile << "_start:" << endl; 
	
	}
	myfile.close();
	regex_search(); //calls regex searches
	
	ofstream file; 
	file.open("assembly_code.s", ios_base::app);
	file << "movl $1, %eax\nint $0x80" << endl; //writes to file ending to every assembly code file
	
	file.close();

}