/*
 * Test program to see whhat happens when the user input does not match the
 * variables' type
 *
 * By Tim Kromer
 */

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	// Variables to receive input
	char ch1 = ' '; // 1 character
	char ch2 = ' '; // a second character
	int int1 = -8888; // a whole number
	double dub1 = -999.999; // decimal (floating point) number

	// Get input from the user
	cout << "Input a char, floating-point number, char, and int: ";
	cin >> ch1 >> dub1;
	cin.clear(); // clears error if wrong input is given
	cin >> ch2 >> int1;

	// Display the values for each variable
	cout << endl;
	cout << setw(12) <<      "Double: " << dub1 << '\n' //setw(12) sets the width to 12 Characters
         << setw(12) << "Characters: '" << ch1 << "', '" << ch2 << "'\n"
		 << setw(12) <<      "Integer: " << int1 << '\n' << endl;

	return 0;
}
