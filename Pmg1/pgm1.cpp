/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 

Date Due: Jan 29 2015
Purpose: This program calculates the amount of change due
***************************************************************/
#include <iostream>
using namespace std;



int main() 
{
	int amoundDue = 0;
	int amoundRec = 0;
	cout <<"Amount due on the bill: ";
	cin >>  amoundDue;
	cout <<endl << "Amount received from the customer: ";
	cin >>  amoundRec;
	int change = amoundRec - amoundDue;
	cout << endl << "the Change due is: " << change << endl << endl;
	int temp = change;
	int one = ((temp %20)%10)%5;
	temp = change - one;
	int five = ((temp %20)%10);
	temp -= five;
	int ten = (temp %20);
	temp -= ten;
	int twe = temp;
	cout << "Twenties: " << twe/20 << endl;
	cout << "Tens: " << ten/10 << endl;
	cout << "Fives: " << five/5 << endl;
	cout << "Ones: " << one << endl;
	return 0;
}
