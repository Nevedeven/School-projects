#pragma once
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Name
{
public:
	Name(); //
	Name(const Name &); //
	Name(const char* first = "", const char* middle = "", const char* last = ""); //
	Name readName(istream &); // 
	//Name(const char* = ""); //Name parser constructor, WIP.
	~Name(); //
	char* copy(const Name); // same as the copy constructor I guess.
	char* copy(const char* first = "", const char* middle = "", const char* last = ""); //
	//char* copy(const char*);
	char* read(istream& = cin); // //read in a dynamic memory string.
	char* getFirst()const; //
	char* setFirst(const char*); //
	char* getMiddle()const; // 
	char* setMiddle(const char*); // 
	char* getLast()const; //
	char* setLast(const char*); //
	void display(ostream & = cout)const; // //display things
	int compareto(const Name&)const; // //alphabetize
	Name operator = (const Name &); // copy
	//Name operator = (const char*); //single string name parser. WIP.
	int operator == (const Name &); // compareto

protected:
	char* first;
	char* middle;
	char* last;
};

inline Name :: Name()
{};

inline Name :: ~Name()
{
	delete [] first;
	delete [] middle;
	delete [] last;
}

inline Name :: Name(const Name& n)
{
	strcpy(first, n.getFirst());
	strcpy(middle, n.getMiddle());
	strcpy(last, n.getLast());
}


inline char* Name :: getFirst() const
{
	return first;
}

inline char* Name :: setFirst(const char* c)
{
	strcpy(first, c);
}

inline char* Name :: getMiddle() const
{
	return middle;
}

inline char* Name :: setMiddle(const char* c)
{
	strcpy(middle, c);
}

inline char* Name :: getLast() const
{
	return last;
}

inline char* Name :: setLast(const char* c)
{
	strcpy(last, c);
}

inline void Name :: display (ostream& out) const
{
	out << last << ", " << first << " " << middle << endl;
}


inline ostream & operator << (ostream & out, const char* c)
	{
	Str.Display (out);
//	cout << Str.pChar;
	return out;
	}

inline istream & operator >> (istream & in, Name n)
	{
		n.readName();
		return in;
	}