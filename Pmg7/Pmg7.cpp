 /***************************************************************
CSCI 240         Program 7    Spring 2016

Programmer: Alex Boyle

Section: 0007

Date Due: April 1 2016 
Purpose: This program picks lottery tickets
***************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#define MAX_PICKS 5
#define MAX_CHOICE 10
using namespace std;

//function prototypes


/******************************************************************
Function:  bool isDuplicate( int [], int, int )

Use: This function determines if a value has already been placed
     into an array

Arguments: int []: the array holding all of the values
           int: the number of values the array holds
           int: the value to look for in the array

Returns: a boolean value that represents whether the value was or
         was not found in the array. true if the value is a
		 duplicate. false if the value is not a duplicate
******************************************************************/
bool isDuplicate( int [], int, int );

/******************************************************************
Function:  int getUserNum( int )

Use: This function gets a number from the user that is between 1
     and an upper bound

Arguments: int: the upper bound

Returns: an integer between 1 and the upper bound, inclusive

Note: This function will not display an initial prompt to the user.
******************************************************************/
int getUserNum( int );

/******************************************************************
Function:  void getWinners( int [], int)

Use: generates the winning numbers for the lottery drawing 

Arguments:  int[]: array where the winning numbers will be stored
			int: the number of numbers being generated

******************************************************************/
void getWinners( int [], int);

/******************************************************************
Function:  void getChoices( int [], int)

Use: Gets the user input numbers for the lottery play

Arguments: 	int[]: array where the user input nimbers will be stored
			int : number of numbers the the user has to input 

******************************************************************/
void getChoices( int [], int);

/******************************************************************
Function:  void sortArray( int [], int)

Use: this function will sort an array from smalist to biggest

Arguments:	int[]: this is the array that will be sorted
			int: number of elements int the array

******************************************************************/
void sortArray( int [], int);

/******************************************************************
Function:  void printWinners( int [], int [], int)

Use: this function checks if the user has picked any winning numbers

Arguments: 	int[]: array of user inputs
			int[]: array of winning numbers
			int: number of elements in each array

******************************************************************/
void printWinners( int [], int [], int);


bool playAgain = true;

int main()
{
	while(playAgain){
	
	int input = 0;
	cout << "\nLottery Game\n3. Pick 3\n4. Pick 4\n5. Pick 5\n\nWhich game would you like to play? ";
	cin>> input;
	while (!(input >= 3 && input <= 5)){
		cout << input;
		cout<< "Please pick a number between 3 and 5: ";
		if(!cin){
			string clear = "";
			cin >> clear;
		}
		cin >>input;
	}
	system("cls");
	cout <<"\nPick " << input << " lottery\n\n";
	//create arrays at the required size
	int userNum[input];
	int winning[input];
	for (int i = 0; i < input;i ++){
		userNum[i] = -1;
		winning[i] = -1;
	}
	//get all nessasay numbers
	getChoices(userNum, input);
	getWinners(winning,input);
	//sort all numbers
	sortArray(userNum,input);
	sortArray(winning,input);

	printWinners(winning,userNum,input);
	cout << "\n\n Do you want to try again(y or n): ";
	string in = "";
	cin >> in;
	if(in.at(0) != 'y')
		playAgain = false;
	system("cls");
}
	return 0;
}


void sortArray( int array[], int numValues ){
	int temp ;
	int pos;
	for (int i = 0; i < numValues; i ++){
		temp = array[i];
		pos = i;
		for (int j = i; j < numValues ; j ++){
			if(temp > array[j]){
				temp = array[j];
				pos = j;
			}	
		}
		array[pos] = array[i];
		array[i] = temp;
		
	}

}


void getWinners( int array[], int numValues ){
		srand(time(0));
		for(int i = 0; i < numValues; i ++)
		{
			int tempNum = (rand() %10) +1;
			
				while (isDuplicate(array,numValues,tempNum)){
						tempNum = (rand() %10) +1;

				}
				array[i] = tempNum;
		}
}


void getChoices( int array[], int numValues ){
	int tempNum = 0;
	for (int i = 0; i < numValues; i ++){
		cout << "\nUser choice " << i + 1 << ": ";
		tempNum = getUserNum(MAX_CHOICE);
		while (isDuplicate(array,numValues,tempNum) && i != 0){
			cout << "you have already used this number, reenter: ";
			tempNum = getUserNum(MAX_CHOICE);
		}
		array[i] = tempNum;
		
	}
}


bool isDuplicate( int array[], int arraySize, int searchNum )
{
//Loop through the array to determine if it is holding searchNum
//If a match is found, return true

for( int sub = 0; sub < arraySize; sub++ )
  {
  if( array[sub] == searchNum )
    return true;
  }

//At this point, no match was found in the array, so false is
//returned.

return false;
}



int getUserNum( int upperBd )
{
int userNum;

//Get an integer number from the user

cin >> userNum;

//Validate the number that the user entered. If the number is invalid,
//display an error message to the user and get another number. Do this
//

while( userNum < 1 or userNum > upperBd )
    {
    cout << "The choice must be between 1 and " << upperBd << ", reenter: ";
    cin >> userNum;
	}

//Return the valid value
return userNum;
}


void printWinners( int winArray[], int userArray[], int numValues ){
	cout << "\n\nThe winning numbers are   ";
	for(int i = 0; i < numValues; i ++)
		cout << winArray[i] << " ";
	int match = 0;
	for (int i = 0; i < numValues; i ++)
		if(isDuplicate(userArray,numValues,winArray[i]))
			match ++;
	cout <<"\nYou matched " << match << " number(s).  You win ";
	switch(match)
	{
		case 0:
			cout << "$0.00";
			break;
		case 1:
			cout << "$1.00";
			break;
		case 2:
			cout << "$5.00";
			break;
		case 3:
			cout << "$10.00";
			break;
		case 4:
			cout << "$20.00";
			break;
		case 5:
			cout << "$25.00";
			break;
	}
	
	
}

