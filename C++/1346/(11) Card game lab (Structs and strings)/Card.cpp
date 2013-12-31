#include <iostream>

using namespace std;

#include <memory.h>
#include <stdlib.h>
#include <time.h>

#include "Card.h"

static char *	CardValues []	=	{
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
	int		CardInDeck;
	int		CardInHand;
	int		WhichHand;

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
	int	i;
	
	for (i = 0; i < 5; i++)
	{
		Display (Hand [i]);
		cout << endl;
	}
}

void InitDeck (Card C [])
	{
	int		i;

	srand (time (0));
	for (i = 0; i < 52; i++)
		{
		C [i].S	= (Suits) (Hearts + (i / 13));
		C [i].V	= (Values) (i % 13);
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


bool flush	(Card Hand[])
{
	Card temp = Hand[0];
	for(int i = 0; i<5; i++)
		if(Hand[i].S != temp.S)//Take a sample card and compare all of the other cards to it.
			return false;
	return true;
}
bool straight		(Card Hand[])
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

bool twoPair		(Card Hand[]) //same thinking as 3kind. Since the possibilities are tested in descending order of score, a 2pair won't be mistaken for a 4kind.
{
	if(((Hand [0].V == Hand [1].V)&&(Hand [2].V == Hand [3].V)) || ((Hand [0].V == Hand [1].V) && (Hand [3].V == Hand [4].V))||((Hand [1].V == Hand [2].V)&&(Hand [3].V == Hand [4].V)))
		return true;
	else
		return false;
}

bool anyPair			(Card Hand[])//pairs will be next to eachother. as soon as a pair is found it'll return true. if nothing is found it returns false. innocent until proven guilty.
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
		return 700 + Hand[4].V;
	if(fullHouse(Hand))
		return 600 + Hand[4].V;
	if(flush(Hand))
		return 500 + Hand[4].V;
	if(straight(Hand))
		return 400 + Hand[4].V;
	if(threeKind(Hand))
		return 300 + Hand[4].V;
	if(twoPair(Hand))
		return 200 + Hand[4].V;
	if(anyPair(Hand))
		return 100 + Hand[4].V;
	return Hand[4].V;
}
void Winner (Card Hands[][5])//Another innocent until proven guilty. I love doing these. I guess I should call it "Base Case."
{
	int other;
	int winner = 0;
	bool tie = false;
	for(int i = 0; i<5; i++)
		if(Score(Hands[i]) > Score(Hands[winner]))
			winner = i;
	for(int i = 0; i<5; i++)
		if((i!=winner)&&(Score(Hands[i]) == Score(Hands[winner])))
		{
			tie = true;
			other = i;
		}
	if(tie)
		cout << "Players " << winner+1 << " and " << other+1 << " have tied with a " << identify(Hands[winner]) << "!" << endl;
	else
		cout << "Player " << winner+1 << " has won with a " << identify(Hands[winner]) << endl;
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
	int		i;
	Card	Temp	[52];
	int		Which;

	for (i = 0; i < 52; i++)
		C [i].Used = false;
	for (i = 0; i < 52; i++)
		{
		do	{
			Which = rand () % 52;
			} while (C [Which].Used);
		C [Which].Used	= true;
		Temp [i]		= C [Which];
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
