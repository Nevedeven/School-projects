#include <iostream>

using namespace std;

#include <memory.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"

static char * CardValues [] = {
"Two",
"Three",
"Four",
"Five",
"Six",
"Seven",
"Eight",
"Nine",
"Ten",
"Jack",
"Queen",
"King",
"Ace"
};



void Deal (Card Deck [], Card Hands [] [5])
{
	int CardInDeck;
	int CardInHand;
	int WhichHand;

	CardInDeck = 0;
	for (CardInHand = 0; CardInHand < 5; CardInHand++)
	for (WhichHand = 0; WhichHand < 4; WhichHand++)
	{
		Hands [WhichHand] [CardInHand] = Deck [CardInDeck];
		CardInDeck++;
	}
}

void Display (const Card & C)
{
	cout << CardValues [C.V] << " of " << (char) C.S;
}

void DisplayHand (const Card Hand [])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		Display (Hand [i]);
		cout << endl;
	}
}

void InitDeck (Card C [])
{
	int i;

	srand (time (0));
	for (i = 0; i < 52; i++)
	{
		C [i].S = (Suits) (Hearts + (i / 13));
		C [i].V = (Values) (i % 13);
	}
}
bool straightFlush(Card Hand [])//a combination of 2 scores. easy.
{
	if(flush(Hand)&&straight(Hand))
		return true;
	else
		return false;
}
bool fourKind (Card Hand [])
{
	if ((Hand [0].V == Hand [3].V) || (Hand [1].V == Hand [4].V))//given in class. The only locations of a 4kind in a sorted hand are first and last, so you only need to test the locations of the first and last of the possible 4kinds.
		return true;
	else
		return false;
}

bool fullHouse (Card Hand [])
{
	if(threeKind(Hand)&&(((Hand [0].V == Hand [1].V)&&(Hand[0].V != Hand[2].V)) || ((Hand [3].V == Hand [4].V)&&(Hand[4].V != Hand[2].V))))//since the pair can only be first or last in a sorted hand, and the threekind could be mistaken for a pair as well, a special case has to be made for the possible pairs, making sure the location of the possible third of that pair doesn't hold the same value as the pair.
		return true;
	else
		return false;
}


bool flush (Card Hand[])
{
	Card temp = Hand[0];
	for(int i = 0; i<5; i++)
		if(Hand[i].S != temp.S)//Take a sample card and compare all of the other cards to it.
			return false;
	return true;
}
bool straight (Card Hand[])
{
	int temp = Hand[0].V;
	for(int i = 0; i<5; i++)
		if(Hand[i].V != temp++)//Hand[0] is the starting value, every card after that has to be one up or it's not a straight. hence the ++.
			return false;
	return true;
}

bool threeKind (Card Hand []) //same thinking as 4kind.
{
	if ((Hand [0].V == Hand [2].V) || (Hand [1].V == Hand [3].V) || (Hand [2].V == Hand [4].V))
		return true;
	else
		return false;
}

bool twoPair (Card Hand[]) //same thinking as 3kind. Since the possibilities are tested in descending order of score, a 2pair won't be mistaken for a 4kind.
{
	if(((Hand [0].V == Hand [1].V)&&(Hand [2].V == Hand [3].V)) || ((Hand [0].V == Hand [1].V) && (Hand [3].V == Hand [4].V))||((Hand [1].V == Hand [2].V)&&(Hand [3].V == Hand [4].V)))
		return true;
	else
		return false;
}

bool anyPair (Card Hand[])//pairs will be next to eachother. as soon as a pair is found it'll return true. if nothing is found it returns false. innocent until proven guilty.
{
	
	for(int i = 0; i<5; i++)
		if(Hand[i].V == Hand[i+1].V)
			return true;
	return false;
}


