/*
 * Intro to While Loops
 */

#include <iostream>

using namespace std;

int main()
{
	int counter;

	cout << "Time for loops!" << endl;

	counter = 0;
	while (counter < 100)
	{
		cout << counter << endl;
		++counter;
	}

	cout << "Finished.";


	return 0;
}
