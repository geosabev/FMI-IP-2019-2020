#pragma once
#include "Utility.h"
#include "Dictionary.h"

//-----------------------------------------------------------------------------------------------------

char wordToGuess[13]; //Stores the word after randomly choosing it by getAWord();

int lengthOfWord = 0; //Stores the length of the given word to guess

bool statusOfLetter[100]; //If a current letter is known or not;
bool usedLetters[256]; //Letters the player tried and guessed;

//-----------------------------------------------------------------------------------------------------

//Resets all data to default after the game ends
void setToNull(int& allowedAttempts, int attemptsSet) {
	for (int i = 0; i < 100; i++)
		statusOfLetter[i] = 0;
	for (int i = 0; i < 256; i++)
		usedLetters[i] = 0;
	allowedAttempts = attemptsSet;
}

//Prints the given word
void printTheWord(int wordID, int lengthSetting) {
	if (lengthSetting == 1)
		cout << shortWords[wordID];
	else if (lengthSetting == 2)
		cout << mediumWords[wordID];
	else if (lengthSetting == 3)
		cout << longWords[wordID];
	else
		cout << unbeatableWords[wordID];
}

//Randomly generates the id of the word (chosen from a different wordlist according to the length)
int selectTheWordToGuess(int lengthSetting, int& lettersToGuess) {
	int idOfWord = generateRandomNumber(0, 19);

	if (lengthSetting == 1)
		strcpy_s(wordToGuess, shortWords[idOfWord]);
	else if (lengthSetting == 2)
		strcpy_s(wordToGuess, mediumWords[idOfWord]);
	else if (lengthSetting == 3)
		strcpy_s(wordToGuess, longWords[idOfWord]);
	else
		strcpy_s(wordToGuess, unbeatableWords[idOfWord]);

	lengthOfWord = strlen(wordToGuess);
	lettersToGuess = lengthOfWord;

	for (int i = 0; i < lengthOfWord; i++) {
		if (wordToGuess[i] == wordToGuess[0] || wordToGuess[i] == wordToGuess[lengthOfWord - 1]) {
			usedLetters[int(wordToGuess[i])] = 1;
			statusOfLetter[i] = true;
			lettersToGuess--;
		}
		else
			statusOfLetter[i] = false;
	}

	return idOfWord;
}

//Changes the preferred length of the word; by default: medium (6 - 8 letters)
int setWordLength(int currentSet) {
	system("cls");
	printHeadlineMessage("Change preferred word length");

	int decision;

	cout << "Select one of the following options:\n";
	cout << "1. Short (3 - 5 letters)\n2. Medium (6 - 8 letters)\n3. Long (9 - 12 letters)\n4. BONUS: Unbeatable words\n\n";

	cout << "Current setting: ";
	if (currentSet == 1)
		cout << "Short (3 - 5 letters)\n\n";
	else if (currentSet == 2)
		cout << "Medium (6 - 8 letters)\n\n";
	else if (currentSet == 3)
		cout << "Long (9 - 12 letters)\n\n";
	else
		cout << "Bonus level: Some of the unbeatable words for Hangman\n\n";

	decision = inputInteger(1, 4);

	return decision;
}

//Changes the ammount of allowed mistakes
int setAmmountOfAttempts(int currentSet) {
	system("cls");
	printHeadlineMessage("Change preferred ammount of attempts");

	cout << "Enter a number between 1 and 10.\n";

	cout << "\nCurrent setting: " << currentSet << "\n\n";

	int decision = inputInteger(1, 10);

	return decision;
}

//Shows the current status of the word (empty and filled positions of letters)
void currentStatus(int wordID, int attemptsLeft) {
	cout << "\nYour word: ";

	for (int i = 0; i < lengthOfWord; i++) {
		if (statusOfLetter[i] == 1)
			cout << wordToGuess[i];
		else
			cout << "_";

		if (i != lengthOfWord - 1)
			cout << " ";
	}

	cout << "\nYou have " << attemptsLeft << " attempts left.\n";
}