int Score (Card Hand[5])
{
	if(straightFlush(Hand))
		return 800 + Hand[4].V;
	if(fourKind(Hand))
	{
		if (Hand [0].V == Hand [3].V)
			return 700 + Hand[3].V;
		return 700 + Hand[4].V;
	}
	if(fullHouse(Hand))
		return 600 + Hand[4].V;
	if(flush(Hand))
		return 500 + Hand[4].V;
	if(straight(Hand))
		return 400 + Hand[4].V;
	if(threeKind(Hand))
	{
		if (Hand [0].V == Hand [2].V)
			return 300 + Hand[2].V;
		if (Hand [1].V == Hand [3].V)
			return 300 + Hand[3].V;
		return 300 + Hand[4].V;
	}
	if(twoPair(Hand))
	{
		if(Hand [2].V == Hand [3].V)
			return 200 + Hand[3].V;
		return 200 + Hand[4].V;
	}
	if(anyPair(Hand))
	{
		for(int i = 0; i<5; i++)
			if(Hand[i].V == Hand[i+1].V)
				return 100 + Hand[i].V;
	}
	return Hand[4].V;
}
void Winner (Card Hands[][5])
{
	int others[3]; //somehow I have to deal with threeway and fourway ties.
	int winner = 0;
	int pOth = -1; //index for the others array, when it's at -1, tie should be false.
	bool tie = false;
	for(int i = 0; i<5; i++) //high score finder
		if(Score(Hands[i]) > Score(Hands[winner]))
			winner = i;
	
	for(int i = 0; i<4; i++) //start tie checking
		if((i!=winner)&&(Score(Hands[i]) == Score(Hands[winner])))
		{
			pOth++;
			others[pOth] = i;//at this point the other hand becomes a candidate
			tie = true; //and the tie flag is tripped
			if(twoPair(Hands[i])) // breaking a twopair tie with the lower pair. 
			{
				int tie1; //original winner
				int tie2; //candidate
				for(int j = 0; j<5; j++)
					if(Hands[winner][j].V == Hands[winner][j+1].V)
					{
						tie1 = Hands[winner][j].V;
						break;
					}
				for(int j = 0; j<5; j++)
					if(Hands[others[pOth]][j].V == Hands[others[pOth]][j+1].V)
					{
						tie2 = Hands[others[pOth]][j].V;
						break;
					}
				if(tie2!=tie1)//the lower of the two pairs are compared, and if they're not the same, the winner is changed, and there's no longer a tie.
				{
					if(tie1>tie2)
						pOth--; //if winner has a better lower pair, the candidate is disregarded.
					if(tie2>tie1)
					{
						winner = others[pOth];
						pOth = -1;
					}
					if(pOth == -1)
						tie = false;
				}
				else
				{
					for(int j = 0; j<5; j++) //but if they are the same, the kickers are compared similarly.
						if((Hands[winner][j].V != Hands[winner][j+1].V)&&(Hands[winner][j].V != Hands[winner][j-1].V))
						{
							tie1 = Hands[winner][j].V;
							break;
						}
					for(int j = 0; j<5; j++)
						if((Hands[others[pOth]][j].V != Hands[others[pOth]][j+1].V)&&(Hands[others[pOth]][j].V != Hands[others[pOth]][j-1].V))
						{
							tie2 = Hands[others[pOth]][j].V;
							break;
						}
					if(tie2!=tie1)
					{
						if(tie1>tie2)
							pOth--; //if the winner has a better kicker the candidate is disregarded.
						if(tie2>tie1)
						{
							winner = others[pOth];
							pOth = -1;
						}
						if(pOth == -1)
							tie = false;
					}
				}
			}//end twopair tie condition
			if(Hands[winner][4].V>Hands[others[pOth]][4].V)
			{
				pOth--;
				if(pOth == -1)
					tie = false;
				continue;
			}
			
			if(Hands[others[pOth]][4].V>Hands[winner][4].V)
			{
				winner = others[pOth];
				pOth = -1;
				tie = false;
				continue;
			}
			if(Hands[winner][3].V>Hands[others[pOth]][3].V)
			{
				pOth--;
				if(pOth == -1)
					tie = false;
				continue;
			}
			
			if(Hands[others[pOth]][3].V>Hands[winner][3].V)
			{
				winner = others[pOth];
				pOth = -1;
				tie = false;
				continue;
			}
			if(Hands[winner][2].V>Hands[others[pOth]][2].V)
			{
				pOth--;
				if(pOth == -1)
					tie = false;
				continue;
			}
			
			if(Hands[others[pOth]][2].V>Hands[winner][2].V)
			{
				winner = others[pOth];
				pOth = -1;
				tie = false;
				continue;
			}
			if(Hands[winner][1].V>Hands[others[pOth]][1].V)
			{
				pOth--;
				if(pOth == -1)
					tie = false;
				continue;
			}
			
			if(Hands[others[pOth]][1].V>Hands[winner][1].V)
			{
				winner = others[pOth];
				pOth = -1;
				tie = false;
				continue;
			}
			if(Hands[winner][0].V>Hands[others[pOth]][0].V)
			{
				pOth--;
				if(pOth == -1)
					tie = false;
				continue;
			}
			
			if(Hands[others[pOth]][0].V>Hands[winner][0].V)
			{
				winner = others[pOth];
				pOth = -1;
				tie = false;
				continue;
			}
		}//if their scores are the same, and their kicker cards are the same, it's a definite tie.
	if(pOth == 1)
	{
		cout << "Players " << winner+1 << " and " << others[0]+1 << " have tied with a ";
		cout << identify(Hands[winner]) << "!" << endl;
	}
	else if (pOth == 2)
	{
		cout << "Players " << winner+1 << ", " << others[0]+1 << " and " << others[1]+1 << " have tied with a ";
		cout << identify(Hands[winner]) << "!" << endl;
	}
	else if (pOth == 3)
	{
		cout << "Everyone wins!" << endl;
	}
	else
	{
		cout << "Player " << winner+1 << " has won with a ";
		cout << identify(Hands[winner]) << endl;
	}
}
char* identify(Card Hand [])
{
	if(straightFlush(Hand))
		return "Straight Flush";
	if(fourKind(Hand))
		return "Four of a Kind";
	if(fullHouse(Hand))
		return "Full House";
	if(flush(Hand))
		return "Flush";
	if(straight(Hand))
		return "Straight";
	if(threeKind(Hand))
		return "Three of a Kind";
	if(twoPair(Hand))
		return "Two Pair";
	if(anyPair(Hand))
		return "Pair";
	cout << "High Card of the " << CardValues [Hand[4].V] << " of " << (char) Hand[4].S;
	return "";
}

void Shuffle (Card C [])//given in class.
{
	int i;
	Card Temp [52];
	int Which;

	for (i = 0; i < 52; i++)
		C [i].Used = false;
	for (i = 0; i < 52; i++)
	{
		do {
			Which = rand () % 52;
		} while (C [Which].Used);
		C [Which].Used = true;
		Temp [i] = C [Which];
	}
	memcpy (C, Temp, 52 * sizeof (Card));
}
void Sort (Card Hand [])//typical bubble sort.
{
	bool sorted = true;
	do
	{
		sorted = true;
		for(int i = 0; i<4; i++)
			if(Hand[i].V>Hand[i+1].V)
			{
				sorted = false;
				Card temp = Hand[i];
				Hand[i] = Hand[i+1];
				Hand[i+1] = temp;
			}
	}while(!sorted);
}