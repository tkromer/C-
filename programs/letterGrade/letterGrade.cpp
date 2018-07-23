#include <iostream>
using namespace std;

int main()
{
	double score; // numerical grade
	int flatScore; // the grade without the decimal part


	char letterGrade;

	// Get nemeric grade from user
	cout << "Enter in your grade:";
	cin >> score;

	// Calculate letter grade
	flatScore = static_cast<int>(score / 10);

	if (flatScore > 10) {
		cout << "You can't get a score higher than 100!" << endl;
		return 0;
	}

	switch (flatScore)
	 {
		case 10:
		case 9:
			letterGrade = 'A';
			break;
		case 8:
			letterGrade = 'B';
			break;
		case 7:
			letterGrade = 'C';
			break;
		case 6:
			letterGrade = 'D';
			break;
		default:
			letterGrade = 'F';
	}


	// Output letter grade
	cout << "Your letter grade is: " << letterGrade << endl;

	return 0;
}
