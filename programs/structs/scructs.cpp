#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ASSIGNMENT_MAX = 10;
struct Student
{
	string firstName;
	string lastName;
	double gpa;
	double assignments[ASSIGNMENT_MAX];
	int assignmentCount;
};

void print(const Student& stud);

void print(const Student stud[], int length);

Student getStudent();

void init (Student student[], int length);

int main ()
{
	const int STUDENT_COUNT = 24;

	Student student[STUDENT_COUNT];

	cout << setprecision(1) << fixed;

	student[0].firstName = "James";
	student[0].lastName = "Kirk";
	student[0].gpa = 3.5;

	for(int index = 0; index < 5; ++index)
	{
		student[0].assignments[student[0].assignmentCount] = 96.2 + index;
		student[0].assignmentCount++;
	}
	init(student, STUDENT_COUNT);

	print(student, STUDENT_COUNT);


	return 0;
}

void print(const Student& stud)
{
	cout << "Name: " << stud.firstName << " " << stud.lastName
	 	<< endl << '\t' << "GPA: " << stud.gpa << endl;
	cout << "\tGrades: ";
	for (int index = 0; index < stud.assignmentCount; ++index)
	{
		cout << stud.assignments[index] << " ";
	}

	cout << '\n' << endl;
}

Student getStudent()
{
	Student newStudent;

	cout << "Enter first name: ";
	cin >> newStudent.firstName;
	cout << "Enter last name: ";
	cin >> newStudent.lastName;
	cout << "Enter gpa: ";
	cin >> newStudent.gpa;

	return newStudent;
}

void print(const Student stud[], int length)
{
	for (int index = 0; index < length; index++)
	{
		print(stud[index]);
	}
}

void init (Student student[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		student[index].firstName = "First" + to_string(index + 1);
		student[index].lastName = "Last" + to_string(index + 1);
		student[index].gpa = 4.0;
		student[index].assignmentCount = 0;
	}
}
