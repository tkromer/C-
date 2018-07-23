/*
 * Determine if a number is positive or negative and even, odd, or neither
 *
 * By Tim Kromer
 */

#include <iostream>
using namespace std;

int main()
{
	// Declare Variables
	double num;

	// Get user input
	cout << "Enter a number: ";
	cin >> num;

	// Determine if positive or negative
	if (num > 0)
		cout << num << " is a positive number" << endl;
	else if(num < 0)
		cout << num << " is a negative number" << endl;
	else
		cout << "Your number is zero" << endl;

	// Determine if number is positive, negative, or neither
	if ((num - static_cast<int>(num)) != 0)
		cout << num << " is not even or odd." << endl;
	else if (static_cast<int>(num) % 2 == 0 || num == 0)
		cout << num << " is an even number." << endl;
	else
		cout << num << " is an odd number." << endl;

	return 0;
}
