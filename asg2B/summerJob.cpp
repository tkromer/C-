/*
 *Takes pay rate and hours from user and calcuates how much is spent on
 *clothes, school supplies, investments, parental investments, and gives
 *the amount remaining.
* by Tim Kromer
 */
#include <iostream>
using namespace std;

int main()
{
	//Declare variables
	double rate, totalHours, weeklyHours, salary, clothes, supplies, bonds, parents;

	//Collect user input
	cout << "Enter your hourly rate: ";
	cin >> rate;

	cout << endl << "Enter the number of hours worked week 1: ";
	cin >> totalHours;

	cout << endl << "Enter the number of hours worked week 2: ";
	cin >> weeklyHours;
	totalHours += weeklyHours;

	cout << endl << "Enter the number of hours worked week 3: ";
	cin >> weeklyHours;
	totalHours += weeklyHours;

	cout << endl << "Enter the number of hours worked week 4: ";
	cin >> weeklyHours;
	totalHours += weeklyHours;

	cout << endl << "Enter the number of hours worked week 5: ";
	cin >> weeklyHours;
	totalHours += weeklyHours;

	//Calculate Salary
	salary = rate * totalHours;
	cout << endl
		 <<"Your salary is $"
		 << salary <<endl;

	//Find salary after taxes
	salary -= (salary * 0.14);
	cout << "Your net income after taxes is $"
		 <<salary <<endl;

	//Budget for clothes
	clothes = salary * 0.10;
	cout << "Your budget for clothes and other accessories is $"
		 <<clothes << endl;

	//Budget for school supplies
	supplies = salary * 0.01;
	cout << "Your budget for school supplies is $"
		 << supplies <<endl;

	//Money to invest
	salary -= clothes + supplies;
	bonds = salary * 0.30;
	cout << "You can invest $"
		 << bonds <<endl;

	//Parental contribution
	parents = static_cast<int>(bonds) * 0.5;
	cout << "Your parents will give you $"
		 <<parents <<endl;

	//Remaining salary
	salary -= bonds;
	cout << "Your remaining salary is $"
		 <<salary <<endl;

	return 0;
}
