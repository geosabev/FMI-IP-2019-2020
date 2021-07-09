/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

//In order to use it in functions declared before it
bool isPartOfTheLanguage(char[]);

//Error message in case of invalid input
void printErrorForBadInput() {
	cout << "Invalid input! Try again!" << endl;
}

//Input validation for integers from minValue to maxValue; returns the number
int inputInteger(int minValue, int maxValue) {
	int input;
	bool validInput = false;
	while (validInput == false) {
		cout << "Choice: ";
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printErrorForBadInput();
		}
		else if (input < minValue || input > maxValue) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printErrorForBadInput();
		}
		else
			validInput = 1;
	}
	return input;
}

//Calculates the length of the string
int calculateStringLength(char str[]) {
	int position = 0, counter = 0;

	while (str[position] != '\0') {
		counter++;
		position++;
	}

	return counter;
}

//Condition 1: An empty string is a word
bool isAnEmptyString(char str[]) {
	int length = calculateStringLength(str);

	return (length == 0);
}

//Condition 2: If <w> is a word, AA<w>B is a word too
bool surroundedByAAandB(char str[]) {
	int length = calculateStringLength(str);
	bool currentStatus = false;

	char sequenceToInspect[253];

	if (str[0] == 'A' && str[1] == 'A') {
		int newPosition = 2;

		bool foundEndingB = false;
		int innerSymbols = 0;

		while (foundEndingB == false && newPosition != length) {
			if (str[newPosition] == 'B' && newPosition == length - 1)
				foundEndingB = true;
			else {
				innerSymbols++;
				newPosition++;
			}
		}

		if (foundEndingB == true) {
			if (innerSymbols == 0)
				currentStatus = true;
			else {
				int positionToGet = newPosition - innerSymbols;

				for (int i = 0; i < innerSymbols; i++) {
					sequenceToInspect[i] = str[positionToGet];
					positionToGet++;
				}

				sequenceToInspect[innerSymbols] = '\0';

				if (isPartOfTheLanguage(sequenceToInspect) == 1)
					currentStatus = true;
				else currentStatus = false;
			}
		}
	}

	if (currentStatus == true)
		return 1;
	else return 0;
}

//Conditions 3 and 5: If <w> is a word, <w>C<w> and <w>D<w> are words too
bool sameWordAroundCorD(char str[]) {
	int length = calculateStringLength(str);
	int middlePosition = length / 2;

	char inspected[256];
	
	bool currentStatus = false;

	int lengthOfInspected = 0;

	if (str[middlePosition] == 'C' || str[middlePosition] == 'D') {
		if (length == 1)
			currentStatus = true;
		else if (length % 2 == 0)
			currentStatus = false;
		else {
			for (int i = 0; i < middlePosition; i++) {
				if (str[i] != str[(middlePosition + 1) + i]) {
					currentStatus = false;
					break;
				}
				else {
					inspected[i] = str[i];
					lengthOfInspected++;
				}
			}

			inspected[lengthOfInspected] = '\0';

			if (lengthOfInspected != middlePosition)
				currentStatus = false;
			else {
				if (isPartOfTheLanguage(inspected) == 1)
					currentStatus = true;
				else
					currentStatus = false;
			}
		}
	}

	if (currentStatus == true)
		return 1;
	else return 0;
}

//Condition 4: If <w1> and <w2> are words, <w1>C<w2> is a word too
bool twoWordsAroundC(char str[]) {
	int length = calculateStringLength(str);

	char leftPart[256];
	char rightPart[256];

	bool currentStatus = false;

	for (int i = 0; i < length; i++) {
		int lengthOfLeft = 0;
		int lengthOfRight = 0;

		if (str[i] == 'C') {
			for (int j = 0; j < i; j++) {
				leftPart[j] = str[j];
				lengthOfLeft++;
			}

			for (int j = 0; j < length; j++) {
				rightPart[j] = str[j + (i + 1)];
				lengthOfRight++;
			}

			leftPart[lengthOfLeft] = '\0';
			rightPart[lengthOfRight] = '\0';

			if (isPartOfTheLanguage(leftPart) == true && isPartOfTheLanguage(rightPart) == true)
				currentStatus = true;
		}
	}

	if (currentStatus == true)
		return 1;
	else return 0;
}

//Condition 6: If <w> has more than 64 symbols in it, <w> is not a word
bool isLongerThan64(char str[]) {
	int length = calculateStringLength(str);

	if (length > 64)
		return true;
	else return false;
}

//Checks if one of the 6 conditions is true
bool isPartOfTheLanguage(char str[]) {

	if (isLongerThan64(str) == true)
		return false;
	else if (isAnEmptyString(str) == true)
		return true;
	else if (surroundedByAAandB(str) == true)
		return true;
	else if (sameWordAroundCorD(str) == true)
		return true;
	else if (twoWordsAroundC(str) == true)
		return true;
	else
		return false;
}

int main() {
	char str[11][256];

	int n = inputInteger(1, 10);

	for (int i = 0; i <= n; i++)
		cin.getline(str[i], 256);

	for (int i = 1; i <= n; i++) {
		if (isPartOfTheLanguage(str[i]) == true)
			cout << 1 << endl;
		else cout << 0 << endl;
	}
}