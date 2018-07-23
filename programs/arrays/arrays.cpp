#include <iostream>
using namespace std;

int main ()
{
	const int SCORES_SIZE = 10;
	int scores[SCORES_SIZE] = { 20, 31, 45, 23, 46, 69 };
	int total = 0;

	cout << "The scores for each game are: ";
	for (int i = 0; i < SCORES_SIZE; ++i)
	{
		cout << scores[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < SCORES_SIZE; ++i)
	{
		total += scores[i];
	}

	cout << "The total is " << total;

	return 0;
}
