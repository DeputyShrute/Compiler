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
	outfile.open("assembly_code.txt", ios_base::app);
	outfile << "\tadd\tDWORD PTR [rbp - "<<(space+1)*4<<"], "<<num<<endl;
	
	*(variables + space) = num;
	return variables;
}
int *func_arithmetic(string code, int *variables)
{
	int destination_letter = code[0]-97; 
	int add_letter = code[4]-97; 
	int num = code[8] - 48;
	ofstream outfile;
	outfile.open("assembly_code.txt", ios_base::app);
	
	if (code[6] == '+')
	{
		outfile<<"\tadd\tDWORD PTR[rbp - "<<(destination_letter+1)*4<<"], "<<num<<endl;
		*(variables + destination_letter) = *(variables + add_letter) + num;
	}
	else if (code[6] == '-')
	{
		outfile << "\tsub\tDWORD PTR[rbp - " << (destination_letter + 1) * 4 << "], " << num << endl;
		*(variables + destination_letter) = *(variables + add_letter) - num;
	}
	else if (code[6] == '*')
	{
		for (int i = 0; i < num; i++)
		{
			outfile << "\tadd\tDWORD PTR[rbp - " << (destination_letter + 1) * 4 << "], " << num << endl;
		}

		*(variables + destination_letter) = *(variables + add_letter) * num;
	}
	
	return variables;
}
int *func_for(string code, int * variables)
{
	unsigned first = code.find("for");
	unsigned last = code.find("end_for");
	string for_code = code.substr(first, last - first);
	//for (int i = 0, i = 3, i = i + 1) x = x + 5, 
	int destination_letter = for_code[34] - 97;
	int add_letter = for_code[38] - 97;
	int num = for_code[42] - 48;
	int for_num = for_code[20] - 48;
	int for_letter = for_code[9] - 97;
	int i_increment = for_code[31] - 48;

	ofstream outfile;
	outfile.open("assembly_code.txt", ios_base::app);
	
	outfile << ".L3:" << endl;
	outfile << "\tcmp\tDWORD PTR[rbp- "<<(for_letter+1)*4<<"], "<< for_num << endl;
	outfile << "\tjg\t.L2" << endl;
	outfile << "\tadd\tDWORD ptr[rbp - "<<(destination_letter+1)*4<<"], "<<num<<endl;
	outfile << "\tadd\tDWORD ptr[rbp - " << (for_letter + 1) * 4 << "], " << i_increment << endl;
	outfile << "\tjmp\t.L3" << endl;
	outfile<<"L2:"<<endl;
	for (int i=0; i<for_num; i++)
	{
		if (for_code[40] == '+')
		{
			*(variables + destination_letter) = *(variables + add_letter) + num;
		}
		else if (for_code[40] == '-')
		{
			*(variables + destination_letter) = *(variables + add_letter) - num;
		}
	}
	return variables;
}
void regex_search()
{
	int variables[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	string code = "int x = 3 for (int i = 0, i = 3, i = i + 1) x = x + 5, end_for";
	regex reg_variable("(int [a-z] = [0-9])"); string variable;
	regex reg_add_subtract("([a-z] = [a-z] [+-] [0-9])"); string add_subtract;
	regex reg_for("for"); string for_loop;
	smatch match;
	
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
	if (regex_search(code, match, reg_for))
	{
		for_loop = match.str(1);
		func_for(code, variables);
	}
	
	for (int i = 0; i < 26;i++)
	{
		cout << *(variables + i) << " ";
	}
}
int main()
{
	ofstream myfile ("assembly_code.txt");
	if (myfile.is_open())
	{
		myfile << "global _start\n";
		myfile << "_start" << endl;
		myfile << "main." << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 4], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 8], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 12], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 16], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 20], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 24], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 28], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 32], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 36], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 40], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 44], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 48], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 52], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 56], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 60], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 64], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 68], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 72], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 76], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 80], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 84], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 88], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 92], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 96], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 100], 0" << endl;
		myfile << "\tmov\tDWORD PTR[rbp - 104], 0" << endl;	
	}
	
	regex_search();
	
	myfile.close();
	
}
