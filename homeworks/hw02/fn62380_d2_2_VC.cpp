/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 2
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

//Checks if a symbol is not allowed (if it's ASCII-code is not between 32 and 126)
bool isNotAnAllowedSymbol(char symbol) {
	return (symbol < 32 || symbol > 126);
}

//Encryption function
char* encryptAString(char* str, int M, int L) {
	int length = calculateLengthOfString(str);

	char encryptionStore[100]; //Stores the new "encrypted" string
	encryptionStore[length] = '\0'; //Marks the end of the string with a terminating zero

	for (int i = 0; i < length; i++) {
		if (isNotAnAllowedSymbol(str[i])) { 
			return str; //If there are any invalid symbols, the string remains untouched
		}

		else {
			int newPosition = i + L;

			if (newPosition < length)
				encryptionStore[newPosition] = str[i] + M;
			
			else {
				do {
					newPosition = newPosition - length;
				} while (newPosition >= length);

				encryptionStore[newPosition] = str[i] + M;
			}
		}
	}

	for (int i = 0; i <= length; i++)
		str[i] = encryptionStore[i];

	return str;
}

int main() {
	char str[101];
	int M, L;

	//Input validation for string (at least one symbol)
	do {
		cout << "Input string: ";
		cin.getline(str, 101, '\n');
		if (calculateLengthOfString(str) == 0) {
			cin.clear();
			cout << "Enter at least one symbol! Try again!" << endl;
		}
		else
			break;
	} while (true);

	//Input validation for M and L (M is between 1-20, L is smaller then the length of the string)
	do {
		cout << "Input M and L: ";
		cin >> M >> L;

		if (M <= 0 || M > 20) {
			cout << "M should be between 1 and 20 and L should be between 1 and the length of your string! Try again!" << endl;
		}
		else {
			if (L <= 0 || L >= calculateLengthOfString(str)) {
				cout << "M should be between 1 and 20 and L should be between 1 and the length of your string! Try again!" << endl;
			}
			else
				break;
		}
	} while (true);

	cout << encryptAString(str, M, L);
}