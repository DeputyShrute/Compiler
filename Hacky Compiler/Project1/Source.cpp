//http://cpprocks.com/files/c++11-regex-cheatsheet.pdf
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;
int *func_variable(string code, int *variables)//takes string, translates letter and number and changes the value at the correct spot in an array
{
	int num; int space;
	space = code[4] - 97;
	num = code[8] - 48;
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	
	outfile<< "addl $"<<num<<", "<<code[4]<<endl;
	outfile<<"movl "<<code[4]<<", %ebx"<<endl;

	//outfile << "movl $" << num << ", %ebx" << endl; //writes variable save to file
	
	*(variables + space) = num; //not neccessary
	return variables;
}
int *func_arithmetic(string code, int *variables)
{
	//writes simple arithmetic function - addition, subtraction, multiplication 
	int destination_letter = code[0]-97; 
	int add_letter = code[4]-97; 
	int num = code[8] - 48;
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	
	

	if (code[6] == '+')
	{
		outfile << "addl $"<< num<<", "<<code[4] << endl;
		outfile << "movl "<<code[4]<< ", %ebx"<< endl;
		outfile << "movl %ebx, "<<code[0]<<endl;
		outfile<< "movl "<< code[0]<<", %ebx"<<endl;
		*(variables + destination_letter) = *(variables + add_letter) + num;
	}
	else if (code[6] == '-')
	{
		outfile << "subl $"<< num<<", "<<code[4] << endl;
		outfile << "movl "<<code[4]<< ", %ebx"<< endl;
		outfile << "movl %ebx, "<<code[0]<<endl;
		outfile<< "movl "<< code[0]<<", %ebx"<<endl;
		*(variables + destination_letter) = *(variables + add_letter) - num;
	}
	else if (code[6] == '*')//multiplication is addition in a loop
	{
		outfile<<"loop_start:\ncmpl $"<<num* *(variables+add_letter)<<", %ebx\nje end_loop\naddl "<<code[4]<<", %ebx\njmp loop_start" <<endl;
		

		outfile << "end_loop:" << endl;

		*(variables + destination_letter) = *(variables + add_letter) * num;
	}
	else if(code[6] == '/')
	{
		outfile<<"loop_start:\ncmpl $"<<*(variables+add_letter)/num<<", %ecx\nje end_loop\nsubl "<<code[4]<< ", %ebx\naddl $1, %ecx\njmp loop_start" <<endl;
		outfile << "end_loop:" << endl;
		outfile << "movl %ecx, %ebx"<<endl;
		outfile << "movl %ecx,"<<code[4]<<endl;
	*(variables + destination_letter) = *(variables + add_letter) / num;
	}
	
	return variables;
}
int *func_for(string code, int * variables)
{
	unsigned first = code.find("for");
	unsigned last = code.find("end_for");
	string for_code = code.substr(first, last - first);
	//for (int i = 0, i = 3, i++,) x = x + 5, 
	int destination_letter = for_code[28] - 97;
	int add_letter = for_code[33] - 97;
	int num = for_code[37] - 48;
	int for_num = for_code[20] - 48;
	
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	outfile << "movl $"<<num<<", %eax" << endl;
	outfile <<"movl $0, %ecx"<<endl;
	outfile << "movl "<<for_code[33]<<", %ebx" << endl;
	if(for_code[34]= '+')
	{
		outfile << "loop_start:\ncmpl $" << for_num << ", %ecx\nje end_loop\naddl %eax, %ebx\naddl $1, %ecx\njmp loop_start" << endl;
	}
	else if(for_code[34]='-')
	{
		outfile << "loop_start:\ncmpl $" << for_num << ", %ecx\nje end_loop\nsubl %eax, %ebx\naddl $1, %ecx\njmp loop_start" << endl;
	}
	
	outfile << "end_loop:" << endl;
	for (int i=0; i<for_num; i++)
	{
		if (for_code[34] == '+')
		{
		
			*(variables + destination_letter) = *(variables + add_letter) + num;
		}
		else if (for_code[34] == '-')
		{
			*(variables + destination_letter) = *(variables + add_letter) - num;
		}
	}
	return variables;
}
void regex_search()
{
	ifstream file("code.txt"); //input file for code
	string code;
	getline(file, code);
	int variables[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //variable array (not neccessary for final compiler but nice for error checking)
	//string code = "int x = 3 for (int i = 0, i = 3, i++) x = x + 5, end_for";
	regex reg_variable("(int [a-z] = [[:digit:]]+;)"); string variable; //regex statements - to be changed as language evolves
	regex reg_add_subtract("([a-z] = [a-z] [+-] [0-9];)"); string add_subtract;
	regex reg_multiply("([a-z] = [a-z] [*] [0-9];)"); string multiply;
	regex reg_divide("([a-z] = [a-z] [/] [0-9];)"); string divide;
	regex reg_for("for"); string for_loop;
	smatch match;
	//calls various functions if the regex statements are a match
	if (regex_search(code, match, reg_variable))
	{
		variable = match.str(1);
		func_variable(variable, variables );
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
	
	for (int i = 0; i < 26;i++) //output loop for array, not neccessary for compiler but good to see error checking
	{
		cout << *(variables + i) << " ";
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
