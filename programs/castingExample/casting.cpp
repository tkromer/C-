/*
 * Testing the cast operators in C++
 * by Tim Kromer
*/

#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	double doub1;

	num1 = static_cast<int>(4.9);
	doub1 = num1 * 1.111;
	doub1 = num1 / 8.0;
	num2 = doub1;

	cout << "num1: " << num1 <<endl;
	cout << "Numeric Value: " << 3.14159 << endl;
	cout << "Numeric Value: " << static_cast<int>(3.14159) << endl;
	cout << "doub1: " << doub1 << endl;
	cout << "num2: " << num2 <<endl;

	doub1 = 5.1561651651;
	cout << "decimal part:" << (doub1 - static_cast<int>(doub1)) <<endl;

	return 0;
}
