#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

using namespace std;

void sort(int* vals, int amt);

int main()
{
	int amt;
	int vals[20];
	char fancy[3];
	cout << "Sorting time. Tell me how many numbers you want to sort,\nas long as it's 20 or less." << endl;

	while(!(cin >> amt)||((amt>20)||(amt<=0)))
	{
		cout << "Try that again. I'm looking for a whole number more than 0 and less than 20: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}

	cout << "\nAlrighty then, go ahead and enter " << amt << " whole numbers." << endl;
	
	for(int i = 0; i < amt; i++)
	{
		switch(i+1){case 1: fancy[0] = 's'; fancy[1] = 't'; fancy[2] = '\0'; break; case 2: fancy[0] = 'n'; fancy[1] = 'd'; fancy[2] = '\0'; break; case 3: fancy[0] = 'r'; fancy[1] = 'd'; fancy[2] = '\0'; break; default: fancy[0] = 't'; fancy[1] = 'h'; fancy[2] = '\0';}
		cout << "\nEnter your " << (i+1) << fancy << " number: ";
		cin >> vals[i];
	}
	
	cout << "\nYour numbers, in the order you entered them, are as follows: ";
	for(int i = 0; i < amt-1; i++)
		cout <<  vals[i] << ", ";
	cout<< vals[amt-1] << endl;

	sort(vals, amt);

	cout << "\nYour numbers, sorted in ascending order, are as follows: ";
	
	for(int i = 0; i < amt-1; i++)
		cout <<  vals[i] << ", ";
	cout<< vals[amt-1] << endl << endl;

}

void sort(int* vals, int amt)
{
	for(int i = 0; i<amt; i++)
	{
		for(int j = 0; j<amt-1; j++)
		{
			if(vals[j]>vals[j+1])
			{
				int temp = vals[j+1];
				vals[j+1] = vals[j];
				vals[j] = temp;
			}
		}
	}
}