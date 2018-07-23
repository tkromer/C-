/**
 * Creates an array, reverses it, and then reverses back to the original
 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/**
 * Prints the array to the screen in rows of 10 and right aligned columns
 * @param myArray [The array to be printed]
 * @param length  [The length of the array]
 */
void printArray(const double myArray[], int length);
/**
 * Swaps the values between 2 positions of the array
 * @param myArray [Array with values to be swapped]
 * @param index1  [Position of the first value]
 * @param index2  [Postion of the second value]
 */
void swap(double myArray[], int index1, int index2);
/**
 * Reverses the values of the array
 * @param array  [Array to be reversed]
 * @param length [Length of the array]
 */
void reverse(double array[], int length);

int main ()
{
	const int ARRAY_SIZE = 56;
	double myArray[ARRAY_SIZE];
	int index = 0;

	// Values in the first half are the square of the index
	for (index; index < (ARRAY_SIZE / 2); ++index)
	{
		myArray[index] = index * index;
	}
	// Values in the second half are the square root of the index
	for (index; index < ARRAY_SIZE; ++index)
	{
		myArray[index] = sqrt(index);
	}

	cout << "Original Array" << endl << endl;
	printArray(myArray, ARRAY_SIZE);

	cout << endl << endl << "The array reversed" << endl << endl;
	reverse(myArray, ARRAY_SIZE);
	printArray(myArray, ARRAY_SIZE);

	cout << endl << endl << "Back to the original" << endl << endl;
	reverse(myArray, ARRAY_SIZE);
	printArray(myArray, ARRAY_SIZE);

	return 0;
}

void printArray(const double myArray[], int length)
{
	int count = 0;

	for (int index = 0; index < length; ++index)
	{
		cout << fixed << setprecision(1) << setw(10) << myArray[index] << " ";
		++count;

		// Allows only 10 values per row
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
	}
}

void swap(double myArray[], int index1, int index2)
{
	double temp = myArray[index1];
	
	myArray[index1] = myArray[index2];
	myArray[index2] = temp;
}

void reverse(double array[], int length)
{
	int second;
	for (int index = 0; index < length / 2; ++index)
	{
		second = (length - 1) - index;

		if (length - index != 0)
		{
			swap(array, index, second);
		}
	}
}
