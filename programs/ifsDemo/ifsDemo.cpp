#include <iostream>
using namespace std;

int main()
{
	int number;

	cout << "Number please: " << endl;
	cin >> number;

	if(number > 5)
	{
		cout << "Greater than five" << endl;
		cout << "Glad you made it to five" << endl;
	}
	else
	{
		cout << "Less than or equal to 5" << endl;
	}

	return 0;
}
