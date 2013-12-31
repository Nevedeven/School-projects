#include <iostream>
#include <conio.h> // special input/output functions
#include <stdlib.h> // needed for system used below
#include <time.h> // for time stuff
using namespace std;

#include "Card.h"

char* identify(Card Hand[]);

void main ()
{
		Card Deck [52];
		Card Hands [4] [5];
		InitDeck (Deck); // the more notable hands start to come out when you don't remake the seed every 2 seconds.
	while(true)
	{
		Shuffle (Deck);
		Deal (Deck, Hands);
		for (int i = 0; i < 4; i++)
		{
			cout << "\tPlayer " << i+1 << " Has:" << endl;
			Sort (Hands [i]);
			DisplayHand (Hands [i]);
		}

		for(int j = 0; j<4; j++)
		{
			cout << "Player " << j+1 << " has a ";
			cout << identify(Hands[j]) << endl;
		}


		Winner(Hands);
		while (!getchar());
	}
}