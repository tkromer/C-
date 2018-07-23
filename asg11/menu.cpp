/**
 * Reads in resturant menu from menuPrices.text, displays the menu, allows
 * customer to make selections, and calculates the bill.
 *
 * By Tim Kromer
 */
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int MENU_SIZE = 8;
struct MenuItem
{
	string name;
	double price;
};
/**
 * Reads the menu from the file and stores it in an array of structs
 */
void getData(MenuItem menuList[]);
/**
 * Displays the menu to the customer
 */
void showMenu(const MenuItem menuList[]);
/**
 * Allows the customer to select an item and its quantity
 */
void makeSelection(int quantity[]);
/**
 * Prints a receipt with the customer's selections, the tax, and the total
 */
void printCheck(const MenuItem menuList[], const int quantity[]);

int main ()
{
	MenuItem menuList[MENU_SIZE];
	int quantity[MENU_SIZE];

	// Initializes the quantity of each item to 0
	for (int index = 0; index < MENU_SIZE; ++index)
	{
		quantity[index] = 0;
	}

	cout << setprecision(2) << fixed;

	getData(menuList);

	showMenu(menuList);

	makeSelection(quantity);

	printCheck(menuList, quantity);

	return 0;
}

void showMenu (const MenuItem menuList[])
{
	cout << "Welcome to Johnny's Resturant" << endl
		<< "--------Today's Menu--------" << endl;

	for (int index = 0; index < MENU_SIZE; ++index)
	{
		cout << right << setw(2) << index + 1 << ": " << left << setw(15)
			<< menuList[index].name	<< "$" << menuList[index].price << endl;
	}
}

void getData(MenuItem menuList[])
{
	ifstream menu;
	char extra;

	menu.open("menuPrices.txt");

	for (int index = 0; index < MENU_SIZE; ++index)
	{
		// Removes new line characters from input stream
		if (menu.peek() == '\n')
			menu.get(extra);

		getline(menu, menuList[index].name);
		menu >> menuList[index].price;
	}

	menu.close();
}

void makeSelection(int quantity[])
{
	char response;
	int itemNumber, itemQuantity;

	cout << endl << "Would you like to pace an order? (y/n): ";
	cin >> response;

	while (response != 'n' && response != 'N')
	{
		if (response == 'Y' || response == 'y')
		{
			cout << endl << "Enter item number: ";
			cin >> itemNumber;
			cout << "Enter item quantity: ";
			cin >> itemQuantity;

			quantity[itemNumber - 1] += itemQuantity;
		}
		else
		{
			cout << "Invalid response";
		}

		cout << "Select another item? (y/n): ";
		cin >> response;
	}
}

void printCheck(const MenuItem menuList[], const int quantity[])
{
	const double TAX_RATE = 0.05;
	double total = 0;
	double tax;

	cout << endl << "Thank you for eating at Johnny's Resturant" << endl;

	for (int index = 0; index < MENU_SIZE; ++index)
	{
		if (quantity[index] != 0)
		{
			cout << right << setw(2) << quantity[index] << " "
				<< left << setw(15)
				<< menuList[index].name	<< "$"
				<< quantity[index] * menuList[index].price << endl;

			total += quantity[index] * menuList[index].price;
		}
	}
	tax = total * TAX_RATE;
	cout << right << setw(6) << "Tax" << left << setw(12) << " " << "$"
		<< tax << endl;
	cout << right << setw(13) << "Amount Due" << left << setw(5) << " " << "$"
		<< total + tax << endl;
}
