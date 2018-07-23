/*
 * Takes miles, feet, and inches from user and converts to inches and meters.
 * by Tim Kromer
 */
#include <iostream>
using namespace std;

int main()
{
	//Declare Variables
	double miles, feet, inches, meters;

	//Get user input
	cout << "Distance in miles: " << endl;
	cin >> miles;

	cout << "Distance in feet: " << endl;
	cin >> feet;

	cout << "Distance in inches: " << endl;
	cin >> inches;

	feet += (miles * 5280); //Converts miles to feet and adds to existing feet
	inches += (feet * 12); // Converts the new feet total to inches and adds to existing measurments
	meters = inches/  39.3701; //Converts the total inches into meters

	cout << "The total distance is "
		 << inches
		 << " inches or "
		 << meters
		 << " meters." << endl;

	return 0;
}
