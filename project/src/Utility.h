#pragma once
#include <iostream>
#include <random>

using namespace std;

//Input validation for integers in an interval
int inputInteger(int minValue, int maxValue) {
	int input;
	bool validInput = false;
	while (validInput == false) {
		cout << "Choice: ";
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Not a valid option! Try again!" << endl;
		}
		else if (input < minValue || input > maxValue) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Not a valid option! Try again!" << endl;
		}
		else
			validInput = 1;
	}
	return input;
} //Input validation for integers

//Generates a random number between x and y
int generateRandomNumber(int from, int to) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(from, to);
	return dist6(rng);
}

//Prints a headline with some kind of decoration
void printHeadlineMessage(const char message[100]) {
	int length = strlen(message);
	for (int i = 0; i < length; i++)
		cout << "-";
	cout << endl << message << endl;
	for (int i = 0; i < length; i++)
		cout << "-";
	cout << endl;
}

//Checks if a given symbol is a letter
bool isALetter(char symbol) {
	return ((symbol >= 'A') && (symbol <= 'Z')) || ((symbol >= 'a') && (symbol <= 'z'));
}