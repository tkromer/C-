/*
 * Demonstrate the functionality of various types of loops
 *
 * By Tim Kromer
 */
 #include <iostream>
 #include <string>
 using namespace std;

int main()
{
	int counter = 1;
	string password;
	char letter;
	double input;

	// While loop
	while (counter < 26)
	{
		cout << counter << endl;
		counter++;
	}

	// Sentinel-controlled loop
	cout << "Please enter the password: ";
	cin >> password;

	if (password != "bucky" && password != "Bucky")
	{
		do
		{
			 cout << endl << "Incorrect password. Try again: ";
			 cin >> password;
		}
		while (password != "bucky" && password != "Bucky");
	}

	cout << endl << "Correct." << endl << endl;

	for (counter = 65; counter < 91; counter++)
	{
		letter = counter;
		cout << letter << ", ";
	}

	cout << endl;

	// Display even numbers, new line every 10th number using wile loop
	counter = 2;

	do
	{
		if (counter % 20 == 0)
			cout << counter << endl;

		cout << counter << ", ";
		counter += 2;
	}
	while(counter < 1004);

	// Test user input with while loop
	cout << endl << endl << "Enter a number: ";
	cin >> input;

	while(cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << endl << "Enter a valid number: ";
		cin >> input;
	}

	cout << input << " is a valid number.";
	return 0;
}
