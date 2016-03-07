/***************************************************************
CSCI 240         Program 5     Spring 2016

Programmer: Alex Boyle

Section: 0005

Date Due: March 11
Purpose: This program calculates a car trip
***************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

double const FLEET_AVG = 25.0;

// Your function Prototypes go here
/***************************************************************
Function:  double getGallons()

Use: This function gets the gallons of fule used in a trip from the user between the numbers 0 and 40

Returns: the users inputed gallons
***************************************************************/
double getGallons();

/***************************************************************
Function:  double getMiles()

Use: This function gets the miles traveled in a trip from the user between the numbers 0 and 800

Returns: the users inputed miles 
***************************************************************/
double getMiles();

/***************************************************************
Function:  double getPricePerGallon()

Use: This function gets the the price for a gallon of fule from the user between the numbers 2 and 7

Returns: the users inputed cost
***************************************************************/
double getPricePerGallon();

/***************************************************************
Function:  double calcTripMileage(double, double) 

Use: This function calculates the mileage for a single trip

Arguments: double: the number of miles traveled 
           double: the number of gallons of fuel used for the trip

Returns: a double value that represents the number of miles per gallon
***************************************************************/
double calcTripMileage(double, double);

/***************************************************************
Function:  double calcTripCost(double, double)

Use: This function calculates the cost of a trip

Arguments: double: the price per gallon on the trip
           double: the number of gallons of fuel used for the trip

Returns: a double value that represents the cost of the trip
***************************************************************/
double calcTripCost(double, double);

/***************************************************************
Function:  double calcTripCost(double, double)

Use: This function calculates the cost per mile of a trip

Arguments: double: total cost of the trip
           double: the number of miles traveled for the trip

Returns: a double value that represents the cost per mile per trip
***************************************************************/
double calcTripCostPerMile(double, double);

/***************************************************************
Function:  double calcOverallMPG(double, double)

Use: This function calculates the overall MPG

Arguments: double: total miles traveled on the trip
           double: the number of gallons of fuel used for the trip

Returns: a double value that represents the overall MPG
***************************************************************/
double calcOverallMPG(double, double);

/***************************************************************
Function:  void showOneTrip(double, double, double)

Use: This function diplays information for one trip

Arguments: double: total trip miles
           double: total trip cost
		   double: total trip cost per mile

***************************************************************/
void showOneTrip(double, double, double);

/***************************************************************
Function:  void showTotals(double, double, double, double)

Use: This function displays totals for data across multible trips 

Arguments: double: total miles across all trips
           double: total gallons of gas across all trips
		   double: total cost of all trips
		   double: overall MPG across all trips
		   
***************************************************************/
void showTotals(double, double, double, double);

/***************************************************************
Function:  void showMileageComparison(double)

Use: This function compairs the users MPG agents the avarage MPG

Arguments: double: overall MPG across all trips

***************************************************************/
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
	while (!(input >= 0.0 && input <= 800.0)){
		cout << "Out of range: must be between 0 and 800 miles. Re-enter: ";
		cin >> input;
	}
	return input;
}


double getPricePerGallon(){
	cout << "Enter the price per gallon: ";
	double input;
	cin >> input;
	while (!(input >= 2.0 && input <= 7.0)){
		cout << "Out of range: must be between 2.00 and 7.00 dollars. Re-enter: ";
		cin >> input;
	}
	return input;
}


double calcTripMileage(double miles, double gallons){
	if(gallons == 0)
		return 0;
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
	cout << "Trip Mileage:            " <<fixed<< setprecision(2) << setw(5) << tripMileage << " mpg";
	cout << "\nTrip Cost:              $" << setw(5) << tripCost;
	cout << "\nTrip Cost per mile:     $" <<fixed<< setprecision(3) <<  setw(6) << tripCostPerMile << endl<< endl;	
}


void showTotals(double totalMiles, double totalGallons, double totalCost, double overallMPG){
	cout << "Total Miles:" <<fixed<< setprecision(2) << setw(11) << totalMiles;
	cout << "\nTotal Gallons:" << setw(9) <<totalGallons;
	cout << "\nTotal Cost:      $" << setw(5) <<totalCost;
	cout << "\nOverall MPG:"	<< setw(11) <<overallMPG;
}


void showMileageComparison(double overallMPG){
	cout << "\n\nYour vehicle's mileage is greater than fleet average by " << overallMPG - FLEET_AVG << " mgp";
}
