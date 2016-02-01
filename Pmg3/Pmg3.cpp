/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 12 2016
Purpose: This program calculates coin flips
***************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	//Variables
	bool isRunning = true;
	char charInput = ' ';
	int toss = -1;
	int input = -1;
	double headPercent = 0;
	double tailPercent = 0;
	string headVis = "";
	string tailVis = "";
	//setting up the random number genorator
	srand(time(0));
	//fomat the output for floats and doubles
	cout << fixed << setprecision(1) ;
	//this is the main loop that runs as long as "isRinning" equals true
	while(isRunning)
	{
		int headsCount = 0;
		int tailsCount = 0;
		cout << "\nHow many times do you want to toss the coin?: ";
		cin >> input;
		//if the number givin is negitive, ask again for a number that is positive
		while (input < 0)
		{
			cout << "\n\nNumber must be positive. How many times to you want to toss the coin?: ";
			cin >> input;
		}
		///this for loop does all the coin flips
		for (int i = 0; i < input; i ++)
		{
			toss = rand() % 2;
			if (toss == 0)
				headsCount ++;
			else
				tailsCount ++;
		}
		//output coin counts
		cout << "\n\nHeads: " << headsCount;
		cout << "\nTails: " << tailsCount;
		
		//calculate coin percentages
		headPercent = ((double)headsCount / input) * 100.0;
		tailPercent = ((double)tailsCount / input) * 100.0;
		
		//these two for loop create the '*' count for the percentage
		for(int i = 0; i < (int)headPercent; i ++)
			headVis += "*" ;
		for (int i = 0; i < (int)tailPercent; i ++)
			tailVis += "*";
			
		//output the percent and  '*' line
		cout << "\n\nHeads Percentage: " << headPercent << " " << headVis;
		cout << "\nTails Percentage: " << tailPercent << " " << tailVis;
		cout << endl;
		//this loop checks if the user wants to continue
		while(!(charInput == 'y' || charInput == 'n'))
		{
			cout << "\nDo you want to go again? (y or n): ";
			cin >> charInput;
		}
		//if the user does not want to continue the main loop stops
		if(charInput == 'n')
			isRunning = false;
		
		
		
		
		//reset values for next loop
		headsCount = 0;
		tailsCount = 0;
		headVis = "";
		tailVis = "";
		charInput == ' ';
	}
	system("pause");
	return 0;
}
