

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;


int toInt(char a){
	if (a == '0')
		return 0;
	else if(a == '1')
		return 1;
	else if(a == '2')
		return 2;
	else if(a == '3')
		return 3;
	else if(a == '4')
		return 4;
	else if(a == '5')
		return 5;
	else if(a == '6')
		return 6;
	else if(a == '7')
		return 7;
	else if(a == '8')
		return 8;
	else if(a == '9')
		return 9;
	return -1;
}
string toString(int a){
	if (a == 0)
		return "0";
	else if(a == 1)
		return "1";
	else if(a == 2)
		return "2";
	else if(a == 3)
		return "3";
	else if(a == 4)
		return "4";
	else if(a == 5)
		return "5";
	else if(a == 6)
		return "6";
	else if(a == 7)
		return "7";
	else if(a == 8)
		return "8";
	else if(a == 9)
		return "9";
	return " ";
}

string addition(string a, string b)
{
	int i = 0;
	int carry = 0;
	string final = "";
 	int loops = 0;
 	if(a.length()>= b.length())
 		loops = a.length();
	else 	
		loops = b.length();
	for( i = 1; i <= loops; i ++){
		int temp = toInt(a.at(a.length() - i)) + toInt(b.at(b.length() - i)) + carry;
		carry = temp /10;
		final = toString(temp%10) + final ;
	}
	if(a.length() > b.length())
		for (i = i; i <= a.length(); i ++)
		{
		int temp = toInt(a.at(a.length() - i)) + carry;
		carry = temp /10;
		final = toString(temp%10) + final ;	
		}
	else 
		for (i = i; i <= b.length(); i ++)
		{
		int temp = toInt(b.at(b.length() - i)) + carry;
		carry = temp /10;
		final = toString(temp%10) + final ;	
		}
	if (carry == 1)
		final = toString(carry) + final;





	return final;
}
string multiply(string a, string b)
{
	int loops = 0;
	vector<string> nums;
	if(a.length() >= b.length())
 		loops = a.length();
	else 	
		loops = b.length();
	for(int i = 1; i <= loops; i ++){
		
	}
}


int main()
{
	string num0 = "";
	string num1 = "";
	cout << "num0: ";
	cin >> num0;
	cout<< "\nnum1: ";
	cin >> num1;
	cout << "the product is: \n";
	cout << addition(num0,num1);
}
