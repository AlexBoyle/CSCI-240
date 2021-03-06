/***************************************************************
CSCI 240         Program 3     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 12 2016
Purpose: This program calculates coin flips
I used long long's insted of ints because I wanted to see how long it would take to calculate large amounts of  coin flips; it takes a long time
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
	//setting up the random number genorator
	srand(time(0));
	//fomat the output for floats and doubles
	cout << fixed << setprecision(1) ;
	//this is the main loop that runs as long as "isRunning" equals true
	while(isRunning)
	{
		//variables
		string Einput = "";
		string headVis = "";
		string tailVis = "";
		int toss = -1;
		double headPercent = 0;
		double tailPercent = 0;
		long long input = -1;
		long long headsCount = 0;
		long long tailsCount = 0;
		//get the users number of flips
		cout << "\nHow many times do you want to toss the coin?: ";
		cin >> input;
		//if the number givin is negitive or 0, ask again for a number that is positive
		while (input <= 0)
		{
			cout << "\n\nNumber must be positive. How many times to you want to toss the coin?: ";
			cin >> input ;
		}
		///this for loop does all the coin flips
		for (long long i = 0; i < input; i ++)
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
		while(!(Einput.compare("y") == 0 || Einput.compare("n") == 0 ))
		{
			cout << "\nDo you want to go again? (y or n): ";
			cin >> Einput;
		}
		//if the user does not want to continue the main loop stops
		if(Einput.compare("n") == 0)
			isRunning = false;
	}
	system("pause");
	return 0;
}
