#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <cctype>
#include <string.h>

using namespace std;

void getNames(char* word, int limit);
void sort(char words[][16], int amt);

int main()
{
	const int LIMIT = 16;
	int amt;
	char words[20][LIMIT];
	char fancy[3];
	while(true){
	cout << "Sorting time again. This time we're entering words.\nTell me how many names you want to enter.\nAgain, 20 or less." << endl;
	while(!(cin >> amt)||((amt>20)||(amt<=0)))
	{
		cout << "Try that again. I'm looking for a whole number more than 0 and less than 20: ";
		cin.clear();
		cin.ignore(10000,'\n');
	}
	cout << "\nAlrighty then, go ahead and enter " << amt << " words.\n(No spaces, max of 15 characters)" << endl;
	gets(fancy);//gotta clear the stream for some reason.
	for(int i = 0; i < amt; i++)
	{
		switch(i+1){case 1: fancy[0] = 's'; fancy[1] = 't'; fancy[2] = '\0'; break; case 2: fancy[0] = 'n'; fancy[1] = 'd'; fancy[2] = '\0'; break; case 3: fancy[0] = 'r'; fancy[1] = 'd'; fancy[2] = '\0'; break; default: fancy[0] = 't'; fancy[1] = 'h'; fancy[2] = '\0';}
		cout << "\nEnter your " << (i+1) << fancy << " word: ";
		gets(words[i]);
	}

	cout << "\nYour words, in the order you entered them, are as follows:" << endl;
	for(int i = 0; i < amt-1; i++)
		cout <<  words[i] << endl;
	cout<< words[amt-1] << endl;

	sort(words, amt);

	cout << "\nYour words, sorted in alphabetical (ASCII) order, are as follows:" << endl;
	
	for(int i = 0; i < amt-1; i++)
		cout <<  words[i] << "\n";
	cout<< words[amt-1] << endl;
	}
}

void sort(char words[][16], int amt)
{
	bool sorted;
	do
	{
		sorted = true;
		amt--;
		for(int j = 0; j<amt; j++)//passes through rows
		{
			char temp1[16]; char temp2[16];
			for(int l=0;l<16;l++) //sets up lowercase cstrings for comparison without changing the original variables.
			{
				temp1[l] = tolower((words[j][l]));
				temp2[l] = tolower((words[j+1][l]));
			}
			if(strcmp(temp1, temp2)>0)
			{
				sorted = false;
				char temp[16];
				strcpy(temp, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j+1], temp);
			}
		}
	}while(!sorted);
}