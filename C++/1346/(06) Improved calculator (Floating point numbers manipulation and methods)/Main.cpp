#include <iostream>
#include <cctype>
#include <string.h>
#include <cstdlib>
using namespace std;
const int NUMVALIDOPS = 8;
const char VALIDOPS[] = {'+', '-', '*', '/', 'x', 'X', 'c', 'C'};
static bool skip = false;
static double L1;

double add(double i, double j);
double sub(double i, double j);
double mult(double i, double j);
double div(double i, double j);
bool getOp(const char* oplist, char& op);
bool getNum(double& d);


int main()
{
	bool good = true;
	double L2;
	char op;
	cout << "This is a calculator. Enter your first number in the first prompt, \nthe operator in the second prompt, and the second number on the third prompt.\nThe result will print on a new line. \nAfter that you can perform operations on the result by entering another operator and another number.\nType 'c' to clear and 'x' to exit." << endl;
	while(true)
	{
		skip = false;
		cout << "\nEnter your first number:" << endl;
		while(!getNum(L1))
		{
		cout << "*** INVALID, ENTER A NUMBER. ***" << endl;
		cout << "\nEnter your first number:" << endl;
		}
		while(!skip){
		while(!getOp(VALIDOPS, op))
			cout << "*** INVALID, ENTER AN OPERATOR. ***" << endl;
		if(!skip)
			while(!getNum(L2))
				cout << "*** INVALID, ENTER A NUMBER. ***" << endl;
		if(!skip){
			switch(op){
					case '+':	
								L1 = add(L1, L2);
								cout << "==> " << L1 << endl;
								break;
					case '-':	
								L1 = sub(L1, L2);
								cout << "==> " << L1 << endl;
								break;
					case '*':	
								L1 = mult(L1, L2);
								cout << "==> " << L1 << endl;
								break;
					case '/':	
								if(L2==0)
									cout << "*** UNPOSSIBLE. DON'T DO THAT. ***" << endl;
								else
								{
									L1 = div(L1, L2);
									cout << "==> " << L1 << endl;
								}
								break;
				}
			}
		}
	}
}

double add(double i, double j)
{
	return i += j;
}
double sub(double i, double j)
{
	return i -= j;
}
double mult(double i, double j)
{
	return i *= j;
}
double div(double i, double j)
{
	return i /= j;
}

bool getOp(const char* oplist, char& op)
{
	char input[80];
	cin>>input;
	for(int i = 0; i<NUMVALIDOPS; i++)
		if(input[0]==oplist[i])
		{
			op = input[0];
			switch(input[0]){
			case 'c':
			case 'C':
						L1 = 0;
						skip = true;
						return true;
			case 'x':
			case 'X':
						exit(0);
			}
			return true;
		}
	return false;
}


bool getNum(double& d)
{
	char input[80];
	cin >> input;
	if(!isdigit(input[0])&&(!(input[0]=='.')))
	{
			switch(input[0]){
			case 'c':
			case 'C':
						L1 = 0;
						skip = true;
						return true;
			case 'x':
			case 'X':
						exit(0);
			default: 
						return false;
		}
	}
	else
		d = atof(input);
	return true;
}