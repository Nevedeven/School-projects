//**************************************************************************
//
// DESCRIPTION: Programming exercise one to print author's name
// CLASS: COSC 1436.S03
// AUTHOR: Deven Tharp
// DATE: January 2013
//
//**************************************************************************
#include <iostream>
using namespace std;
long L1;
long L2;

void main ()
{
	cout << "For this trick, I'm going to need 2 whole numbers.\nNumber one: ";
	cin >> L1;
	cout << "\nNumber two: ";
	cin >> L2;

	if(L1>L2)
		cout << L1;
	else if(L2>L1)
		cout << L2;
	else
		cout << "Neither";
	cout << " is the largest number of the two." << endl;
	cout << L1 << " is ";
	if(L1<0)
		cout << "negative.";
	else
		cout << "positive.";
	cout << "\n" << L2 << " is ";
	if(L2<0)
		cout << "negative.";
	else
		cout << "positive.";
	long L3;
	cout << "\n\nNow gimme another number: ";
	cin >> L3;
	cout << L3 << " spelled out is ";
	switch(L3)
	{
	case 1: cout << "\"one.\"";
		break;
	case 2: cout << "\"two.\"";
		break;
	case 3: cout << "\"three.\"";
		break;
	case 4: cout << "\"four.\"";
		break;
	case 5: cout << "\"five.\"";
		break;
	case 6: cout << "\"six.\"";
		break;
	case 7: cout << "\"seven.\"";
		break;
	case 8: cout << "\"eight.\"";
		break;
	case 9: cout << "\"nine.\"";
		break;
	default:cout << "out of range.";
		break;
	}
	cout << endl;
}
/*
1) Read in two whole numbers
2) Display which of the numbers is the largest
3) Display whether each number is positive or negative
4) Read in a third number
5) Using a switch, display the number as a name (i.e. ONE, TWO, etc.) 
if the number is from zero to nine, or if the number is not in that range display “Out of Range”.
*/