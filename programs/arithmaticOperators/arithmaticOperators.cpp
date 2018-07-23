/*
 * Arithmatic operators are tested
 * by Tim Kromer
 */
#include <iostream>
using namespace std;

int main()
{
	int num1 = 1;
	int num2 = 1;

	cout << "num1 = " <<num1 <<", num2 = " << num2 <<endl;

	++num1;
	num2++;

	cout << "num1 = " <<num1 <<", num2 = " << num2 <<endl;

	cout << "num1 = " <<++num1 <<", num2 = " << num2++ <<endl;
	cout << "num1 = " <<num1 <<", num2 = " << num2 <<endl;
	return 0;
}
