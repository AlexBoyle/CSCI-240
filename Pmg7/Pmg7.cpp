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

bool isDuplicate( int [], int, int );
int getUserNum( int );
void getWinners( int [], int);
void getChoices( int [], int);
void sortArray( int [], int);
void printWinners( int [], int [], int);

int main()
{
	int input = 0;
	cout << "Lottery Game\n3. Pick 3\n4. Pick 4\n5. Pick 5\n\nWhich game would you like to play? ";
	cin>> input;
	while (!(input >= 3 && input <= 5)){
		cout<< "Please pick a number between 3 and 5: ";
		cin >>input;
	}
	cout <<"\nPick " << input << " lottery\n\n";
	
	int userNum[input];
	int winning[input];
	getChoices(userNum, input);
	for(int i = 0; i < input; i ++)
		cout << userNum[i];
	getWinners(winning,input);

	sortArray(userNum,input);
	
	sortArray(winning,input);

	printWinners(winning,userNum,input);
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
		cout << "User choice " << i + 1 << ": ";
		tempNum = getUserNum(MAX_CHOICE);
		while (isDuplicate(array,numValues,tempNum) && i != 0){
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
