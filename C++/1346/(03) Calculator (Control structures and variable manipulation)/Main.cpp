/**************
* Lab 5 - calculator
* Deven Tharp
* 2/18/2013
**************/

#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

int main()
{
	
	double D1;
	double D2;
	char input[80];
	char op;
	bool skip = false;
	bool good = true;

	cout << "This is a calculator. Enter your first number in the first prompt, \nthe operator in the second prompt, and the second number on the third prompt.\nThe result will print on a new line. \nAfter that you can perform operations on the result by entering another operator and another number.\nType 'c' to clear and 'x' to exit." << endl;
	while(true)
	{
		do
		{
			cout << "\nEnter your first number:" << endl;
			good = true;
			cin >> input;
			if(!isdigit(input[0])&&(!(input[0]=='.')))
			{
				switch(input[0]){
					case 'c':
					case 'C':
								D1 = 0;
								skip = true;
								break;
					case 'x':
					case 'X':
								return 0;
					default: 
								cout << "*** INVALID, ENTER A NUMBER. ***" << endl;
								good = false;
				}
			}
			else
				D1 = atof(input);
		}while(!good);
		while(!skip){
			do
			{
				good = true;
				cin >> input;
				op = input[0];
				switch(op){
					case '+':
					case '-':
					case '*':
					case '/':
								break;
					case 'c':
					case 'C':
								D1 = 0;
								skip = true;
								break;
					case 'x':
					case 'X':
								return 0;
					default: 
								cout << "*** INVALID, ENTER AN OPERATOR. ***" << endl;
								good = false;
				}
			}while(!good);
			if(!skip)
			{
				do
				{
					good = true;
					cin >> input;
					if(!isdigit(input[0])&&(!(input[0]=='.')))
					{
						switch(input[0]){
							case 'c':
							case 'C':
										D1 = 0;
										skip = true;
										break;
							case 'x':
							case 'X':
										return 0;
							default: 
										cout << "*** INVALID. ENTER A NUMBER. ***" << endl;
										good = false;
						}
					}
					else
						D2 = atof(input);
				}while(!good);
			}
			if(!skip){
				switch(op){
						case '+':
									D1 += D2;
									cout << "==> " << D1 << endl;
									break;
						case '-':
									D1 -= D2;
									cout << "==> " << D1 << endl;
									break;
						case '*':
									D1 *= D2;
									cout << "==> " << D1 << endl;
									break;
						case '/':
									if(!(D2==0))
									{
										D1 /= D2;
										cout << "==> " << D1 << endl;
									}
									else
										cout << "*** UNPOSSIBLE. DON'T DO THAT. ***" << endl;
									break;
				}
			}
		}
	}
}
