/*
 * Reads employee pay information from a file and displays it back to the user
 *
 * By Tim Kromer
 */

 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 using namespace std;

int main()
 {
	// Open File
	ifstream fileIn;
	fileIn.open("salaryInfo.txt");

	// Declare variables
	string lastName1, firstName1;
	string lastName2, firstName2;
	string lastName3, firstName3;
	double salary1, percentRaise1;
	double salary2, percentRaise2;
	double salary3, percentRaise3;

	// Get info from file
	fileIn >> lastName1 >> firstName1 >> salary1 >> percentRaise1
	>> lastName2 >> firstName2 >> salary2 >> percentRaise2
	>> lastName3 >> firstName3 >> salary3 >> percentRaise3;

	// Close file
	fileIn.close();

	// Calculate salary after raise
	salary1 += salary1 * percentRaise1 * 0.01;
	salary2 += salary2 * percentRaise2 * 0.01;
	salary3 += salary3 * percentRaise3 * 0.01;

	// Display 2 decimal places, no scientific notation
	cout << setprecision(2) << fixed;

	// Output
	cout << firstName1 << " " << lastName1 << " $" << salary1 << '\n'
		 << firstName2 << " " << lastName2 << " $" << salary2 << '\n'
		 << firstName3 << " " << lastName3 << " $" << salary3;

	return 0;
 }
