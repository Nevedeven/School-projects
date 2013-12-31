/*most of main method is acknowledged to be taken from class example written by Bill Slater. It's safe to assume that anything that doesn't look like a student's work in this file is Bill's work*/

#include <iostream>

using namespace std;

#include <conio.h>	// special input/output functions
#include <stdlib.h>	// needed for system used below
#include <time.h>	// for time stuff

const	int		MaxCols	(60);
const	int		MaxRows	(60);
const	int		SecondsToWait (0.75);

char input[200];

bool	Board	[MaxRows + 2] [MaxCols + 2];

bool checkNeighbors(int r, int c);
void showBoard();
void getInput();
int	Generation = 0;
bool inputFlag = false;	

void main ()
	{
	while(true)
	{
		int		Row;
		int		Col;
		bool	NextGeneration	[MaxRows + 2] [MaxCols + 2];
		time_t	StopTime;
	
		//	Set up the board - User enters which cells are "alive" (this is generation 0)
		memset (Board, false, (MaxRows + 2) * (MaxCols + 2) * sizeof (bool));
		memset (NextGeneration, false, (MaxRows + 2) * (MaxCols + 2) * sizeof (bool));
		showBoard();
		cout << "Enter your coordinates for the initial living cells, (x,y): ";
		getInput();
		Generation = 0;
		do	{
			showBoard();
			cout << "Hit any key to stop the game." << endl;
		//		For each cell on the board
			for (Row = 1; Row <= MaxRows; Row++)
				for (Col = 1; Col <= MaxCols; Col++)
					{
						NextGeneration[Row][Col] = checkNeighbors(Row, Col);
					}
			StopTime = time (0) + SecondsToWait;
			while (time (0) < StopTime);
			Generation++;
			memcpy (Board, NextGeneration, (MaxRows + 2) * (MaxCols + 2) * sizeof (bool));	// copies one array to another
			StopTime = time (0) + SecondsToWait;
			while (time (0) < StopTime);
			} while (!_kbhit ());	// kbhit is true if a key has been typed
		cout << "Restarting program. There's an X button at the top right there if you want to leave." << endl;
		}
	}


void getInput()
{
	int x = 0;
	int y = 0;
	char * pointer;
	cin.getline(input, 200);
	pointer = strtok (input," ,.-()");
	while(pointer != NULL)
	{
		x = atol(pointer);
		pointer = strtok (NULL, " ,.-");
		y = atol(pointer);
		pointer = strtok (NULL, " ,.-");
		if(x>60||y>60||x<1||y<1)
		{
			inputFlag = 1;
			continue;
		}
		Board[y][x] = 1;
	}
}
void showBoard()
{
	system ("cls");
	//		Show the current generation
	cout << "Generation: " << Generation << endl;
	for (int Row = 1; Row <= MaxRows; Row++)
		{
		for (int Col = 1; Col <= MaxCols; Col++)
			cout << ((Board [Row] [Col]) ? '*' : '-') << ' '; // try making the font smaller.
		cout <<endl;
		}
	if(inputFlag)
				cout << "One or more of your inputs were invalid, so they were skipped." << endl;
}

bool checkNeighbors(int r, int c)
{
	int n = 0;
	if(Board[r-1][c-1] == 1)
		n++;
	if(Board[r-1][c] == 1)
		n++;
	if(Board[r-1][c+1] == 1)
		n++;
	if(Board[r][c-1] == 1)
		n++;
	if(Board[r][c+1] == 1)
		n++;
	if(Board[r+1][c-1] == 1)
		n++;
	if(Board[r+1][c] == 1)
		n++;
	if(Board[r+1][c+1] == 1)
		n++;
	if(n==2) //if the number of living neighbors is 2, the cell's state remains unchanged.
		return Board[r][c];
	if(n==3)
		return 1;
	else if(n<=1||n>=4)
		return 0;
}