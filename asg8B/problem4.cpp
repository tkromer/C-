/*
 * Takes input file of unspecified length and translates it to pig latin
 * while maintaining original punctuation and whitespace.
 *
 * By Tim Kromer
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Returns true if the character is a vowel, false if its a consonant
 * @param ch the character to be checked
 * @retrn true if vowel, false if not
 */
bool isVowel (char ch);

/**
 * Removes the first character of the string, and places it at the
 * end of the string.
 * @param pString the word to be rotated.
 * @return the new reordered string
 */
string rotate (const string& pStr);

/**
 * Takes input string and converts it to pig latin while maintaining original
 * punctuation.
 * @param pString the word to be translated
 * @return the translated word
 */
string pigLatinString (string pStr);
/**
 * Returns true if character is punctuation, false if it is not.
 */
bool isPunctuation(char ch);
/**
 * Returns true if character is whitespace, false if it is not.
 */
bool isWhitespace(char ch);

int main ()
{
	string str;
	char whitespace;

	ifstream input;
	ofstream output;

	input.open("SampleText.txt");
	output.open("output.txt");

	while (!input.eof())
	{
		// Checks for whitespace, adds to output.txt if found
		if (isWhitespace(input.peek()))
		{
			input.get(whitespace);
			output << whitespace;
		}
		else
		{
		 // Takes in next string and converts to pig latin
			input >> str;
			output << pigLatinString(str);
		}
	}

	input.close();
	output.close();

	return 0;
}

bool isVowel (char ch)
{
	switch (ch)
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'Y':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'y':
			return true;
		default:
			return false;
	}
}

string rotate (const string& pStr)
{
	string::size_type len = pStr.length();

	string rStr;

	// Removes the first character of the string and appends it to the end
	rStr = pStr.substr(1, len - 1) + pStr[0];

	return rStr;
}

string pigLatinString (string pStr)
{
	string::size_type len = pStr.length();
	char punctuation;

	bool foundVowel;

	string::size_type counter;

	// Checks for punctuation at end of string
	if (isPunctuation(pStr[len - 1]))
	{
		punctuation = pStr[len - 1];
	 // Removes the punctuation from end of string
		pStr.erase(len - 1, 1);
	}

	// IF pStr starts with a vowel, leave as is and add -way to the end
	if (isVowel(pStr[0]))
		pStr = pStr + "-way";
	else
	{
		pStr = pStr + '-'; // adds hyphen to end of string
		pStr = rotate(pStr); // moves first letter to end of string

		len = pStr.length();
		foundVowel = false;

		// Moves the first letter to the end until the first letter is a vowel
		for (counter = 1; counter < len - 1; counter++)
		{
			if (isVowel(pStr[0]))
			{
				foundVowel = true;
				break;
			}
			else

				pStr = rotate(pStr);
		}
		// If string has no vowels, add -way to the end
		if (!foundVowel)
			pStr = pStr.substr(1, len) + "-way";
		else
			// If string changed to start with vowel, add ay to the end
			pStr = pStr + "ay";
	}

	// Adds punctuation back to end of string
	pStr += punctuation;

	return pStr;
	hello
}

bool isPunctuation(char ch)
{
	switch (ch)
	{
		case ',':
		case '.':
		case '?':
		case '!':
		case ';':
		case ':':
			return true;
		default:
			return false;
	}
}

bool isWhitespace(char ch)
{
	switch (ch)
	{
		case ' ':
		case '\n':
		case '\r':
		case '\t':
			return true;
		default:
			return false;
	}
}
