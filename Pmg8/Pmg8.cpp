/***************************************************************
CSCI 240         Program 8   Spring 2016

Programmer: Alex Boyle

Section: 0007

Date Due: April 1 2016 
Purpose: This program picks lottery tickets
***************************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Employee Class Definition
class Employee
{
public:
  Employee();
  Employee( const char [], int, double );
    
  void printEmp();
  void increaseSalary( double );

  void setIDnum( int );
  void setSalary( double );

  int getIDnum();
  double getSalary();

private:
  char name[25];
  int idNum;
  double salary;
};

int main()
{

//Create 5 Employee objects.


//First Employee

//Create the object
Employee e1= Employee( "Amy Byrnes", 978179, 678367732.40);

//Display the first employee's information
cout<<"The first Employee object : "<<endl;
e1.printEmp();
cout<<endl;


//Increase the first employee's salary and display the updated results
e1.increaseSalary(115.15);
e1.printEmp();
cout<<endl<<endl<<endl;

//Second Employee

//Create the object
Employee e2;

//Display the second employee's information
cout<<"The second Employee object : "<<endl;
e2.printEmp();
cout<<endl;

//Try to increase the second employee's salary by a negative amount
e2.increaseSalary(-1000.00);
cout<<endl<<endl<<endl<< endl;


//Third Employee

//Create the object
Employee e3= Employee("Annie Walker", 24933, 820.12);

//Display the third employee's information
cout<<"The third Employee object : "<<endl;
e3.printEmp();
cout<<endl;

//Change the third employee's salary and id number
e3.setSalary(8.12);
e3.setIDnum(654321);

//Display the update information for the third employee
e3.printEmp();
cout<<endl<<endl<<endl;


//Fourth Employee

//Create the object
Employee e4= Employee("Eyal Lavin", 91781,2468.00);

//Display the fourth employee's information
cout<<"The fourth Employee object : "<<endl;
e4.printEmp();
cout<<endl;


//Try to change the id number for the fourth employee to an invalid value
e4.setIDnum(809);
cout<<endl;

//Change the fourth employee's salary and display just the updated salary
e4.setSalary(9517.53);

cout<<"Employee 4 has a salary of $"<<e4.getSalary()<<endl<<endl;


//Display the update information for the fourth employee
e4.printEmp();
cout<<endl<<endl<<endl;


//Fifth Employee Object

//Create the object
Employee e5= Employee("Auggie Anderson",2012,71940.76);

//Display the fifth employee's information
cout<<"The fifth Employee object : "<<endl<<endl;
e5.printEmp();
cout<<endl;


//Try to change the salary for the fifth employee to a negative amount
e5.setSalary(-1000);
cout<<endl;

//Display only the id number for the fifth employee
cout<<"Employee 5 has an identification number of "<<e5.getIDnum()<<endl<<endl;

//Display the update information for the fifth employee
e5.printEmp();
cout<<endl<<endl<<endl;

return 0;
}


//Code the constructors and methods for the Employee class after this line
  Employee::Employee(){
	strcpy(name, "none");
	idNum = 1000;
	salary = 0;
  }
  Employee::Employee( const char nameS[] , int idS, double salaryS ){
  	strcpy(name, nameS);
  	idNum = idS;
  	salary = salaryS;
  }
    
  void Employee::printEmp(){
  	cout << "\nEmployee: " <<left<<setw(20)<< name << "ID: " <<left<<setw(10)<< idNum<<"Salary: $" <<right<<setw(12)<<fixed<<setprecision(2)<<salary ;
  }
  void Employee::increaseSalary( double num ){
  	if(num >0 )
  	salary += num;
  	else
  	cout <<endl << "Error: the salary cannot be increased\n";
  }

  void Employee::setIDnum( int id){
  	if(id >= 1000 && id <= 9999999)
  	idNum = id;
  	else{
  		cout<<endl<<"Error: the new identification number is invalid. It will be set to 1000\n"<<endl;
  		idNum = 1000;
	  }
  }
  void Employee::setSalary( double sal ){
  	if(sal > 0)
  		salary = sal;
  	else{
  		cout<<endl<<"Error: the passed in salary is invalid. The salary will be set to 0.00\n";
		salary = 0;	
	}
  }

  int Employee::getIDnum(){
  	return idNum;
  }
  double Employee::getSalary(){
  	return salary;
  }

