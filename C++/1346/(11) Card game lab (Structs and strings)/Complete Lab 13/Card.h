#ifndef CARD_H
#define CARD_H

enum Suits {Hearts = 3, Diamonds, Clubs, Spades};
enum Values {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card
{
	Suits S;
	Values V;
	bool Used;
};


void  Deal (Card [], Card [] [5]);
void  Display (const Card &); // passing by reference is more efficient but the default is to pass by value
void  DisplayHand (const Card []);
void  InitDeck (Card []);
bool  straightFlush (Card []); //testing...
bool  fourKind (Card []); // works! sweet baby jesus!
bool  fullHouse (Card []); // works
bool  flush (Card []); // works! FINALLY!
bool  straight (Card []); // works
bool  threeKind (Card []); // works
bool  twoPair (Card []); // works
bool  anyPair (Card []); // works
int   Score (Card []);
void  Winner (Card [][5]);
char* identify (Card []);
void  Shuffle (Card []);
void  Sort (Card []);


#endif