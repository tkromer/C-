/*
 * Find the type of disc, number of discs, determine available discount,
 * determine cost of discs, and calculate total cost.
 *
 * By Tim Kromer
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Declare variables
	const double DISC_GOLF_RETAIL = 12.99;
	const double ULTIMATE_DISC_RETAIL = 18.99;
	double price, total;
	int discSelVal, numDiscs;
	char discSel;
	string discType;

	// Get type of disc from user
	cout << "Welcome to the Flying-Disc Shop!" << '\n' << '\n'
		<< "Enter 'u' for ultimate discs or 'g' for disc golf: ";
	cin >> discSel;

	// Determine disc type from user input
	discSelVal = discSel;

	switch (discSelVal)
	{
		case 85:
			discType = "Ultimate Disc";
			price = ULTIMATE_DISC_RETAIL;
			break;
		case 117:
			discType = "Ultimate Disc";
			price = ULTIMATE_DISC_RETAIL;
			break;
		case 71:
			discType = "Disc-Golf Disc";
			price = DISC_GOLF_RETAIL;
			break;
		case 103:
			discType = "Disc-Golf Disc";
			price = DISC_GOLF_RETAIL;
			break;
		default:
			cout << '\n' << "That is not a valid selection.";
			return 0;
	}

	// Get number of discs from user
	cout << '\n' << "Enter the number of " << discType << "(s): ";
	cin >> numDiscs;

	// Determine cost of discs
	if(numDiscs < 0)
	{
		cout << '\n' << numDiscs << " is an invalid number of discs.";
		return 0;
	}
	else if(numDiscs < 5)
	{
		total = numDiscs * price;
	}
	else if(numDiscs < 10)
	{
		price = price - (price * .1);
		total = numDiscs * price;
	}
	else if(numDiscs < 20)
	{
		price = price - (price * .15);
		total = numDiscs * price;
	}
	else if(numDiscs < 30)
	{
		price = price - (price * .2);
		total = numDiscs * price;
	}
	else
	{
		price = price - (price * .25);
		total = numDiscs * price;
	}

	// Manipulate format for receipt
	cout << '\n' << fixed << setprecision(2) << setfill('-');

	// Display receipt
	cout << setw(19) << "Receipt" << setw(13) << '\n'
		<< "     Disc Type: " << discType << '\n'
		<< "      Quantity: " << numDiscs << '\n'
		<< "Price per Disc: $" << price << '\n'
		<< "         Total: $" << total << '\n';

	return 0;
}