//The player tries to guess a letter
void makeAGuess(int wordID, int& allowedAttempts, int& unguessedLetters) {
	char letter;
	bool correctGuess = false;

	currentStatus(wordID, allowedAttempts);

	cout << "\nMake a guess: "; cin >> letter;

	system("cls");

	if (usedLetters[int(letter)] == 1)
		cout << "You cannot use this letter! Try using another one!\n";
	else {
		if (isALetter(letter)) {
			usedLetters[int(letter)] = 1;

			for (int i = 0; i < lengthOfWord; i++) {
				if (letter == wordToGuess[i]) {
					correctGuess = true;

					if (statusOfLetter[i] == 0) {
						statusOfLetter[i] = 1;
						usedLetters[int(letter)] = 1;
						unguessedLetters = unguessedLetters - 1;
					}

				}
			}

			if (correctGuess == true && unguessedLetters > 0)
				cout << "Correct guess!\n";
			else if (correctGuess == false) {
				cout << "Wrong guess!\n";
				allowedAttempts = allowedAttempts - 1;
			}
		}
		else
			cout << "Not a letter! Try again!\n";
	}
}

//The game
void game(int attemptsSetting, int lengthSetting) {
	printHeadlineMessage("Game started!");

	int remainingUnguessedLetters = 0;
	int idNumberOfWord = selectTheWordToGuess(lengthSetting, remainingUnguessedLetters);

	while (true) {
		if (remainingUnguessedLetters == 0) {
			system("cls");
			printHeadlineMessage("YOU WIN!");

			cout << "\nThe word was: ";
			printTheWord(idNumberOfWord, lengthSetting);

			break;
		}

		if (attemptsSetting == 0) {
			system("cls");
			printHeadlineMessage("YOU LOSE!");

			cout << "\nThe word was: ";
			printTheWord(idNumberOfWord, lengthSetting);

			break;
		}
		
		makeAGuess(idNumberOfWord, attemptsSetting, remainingUnguessedLetters);
	}
}

//Main menu (play a game, change settings, exit)
void mainMenu(int allowedAttempts, int lengthIndex) {
	system("cls");
	printHeadlineMessage("Hangman: Main menu");

	cout << "Select one of the following options: " << endl;
	cout << "1. Start a new game\n2. Settings\n3. Exit\n\n";

	int choice = inputInteger(1, 3);

	system("cls");

	switch (choice) {
		case 1: {
			int keepAttempts = allowedAttempts;

			game(allowedAttempts, lengthIndex);

			cout << endl;
			system("pause");

			setToNull(allowedAttempts, keepAttempts); //After finishing the game, all settings are reset

			mainMenu(allowedAttempts, lengthIndex);

			break;
		}
		case 2: {
			printHeadlineMessage("Hangman: Settings");
			cout << "Select one of the following options:\n";
			cout << "1 - Change the length of the words\n2 - Change the ammount of attempts\n3 - Return to main menu\n\n";

			int decision = inputInteger(1, 3);

			if (decision == 1) {
				lengthIndex = setWordLength(lengthIndex);

				system("cls");

				cout << "Setting saved!\n";
				system("pause");
			}
			else if (decision == 2) {
				allowedAttempts = setAmmountOfAttempts(allowedAttempts);

				system("cls");

				cout << "Setting saved!\n";
				system("pause");
			}

			mainMenu(allowedAttempts, lengthIndex);

			break;
		}
		case 3: {
			cout << "Are you sure you want to exit?\n";
			cout << "1 - Accept / 0 - Cancel\n\n";

			int selection = inputInteger(0, 1);

			if (selection == 1) {
				system("cls");
				printHeadlineMessage("Goodbye! Thanks for playing!");
			}
			else
				mainMenu(allowedAttempts, lengthIndex);

			break;
		}
	}
}