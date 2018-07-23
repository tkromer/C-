/*
 * Read files programmaticaly
 * By Tim Kromer
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream fileIn;
	fileIn.open("score.txt");

	int score1, score2, score3, score4, score5;
	double avg;


	fileIn >> score1 >> score2 >> score3 >> score4 >> score5;

	fileIn.close();

	cout << "The test scores are: "
		<< score1 << ", "
		<< score2 << ", "
		<< score3 << ", "
		<< score4 << ", "
		<< score5 << endl;

	avg = score1 + score2 + score3 + score4 + score5;
	avg /= 5.0;

	cout << setprecision(2) << fixed;
	cout << "The average of the test scores is: " << avg << endl;

	return 0;
}
