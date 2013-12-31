#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>  

using namespace std;

int roll();
bool jeopardy(int match);
int main()
{
	
	srand(time(0));
	long long pool = 50;
	bool win = false;
	cout << "\nThis is a simplified game of craps.\nIf you roll a 7 or 11 on your first roll you automatically win that round.\nIf you roll a 2, 3 or 12 on your first roll you automatically lose that round.\nIf you roll anything else, you must try to roll that number again.\nIf you successfully roll that number again, you win the round.\nBut if you roll a 7 before then, you automatically lose the round.\nThis is a betting game, before each round you must place a bet.\n If you win, you gain that amount, if you lose, you lose that amount." << endl;
	while(true)
	{
		bool bad = true;
		long long bet = 0;
		if(pool==0)
		{
			cout<<"You're broke. go home."<< endl;
			return 0;
		}
		do
		{
			cout <<"\nYour pool contains: $" << pool << ". Place your bet." << endl;
			if(!(cin >> bet))
			{
				cout<<"This isn't a penny game. We're playing for dollar bills. \nput in a whole number more than 0." << endl;
				continue;
			}
			if(bet == -1)
				return 0;
			if(bet<=0)
			{
				cout << "Nice try. Make that a positive number." << endl;
				continue;
			}
			if(bet>pool)
			{
				cout << "Don't bet more than you have. \nGo sell something and come back if you wanna bet that much." << endl;
				continue;
			}
			bad = false;
		}while(bad);
		int r = roll();
		int timewarp = time(0)+1;
		while(time(0)<=timewarp);
		cout << "roll 1 is " << r << endl;
		switch(r)
		{
			case 2: win = false; break;
			case 3: case 4:	case 5:	case 6: win = jeopardy(r); break;
			case 7: win = true; break;
			case 8: case 9: case 10: win = jeopardy(r); break;
			case 11: win = true; break;
			case 12: win = false; break;
			default: cout<<"The random number generator seems to be broken."; 
		}
		if(win)
		{
			cout << "You win!" << endl;
			pool += bet;
		}
		else
		{
			cout << "You lose." << endl;
			pool -= bet;
		}
	}
}

int roll()
{
	return ((rand()%6)+1)+((rand()%6)+1);
}

bool jeopardy(int match)
{
	int tries = 1;
	int num;
	cout << "Phase 2. Your point number is " << match << endl;
	do
	{
		int timewarp = time(0)+1;
		while(time(0)<=timewarp);
		num = roll();
		cout << "roll " << ++tries << " gives you a " << num << endl;
		if(num == 7)
			return false;
	}while(num != match);
	return true;
}
//9 comes up way more than 8, but it shouldn't. 6 comes up WAY MORE than 7, but it DEFINITELY shouldn't. 3 comes up more than 5, which comes up way more than 10 or 11, which both come up way more than 4.
//this random number generator isn't helping out much.