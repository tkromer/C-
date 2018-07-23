/*
 * Determines if a number is prime.
 *
 * By Tim Kromer
 */

#include <iostream>
using namespace std;

// Prototype functions
/**
 * Gets a positive whole number from the user.
 */
int getPositiveWholeNumber();
/**
 * Determines if the number is prime.
 */
bool isPrime(int num);
/**
 * Displays whether or not the number is prime.
 */
void displayNumberInfo(int num);

int main()
{
	displayNumberInfo(getPositiveWholeNumber());
	return 0;
}

int getPositiveWholeNumber()
{
	int num = 0;

	do
	{
		cout << endl << "Enter a positive whole number: ";
		cin >> num;
	}
	while(num == 0);

	return num;
}

bool isPrime(int num)
{
	if (num <= 1)
		return false;

	for (int count = (num / 2); count > 1; count--)
	{
		if (num % count == 0)
			return false;
	}

			return true;
}

void displayNumberInfo(int num)
{
	if (isPrime(num))
		cout << endl << num << " is prime.";
	else
		cout << endl << num << " is not prime.";
}
