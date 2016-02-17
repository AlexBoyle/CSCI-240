/***************************************************************
CSCI 240         Program 1     Spring 2016

Programmer: Alex Boyle

Section: 0005

Date Due: Feb 
Purpose: This program
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double const FLEET_AVG = 25.0;

// Your function Prototypes go here
double getGallons();
double getMiles();
double getPricePerGallon();
double calcTripMileage(double, double);
double calcTripCost(double, double);
double calcTripCostPerMile(double, double);
double calcOverallMPG(double, double);
void showOneTrip(double, double, double);
void showTotals(double, double, double, double);
void showMileageComparison(double);



int main() {
	double 	gallons	 	 	= 0,		//Place holder for user inputs
		   	miles	 	 	= 0,    	
		   	pricePerGallon 	= 0;		
	
	double 	tripMileage 	= 0,		//Place holder for one trip stats
		   	tripCost 	 	= 0,		
		   	tripCostPerMile = 0;		
	
	double 	totalGallons	= 0,		//Place holder for stats for all trips
		  	totalMiles	 	= 0,		
		  	totalCost	 	= 0;		
	
	double	overallMPG	 	= 0;		//Place holder for Overall Miles Per Gallon
	
	char	another;	             	//Holds user's answer
	
	//Print Title
	cout << "     Fuel Usage Analysis" << endl << endl;
	
	//Start do... while loop to process unknown number of trips
	do {
		//Get trip values
		gallons = getGallons();
		miles = getMiles();
		pricePerGallon = getPricePerGallon();
		
		cout << endl;
		
		//Calculate trip costs
		tripMileage = calcTripMileage(miles , gallons);
		tripCost = calcTripCost(pricePerGallon , gallons);
		tripCostPerMile = calcTripCostPerMile(tripCost , miles);
		
		//Accumulate totals
		totalGallons += gallons;
		totalMiles += miles;
		totalCost += tripCost;
		
		overallMPG = calcOverallMPG(totalMiles, totalGallons);

        //Display stats for one trip
		showOneTrip(tripMileage, tripCost, tripCostPerMile);
		
	
		cout << "Another? (y or n) ";
    	cin >> another;
		
	}
	while (another == 'y' || another =='Y');
	
	
	//Print totals of entered trips 
	showTotals(totalMiles, totalGallons, totalCost, overallMPG);
	
	//Compare overall mpg from entered trips and compare with fleet average
	showMileageComparison(overallMPG);
	
	
	return 0;
}


//Your function definitions go here

double getGallons(){
	cout << "Enter the number of gallons of fuel: ";
	double input;
	cin >> input;
	while (!(input >= 0.0 && input <= 40.0)){
		cout << "Out of range: must be between 0 and 40 gallons. Re-enter: ";
		cin >> input;
	}
	return input;
}

double getMiles(){
	cout << "Enter the number of miles: ";
	double input;
	cin >> input;
	while (!(input >= 0.0 && input < 800.0)){
		cout << "Out of range: must be between 0 and 800 miles. Re-enter: ";
		cin >> input;
	}
	return input;
}

double getPricePerGallon(){
	cout << "Enter the price per gallon: ";
	double input;
	cin >> input;
	while (!(input >= 2.0 && input < 7.0)){
		cout << "Out of range: must be between 0 and 800 miles. Re-enter: ";
		cin >> input;
	}
	return input;
}

double calcTripMileage(double miles, double gallons){
	double temp = miles/gallons;
	if (temp < 0)
		return 0;
	else 
		return temp;
}

double calcTripCost(double pricePerGallon, double gallons){
	return pricePerGallon * gallons;
}

double calcTripCostPerMile(double tripCost, double miles){
	if(miles == 0)
	return 0;
	else 
	return tripCost/miles;
}

double calcOverallMPG(double totalMiles, double totalGallons){
	if(totalGallons == 0)
	return 0; 
	else 
	return totalMiles/totalGallons;
}

void showOneTrip(double tripMileage, double tripCost, double tripCostPerMile){
	cout << "Trip Mileage:             " <<fixed<< setprecision(2) << tripMileage << " mpg";
	cout << "\nTrip Cost:              $ " << tripCost;
	cout << "\nTrip Cost per mile:     $  " <<fixed<< setprecision(3) << tripCostPerMile << endl<< endl;	
}

void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG){
	cout << "Total Miles:      " <<fixed<< setprecision(2) << totalMiles;
	cout << "\nTotal Gallons:     " << totalGallons;
	cout << "\nTotal Cost:      $ " << totalCost;
	cout << "\nOverall MPG:       "	<< overallMPG;
}

void showMileageComparison(double overallMPG){
	cout << "\n\nYour vehicle's mileage is greater than fleet average by " << overallMPG - FLEET_AVG << " mgp";
}
