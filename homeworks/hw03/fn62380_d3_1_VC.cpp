/**
*
* Solution to homework assignment 3
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
#include <random>
using namespace std;

const int AMMOUNT_OF_QUESTIONS = 10;
const int MAX_LENGTH_OF_QUESTION = 1000;
const int MAX_LENGTH_OF_ANSWER = 1000;
const int DISTANCE_BETWEEN_SMALL_AND_CAPITAL_LETTER = 32;

bool stopTheGame = false;
bool usedLifeline = false;

bool availabilityOfAnswers[4] = { 1,1,1,1 };

struct Question {
	char question[MAX_LENGTH_OF_QUESTION];
	char answerOne[MAX_LENGTH_OF_ANSWER];
	char answerTwo[MAX_LENGTH_OF_ANSWER];
	char answerThree[MAX_LENGTH_OF_ANSWER];
	char answerFour[MAX_LENGTH_OF_ANSWER];
	int correctAnswerNumber;
};

Question quiz[AMMOUNT_OF_QUESTIONS]{
	{ "Adele performed the theme song to which James Bond film?",
		"Casino Royale", "Quantum of Solace", "Skyfall", "From Russia With Love", 3 },
	{ "Which of these antagonist characters was created by novelist J.K. Rowling?",
		"Lord Farqaad", "Professor Moriarty", "Darth Vader", "Lord Voldemort", 4 },
	{ "Which of these NBA franchises has never signed LeBron James?",
		"Miami Heat", "Los Angeles Lakers", "Cleveland Cavaliers", "Boston Celtics", 4 },
	{ "Which one of the following is the world's best-selling album of all time?",
		"AC/DC's 'Back in Black'", "Eagles' 'Their Greatest Hits (1971–1975)'",
		"Michael Jackson's 'Thriller'", "Pink Floyd's 'The Dark Side of the Moon'", 3 },
	{ "What is the largest planet in our Solar System?",
		"Earth", "Pluto", "Saturn", "Jupiter", 4 },
	{ "In which language was the book 'War and Peace' originally written?",
		"English", "German", "Russian", "French", 3 },
	{ "According to Persian folklore, who is the storyteller of 'One Thousand and One Nights'?",
		"Kanaan", "Scheherazade", "Hatshepsut", "Homer", 2 },
	{ "What restaurant franchise advises you to 'Eat Fresh'?",
		"Taco Bell", "Subway", "KFC", "McDonald's", 2 },
	{ "Which is the third biggest city in Bulgaria?",
		"Plovdiv", "Burgas", "Varna", "Stara Zagora", 2 },
	{ "Which one of the following is the best-selling video game in the world?",
		"Minecraft", "Grand Theft Auto V", "Tetris", "PlayerUnknown's Battlegrounds (PUBG)", 1 }
};

Question quiz5050[AMMOUNT_OF_QUESTIONS]{
	{ "Adele performed the theme song to which James Bond film?",
		"", "Quantum of Solace", "Skyfall", "", 3 },
	{ "Which of these antagonist characters was created by novelist J.K. Rowling?",
		"", "Professor Moriarty", "", "Lord Voldemort", 4 },
	{ "Which of these NBA franchises has never signed LeBron James?",
		"", "Los Angeles Lakers", "", "Boston Celtics", 4 },
	{ "Which one of the following is the world's best-selling album of all time?",
		"", "Eagles' 'Their Greatest Hits (1971–1975)'", "Michael Jackson's 'Thriller'", "", 3 },
	{ "What is the largest planet in our Solar System?",
		"", "", "Saturn", "Jupiter", 4 },
	{ "In which language was the book 'War and Peace' originally written?",
		"", "German", "Russian", "", 3 },
	{ "According to Persian folklore, who is the storyteller of 'One Thousand and One Nights'?",
		"Kanaan", "Scheherazade", "", "", 2 },
	{ "What restaurant franchise advises you to 'Eat Fresh'?",
		"Taco Bell", "Subway", "", "", 2 },
	{ "Which is the third biggest city in Bulgaria?",
		"Plovdiv", "Burgas", "", "", 2 },
	{ "Which one of the following is the best-selling video game in the world?",
		"Minecraft", "", "Tetris", "", 1 }
};

//Checks if a symbol is one of the letters between A and D (small or capital)
bool isLetterFromAToD(char symbol) {
	return ((symbol >= 'A' && symbol <= 'D') || (symbol >= 'a' && symbol <= 'd'));
}

//Checks if a symbol is the letter L (small or capital)
bool isTheLetterL(char symbol) {
	return (symbol == 'L' || symbol == 'l');
}

//Error message in case of invalid input
void printErrorForBadInput() {
	cout << "Invalid input! Try again!" << endl;
}

//Prints a message with some kind of decoration
void printHeadlineMessage(const char message[100]) {
	int length = strlen(message);

	for (int i = 0; i < length; i++)
		cout << "-";

	cout << endl << message << endl;

	for (int i = 0; i < length; i++)
		cout << "-";

	cout << endl;
}

//Prints a given question and the possible answers
void printTheQuestion(int idOfQuestion) {
	cout << quiz[idOfQuestion].question << endl;
	cout << "A. " << quiz[idOfQuestion].answerOne << endl;
	cout << "B. " << quiz[idOfQuestion].answerTwo << endl;
	cout << "C. " << quiz[idOfQuestion].answerThree << endl;
	cout << "D. " << quiz[idOfQuestion].answerFour << endl;
}

//Prints the given question with two wrong answers eliminated
void printQuestionAfter5050(int idOfQuestion) {
	cout << quiz5050[idOfQuestion].question << endl;
	
	if(quiz5050[idOfQuestion].answerOne[0] != '\0')
		cout << "A. " << quiz5050[idOfQuestion].answerOne << endl;
	
	if (quiz5050[idOfQuestion].answerTwo[0] != '\0')
		cout << "B. " << quiz5050[idOfQuestion].answerTwo << endl;
	
	if (quiz5050[idOfQuestion].answerThree[0] != '\0')
		cout << "C. " << quiz5050[idOfQuestion].answerThree << endl;
	
	if (quiz5050[idOfQuestion].answerFour[0] != '\0')
		cout << "D. " << quiz5050[idOfQuestion].answerFour << endl;
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

//Input validation for small or capital letters between A and D; returns position in alphabet (1 to 4)
int inputLetter() {
	char input[1000];

	do {
		cout << "Choice: ";

		cin >> input;

		int length = strlen(input);

		if (length == 1) {
			if (isLetterFromAToD(input[0]))
				break;
			else if (isTheLetterL(input[0])) {
				if (usedLifeline == false)
					return input[0];
				else {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You already used it!\n";
				}
			}
			else {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				printErrorForBadInput();
			}
		}
		else {
			cin.clear();
			cin.ignore(1000, '\n');
			printErrorForBadInput();
		}
	} while (true);

	return (input[0] - 'A' + 1);
}

//Generates a random number from minValue to maxValue
int generateRandomNumber(int minValue, int maxValue) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(minValue, maxValue);

	return dist6(rng);
}

//Randomly gets the id of one of the questions
int selectRandomQuestion() {
	int idOfQuestion = generateRandomNumber(0, AMMOUNT_OF_QUESTIONS - 1);

	return idOfQuestion;
}

//Eliminates two wrong answers of a question
void useFiftyFifty(int idNumberOfQuestion) {
	usedLifeline = true;
	
	if (quiz5050[idNumberOfQuestion].answerOne[0] == '\0')
		availabilityOfAnswers[0] = false;
	else
		availabilityOfAnswers[0] = true;

	if (quiz5050[idNumberOfQuestion].answerTwo[0] == '\0')
		availabilityOfAnswers[1] = false;
	else
		availabilityOfAnswers[1] = true;

	if (quiz5050[idNumberOfQuestion].answerThree[0] == '\0')
		availabilityOfAnswers[2] = false;
	else
		availabilityOfAnswers[2] = true;

	if (quiz5050[idNumberOfQuestion].answerFour[0] == '\0')
		availabilityOfAnswers[3] = false;
	else
		availabilityOfAnswers[3] = true;

	system("cls");

	printHeadlineMessage("Who Wants to Be a Millionaire?");

	printQuestionAfter5050(idNumberOfQuestion);

	cout << "\nYou activated your lifeline '50/50'!\nTwo wrong answers were eleminated!\n\n";

}

//Prints the correct answer of a given question
void printCorrectAnswer(int idOfQuestion) {
	cout << "The correct answer is: ";

	switch (quiz[idOfQuestion].correctAnswerNumber) {
	case 1: {
		cout << quiz[idOfQuestion].answerOne;
		break;
	}
	case 2: {
		cout << quiz[idOfQuestion].answerTwo;
		break;
	}
	case 3: {
		cout << quiz[idOfQuestion].answerThree;
		break;
	}
	case 4: {
		cout << quiz[idOfQuestion].answerFour;
		break;
	}
	}
}

//The user selects one of the possible answers; returns 1 if correct, 0 if wrong
bool answerTheQuestion(int idNumberOfQuestion) {
	int userAnswer = inputLetter();

	if (isTheLetterL(char(userAnswer))) {
		useFiftyFifty(idNumberOfQuestion);

		do {
			userAnswer = inputLetter();
		} while (availabilityOfAnswers[userAnswer - 1] == false);
	}

	if (userAnswer == quiz[idNumberOfQuestion].correctAnswerNumber)
		return 1;
	else
		return 0;
}

//Prints a goodbye message and sets stopTheGame to true
void exitTheGame() {
	system("cls");

	printHeadlineMessage("Who Wants to Be a Millionaire?");

	cout << "Goodbye! Thank you for playing!\n";

	stopTheGame = true;
}

//Selects a random question, prints it and it's possible answers and asks the user to select one
void playTheGame() {
	printHeadlineMessage("Who Wants to Be a Millionaire?");

	int idOfQuestion = selectRandomQuestion();

	printTheQuestion(idOfQuestion);

	cout << "\n(Don't forget you can always use your lifeline 50/50 to remove 2 incorrect answers!)\n";
	cout << "Just type L to activate it!\n\n";

	bool userAnswer = answerTheQuestion(idOfQuestion);

	if (userAnswer == true)
		cout << "\nCorrect answer!";
	else {
		cout << "\nWrong answer! ";
		printCorrectAnswer(idOfQuestion);
	}

	cout << endl << endl;
	system("pause");

	usedLifeline = false;
	
	system("cls");
	printHeadlineMessage("Who Wants to Be a Millionaire?");

	cout << "Select one of the following options : " << endl;
	cout << "1. Another question\n2. Exit\n\n";

	int decision = inputInteger(1, 2);

	system("cls");

	if (decision == 1)
		playTheGame();
	else
		exitTheGame();
}

int main() {
	while (stopTheGame == 0) {
		system("cls");

		printHeadlineMessage("Who Wants to Be a Millionaire?");

		cout << "Select one of the following options: " << endl;
		cout << "1. Answer a question\n2. Exit\n\n";

		int selection = inputInteger(1, 2);

		system("cls");

		switch (selection) {
			//Play the game: user has to answer a given question
			case 1: {
				playTheGame();

				break;
			}
			//Exit the game
			case 2: {
				exitTheGame();

				break;
			}
		}
	}
}