/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
using namespace std;

//Instead of using strlen
int calculateLengthOfString(char* arr) {
	int counter = 0;

	while (arr[counter] != '\0') {
		counter++;
	}

	return counter;
}

//Error message in case of invalid input
void printErrorForBadInput() {
	cout << "Invalid input! Try again!" << endl;
}

//Checks if a symbol is a capital letter
bool isACapitalLetter(char symbol) {
	return (symbol >= 'A' && symbol <= 'Z');
}

//Calculates the position of a letter in the alphabet
int positionOfLetterInTheAlphabet(char letter) {
	return letter - 'A' + 1;
}

//Converts the string to the number of the column it represents in Microsoft Excel 
int calculateExcelColumnNumber(char* address) {
	int length = calculateLengthOfString(address);

	int sum = 0, power = 0;

	for (int i = length - 1; i >= 0; i--) {
		sum = sum + (pow(26, power) * positionOfLetterInTheAlphabet(address[i]));
		power++;
	}

	return sum;
}

int main() {
	char str[100]; bool validInput = 0;

	//Input validation
	while (validInput != 1) {
		cout << "Input: ";
		cin >> str;
		int incorrect = 0;
		int length = calculateLengthOfString(str);

		if (length > 3) { //String must be maximum 3 symbols long
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printErrorForBadInput();
		}
		else {
			for (int i = 0; i < length; i++) {
				if (isACapitalLetter(str[i]) == 0) //Only capital letters are supported
					incorrect++;
			}
			if (incorrect != 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				printErrorForBadInput();
			}
			else
				validInput = 1;
		}
	}

	int columnNumber = calculateExcelColumnNumber(str);

	cout << columnNumber;
}