/*
 * Extracts months, days, and years from user input
 *
 * By Tim Kromer
 */
 
 #include <iostream>
 #include <iomanip>
 using namespace std;

 int main()
 {
	 // Declare variables
	 int day, month, year;
	 char slash;

	 // Get user input
	 cout << "Enter date (mm/dd/yyyy): ";
	 cin >> month >> slash >> day >> slash >> year;

	 // Output
	 cout << setfill('0') << '\n'; //adds leading 0s

	 cout << "Month entered: " << setw(2) << month << endl
	  	  << "Day entered  : " << setw(2) << day << endl
		  << "Year entered : " << setw(4) << year;

	 return 0;
 }
