/*
 * Demonstrates different ways to format numbers.
 *
 * By Tim Kromer
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// Declare numbers variables and initialize them.
	const int COL_WIDTH = 7; // const int cant be changed in the program
	double dub1 = 67.000194675432;
	double dub2 = 1.0;
	double dub3 = 0.1;
	double dub4 = 0.000000005;
	double dub5 = -1;
	int num1 = 12345;

	// Set the format for numeric Output
	//cout << scientific; // All Output in scientific notation
	//cout << fixed; // every double gets rounded to 6 decimal places
	//cout << showpoint; // Every double has a decimal place
	//cout << setprecision(2); // Only 2 significant digits will be output
	cout << fixed << setprecision(2) << setfill('*'); // 2 sig figs after the decimal;
	// setfill() fills the empty space after setw()

	// Output numbers in 2 columns
	cout << setw(COL_WIDTH) << "Col1" << setw(COL_WIDTH) << "Col 2" << '\n'
		 //<< right // Everything after will be right aligned
		 << setw(COL_WIDTH) << dub1 << setw(COL_WIDTH) << dub2 << '\n'
		 << setw(COL_WIDTH) << dub3 << setw(COL_WIDTH) << dub4 << endl
		 << setw(COL_WIDTH) << dub5 << setw(COL_WIDTH) << num1 << endl;

	return 0;
}
