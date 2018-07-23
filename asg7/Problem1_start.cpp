/**
 * Gets the user's name, gender, and time of day and displays
 * appropriate greeting.
 *
 * By Tim Kromer
 */
#include <iostream>
#include <string>
using namespace std;

// Greets the user with a generic name
void greet (const string name = "Earthling");

// Gets the time of day and provides appropriate greeting
void greet (int hour);

// Takes the user's name, gender and time of day and displays a polite greeting.
void greet (int hour, bool gender, string name = "");

// User inputs if they are male or female
bool isFemale ();

int main()
{
	string name;
	int hour;

	// standard greeting
	greet();
	cout << endl;

	// Prompt user for his or her name
	cout << "What is your name? ";
	getline(cin, name);

	// Greet by name
	greet(name);
	cout << endl;

	// Prompt the user for the hour of the day
	cout << "What hour of the day is it? ";
	cin >> hour;

	// Greet based on the time of day.
	greet(hour); // greet by the time of day
	cout << "." << endl << endl;

	// Greet based on the time of day and the gender.
	greet(hour, isFemale(), name); // greet by time of day and gender

	return 0;
}

void greet (const string name)
{
	cout << "Greetings " << name << "!";
}

void greet (int hour)
{
	if (hour < 12) // Before noon
		cout << "Good morning";
	else if (hour < 17) // Between noon and 5 PM
		cout << "Good afternoon";
	else if (hour < 22) // Between 5 PM and 10 PM
		cout << "Good evening";
	else // After 10 PM
		cout << "Goodnight";
}

void greet (int hour, bool gender, string name)
{
	greet(hour);

	if (gender)
		cout << " Ms. ";
	else
		cout << " Mr. ";

	cout << name << ".";
}

bool isFemale ()
{
	char gender;

	cout << "Are you male or female (m/f)? ";

	// The only way to exit the loop is an acceptable response
	do
	{
		cin >> gender;
		if (gender == 'f' || gender == 'F')
			return true;
		else if (gender == 'm' || gender == 'M')
			return false;
		else
			cout << endl
				<< "Please type either 'm' for male or 'f' for female: ";
	} while (gender);
}
