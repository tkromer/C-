/*
 * Converts degrees Farenheit into degrees Celcius and Kelvin.
 *
 * By Tim Kromer
 */

 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
 {
	 // Declare variables
	 const double KEL_DIF = 273.15;
	 double fahr, cel, kel;

	 // Get user input
	 cout << "What is the temperature in Fahrenheit: ";
	 cin >> fahr;

	 // Calculate temps
	 cel = (fahr - 32) / 1.8;
	 kel = cel + KEL_DIF;

	 // Output results
	 cout << setprecision(3) << fixed;

	 cout << endl << "Fahrenheit: " << fahr << " degrees" << endl
	 	  << "Celcius: " << cel << " degrees" << endl
		  << "Kelvin: " << kel;

	 return 0;
 }
