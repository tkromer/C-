/*
 * Fuzz comparisons of numbers, because of float-point rounding error.
 * by Dr. Hayes
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double one = 3/7.0 + 2/7.0 + 2/7.0; // equals 7/7 or 1, right?

	// Test if the number is stored as one
	// Notice this does not work, because of rounding error
	if (one == 1.0)
	{
		cout << "The number equals one, as it should!" << endl;
	}
	else
	{
		cout << "The number does not equal 1, because of rounding error."
			<< endl;
	}

	// Try increasing the precision, until the output shows that the variable
	// does not hold the value 1.0.
	cout << setprecision(6) << fixed;
	cout << "The number is " << one << endl;

	// Fuzzy compare the variable with 1.
	// If they are really close, consider them equal.
	if(abs(one - 1.0) < 1E-10) // 1E-10 is shorthand for writing 0.0000000001
	{
		cout << "The number is so very close to one. Let's call it one."
			<< endl;
	}
	else
	{
		cout << "The number is NOT one!" << endl;
	}

	return 0;
}