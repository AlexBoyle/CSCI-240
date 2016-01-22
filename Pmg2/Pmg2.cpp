/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Jan 29 2015
Purpose: This program calculates the amount of change due
***************************************************************/
#include <iostream>
using namespace std;
double pi = 3.14159;
double areaCircle(int rad)
{
	return (pi * (rad * rad));
}
double areaTriangle( int bace, int height)
{
	return (.5 * (bace * height));
}
double areaEclipse(int major, int minor)
{
	return (pi * (major * minor));
}
int main() 
{
	int choice = 0;
	cout << "1. Calculate the area of a circle\n"
		 << "2. Calculate the area of a triangle\n"
		 << "3. Calculate the area of an ellipse\n"
		 << "4. Quit\n"
		 << "Select one: ";
	cin >> choice;
	cout << endl;
	switch(choice)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "Goodbye!";
			break;
		default:
			break;
}
return 0;
}
