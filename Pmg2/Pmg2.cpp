/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 5 2016
Purpose: This program calculates the amount of change due
***************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
const double pi = 3.14159;



/*
* Returns the area of a circle with a givin radius
*
*@param rad Radius of  circle
*
*@return The area of the circle with the givin radius
*/
double areaCircle(int rad)
{
	return (pi * (rad * rad));
}
/*
* Returns the area of a triangle with a givin base and height
*
*@param base Width of the base of the triangle  
*@param height Height of the givin triangle
*
*@return The area of a triangle with a givin base and height
*/


double areaTriangle( int base, int height)
{
	return (.5 * (base * height));
}


/*
* Returns the area of an elipse with a givin major and minor axis
*
*@param major Major axis
*@param minor Minor axis
*
*@return The area of an elipse with a givin major and minor axis
*/
double areaEclipse(int major, int minor)
{
	return (pi * (major * minor));
}



int main() 
{
	int choice = 0;
	
	cout << "\nGeometry Calculator\n\n"
		<< "1. Calculate the area of a circle\n"
		<< "2. Calculate the area of a triangle\n"
		<< "3. Calculate the area of an ellipse\n"
		<< "4. Quit\n"
		<< "\nEnter your choice(1-4): ";
	cin >> choice;
	cout << endl;
	switch(choice)
	{
		case 1:
		{
			int rad = 0;
			cout << "\nEnter the radius: ";
			cin >> rad;
			cout << "\nThe area of the circle is " << setprecision(2) << fixed << areaCircle(rad);
			break;
		}
		case 2:
		{
			int base = 0;
			int height = 0;
			cout << "\nEnter the length of the base: ";
			cin >> base;
			cout << "\nEnter the height: ";
			cin >> height;
			cout << "\nThe area of the triangle is " << setprecision(2) << fixed << areaTriangle(base, height);
			break;
		}
		case 3:
		{
			int major = 0;
			int minor = 0;
			cout << "\nEnter the length of the Semi-Major Axis: ";
			cin >> major;
			cout << "\nEnter the length of the Semi-Minor Axis: ";
			cin >> minor;
			cout << "\nThe area of the eclipse is " << setprecision(2) << fixed << areaEclipse(major, minor);
			break;
		}
		case 4:
			cout << "\n\nGoodbye!";
			break;
		default:
			break;
}
return 0;
}
