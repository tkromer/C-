/**
 * Reads in the names and grades of students from grades.txt. The program
 * stores this information in a series of arrays, calculates average grades,
 * letter grades, and finds the student with the highest average. It then
 * outputs this information in an easily readable format.
 *
 * By Tim Kromer
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// Number of assignments
const int NUM_OF_GRADES = 6;

/**
 * Returns the array index of the student with the highest average
 */
int maxIndex(const double avgGrades[], int classSize);

/**
 * Calculates the average of a single students scores
 */
double calculateAverage(const int grades[]);
/**
 * Calculates the average score of each student in the class
 */
void calculateAverages(int const grades[][NUM_OF_GRADES], double avgGrades[],
	int classSize);
/**
 * Calculates the class average
 */
double calculateClassAverage(double const averages[], int classSize);
/**
 * Calculates each student's letter grade
 */
void calculateLetterGrade(const double scores[], char letterGrades,
	int classSize);
/**
 * Reads the student's names and grades from a file
 */
int getData(string names[], int grades[][NUM_OF_GRADES], string inputFile);
/**
 * Prints the gradebook
 */
void print(const string names[], const int grades[][NUM_OF_GRADES],
	int classSize, double avgGrades[], char letterGrades[]);

int main ()
{
	const int NUM_OF_STUDENTS = 20;
	string names[NUM_OF_STUDENTS];
	int grades[NUM_OF_STUDENTS][NUM_OF_GRADES];
	int classSize  = getData(names, grades, "grades.txt");
	double avgGrades[NUM_OF_STUDENTS];
	char letterGrades[NUM_OF_STUDENTS];

	print(names, grades, classSize, avgGrades, letterGrades);

	return 0;
}

int maxIndex(const double avgGrades[], int classSize)
{
	double highestAvg = avgGrades[0];
	// Set to 0 incase first student is highest
	int bestStudent = 0;

	for (int student = 0; student < classSize; ++student)
	{
		if(avgGrades[student] > highestAvg)
		{
			highestAvg = avgGrades[student];
			bestStudent = student;
		}
	}

	return bestStudent;
}

double calculateAverage(const int grades[])
{
	double avg = 0;

	for (int score = 0; score < NUM_OF_GRADES; ++score)
		avg += grades[score];
	avg /= NUM_OF_GRADES;

	return avg;
}

void calculateAverages(const int grades[][NUM_OF_GRADES], double avgGrades[],
	int classSize)
{
	int scores[NUM_OF_GRADES];
	int student, scoreIndex;

	for (student = 0; student < classSize; ++student)
	{
		for (scoreIndex = 0; scoreIndex < NUM_OF_GRADES; ++scoreIndex )
		{
			scores[scoreIndex] = grades[student][scoreIndex];
		}

		avgGrades[student] = calculateAverage(scores);
	}
}

double calculateClassAverage(double const averages[], int classSize)
{
	double classAvg = 0;

	for (int student = 0; student < classSize; ++student)
		classAvg += averages[student];

	return classAvg / classSize;
}

void calculateLetterGrade(const double scores[], char letterGrades[],
	int classSize)
{

	for (int gradeIndex = 0; gradeIndex < classSize; ++gradeIndex )
	{
		if (scores[gradeIndex] >= 90)
			letterGrades[gradeIndex] = 'A';
		else if (scores[gradeIndex] >= 80)
			letterGrades[gradeIndex] = 'B';
		else if (scores[gradeIndex] >= 70)
			letterGrades[gradeIndex] = 'C';
		else if (scores[gradeIndex] >= 60)
			letterGrades[gradeIndex] = 'D';
		else
			letterGrades[gradeIndex] = 'F';
	}
}

int getData(string names[], int grades[][NUM_OF_GRADES], string inputFile)
{
	int student = 0;
	int score;

	ifstream scoresheet;
	scoresheet.open(inputFile);

	while (!scoresheet.eof())
	{
		scoresheet >> names[student];

		for (score = 0; score < NUM_OF_GRADES; ++score)
		{
			scoresheet >> grades[student][score];
		}

		++student;
	}

	scoresheet.close();

	return student;
}

void print(const string names[], const int grades[][NUM_OF_GRADES],
	int classSize, double avgGrades[], char letterGrades[])
{
	const int SPACING = 10;
	int student, score;

	calculateAverages(grades, avgGrades, classSize);
	calculateLetterGrade(avgGrades, letterGrades, classSize);

	// format output
	cout << fixed << setprecision(2) << setfill(' ');

	/*************************Column  Headings********************************/
	cout << " Name ";
	for (int asgIndex = 1; asgIndex <= NUM_OF_GRADES; ++asgIndex)
	{
		cout << setw(SPACING) << " HW " << asgIndex;
	}
	cout << setw(SPACING + 7) << "Average " << setw(SPACING + 8)
		<< "Letter Grade " << endl;
	/************************************************************************/

	for (student = 0; student < classSize; ++student)
	{
		// Prints name of student
		cout << setw(SPACING) << names[student] << " ";

		for (score = 0; score < NUM_OF_GRADES; ++score)
		{
			// prints alll 6 grades before starting new line
			cout << setw(SPACING) << grades[student][score] << " ";
		}
		// Prints averages and letter grades
		cout << setw(SPACING) << " " << avgGrades[student] << setw(SPACING)
			<< " " << letterGrades[student] << endl;
	}

	cout << endl << endl << " Class Average: "
		<< calculateClassAverage(avgGrades, classSize)	<< endl
		<< " The student with the highest grade is: "
		<< names[maxIndex(avgGrades, classSize)];
}
