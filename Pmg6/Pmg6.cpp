/***************************************************************
CSCI 240         Program 6     Spring 2016

Programmer: Alex Boyle

Section: 0006

Date Due: March 25
Purpose: This program checks if passwords are valid
***************************************************************/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;



/***************************************************************
Function:  isSpecial(char)

Use: to check for special chars

Arguments: char: the char being cheked to see if it contains a special char

Returns: a bool true if the password is valid or false if the password is not valid
***************************************************************/
bool isSpecial( char);

/***************************************************************
Function:  bool isMissing(string)

Use: th check what each password is missing

Arguments: string: The password being checked

Returns: a bool true if the password is valid or false if the password is not valid
***************************************************************/
 bool isMissing(string);





int main(){
	ifstream infile;        //input file stream variable
	infile.open( "password.txt" );    //open the file for reading
	char ch = ' ';
	string pass = "";
	int numVal = 0;
	int passwords = 0;
	if( infile.fail() )       //if the input file failed to open
	{
		cout << "input file did not open" << endl;
		exit(-1);            //stop execution of the program immediately
	}
	while(infile)
	{
		while ((ch = infile.get()) != '\n' && infile) //loop to take in the password
			pass += ch;
	
			cout << pass << endl;
			if(isMissing(pass))//check if the password is missing anything
				numVal ++;
			cout << endl;
			passwords ++;
			ch = ' ';
			pass = "";
	}
	infile.close();//close reader
	//output
	 cout << "Total Number of Passwords: " << passwords << endl ;
	 cout << "  Valid:   " << numVal << endl;
	 cout << "  Invalid: " <<passwords - numVal << endl;
	return 0;
}





bool isSpecial( char ch ){
	return (ch == '$' || ch == '%' || ch == '#' || ch == '*' );

}


bool isMissing(string pass){
	bool total;
	bool alpha = true;
	bool upper = true;
	bool lower = true;
	bool num = true;
	for (int i = 0; i < pass.length() ; i ++)	//checks for problems in the password
	{
		if(isSpecial(pass.at(i)))
			alpha = false;
		else if(isupper(pass.at(i)))
			upper = false;
		else if(islower(pass.at(i)))
			lower = false;
		else if(isdigit(pass.at(i)))
			num = false;
	}
	
	//this if group outputs the problems w/ the password
	if(pass.length() < 5)
		cout << "   Not enough characters" << endl;
	if(alpha)
		cout << "   Missing special character" << endl;
	if(upper)
		cout << "   Missing Uppercase letter" << endl;
	if(lower)
		cout << "   Missing lowercase letter" << endl;
	if(num)
		cout << "   Missing digit" << endl;
	total = !(alpha || upper || lower || num || (pass.length() < 5));
	if(total)
		cout << "  Valid password" << endl;
	return total;
}
