#include <iostream>
#include <string>
using namespace std;

enum Color
{
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	INDIGO,
	VIOLET,
	NO_COLOR
};

string colorToString (Color color);

Color stringToColor (const string& colorName);

int main ()
{
	Color myColor = BLUE;

	cout << "The color options are: " << endl;

	for (Color currentColor = RED; currentColor < NO_COLOR;
		currentColor = static_cast<Color>(currentColor + 1))
	{
		cout << '\t' << colorToString(currentColor) << endl;;
	}



	return 0;
}

string colorToString (Color color)
{
	switch (color)
	{
		case RED:
			return "red";
		case ORANGE:
			return "orange";
		case YELLOW:
			return "yellow";
		 case GREEN:
		 	return "green";
		case BLUE:
			return "blue";
		case INDIGO:
			return "indigo";
		case VIOLET:
			return "violet";
	}
	return "no color";
}

Color stringToColor (const string& colorName)
{
	if (colorName == "RED" || colorName == "red" || colorName == "Red")
		return RED;
	else if ( colorName == "ORANGE" || colorName == "orange")
		return ORANGE;
	else if ( colorName == "YELLOW" || colorName == "yellow")
		return YELLOW;
	else if ( colorName == "GREEN" || colorName == "green")
		return GREEN;
	else if ( colorName == "BLUE" || colorName == "blue")
		return BLUE;
	else if ( colorName == "INDIGO" || colorName == "indigo")
		return INDIGO;
	else if ( colorName == "VIOLET" || colorName == "violet")
		return VIOLET;

	return NO_COLOR;
}
