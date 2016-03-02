 /***************************************************************
CSCI 240         Program 6     Spring 2016

Programmer: Alex Boyle

Section: 0006

Date Due: April 1 2016 
Purpose: This program
***************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#define MAX_PICKS 5
#define MAX_CHOICE 10
using namespace std;

//function prototypes

bool isDuplicate( int [], int, int );
int getUserNum( int );
void getWinners( int [], int);
void getChoices( int [], int);
void sortArray( int [], int);
void printWinners( int [], int [], int);

int main()
{
	int userNum[MAX_PICKS];
	int winning[MAX_PICKS];
	cout << "Pick 5 lottery\n\n";
	getChoices(userNum, MAX_PICKS);
	cout << endl << userNum[0];	
	return 0;
}
void sortArray( int array[], int numValues ){
	int tempArr[numValues];
	for (int i = 0; i < numValues; i ++)
		tempArr[i] = array[i]
		for (int j = i; j < numValues ; j ++){
			if(tempArr[i] > array[j])
				tempArr[i] = array[i + j];
		}
}
void getWinners( int array[], int numValues ){
		srand(time(0));
		for(int i = 0; i < numValues; i ++)
		{
			int tempNum = (rand() %10) +1;
				while (isDuplicate(array,numValues,tempNum)){
						int tempNum = ()rand() %10) +1;
				}
				array[i] = tempNum;
		}
}
void getChoices( int array[], int numValues ){
	int tempNum = 0;
	for (int i = 0; i < numValues; i ++){
		cout << "User choice " << i + 1 << ": ";
		tempNum = getUserNum(MAX_CHOICE);
		while (isDuplicate(array,numValues,tempNum)){
			cout << "you have already used this number, reenter: ";
			tempNum = getUserNum(MAX_CHOICE);
		}
		array[i] = tempNum;
	}
}

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

/******************************************************************
Function:  int getUserNum( int upperBd )

Use: This function gets a number from the user that is between 1
     and an upper bound

Arguments: int: the upper bound

Returns: an integer between 1 and the upper bound, inclusive

Note: This function will not display an initial prompt to the user.
******************************************************************/

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

