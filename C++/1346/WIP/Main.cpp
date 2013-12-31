#include <iostream>
#include <string>

using namespace std;
struct Plane
{
	char* Name;
	int Capacity;
	int remaining;
	Party* roster;
	int index;
};

struct Party
{
	char* Name;
	int Size;
	Plane request;
};

bool arrive(Party p);
void transfer(Party a);
void fly(Plane departing);
char* read();
void sort(Party* roster, int last);
static int parties = 0;
Plane Lounge;

int main()
{
	char* input = new char;
	Plane Alfa;
	Plane Bravo;
	Party* roster = new Party;
	system("cls");
	cout << "\n type 'help' for commands and instructions" << endl;

	while(true)
	{
		cin >> input;
		if(strcmpi(input, "help")==0)
		{
			cout << "start out by indicating the capacities of alfa (size), bravo (size), and the lounge (size)." << endl;
			cout << "'fly' (name) causes a plane with the name (name) to take off instantly" << endl;
			cout << "'arrive' (name) (size) (plane) denotes a party with the name  (name) and size (size) that wants to get on plane (plane). If there's no room on the requested plane, they're placed in the lounge." << endl;
			cout << "'shutdown' shuts down the console. Planes will still fly." << endl;
			cout << "None of the (parameters) above can have spaces in them." << endl;
		}
		else if(strcmpi(input, "alfa")==0)
		{
			while(!cin >> Alfa.Capacity||Alfa.Capacity<1);
			Alfa.remaining = Alfa.Capacity;
		}
		else if(strcmpi(input, "bravo")==0)
		{
			while(!cin >> Bravo.Capacity||Bravo.Capacity<1);
			Bravo.remaining = Bravo.Capacity;
		}
		else if(strcmpi(input, "fly")==0)
		{
			while(1)
			{
				cin >> input;
				if(strcmpi(input, "alfa")==0)
				{
					fly(Alfa);
					break;
				}
				else if(strcmpi(input, "bravo")==0)
				{
					fly(Bravo);
					break;
				}
				else
				{
					cout << "Alfa or Bravo?" << endl;
				}
			}
		}
		else if(strcmpi(input, "arrive")==0)
		{
			while(1)
			{
				cin >> input;
				if(strcmpi(input, "alfa")==0)
				{
					roster[parties].request = Alfa;
					break;
				}
				else if(strcmpi(input, "bravo")==0)
				{
					roster[parties].request = Bravo;
					break;
				}
				else
				{
					cout << "Alfa or Bravo?" << endl;
				}
			}
			roster[parties].Name = read();
			while(!cin >> roster[parties].Size||roster[parties].Size<1);
			if(!arrive(roster[parties++]))
			{
				cout << "Party " << roster[parties].Name << " has been turned away." << endl;
				delete [] roster[parties].Name;
				parties--;
			}
		}
		else if(strcmpi(input, "shutdown")==0)
		{
			while(parties>0)
			{
				if(Alfa.Capacity>Alfa.remaining)
					fly(Alfa);
				if(Bravo.Capacity>Bravo.remaining)
					fly(Bravo);
			}
			return 0;
		}
		else
			cout<<"Invalid. Try again."<<endl;
		delete [] input;
	}
}

char* read() //recycled code
{
char C; // entered char
char * pLine; // The string
char * pTemp; // for resizing
int index; // location for next char to go
int limit; // current size of array

	limit = 50;
	index = 0;
	pLine = new char [limit + 1];
	while ((C = cin.get ()) != ' ') //pressing space stops input and returns the string.
	{
		pLine [index++] = C;
		if (index >= limit)
		{
			limit *= 2;
			pTemp = new char [limit + 1];
			memcpy (pTemp, pLine, index);
			delete [] pLine;
			pLine = pTemp;
		}
		else;
	}
	pLine [index] = '\0'; //character that ends the string.
	return pLine;
}

void sort(Party* roster, int last) // recycled code
{
	bool sorted;
	do
	{
		sorted = true;
		last--;
		for(int j = 0; j<last; j++)
		{
			if(roster[j].Size<roster[j+1].Size)
			{
				Party temp = roster[j];
				roster[j] = roster[j+1];
				roster[j+1] = temp;
			}
		}
	}while(!sorted);
}

bool arrive(Party p)
{
	if(p.Size>p.request.Capacity)
		return false;
	if(p.Size>p.request.remaining)
	{
		if(p.Size>Lounge.remaining)
			return false;
		Lounge.roster[Lounge.index++] = p;
	}
	p.request.roster[p.request.index++] = p;
}

void fly(Plane departing)
{

}