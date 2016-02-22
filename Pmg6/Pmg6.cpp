/***************************************************************
CSCI 240         Program 6     Spring 2016

Programmer: Alex Boyle

Section: 0006

Date Due: Feb 
Purpose: This program
***************************************************************/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;
bool isMissing(string pass){
	bool total;
	bool alpha = true;
	bool upper = true;
	bool lower = true;
	bool num = true;
	for (int i = 0; i < pass.length() ; i ++){
		if(pass.at(i) == '$' || pass.at(i) == '%' || pass.at(i) == '#' || pass.at(i) == '*' )
			alpha = false;
		if(isupper(pass.at(i)))
			upper = false;
		if(islower(pass.at(i)))
			lower = false;
		if(isdigit(pass.at(i)))
			num = false;
	}
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





int main(){
	ifstream infile;        //input file stream variable
	infile.open( "password.txt" );    //open the file for reading
	string ch;
	int numVal = 0;
	int passwords = 0;
	if( infile.fail() )       //if the input file failed to open
	{
		cout << "input file did not open" << endl;
		exit(-1);            //stop execution of the program immediately
	}
	while(infile)
	{
	
		infile >> ch;
		cout << ch << endl;
		if(isMissing(ch))
			numVal ++;
		cout << endl;
		passwords ++;
	}
	infile.close();
	 cout << "Total Number of Passwords: " << passwords << endl ;
	 cout << "  Valid:   " << numVal << endl;
	 cout << "  Invalid: " <<passwords - numVal << endl;
	return 0;
}
