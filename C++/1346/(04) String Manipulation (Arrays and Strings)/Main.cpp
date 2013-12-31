#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cmath>

using namespace std;

int main()
{
	long i; // this is to be the length of the entered string
	long k; // this is to be the length of the string without spaces
	char input[80]; //the entered string goes in here.
	char final[80]; //Then later on it has the spaces taken out and is put in here.
	bool ok = true; //This is whether or not the string is a palindrome. In this case it's "Innocent until proven guilty." Or true until false.
	cout << "This is a palindrome detector. Enter a string and I'll tell you if it's a palindrome. Type 'END' when you want to exit." << endl;
	while(true){ //infinite loop. type "END" to exit.
		i=0;
		k=0;
		ok = true;
		do{
			cin.clear();
			cout << "\nGo ahead and enter your string: ";
			cin.getline(input, 80);
			if(cin.fail())
			{
				cin.clear();
				cout << "\n***Your string is too large. Try a smaller one.***" << endl;
				cin.ignore(cin.gcount(), '\0'); //I'd hoped this would work to deal with strings that are too large, but it just reduces the effect down to a few error messages. Since then i've given up because it's better than a crash.
			}
		}while(cin.fail());
		if((input[0] == 'E') && (input[1] == 'N') && (input[2] == 'D'))//checking for "END"
			return 0;
		while(input[i]!='\0')//starts at input[0] and iterates at i++. Stops right before the end of string char, giving the number of chars in the string. 
		{
			if(input[i]!=' ')//since many palindromes ignore spaces, we'll make another string of the same input without spaces.
			{
				final[k] = tolower(input[i]);//since k will be staggered behind i if there are spaces in the string, we need k as another iterator.
				k++;
			}
			i++;
		}final[k] = '\0';//I think we need both of the iterators in those while loops, but final doesn't have an end of string char because the loop is stopped right before it. It gets fixed here. Sloppy, but effective :\.
		cout << "i = "<< i << " k = " << k;
		for(int j = 0; j<k/2; j++)
		{
			if(final[j] != final[k-1-j]) //if any of the characters compared in pairs sequentially from the outside inward aren't the same, the string is not a palindrome. unfortunately i need to offset k by 1.
				ok = false;
		}
		if(ok)
			cout << "\nYour string is a palindrome." << endl;
		else
			cout << "\nYour string is not a palindrome." << endl;
	}
}