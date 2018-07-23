/**
 * A program that converts a phrase it into all capitals, inverts the characters
 * so the phrase is backwards, and doubles each letter in the phrase
 *
 * By Tim Kromer
 */

#include <iostream>
#include <string>
using namespace std;

string toAllCaps(const string& text);

string reverse(const string& text);

string doubleTheLetters(const string& text);

int main ()
{
	string phrase; // the phrase that will be inputted by the user

	cout << "Enter a phrase to be converted: ";
	getline (cin, phrase); // Get whole line of input

	cout << "The phrase in all capitals is: "
		<< toAllCaps(phrase) << endl;

	cout << "The backwards phrase is: " << reverse(phrase) << endl;

	cout << "Speaking slowly: " << doubleTheLetters(phrase) << endl;

	return 0;
}

string toAllCaps(const string& text)
{
	string capsString = text;

	// Check for lowercase leters and make them uppercase
	for (string::size_type index = 0; index < text.length(); ++index)
	{
		if (text[index] >= 'a' && text[index] <= 'z')
		{
			capsString[index] = text[index] - 'a' + 'A';
		}
	}

	return capsString;
}

string reverse(const string& text)
{
	string reversedText;

	// Iterates from the end to the begining of the string
	// For string::size_type, 1 less than zero is the max value
	// string::npos
	for (string::size_type index  = text.length() - 1;
		index < string::npos; --index)
	{
		reversedText += text[index];
	}
	return reversedText;
}

string doubleTheLetters(const string& text)
{
	string doubled;

	// Add each letter twice to the doubled variable.
	for (string::size_type index = 0; index < text.length(); ++index)
	{
		if (text[index] >= 'a' && text[index] <= 'z'||
			text[index] >= 'A' && text[index] <= 'Z')
		{
			doubled += text[index];
			doubled += text[index];
		}
	}

	return doubled;
}
