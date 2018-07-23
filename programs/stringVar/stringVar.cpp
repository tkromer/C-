/*
 * Get an employee's name, hourly rate, and percent raise.
 * Calculate the new hourly rate
 *by Tim Kromer
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	double hourlyRate;
	double percentIncrease;

	cout << "Enter the emplyee's name: " << endl;
	cin >> name;

	cout << "Enter current pay rate: " << endl;
	cin >> hourlyRate;

	cout << "Enter percent increase for raise: " << endl;
	cin>> percentIncrease;

	//hourlyRate = hourlyRate * percentIncrease + hourlyRate;
	//hourlyRate = hourlyRate * (percentIncrease + 1);
	hourlyRate *= percentIncrease +1;

	cout << name << "'s new hourly rate is " << hourlyRate <<"." << endl;

	return 0;
}
