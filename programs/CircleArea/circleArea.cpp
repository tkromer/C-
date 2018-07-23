/*
 * Calculates the area of a circle given the radius input from the user.
 *
 *by Tim Kromer
*/

#include <iostream>
using namespace std;

int main()
{
	double radius; //Double is a number that can be a decimal
	double area;

	cout <<"Enter the radius of a circle: ";
	cin >> radius;

	area = 3.14159 * radius * radius;

	cout << "The radius is " << radius << endl;
	cout << "The area of the circle is " << area << endl;


	return 0;
}
