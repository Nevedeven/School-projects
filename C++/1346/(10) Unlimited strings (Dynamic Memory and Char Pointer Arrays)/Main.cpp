#include <iostream> // cin cout
#include <string> // for .length()
#include <memory> // for strcpy and such
#include <cstdlib>
using namespace std;

char* read (); // reads in your unlimited string
void resize(char** words, int max); // Turns the pointer array into a vector, makes it so you can enter unlimited names. Pretty clunky since you have to copy over every string.
void sort (char** words, int last); // Standard bubble sort.
int search (char* word, char** list, int index); // less than standard binary search. I did this from memory.

int main()
{
	int max = 20; //vector for pointer array size.
	char** words = new char*[max]; 
	char* input = new char;
	int index = 0;
		cout << "Same song, third verse, a little bit harder and a whole lot worse.\nGimme as many words as you can muster, as long as you please.\nBring it. Enter an empty string when you're done." << endl;
		do
		{
			input = read();
			if(input[0]=='\0') // Base case. My java teacher would cry for how many times I use break now.
				break;
			if(index>max-1) //If you're almost at the end the array resizes.
			{
				resize(words, max);
			}
			words[index++] = input; //append pointer to pointer array
		}while(1);

		cout << "You entered these words or phrases: " << endl;

		for(int i = 0; i<index; i++)
			cout << i << ") " << words[i] << endl; // show

		sort(words, index); //sort
	
		cout << "I sorted them all for you so you can search for words: " << endl;
		for(int i = 0; i<index; i++)
			cout << i << ") " << words[i] << endl; //show sorted
		int prompt = 5; // I didn't want this prompt to constantly bother the user so I put in a counter.
		int found;
		do
		{
			cout << "Gimme a string to search for." << endl;
			input = read();
			found = search(input, words, index);
			if(input[0]=='\0')
				break;
			if(found!= -1)
				cout << "The word " << input << " is at index " << found << endl;
				else
				cout << "The word " << input << " is not in the array." << endl;
			if(prompt >= 5)
			{
				cout << "\nEnter an empty string to stop searching.\n" << endl;
				prompt = 0;
			}
			prompt++;
		}while(1);
}

char* read() //basically the readLine I got in class.
	{
			char	C; // entered char
			char *	pLine; // The string
			char *	pTemp; // for resizing
			int		index; // location for next char to go
			int		limit; // current size of array

	limit	= 50;
	index	= 0;
	pLine			= new char [limit + 1];
	while ((C = cin.get ()) != '\n') //pressing enter stops input and returns the string.
		{
		pLine [index++] = C; 
		if (index >= limit)
				{
				limit	*= 2;
				pTemp			= new char [limit + 1];
				memcpy (pTemp, pLine, index);
				delete [] pLine;
				pLine			= pTemp;
				}
			else;
		}
	pLine [index] = '\0'; //character that ends the string.
	return pLine;
	}

void resize(char** words, int max) //If the char pointer array gets too large
{
	char** temp = new char*[max+20]; //a new one is made with 20 more spaces.
	for(int i = 0; i<max; i++)
		temp[i] = words[i]; //All of the strings from the old array are copied over
	words = temp; //And the pointer is assigned the address of the new char pointer array.
}

void sort(char** words, int last)
{
	bool sorted;
	do
	{
		sorted = true;
		last--;
		for(int j = 0; j<last; j++)//passes through rows
		{
			string easy1 = words[j]; string easy2 = words[j]; //I
			for(int i = 0; i<easy1.length(); i++) //Regret
				easy1[i] = tolower(words[j][i]); //doing
			for(int i = 0; i<easy2.length(); i++) //this
				easy2[i] = tolower(words[j+1][i]); //I could have just
			const char* temp1 = easy1.c_str(); //used one of the ignore case methods
			const char* temp2 = easy2.c_str(); //in the string library
			if(strcmp(temp1, temp2)>0)
			{
				sorted = false;
				char temp[16];
				strcpy(temp, words[j]);
				strcpy(words[j], words[j+1]);
				strcpy(words[j+1], temp);
			}
		}
	}while(!sorted); //regardless of that, the sort still works.
}

int search (char* word, char** list, int index)//did this from memory so it's a bit sloppy.
{
	int min = 0;
	int max = index;
	int mid = (min+max)/2;//a binary search works by taking a sorted array, splitting it in half, and determining which half to search by the value in the middle.
	while(max>min) //it keeps splitting the array until either the middle value is the one you're searching for,
	{//or the upper and lower boundaries for the section you're searching have passed eachother, in which case the value doesn't exist.
		string easy1 = word; string easy2 = list[mid]; //did the same thing here for comparing strings.
		for(int i = 0; i<easy1.length(); i++)
			easy1[i] = tolower(word[i]);
		for(int i = 0; i<easy2.length(); i++)
			easy2[i] = tolower(list[mid][i]);
		const char* temp1 = easy1.c_str();
		const char* temp2 = easy2.c_str();
		if(strcmp(temp1,temp2)>0) 
		{
			min = mid+1; 
			mid = (min+max)/2; 
		}
		else if(strcmp(temp1,temp2)<0) 
		{
			max = mid;
			mid = (min+max)/2;
		}
		else
			return mid;
	}
	return -1;
}