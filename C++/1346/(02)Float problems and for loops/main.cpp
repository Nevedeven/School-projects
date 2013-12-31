//**************************************************************************
//
// DESCRIPTION: Programming exercise 4 to reveal the flaws of the floating point decimal type.
// CLASS: COSC 1436.S03
// AUTHOR: Deven Tharp
// DATE: January 2013
//
//**************************************************************************
#include <iostream>
using namespace std;
double DR1;
double DR2;
double DHelper = 1;
float FR1;
float FR2;
float FHelper = 1.0;
void main ()
{
	cout << "This program is going to sum (1/(1 -> 100,000,000)) and (1/(100,000,000 -> 1)) \nand store them in two sets of floats and doubles in order to display the problem with converting fractions between decimal and binary, \nespecially without adequate memory to hold a sufficient amount of digits after the decimal." << endl;
	for(int i = 1; i<=100000000; i++)
	{
		DR1 += 1/DHelper;
		DR2 += 1/(100000001 - DHelper++);
		FR1 += 1/FHelper;
		FR2 += 1/(100000001 - FHelper++);
	}
	cout << "The results for holding (1/(1 -> 100,000,000)) and (1/(100,000,000 -> 1))\n in floats are:\n" << FR1 << "\nand:\n" << FR2 << "\nRespectively." << endl;
	cout << "The results for holding the same equations in doubles are:\n" << DR1 << "\nand:\n" << DR2 << "\nRespectively." << endl;
	cout << "I think the difference in the float variables has something to do with the maximum size of a value that they can hold, \nand if it becomes a value that the variable can't 'hold' with it's allocated memory, \nthe variable becomes 'broken' and can't have another value added to it. \nwhat brought me to this conclusion was the enormous difference between the ascending and descending float sums, \nand the fact that both added together was still less than the summed doubles. \nIf I were to guess where the error occured, I'd have to say somewhere halfway down the line around the 50,000,000s. \nMaybe it has something to do with the float trying to switch between a normalized and a de-normalized number, \n That could be a big problem there. I think that may be it." << endl;
}
