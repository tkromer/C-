#include <iostream>
using namespace std;

int main()
{
	char aChar; // characters are numbers to
	int aNumber; // number
	bool aBool; // either true or false (1 or 0)

	// Get character from user
	cout << "Character please: " << endl;
	cin >> aChar;

	// Change the representation of the Character
	aNumber = aChar;
	aBool = aChar;

	cout << "char ='" << aChar << "'" << endl;
	cout << "number = " << aNumber << endl;
	cout << "bool = " << aBool << endl;


	return 0;
}
