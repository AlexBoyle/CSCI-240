

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
	string end = "";
	string temp[b.length()] ;
	for(int i=b.length()-1;i>=0;i--)
	{
		int carry=0;
		int result=0;
		int rem=0;
		temp [b.length()-i-1]= "";
		for	(int j=a.length()-1;j>=0;j--)
		{
			result = toInt(a[j])*toInt(b[i]) + carry;
			carry = result/10;
			rem = result%10;
			temp[b.length() - i-1]= toString(rem)+ temp[b.length() - i-1];
		}
		if(carry>0)
		{
			temp[b.length() -i-1] = toString(carry) + temp[b.length() -i -1];
		}
	}
	for (int i = 0; i < b.length(); i ++){
			end =  end + temp[b.length()-i-1];
	}
return end;
}


int main()
{
	while(true){
		cout << endl<<endl<<endl;
	string num0 = "";
	string num1 = "";
	cout << "num0: ";
	cin >> num0;
	cout<< "\nnum1: ";
	cin >> num1;
	cout << addition(num0,num1);
	cout << endl <<  multiply(num0,num1);
}
}
