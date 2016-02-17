/***************************************************************
CSCI 240         Program 4     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 19
Purpose: This program genorates sets 10 random numbers and then catigorizes them
***************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int BIGGEST = 100;
const int SMALLEST = 50;
const int LOOPS = 10;


/*
*@param numStars number of stars to be genorated
*
*@return A string that is numStars long
*/
string genStars(int numStars){
	string stars = "";
	for (int i = 0; i < numStars; i ++)
		stars += "*";
	return stars;
}


int main(){
	//seting up random-ness
	//srand(time(0));
	//this is for the ta's to grade
	srand(0);
	//vars that hold through each loop
	bool running = true;
	int setNumber = 0;
	int totalNinetyAndUp = 0;
	int totalEighty = 0;
	int totalSeventy = 0;
	int totalSixty = 0; 
	int totalFiftyAndLess = 0;
	
	//main loop
	while (running){
		//temporary vars
		int ninetyAndUp = 0;
		int eighty = 0;
		int seventy = 0;
		int sixty = 0; 
		int fiftyAndLess = 0;
		cout << "Set " << setNumber << endl;
		//gening 10 numbers
		for (int i = 0; i < LOOPS; i ++ ){
			int num = (rand() % ((BIGGEST - SMALLEST) + 1)) + SMALLEST;
			cout << num << endl;
			if(num >= 90){
				ninetyAndUp ++;
				totalNinetyAndUp ++;
			}
			else if(num >= 80){
				eighty ++;
				totalEighty ++;
			}
			else if(num >= 70){
				seventy ++;
				totalSeventy ++;
			}
			else if(num >=60){
				sixty ++;
				totalSixty ++;
			}
			else if(num >= 50){
				fiftyAndLess ++;
				totalFiftyAndLess ++;
			}
		} 
		
		
		//output statistics
		cout << "\n90s + count: " << ninetyAndUp << "  80s count: " << eighty << "  70s count: " << seventy << "  60s count: " << sixty << "  Less than 60s: " << fiftyAndLess << endl << endl;
		
		
		//another one?
		cout << "Do you want to generate another set? ";
		//i used a string as to prevent multable loops going with an input like "yyy"
		string input ;
		cin >> input;
		
		
		//if the user is done
		if(tolower(input.at(0)) != 'y'){
			running = false;
			cout <<	"\n\nOverall Counts" << endl;
			cout << "90s + count:      " << totalNinetyAndUp << "  " << genStars(totalNinetyAndUp) << endl;
			cout << "80s count:        " << totalEighty << "  " <<  genStars(totalEighty) << endl;
			cout << "70s count:        " << totalSeventy << "  " <<  genStars(totalSeventy) << endl;
			cout << "60s count:        " << totalSixty << "  " <<  genStars(totalSixty) << endl;
			cout << "Less than 60s:    " << totalFiftyAndLess << "  " <<  genStars(totalFiftyAndLess) << endl;
			cout <<"\n\n Goodbye!";
		}
		else 
			setNumber ++;
		cout << endl;
	}
	system("pause");
}
