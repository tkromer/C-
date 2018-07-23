#include <iostream>
using namespace std;

void printArray (const auto list[], int length);

void swap (int list[], int index1, int index2);

void swap(int& index1, int& index2);

int smallestValuesIndex (const int list[], int length, int startIndex = 0);

void selectionSort (int list[], int length);

int main ()
{
	// Declare a 9 element array
	const int ARRAY_SIZE = 9;
	int myArray[ARRAY_SIZE] = {16, 30, 24, 7, 62, 45, 5, 55, 5};

	// Pringt the unsorted array
	printArray(myArray, ARRAY_SIZE);

	// Sort the array
	selectionSort(myArray, ARRAY_SIZE);

	// Print the sorted
	cout << "The sorted array is: \n";
	printArray (myArray, ARRAY_SIZE);

	return 0;
}

void printArray(const auto list[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		cout << list[index] << ", ";
	}
}

void swap (int list[], int index1, int index2)
{
	swap(list[index1], list[index2]);
}

void swap(int& index1, int& index2)
{
	int tempValue = index1;

	index1 = index2;
	index2 = tempValue;
}

int smallestValuesIndex (const int list[], int length, int startIndex)
{
	int minIndex = startIndex;

	for (int index = startIndex + 1; index < length; ++index)
	{
		 if(list[minIndex] > list [index])
		 {
			minIndex = index;
		 }
	}

	return minIndex;
}

void selectionSort (int list[], int length)
{
	int minIndex;
	for (int indexOfFirstUnsorted = 0; indexOfFirstUnsorted < length;
		indexOfFirstUnsorted++)
	{
		minIndex = smallestValuesIndex(list, length, indexOfFirstUnsorted);

		if(indexOfFirstUnsorted != minIndex)
			swap(list, indexOfFirstUnsorted, minIndex);
	}
}
