/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 4
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

//Checks if a symbol is a capital letter
bool isCapitalLetter(char symbol) {
	return (symbol >= 'A' && symbol <= 'Z');
}

//Checks if a symbol is a small letter
bool isSmallLetter(char symbol) {
	return (symbol >= 'a' && symbol <= 'z');
}

//Checks if a symbol is a dash or a underline
bool isUnderlineOrDash(char symbol) {
	return (symbol == '_' || symbol == '-');
}

//Checks if a symbol is part of a word (a valid "letter")
bool isPartOfAWord(char symbol) {
	return (isCapitalLetter(symbol) || isSmallLetter(symbol) || isUnderlineOrDash(symbol));
}

//A word can be surrounded only by space, tab, start/end of string to be valid
bool allowedSymbolsAroundAWord(char symbol) {
	return (symbol == ' ' || symbol == '\t' || symbol == '\0');
}

int findAndCountTheShortestWords(char* arr) {
	int length = calculateLengthOfString(arr);

	int counter = 0, currentShortest = length;
	int ammountOfShortestWords = 0;

	for (int i = 0; i < length; i++) {
		if (isPartOfAWord(arr[i]) == 1) {
			int position = i;

			while (isPartOfAWord(arr[position]) == 1) {
				counter++;
				position++;
			}

			if (i != 0) {
				if (allowedSymbolsAroundAWord(arr[i - 1]) == 0) {
					counter = 0;
					i = position;
					continue;
				}
			}

			if (allowedSymbolsAroundAWord(arr[position]) == 1) {
				if (currentShortest > counter) {
					currentShortest = counter; //New length of the shortest words
					ammountOfShortestWords = 0; //New ammount of the shortest words
					ammountOfShortestWords++;
				}
				else if (counter == currentShortest) {
					ammountOfShortestWords++; //The length is the same, but the ammount is now bigger
				}
			}

			counter = 0; //Finished work on this word, going for the next one
			i = position; //Skips all 'i'-s already inspected
		}
	}

	return ammountOfShortestWords;
}

int main()
{
	char arr[100];

	//Input validation (at least one symbol)
	do {
		cout << "Input: "; cin.getline(arr, 100);
		if (calculateLengthOfString(arr) == 0) {
			cin.clear();
			cout << "Come on, don't be silly! Enter at least one symbol!" << endl;
		}
		else
			break;
	} while (true);

	cout << findAndCountTheShortestWords(arr);
}