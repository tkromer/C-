/*
 *
 */
#include <iostream>
#include <iomanip>
using namespace std;

bool isWhiteSpace (char character);

void countWordsByLength (int& oneChar, int& twoChar, int& threeChar,
 	int& fourChar, int& fiveChar);

void printCount (int wordLength, int amntWords);

int main ()
{
	int oneChar = 0;
	int twoChar = 0;
	int threeChar = 0;
	int fourChar = 0;
	int fiveChar = 0;

	countWordsByLength (oneChar, twoChar, threeChar, fourChar, fiveChar);

	printCount(1, oneChar);
	printCount(2, twoChar);
	printCount(3, threeChar);
	printCount(4, fourChar);
	printCount(5, fiveChar);

	return 0;
}

bool isWhiteSpace (char character)
{
	switch (character)
	{
		case '\n':
			return true;
		case '\r':
			return true;
		case ' ':
			return true;
		default:
			return false;
	}
}

void countWordsByLength (int& oneChar, int& twoChar, int& threeChar,
 	int& fourChar, int& fiveChar)
{
	int count = 0;
	char character;

	cout << "Enter some Text: ";

	do
	{
		cin.get(character);
		if (isWhiteSpace(character))
		{
			switch (count)
			{
				case 1:
					oneChar++;
					count = 0;
					break;
				case 2:
					twoChar++;
					count = 0;
					break;
				case 3:
					threeChar++;
					count = 0;
					break;
				case 4:
					fourChar++;
					count = 0;
					break;
				case 5:
					fiveChar++;
					count = 0;
					break;
			}
		}
		else
		{
			if (character >= 'a' && character <= 'z' ||
				character >= 'A' && character <= 'Z')
				count++;
		}
	}
	while (character != '\n');
}

void printCount (int wordLength, int amntWords)
{
	cout << right;
	cout << wordLength << "-letterwords: " << setw(3) << amntWords << endl;
}
