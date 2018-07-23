/*
 * Determine if letter is uppercase or lower case
 * and whether or not its a vowel
 *
 *By Tim Kromer
 */

#include <iostream>
using namespace std;

int main()
{
	// Declare variables
	int letterVal, isVowel;
	char letter;

	// Get user input
	cout << "Enter a character: ";
	cin >> letter;

	// Convert character into number value
	letterVal = letter;

	// Determine if character is a vowel
	switch (letterVal)
	{
		case 97:
			isVowel = 1;
			break;
		case 101:
			isVowel = 1;
			break;
		case 105:
			isVowel = 1;
			break;
		case 111:
			isVowel = 1;
			break;
		case 117:
			isVowel = 1;
			break;
		case 121:
			isVowel = 2;
			break;
		case 65:
			isVowel = 1;
			break;
		case 69:
			isVowel = 1;
			break;
		case 73:
			isVowel = 1;
			break;
		case 79:
			isVowel = 1;
			break;
		case 85:
			isVowel = 1;
			break;
		case 89:
			isVowel = 2;
			break;
		default:
			cout << '\n' << letter << " is not a vowel";
			return 0;
	}

	// Ouput
	if (isVowel == 1)
		cout << '\n' << letter << " is a vowel";
	else
		cout << '\n' << letter << " maybe a vowel";

	 return 0;
}
