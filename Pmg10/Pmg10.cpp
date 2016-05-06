/***************************************************************
CSCI 240         Program 9   Spring 2016

Programmer: Alex Boyle

Section: 0009


Note:
	- Ludum dare game jam entry:
		http://ludumdare.com/compo/ludum-dare-35/?action=preview&uid=46816



Purpose: This program is a dice game
***************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>
using namespace std;



class Student{
	#define MAX_PMG 905
	#define MAX_QUIZ 120
	#define MAX_LOW_QUIZ 20
	#define MAX_EXAM 300
	public:
		Student(const char[], int, int, int, double);
		void setPgmPts( int );
		void setQuizPts( int );
		void setSum2Low( int );
		void setExamPts( double );
		double calcPgmAverage();
		double calcExamAndQuizAverage();
		double calcCourseAverage();
		char letterGrade();
		void printStudent();
		
		
	private:
		char name[50];
		int totalPmgP;
		int totalQuizP;
		int totalLow;
		double totalExamP;
	
	
};


int main(){
	Student std1("Alex B",767,106,10,286.5);
	Student std2("Pat Jones",474,53,0,218.5);
	Student std3("Chris Wilson",905,120,20,300);
	Student std4("name here",-1,-1,-1,-1);
	
	cout<<"\n\nThe first Student object \n\n";
	std1.printStudent();
	cout<<"\n\nThe second Student object \n\n";
	std2.printStudent();
	cout<<"\n\nThe third Student object \n\n";
	std3.printStudent();
	cout<<"\n\nThe forth Student object \n\n";
	std4.printStudent();
	
	std4.setQuizPts(107);
	std4.setPgmPts(639);
	std4.setExamPts(211.5);
	std4.setSum2Low(8);
	cout<<"\n\nThe fourth Student object \n\n";
	std4.printStudent();
}


	
	Student::Student(const char nameT[], int pmg, int quiz, int low, double exam){
		strcpy(name,nameT);
		setPgmPts(pmg);
		setQuizPts(quiz);
		setSum2Low(low);
		setExamPts(exam);
	}
	
	void Student::setPgmPts( int newPgmPts){
		if (newPgmPts > MAX_PMG || newPgmPts < 0){
			cout << "Error in setPgmPts: argument is invalid\n";
			totalPmgP = 0;
		}
		else 
			totalPmgP = newPgmPts;
	}
	
	void Student::setQuizPts( int newQuizPts){
		if (newQuizPts > MAX_QUIZ || newQuizPts < 0){
			cout << "Error in setQuizPts: argument is invalid\n";
			totalQuizP = 0 ;
		}
		else 
			totalQuizP = newQuizPts;
	}
	
	void Student::setSum2Low( int newSum2Low){
		if (newSum2Low >MAX_LOW_QUIZ || newSum2Low < 0){
			cout << "Error in setSum2Low: argument is invalid\n";
			totalLow = 0;
		}
		else 
			totalLow = newSum2Low;
	}
	
	void Student::setExamPts( double newExamPts){
		if (newExamPts > MAX_EXAM || newExamPts < 0){
			cout << "Error in setExamPts: argument is invalid\n";
			totalExamP = 0;
		}
		else 
			totalExamP = newExamPts;
	}
	
	double Student::calcPgmAverage(){
		return (((double)totalPmgP/MAX_PMG)*100);
	}
	
	double Student::calcExamAndQuizAverage(){
		return (((double)(totalExamP + totalQuizP - totalLow)/(MAX_EXAM + MAX_QUIZ - MAX_LOW_QUIZ))*100);
	}
	
	double Student::calcCourseAverage(){
		return calcPgmAverage()*.3 + calcExamAndQuizAverage()*.7;
	}
	char Student::letterGrade(){
		double scr = calcCourseAverage();
		if(scr >= 90 )
			return 'A';
		else if(scr >= 80 )
			return 'B';
		else if(scr >= 70 )
			return 'C';
		else if(scr >= 60 )
			return 'D';
		else
			return 'F';
	}
	void Student::printStudent(){
		cout << setprecision(4);
		cout << name << endl;
		cout << "  Program Average:    " <<setw(7)<<calcPgmAverage()<< endl;
		cout << "  Exam + Quiz Average:" <<setw(7)<<calcExamAndQuizAverage()<<  endl;
		cout << "  Course Average:     " <<setw(7)<<calcCourseAverage()<<  endl;
		cout << "  Letter Grade:       " <<setw(7)<<letterGrade()<<  endl<<  endl;
	}


































