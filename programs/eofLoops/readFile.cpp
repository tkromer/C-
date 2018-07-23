#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int total = 0;
	int inputNum;
	ifstream numsIn;

	numsIn.open("data.txt");

	// TODO: Read in numbers
	numsIn >> inputNum;
	while (!numsIn.eof())
	{
		total += inputNum;
		cout << inputNum << ", ";
		numsIn >> inputNum;
	}
	cout << endl;
	numsIn.close();

	cout << "The Total is  " << total << endl;
	return 0;
}
