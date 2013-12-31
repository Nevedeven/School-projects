#include <iostream>

using namespace std;

#include "Card.h"

char* identify(Card Hand[]);

void main ()
{
	Card	Deck [52];
	Card	Hands [4] [5];
	InitDeck (Deck);
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
}