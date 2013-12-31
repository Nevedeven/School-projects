//**************************************************************************
//
// DESCRIPTION: Programming exercise one to print author's name
// CLASS: COSC 1436.S03
// AUTHOR: Deven Tharp
// DATE: January 2013
//
//**************************************************************************
#include <iostream>
#include <string>

using namespace std;

void sum (int n1, int n2, int d1, int d2)
{
	n1 *= d2;
	n1 += (n2*d1);
	d1 *= d2;
	cout << n1 << "/" << d1 << endl; 
}

void divi (int n1, int n2, int d1, int d2)
{
	d1 *= n2;
	n1 *= d2;
	cout << n1 << "/" << d1 << endl; 
}

void mult (int n1, int n2, int d1, int d2)
{
	d1 *= d2;
	n1 *= n2;
	cout << n1 << "/" << d1 << endl; 
}

void sub (int n1, int n2, int d1, int d2)
{
	n1 *= d2;
	n1 -= (n2*d1);
	d1 *= d2;
	cout << n1 << "/" << d1 << endl; 
}

void main ()
{
	long num1, num2;
	cout << "Okay, so for this program I'm going to need two whole numbers,\nand this is tricky because I don't know how to filter out anything\nyou type after those numbers.\nSo you're going to have to type the number right on the first try, Ok? Ok.\nGo ahead and type in the first one:";
	cin >> num1;
	cout << "\nNow enter the second number:";
	cin >> num2;
	cout << "\nOkay, here's your first number: " << num1 << "\nHere's your second number:" << num2 << endl;
	cout << "Here's your numbers summed: " << (num1+num2) << endl;
	cout << "Divided: " << (num1/num2) << " (with a remainder of " << (num1% num2) << ".)" << endl;
	cout << "Multiplied: " << (num1*num2) << endl;
	cout << "and Subtracted: " << (num1-num2) << "\n\nIsn't that great?\n\nBut wait!\nHere's the challenge mode:" << endl;
	
	long denom1, denom2;
	cout << "This time I want you to enter two fractions.\nStarting with a numerator: ";
	cin >> num1;
	cout << "\nA denominator: ";
	cin >> denom1;
	cout << "\nAnother numerator: ";
	cin >> num2;
	cout << "\nAnd another denominator: ";
	cin >> denom2;
	cout << "\nAgain, here's your first number: " << num1 << "/" << denom1 << "\nyour second number: " << num2 << "/" << denom2 << endl;
	cout << "Here's your numbers summed: ";
	sum(num1,num2,denom1,denom2);
	cout << "Divided: ";
	divi(num1,num2,denom1,denom2);
	cout << "Multiplied: ";
	mult(num1, num2, denom1, denom2);
	cout << "and Subtracted: ";
	sub(num1, num2, denom1, denom2);
}
