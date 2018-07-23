/*
 * User inputs line of text, program removes all vowels and capitalizes the
 * consonants.
 *
 * By Tim Kromer
 */

#include <iostream>
#include <string>

using namespace std;

/*
 * Returns true if leter is vowel, false if it is not
 */
bool checkVowel(char letter);
/*
 * Removes all vowels from a string of text
 */
string removeVowels(const string& text);
/*
 * Capitalizes all consonants
 */
string allCaps(const string& text);

int main ()
{
	string text;

	cout << "Enter some text: ";
	getline(cin, text);

	cout << endl << allCaps(removeVowels(text));
	return 0;
}

bool checkVowel(char letter)
{
	switch (letter)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
			return true;
	}

	return false;
}

string removeVowels(const string& text)
{
	string noVowels;

	for (string::size_type index = 0; index < text.length(); ++index)
	{
		// No need to check non-letter characters
		if (text[index] >= 'a' && text[index] <= 'z' ||
			text[index] >= 'A' && text[index] <= 'Z')
		{
			// Add consonants to the string
			if (!checkVowel(text[index]))
			{
				noVowels += text[index];
			}
		}
		else
		{
			// add non-letter characters to the string
			noVowels += text[index];
		}
	}

	return noVowels;
}

string allCaps(const string& text)
{
	string capLetters = text;

	// Capitalizes
	for (string::size_type index = 0; index < text.length(); ++index)
	{
		// checks for lowercase and Capitalizes them
		if (text[index] >= 'a' && text[index] <= 'z')
		{
			capLetters[index] = text[index] - 'a' + 'A';
		}
	}

	return capLetters;
}
