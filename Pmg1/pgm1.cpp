/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Jan 29 2016
Purpose: This program calculates the amount of change due
***************************************************************/
#include <iostream>
using namespace std;



int main() 
{
	//var declaration
	int amoundDue = 0;
	int amoundRec = 0;
	
	
	//get inputs from user
		cout <<"Amount due on the bill: ";
		cin >>  amoundDue;
		cout <<endl << "Amount received from the customer: ";
		cin >>  amoundRec;
		
		
	//get the amount of change to give back
		int change = amoundRec - amoundDue;
		cout << endl << "the Change due is: " << change << endl << endl;
		int bills = change;
		
		
	//use modular math to remove every 20, 10 , and 5 doller bill so you are left with the dollar bills
		int one = ((bills %20)%10)%5;
	//subtract the doller bills
		bills -= one;
	//use modular math to remove every 20 and 10 dollar bills so you are left with the amount of money in five doller bills
		int five = ((bills %20)%10);
	//subtract the amount of th five doller bills
		bills -= five;
	//use moduler math to remove every 20 doller bill so you are left with the amount in ten doller bills
		int ten = (bills %20);
	//subtract the amount of ten doller bills
		bills -= ten;
	//after the above math, you should be left with only 20 doller bills
		int twenty = bills;
		
		
	//disp amounts
		cout << "Twenties: " << twenty/20 ;
		cout << "\nTens: " << ten/10 ;
		cout << "\nFives: " << five/5 ;
		cout << "\nOnes: " << one ;
	return 0;
}
