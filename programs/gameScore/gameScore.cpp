#include <iostream>
#include <string>
using namespace std;

void updateScore (double& currentScore, double amount);

void getUserInformation (string& name, int& skillLevel);

int main ()
{
	double score = 0;
	string userName;
	int difficultyLevel;

	getUserInformation (userName, difficultyLevel);

	cout << "Welcome " << userName << endl;
	cout << "Difficulty Level: " << difficultyLevel << endl;

	cout << "The score is: " << score << endl;

	updateScore (score, 10);

	cout << "Score is now: " << score << endl;

	return 0;
}

void updateScore (double& currentScore, double amount)
{
	currentScore += amount;
	cout << "CurrentScore is now: " << currentScore << endl;
}

void getUserInformation (string& name, int& skillLevel)
{
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your skill level (1 to 3): ";
	cin >> skillLevel;
}
