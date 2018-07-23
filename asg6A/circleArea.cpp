/*
 * User inputs the radius of a circle and height of a cylinder. The program
 * calculates the diameter, circumference and area of the circle, as well
 * as the volume of the cylinder. The user then inputs a set of coordinates
 * and is told if they are inside of the circle.
 *
 * By Tim Kromer
 */

#include <iostream>
#include <cmath>
using namespace std;

// Global Variables
const double PI = 3.14159;

// Function prototypes
/**
 * Returns the circumference of the circle
 */
double circumference(double radius);
/**
 * Returns the area of the circle
 */
double area(double radius);
/**
 * Returns the volume of the cylinder
 */
double cylinderVolume(double radius, double height);
/**
 * Determines if given point is inside of the circle
 */
bool insidePoint(double radius, double pointX, double pointY);

int main()
{
	// Variables
	double radius, height, diameter, pointX, pointY;

	// Get measurments of cylinder
	cout << "Enter the radius of the circle: ";
	cin >> radius;
	cout << endl << "Enter the height of the cylinder: ";
	cin >> height;

	diameter = radius * 2;

	// Display measurments
	cout << endl << "Radius =  " << radius << endl
		<< "Diameter =  " << diameter << endl
		<< "circumference =  " << circumference(radius) << endl
		<< "Area =  " << area(radius) << endl
		<< "Cylinder Volume = " << cylinderVolume(radius, height) << endl;

	// Get point coordinates
	cout << endl << "Check if point is within a circle centered at (0, 0)"
		<< endl << "Enter the x-coordinate of a point: ";
	cin >> pointX;
	cout << endl << "Enter the y-coordinate of a point: ";
	cin >> pointY;

	// Determine if the point is in the circle
	if (insidePoint(radius, pointX, pointY))
	{
		cout << endl << "(" << pointX << ", " << pointY
			<< ") is within the circle.";
	}
	else
	{
		cout << endl << "(" << pointX << ", " << pointY
			<< ") is not within the circle.";
	}

	return 0;
}

double circumference(double radius)
{
	double circumference;

	circumference = 2 * PI * radius;

	return circumference;
}

double area(double radius)
{
	double area;

	area = PI * radius * radius;

	return area;
}

double cylinderVolume(double radius, double height)
{
	double volume;

	volume = area(radius) * height;

	return volume;
}

bool insidePoint(double radius, double pointX, double pointY)
{
	if (hypot(pointX, pointY) <= radius)
		return true;
	else
		return false;
}
