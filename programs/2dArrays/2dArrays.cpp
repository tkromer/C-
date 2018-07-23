#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int COL_COUNT = 10;

void printArray(const auto array[], int length);

void printArray(const auto array[][COL_COUNT], int rowCount);

int main()
{
	const int ROW_COUNT = 10;
	//nt table[ROW_COUNT][COL_COUNT];
	string board[ROW_COUNT][COL_COUNT];
	int rowIndex, colIndex;
	char rowLetter;

	for (rowIndex = 0; rowIndex < ROW_COUNT; ++rowIndex)
	{
		rowLetter = 'A' + rowIndex;
		for (colIndex = 0; colIndex < COL_COUNT; ++colIndex)
		{
			board[rowIndex][colIndex] = rowLetter + to_string(colIndex + 1);
		}
	}

	printArray(board, ROW_COUNT);

	return 0;
}

void printArray(const auto array[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		cout << setw(4) << array[index] << " ";
	}
	cout << endl;
}

void printArray(const auto array[][COL_COUNT], int rowCount)
{
	int rowIndex, colIndex;

	for (colIndex = COL_COUNT - 1; colIndex >= 0; --colIndex)
	{
		for (rowIndex = rowCount - 1; rowIndex >= 0; --rowIndex)
		{
			cout << setw(4) << array[rowIndex][colIndex];
		}
		cout << endl;
	}

	/*for (rowIndex = 0; rowIndex < rowCount; ++rowIndex)
	{
			printArray(array[rowIndex], COL_COUNT);
	}*/





}
