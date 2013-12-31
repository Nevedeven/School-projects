//Deven Tharp Final Exam
// COSC 1436.S03
// Professor Bill Slater
// May 13, 2013

#include <iostream>
#include <string>
using namespace std;

struct Person // number 4
{
	char firstName[20];
	char lastName[30];
	int DOB;
	int children;
	Person* spouse;
};

int wordCount(char* words);// number 1
void stringManip(char* sentence, char* vowels, char* consonants);// number 2
int highestDivisor(int num); // number 3
int findLastCase(char* sentence, char c); // number 5
char* bureaucrifyName(char* first, char* middle, char* last); // number 6
int GCD (int num1, int num2); // number 7
bool strcompi (char* word1, char* word2, bool* compareFlag); // number 8
int multiples (int base, int one, int two, int three); // number 9

int main()
{
	cout << "Hi." << endl;
	return 0;
}

int wordCount (char* words)// number 1
{
	int i = 0;
	int num = 0;
	while (words[i]!='\0')
	{
		if(words[i]==' ')
			if(words[i-1]!=' ')
				num++;
		i++;
	}
	return num;
}

void stringManip(char* sentence, char* vowels, char* consonants) // number 2
{
	int i = 0;
	int v = 0;
	int c = 0;

	while (sentence[i]!='\0')
	{
		switch(sentence[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': vowels[v++] = sentence[i];
			default: consonants[c++] = sentence[i];
		}
		i++;
	}
}

int highestDivisor(int num)
{
	int div = -1;
	if (num<0)
		num-=num*2;
	for(int i = 0; i<num; i++)
	{
		if(num%i == 0)
			div = i;
	}
	return div;
}

int findLastCase(char* sentence, char c)
{
	int i = 0;
	int index = -1;
	while (sentence[i]!='\0')
	{
		if(sentence[i] == c)
			index = i;
		i++;
	}
	return index;
}

char* bureaucrifyName(char* first, char* middle, char* last) // number 6
{
	int i = 0;
	while(first[i] != '\0')
		i++;
	while(middle[i] != '\0')
		i++;
	while(last[i] != '\0')
		i++;
	i+=3;
	char* bureauName = new char[i];
	int p = 0;
	i = 0;
	while (last[i] != '\0')
		bureauName[p++] = last[i++];
	bureauName[p++] = ',';
	bureauName[p++] = ' ';
	i = 0;
	while (first[i] != '\0')
		bureauName[p++] = first[i++];
	i = 0;
	bureauName[p++] = ' ';
	while (middle[i] != '\0')
		bureauName[p++] = middle[i++];
	return bureauName;
}

int GCD(int num1, int num2)// number 7
{
	int div = -1;
	int s;
	if(num1>num2)
		s=num2;
	else
		s=num1;
	for(int i = 1; i<=s; i++)
	{
		if(((num1%i) == 0)&&((num2%i) == 0))
			div = i;
	}
	return div;
}

bool strcompi (char* word1, char* word2, bool& compareFlag)// number 8
{
	if(strcmpi(word1,word2) == 0)
		return compareFlag = true;
	return compareFlag = false;
}

int multiples (int base, int one, int two, int three) // number 9
{
	int num = 0;
	if(base%one == 0)
		num += 1;
	if(base%two == 0)
		num += 10;
	if(base%three == 0)
		num += 100;
	return num;
}