/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 12 2016
Purpose: This program 
***************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	bool isRunning = true;
	int headsCount = 0;
	int tailsCount = 0;
	double headPercent = 0;
	double tailPercent = 0;
	string headVis = "";
	string tailVis = "";
	int toss = -1;
	int input = -1;
	char charInput = ' ';
	srand(time(0));
	cout << fixed << setprecision(1) ;
	while(isRunning)
	{
		cout << "\nHow many times do you want to toss the coin?: ";
		cin >> input;
		//if the number givin is negitive, ask again for a number that is positive
		while (input < 0)
		{
			cout << "\n\nNumber must be positive. How many times to you want to toss the coin?: ";
			cin >> input;
		}
		for (int i = 0; i < input; i ++)
		{
			toss = rand() % 2;
			if (toss == 0)
				headsCount ++;
			else
				tailsCount ++;
		}
		cout << "\n\nHeads: " << headsCount;
		cout << "\nTails: " << tailsCount;
		headPercent = ((double)headsCount / input) * 100.0;
		tailPercent = ((double)tailsCount / input) * 100.0;
		for(int i = 0; i < (int)headPercent; i ++)
			headVis += "*" ;
		for (int i = 0; i < (int)tailPercent; i ++)
			tailVis += "*";
		cout << "\n\nHeads Percentage: " << headPercent << " " << headVis;
		cout << "\nTails Percentage: " << tailPercent << " " << tailVis;
		cout << endl;
		while(!(charInput == 'y' || charInput == 'n'))
		{
			cout << "\nDo you want to go again? (y or n): ";
			cin >> charInput;
		}
		if(charInput == 'n')
			isRunning = false;
		
		
		
		
		
		headsCount = 0;
		tailsCount = 0;
		headVis = "";
		tailVis = "";
		charInput == ' ';
	}
	
	
	system("pause");
	return 0;
}
