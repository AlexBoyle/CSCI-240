/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0002

Date Due: Feb 
Purpose: This program
***************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;
const int BIGGEST = 100;
const int SMALLEST = 50;
const int LOOPS = 10;
string genStars(int numStars){
	string stars = "";
	for (int i = 0; i < numStars; i ++)
		stars += "*";
	return stars;
}
int main(){
	srand(time(0));
	bool running = true;
	int setNumber = 0;
	int totalNinetyAndUp = 0;
	int totalEighty = 0;
	int totalSeventy = 0;
	int totalSixty = 0; 
	int totalFiftyAndLess = 0;
	while (running){
		int ninetyAndUp = 0;
		int eighty = 0;
		int seventy = 0;
		int sixty = 0; 
		int fiftyAndLess = 0;
		cout << "Set " << setNumber << endl;
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
		cout << "\n90s + count: " << ninetyAndUp << "  80s count: " << eighty << "  70s count: " << seventy << "  60s count: " << sixty << "  Less than 60s: " << fiftyAndLess << endl << endl;
		cout << "Do you want to generate another set? ";
		char input;
		cin >> input;
		if(tolower(input) != 'y'){
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
