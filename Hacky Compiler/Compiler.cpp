#include <iostream>
#include <string>
#include <regex>
#include <fstream>

using namespace std;
void regex_search(string code);
void func_variable(string code)//fix so that it works iwth both 1 and 2 digit numbers
{
    //intx=1;

    ofstream outfile;
    outfile.open("assembly_code.s", ios_base::app);

    unsigned first = code.find("=");
    unsigned last = code.find(";");
    string num = code.substr(first, last-first);

    int length = num.length();

    if(length = 3)
    {
    	outfile<< "addl $"<<code[5]<<code[6]<<", "<<code[3]<<endl;//writes code to save a variable in a slot
		outfile<<"movl "<<code[3]<<", %ebx"<<endl; //writes variable to ebx so it can be outputted
    }
    else if(length = 2)
    {
	    outfile<< "addl $"<<code[5]<<", "<<code[3]<<endl;//writes code to save a variable in a slot
		outfile<<"movl "<<code[3]<<", %ebx"<<endl; //writes variable to ebx so it can be outputted
    }
}
void func_arithmetic1(string code)//number + number
{
	//x=3+13;
	//writes simple arithmetic functons - additon, subracton, multiplication and modulus
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	int length = code.length();
	//addition for up to 2 digit numbers
	if(code[3]=='+' && length==7)
	{
		outfile<< "movl $"<<code[4]<<code[5]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='+')
	{
		outfile<< "movl $"<<code[4]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	if(code[4]=='+'&& code.length()==8)
	{
		outfile<< "movl $"<<code[5]<<code[6]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<<code[3]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[4]=='+')
	{
		outfile<< "movl $"<<code[5]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<<code[3]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//subtraction
	if(code[3]=='-')
	{
		outfile<< "movl $"<<code[4]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	if(code[4]=='-'&&length ==7)
	{
		outfile<< "movl $"<<code[5]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<<code[3]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[4]=='-')
	{
		outfile<< "movl $"<<code[5]<<code[6]<< ", %eax"<<endl;
		outfile<< "movl $"<<code[2]<<code[3]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//multiplication
	if(code[3]=='*' && length==7)
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<code[2]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[4]<<code[5]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='*')
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<code[2]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[4]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	if(code[4]=='*'&& code.length()==8)
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<code[2]<<code[3]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[5]<<code[6]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[4]=='*')
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl $"<<code[2]<<code[3]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[5]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//division
	if(code[3]=='/')
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl $"<<code[2]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl $"<<code[4]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}
	if(code[4]=='/'&&length ==7)
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl $"<<code[2]<<code[3]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl $"<<code[5]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}
	else if(code[4]=='/')
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl $"<<code[2]<<code[3]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl $"<<code[5]<<code[6]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}
}
void func_arithmetic2(string code)//letter + letter
{
	//x=3+13;
	//writes simple arithmetic functons - additon, subracton, multiplication and modulus
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	int length = code.length();
	//addition for up to 2 digit numbers
	if(code[3]=='+')
	{
		outfile<< "movl "<<code[4]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//subtraction
	if(code[3]=='-')
	{
		outfile<< "movl "<<code[4]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//multiplication
	if(code[3]=='*')
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl "<<code[2]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl "<<code[4]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//division
	if(code[3]=='/')
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl "<<code[2]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl "<<code[4]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}
}
void func_arithmetic3(string code)//letter+number
{
	//x=3+13;
	//writes simple arithmetic functons - additon, subracton, multiplication and modulus
	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);
	int length = code.length();
	//addition for up to 2 digit numbers
	if(code[3]=='+' && length==7)
	{
		outfile<< "movl $"<<code[4]<<code[5]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='+')
	{
		outfile<< "movl $"<<code[4]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "addl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	//subtraction
	if(code[3]=='-'&&length==7)
	{
		outfile<< "movl $"<<code[4]<<code[5]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='-')
	{
		outfile<< "movl $"<<code[4]<< ", %eax"<<endl;
		outfile<< "movl "<<code[2]<< ", %ebx"<<endl;
		outfile<< "subl %eax, %ebx"<<endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	
	//multiplication
	if(code[3]=='*' && length==7)
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl "<<code[2]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[4]<<code[5]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='*')
	{
		outfile<< "movl $0, %ebx"<<endl;
		outfile<< "movl $0, %ecx"<<endl;
		outfile<<"mult_loop_start:"<<endl;
		outfile<<"cmpl "<<code[2]<<", %ecx"<<endl;
		outfile<<"je mult_end_loop"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"addl $"<<code[4]<<", %ebx"<<endl;
		outfile<<"jmp mult_loop_start" <<endl;
		outfile<<"mult_end_loop:" << endl;
		outfile<< "movl %ebx, "<<code[0]<<endl;
	}

	//division
	if(code[3]=='/'&&length==7)
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl "<<code[2]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl $"<<code[4]<<code[5]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}
	else if(code[3]=='/')
	{
		outfile<<"movl $0, %ebx"<<endl;
		outfile<<"movl "<<code[2]<<", %ecx"<<endl;
		outfile<<"div_loop_start:"<<endl;
		outfile<<"cmpl $0, %ecx"<<endl;
		outfile<<"je div_end_loop"<<endl;
		outfile<<"subl $"<<code[4]<<", %ecx"<<endl;
		outfile<<"addl $1, %ebx"<<endl;
		outfile<<"jmp div_loop_start" <<endl;
		outfile<<"div_end_loop:" << endl;
		outfile<<"movl %ebx, "<<code[0]<<endl;
	}

}
 /*{ fprintf(output, "\n FOR LOOP    : FOR (  var '%s' := %s; %s; %s;  )", $4 ,$6, $8, $10);}*/
void func_for(string code)
{
	unsigned first = code.find("for"); //removes all code that is not part of the loop
	unsigned last = code.find("end_for");
	string for_code = code.substr(first, last-first);
	unsigned x = code.find(")");
	unsigned y = code.find("end_for");
	string body = code.substr(x, y-x);

	ofstream outfile;
	outfile.open("assembly_code.s", ios_base::app);

	if(for_code[16]=='+' && for_code[17]=='+')
	{
		outfile<<"movl $"<<for_code[9]<<", %ecx"<<endl;
		outfile<<"loop_start:"<<endl;
		outfile<<"addl $1, %ecx"<<endl;
		outfile<<"cmpl $"<<for_code[13]<<", %ecx"<<endl;
		outfile<<"je end_loop"<<endl;

		regex_search(body);
	}
	else if(for_code[17]=='-'&&for_code[17]=='-')
	{
		outfile <<"movl $"<<for_code[13]<<", %ecx"<<endl;

		outfile << "loop_start:"<<endl;
		outfile << "cmpl $"<<for_code[20]<<", %ecx"<<endl;
		outfile << "je end_loop"<<endl;
	
		regex_search(body);
	
		outfile << "subl $1, %ecx"<<endl;
	}
	outfile<< "jmp loop_start"<<endl;
	outfile<< "end_loop:"<<endl;
}
void func_if(string code)
{
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
		unsigned x = code.find(")");
		unsigned y = code.find("end_if");
		string if_state = code.substr(x, y-x);
		outfile<<"jmp end"<<endl;
		outfile<<"if:"<<endl;
		
		regex_search(if_state);
		outfile<<"end:"<<endl;

	}
}
void regex_search(string code)
{
   //expression to locate a variable
    regex reg_variable("(int[a-z]=[[:digit:]]+,)"); string variable; //regex statements - to be changed as language evolves
    //expressions to locate arithmetic
	regex reg_add_numbers("([a-z]=[[:digit:]]+[+-][[:digit:]]+,)"); string add_numbers;
	regex reg_mult_numbers("([a-z]=[[:digit:]]+[*][[:digit:]]+,)"); string mult_numbers;
	regex reg_div_numbers("([a-z]=[[:digit:]]+[/][[:digit:]]+,)"); string div_numbers;
    
	regex reg_add_subtract("([a-z]=[a-z][+-][0-9],)"); string add_subtract;
    regex reg_multiply("([a-z]=[a-z][*][0-9],)"); string multiply;
	regex reg_divide("([a-z]=[a-z][/][0-9],)"); string divide;
	
	regex reg_multiply_letters("([a-z]=[a-z][*][a-z],)"); string multiply_letters;
	regex reg_divide_letters("([a-z]=[a-z][/][a-z],)"); string divide_letters;
	regex reg_add_subtract_letters("([a-z]=[a-z][+-][a-z],)"); string add_subtract_letters;
    //expressions to locate for and if statements
    regex reg_for("for"); string for_loop;
	regex reg_if("if"); string if_statement;

    smatch match;

    //calls various functions if the regex statements are a match
	//variables
	if (regex_search(code, match, reg_variable))
	{
		variable = match.str(1);
		func_variable(variable );
	} 
	//arithmetic - two numbers
	if (regex_search(code, match, reg_add_numbers))
	{
		add_numbers = match.str(1);
		func_arithmetic1(add_numbers);
	}
	if (regex_search(code, match, reg_mult_numbers))
	{
		mult_numbers = match.str(1);
		func_arithmetic1(mult_numbers);
	}
	if (regex_search(code, match, reg_div_numbers))
	{
		div_numbers = match.str(1);
		func_arithmetic1(div_numbers);
	}
	//arithmetic - two letters
	if (regex_search(code, match, reg_add_subtract_letters))
	{
		add_subtract_letters = match.str(1);
		func_arithmetic2(add_subtract_letters);
	}
	if (regex_search(code, match, reg_multiply_letters))
	{
		multiply_letters = match.str(1);
		func_arithmetic2(multiply_letters);
	}
	if (regex_search(code, match, reg_divide_letters))
	{
		divide_letters = match.str(1);
		func_arithmetic2(divide_letters);
	}
	//arithmetic - one number, one letter
	if (regex_search(code, match, reg_add_subtract))
	{
		add_subtract = match.str(1);
		func_arithmetic3(add_subtract);
	}
	if (regex_search(code, match, reg_multiply))
	{
		multiply = match.str(1);
		func_arithmetic3(multiply);
	}
	if (regex_search(code, match, reg_divide))
	{
		divide = match.str(1);
		func_arithmetic3(divide);
	}
	//for
	if (regex_search(code, match, reg_for))
	{
		for_loop = match.str(1);
		func_for(code);
	}
	//if
		if (regex_search(code, match, reg_if))
	{
		if_statement = match.str(1);
		func_if(code);
	}
}
void regex_search()
{
	//cout<<"x";
    //accepts file input and removes spaces, tabs and lines
    ifstream file;
    file.open("code.txt");

    stringstream strstream;
    strstream<<file.rdbuf();
    string code = strstream.str();

    code.erase(remove(code.begin(),code.end(), ' '), code.end());
    code.erase(remove(code.begin(),code.end(), '\t'), code.end());
    code.erase(remove(code.begin(),code.end(), '\n'), code.end());
    //expression to locate a variable
    regex reg_variable("(int[a-z]=[[:digit:]]+;)"); string variable; //regex statements - to be changed as language evolves
    //expressions to locate arithmetic
	regex reg_add_numbers("([a-z]=[[:digit:]]+[+-][[:digit:]]+;)"); string add_numbers;
	regex reg_mult_numbers("([a-z]=[[:digit:]]+[*][[:digit:]]+;)"); string mult_numbers;
	regex reg_div_numbers("([a-z]=[[:digit:]]+[/][[:digit:]]+;)"); string div_numbers;
    
	regex reg_add_subtract("([a-z]=[a-z][+-][[:digit:]]+;)"); string add_subtract;
    regex reg_multiply("([a-z]=[a-z][*][[:digit:]]+;)"); string multiply;
	regex reg_divide("([a-z]=[a-z][/][[:digit:]]+;)"); string divide;
	
	regex reg_multiply_letters("([a-z]=[a-z][*][a-z];)"); string multiply_letters;
	regex reg_divide_letters("([a-z]=[a-z][/][a-z];)"); string divide_letters;
	regex reg_add_subtract_letters("([a-z]=[a-z][+-][a-z];)"); string add_subtract_letters;
    //expressions to locate for and if statements
    regex reg_for("for"); string for_loop;
	regex reg_if("if"); string if_statement;

    smatch match;

    //calls various functions if the regex statements are a match
	//variables
	string::const_iterator searchStart(code.cbegin());
	while(regex_search(searchStart, code.cend(), match, reg_variable))
	{
		searchStart=match.suffix().first;
		variable = match.str(1);
		func_variable(variable);
	} 
	//arithmetic - two numbers
	while(regex_search(searchStart, code.cend(), match, reg_add_numbers))
	{
		searchStart=match.suffix().first;
		add_numbers = match.str(1);
		func_arithmetic1(add_numbers);
	} 
	while(regex_search(searchStart, code.cend(), match, reg_mult_numbers))
	{
		searchStart=match.suffix().first;
		mult_numbers = match.str(1);
		func_arithmetic1(mult_numbers);
	}
	while(regex_search(searchStart, code.cend(), match, reg_div_numbers))
	{
		searchStart=match.suffix().first;
		div_numbers = match.str(1);
		func_arithmetic1(div_numbers);
	}
	//arithmetic - two letters
	while(regex_search(searchStart, code.cend(), match, reg_add_subtract_letters))
	{
		searchStart=match.suffix().first;
		add_subtract_letters = match.str(1);
		func_arithmetic2(add_subtract_letters);
	} 
	while(regex_search(searchStart, code.cend(), match, reg_multiply_letters))
	{
		searchStart=match.suffix().first;
		multiply_letters = match.str(1);
		func_arithmetic2(multiply_letters);
	}
	while(regex_search(searchStart, code.cend(), match, reg_divide_letters))
	{
		searchStart=match.suffix().first;
		divide_letters = match.str(1);
		func_arithmetic2(divide_letters);
	}
	//arithmetic - one number, one letter

	while(regex_search(searchStart, code.cend(), match, reg_add_subtract))
	{
		searchStart=match.suffix().first;
		add_subtract_letters = match.str(1);
		func_arithmetic3(add_subtract_letters);
	} 
	while(regex_search(searchStart, code.cend(), match, reg_multiply))
	{
		searchStart=match.suffix().first;
		multiply = match.str(1);
		func_arithmetic3(multiply);
	}
	while(regex_search(searchStart, code.cend(), match, reg_divide))
	{
		searchStart=match.suffix().first;
		divide = match.str(1);
		func_arithmetic3(divide);
	}
	//for
	while(regex_search(searchStart, code.cend(), match, reg_for))
	{
		searchStart=match.suffix().first;
		for_loop = match.str(1);
		func_for(code);
	}
	//if
		while(regex_search(searchStart, code.cend(), match, reg_if))
	{
		searchStart=match.suffix().first;
		if_statement = match.str(1);
		func_if(code);
	}
}
int main()
{
    ofstream myfile ("assembly_code.s");//announces outout file for assembly code
	if (myfile.is_open()) //starts off assembly code - writes text that every program
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
}	