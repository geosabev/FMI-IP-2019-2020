/**
*
* Solution to homework assignment 2
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

//Instead of using strlen
int calculateLengthOfString(char* arr) {
	int counter = 0;

	while (arr[counter] != '\0') {
		counter++;
	}

	return counter;
}

char* combineTwoStrings(char* arr1, char* arr2) {
	int length1 = calculateLengthOfString(arr1);
	int length2 = calculateLengthOfString(arr2);

	int shorterLength = 0, biggerLength = 0;

	char repeated[100]; //Stores the shorter string to be copied into the new combination
	char combination[100]; //Stores the combination of the two strings

	//Determines which is the shorter one and copies it into the string that will be repeated
	if (length1 < length2) {
		strcpy_s(repeated, arr1);
		shorterLength = length1;
		biggerLength = length2;
	}
	else {
		strcpy_s(repeated, arr2);
		shorterLength = length2;
		biggerLength = length1;
	}

	//Repeatedly copies the shorter string to the longer one
	for (int i = 0; i < biggerLength; i = i + shorterLength) {
		int position = i;
		for (int j = 0; j < shorterLength; j++)
		{
			if (position == biggerLength - 1) {
				combination[position] = repeated[j];
				break;
			}
			else {
				combination[position] = repeated[j];
				position++;
			}
		}
	}

	combination[biggerLength] = '\0'; //Marks the end of the string with a special "terminating zero"

	for (int i = 0; i <= biggerLength; i++)
		arr1[i] = combination[i];

	return arr1;
}

int main() {
	char arr1[101], arr2[101];

	//Input validation for first string (at least one symbol)
	do {
		cout << "arr1 = "; cin.getline(arr1, 101);

		if (calculateLengthOfString(arr1) == 0) {
			cin.clear();
			cout << "Come on, enter at least one symbol! Try again!" << endl;
		}
		else
			break;
	} while (true);

	//Input validation for second string (at least one symbol and not the same length as the first one)
	do {
		cout << "arr2 = "; cin.getline(arr2, 100);
		if (calculateLengthOfString(arr2) == calculateLengthOfString(arr1)) {
			cin.clear();
			cout << "The two strings must have different lengths! Enter a new arr2!" << endl;
		}
		else if (calculateLengthOfString(arr2) == 0) {
			cin.clear();
			cout << "Come on, enter at least one symbol! Try again!" << endl;
		}
		else
			break;
	} while (true);

	cout << combineTwoStrings(arr1, arr2);
}