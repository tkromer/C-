/*
 * Recieves min and max values from user and creates a random number. Program
 * then tries to guess the random number and outputs the number of tries to a
 * file. A new number is generated and guessed 1000 times.
 *
 * By Tim Kromer
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<fstream>
using namespace std;

/**
 * Returns the middle (rounded down) of a range of numbers.
 */
int midRange(int min, int max);
/**
 * Gets the min and max values from the user.
 */
void getNumberRange(int& min, int& max);
/**
 * Generates the nubmer and checks the guess and says if it is
 * correct, high, or low.
 */
int checkGuess(int guess, int min = 0, int max = 0);
/**
 * Guesses the number, records number of attempts
 */
int guessUntilFound(int min, int max);
/**
 * Outputs the number of attempts to runlog.txt
 */
void generateRunStats(int min, int max);

int main()
{
	int min, max; // the min and max value the answer can be

	// Seed the random number generator using the current time.
	srand(static_cast<unsigned int>(time(nullptr)));

	// Get the range of random numbers from the user
	getNumberRange(min, max);

	// Give the function creating the random numbers the range or values.
	// min-1 is used as the first parameter, because it will never the a
	//   Correct guess.
	checkGuess(min - 1, min, max);

	// Guess 1000 numbers and write the number of guesses to a file
	generateRunStats(min, max);

	// Display message to user when finished.
	cout << "Finished! The number of guesses the computer took per number are"
		<< " stored in 'runlog.txt'."
		<< endl;

	return 0;
}

int midRange(int min, int max)
{
	// The middle value is always the average of the min and max.
	return (max + min) / 2;
}

void getNumberRange(int& min, int& max)
{
	// Gets user input
	cout << "Enter the min and max numbers: ";
	cin >> min >> max;

	// Makes sure input is valid
	if (min >= max)
	{
		cout << "Invalid input. " << endl;
		getNumberRange(min, max);
	}
}

int checkGuess(int guess, int min, int max)
{
	static const int RANGE = max - min + 1;
	static const int MIN_VALUE = min;
	static int numberToGuess;

	// Generates random number on first call from main()
	if (guess < MIN_VALUE)
	{
		numberToGuess = rand() % RANGE + MIN_VALUE;
	}

	// Returns number comparison
	if (guess > numberToGuess)
	{
		return 1;
	}
	else if (guess < numberToGuess)
	{
		return -1;
	}
	else
	{
		// Generates new number on correct guess
		numberToGuess = rand() % RANGE + MIN_VALUE;
		return 0;
	}
}

int guessUntilFound(int min, int max)
{
	int numberOfGuesses = 0;
	int guess, result;
	bool isGuessedCorrectly = false;

	do
	{
		guess = midRange(min, max);
		result = checkGuess(guess);

		if (result < 0)
		{
			min = guess + 1;
			numberOfGuesses++;
		}
		else if (result > 0)
		{
			max = guess - 1;
			numberOfGuesses++;
		}
		else
		{
			return numberOfGuesses;
		}
	} while(!isGuessedCorrectly);
}

void generateRunStats(int min, int max)
{
	ofstream fileOut;
	fileOut.open("runlog.txt");

	for (int count = 1; count <= 1000; count++)
	{
		fileOut << guessUntilFound(min, max) << endl;
	}
	fileOut.close();
}
