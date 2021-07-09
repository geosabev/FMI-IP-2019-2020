/**
*
* Solution to homework assignment 3
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

//Instead of strlen; calculates ammount of symbols in a string
int calculateStringLength(char str[]) {
	int position = 0, counter = 0;

	while (str[position] != '\0') {
		counter++;
		position++;
	}

	return counter;
}

//Instead of strcpy; copies one string into another
void copyStringIntoString(char source[], char destination[]) {
	int lengthOfSource = calculateStringLength(source);
	for (int i = 0; i < lengthOfSource; i++)
		destination[i] = source[i];
	destination[lengthOfSource] = '\0';
}

//Checks if a given string number is a 0
bool isZero(char str[]) {
	int length = calculateStringLength(str);

	if (length == 1 && str[0] == '0')
		return 1;

	return 0;
}

//Checks if a given symbol is '+', '-' or '*'
bool isOperationSymbol(char symbol) {
	return (symbol == '+' || symbol == '-' || symbol == '*');
}

//Checks if a given symbol is a digit
bool isCharDigit(char symbol) {
	return (symbol >= '0' && symbol <= '9');
}

//Checks if a given string number is negative
bool isNegative(char str[]) {
	if (str[0] == '-')
		return 1;
	else
		return 0;
}

//Checks if two given string numbers are both positive
bool bothArePositive(char str1[], char str2[]) {
	return (isNegative(str1) == false && isNegative(str2) == false);
}

//Checks if two given string numbers are both negative
bool bothAreNegative(char str1[], char str2[]) {
	return (isNegative(str1) && isNegative(str2));
}

//Input validation: an arithmetic operation symbol
char inputOperation() {
	char inputStr[256], operationSymbol = '*';
	bool correctInput = false;

	while (correctInput == false) {
		cout << "Input operation: ";

		cin >> inputStr;
		int inputLength = calculateStringLength(inputStr);

		if (inputLength != 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not an operation symbol! Try again!\n";
		}
		else if (isOperationSymbol(inputStr[0]) == true) {
			operationSymbol = inputStr[0];
			correctInput = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Not an operation symbol! Try again!\n";
		}
	}

	return operationSymbol;
}

//Input validation: a string number
void inputStringNumber(char* str) {
	char inputStr[101];
	bool correctInput = false;
	int lengthOfCorrectInput = 0;

	while (correctInput == false) {
		cin >> inputStr;
		int inputLength = calculateStringLength(inputStr);

		int count = 0;

		for (int i = 0; i < inputLength; i++) {
			if (isCharDigit(inputStr[i]) == false && isNegative(inputStr) == false) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Not a number! Try again!\n";
				break;
			}
			else count++;
		}

		if (count == inputLength) {
			lengthOfCorrectInput = inputLength;
			correctInput = true;
		}
		else
			count = 0;
	}

	for (int i = 0; i < lengthOfCorrectInput; i++)
		str[i] = inputStr[i];

	str[lengthOfCorrectInput] = '\0';
}

//Converts a digit-symbol to a digit-integer
int convertCharDigitToInt(char symbol) {
	return (symbol - '0');
}

//Compares two string numbers: 1 - the first is bigger, 2 - the second is bigger
int compareTwoStringNumbers(char str1[], char str2[]) {
	int length1 = calculateStringLength(str1);
	int length2 = calculateStringLength(str2);

	bool negative = false;

	int bigger = 0;

	if (isNegative(str1) == true && isNegative(str2) == false)
		return 2;
	else if (isNegative(str1) == false && isNegative(str2) == true)
		return 1;
	else if (isNegative(str1) == true && isNegative(str2) == true) {
		if (length1 < length2)
			return 1;
		else if (length1 > length2)
			return 2;
		negative = true;
	}
	else {
		if (length1 < length2)
			return 2;
		else if (length1 > length2)
			return 1;
	}

	for (int i = length1 - 1; i >= 0; i--) {
		int digit1 = convertCharDigitToInt(str1[i]);
		int digit2 = convertCharDigitToInt(str2[i]);

		if (negative) {
			if (digit1 > digit2)
				bigger = 2;
			else if (digit1 < digit2)
				bigger = 1;
		}
		else {
			if (digit1 > digit2)
				bigger = 1;
			else if (digit1 < digit2)
				bigger = 2;
		}
	}

	return bigger;
}

//Converts a digit-integer to a digit-symbol
char convertIntDigitToChar(int digit) {
	return (digit + '0');
}

//Finds the absolute value of a string number
void findAbsoluteValue(char str[], char destination[]) {
	int lengthOfString = calculateStringLength(str);

	if (str[0] == '-') {
		for (int i = 0; i < lengthOfString - 1; i++)
			destination[i] = str[i + 1];
		destination[lengthOfString - 1] = '\0';
	}
	else {
		for (int i = 0; i < lengthOfString; i++)
			destination[i] = str[i];
		destination[lengthOfString] = '\0';
	}
}

//Reverses a given string
char* reverseString(char str[]) {
	char reversedString[101];

	int lengthOfGivenString = calculateStringLength(str);

	for (int i = 0; i < lengthOfGivenString; i++)
		reversedString[i] = str[lengthOfGivenString - (i + 1)];
	reversedString[lengthOfGivenString] = '\0';

	for (int i = 0; i <= lengthOfGivenString; i++)
		str[i] = reversedString[i];

	return str;
}

//The operation addition
char* addition(char str1[], char str2[]) {
	int length1 = calculateStringLength(str1);
	int length2 = calculateStringLength(str2);

	char absStr1[101], absStr2[101];
	findAbsoluteValue(str1, absStr1);
	findAbsoluteValue(str2, absStr2);

	int biggerLength = 0;

	char sum[200];
	bool addOneToTheNext = false;

	copyStringIntoString(reverseString(absStr1), str1);
	copyStringIntoString(reverseString(absStr2), str2);

	if (length1 < length2)
		biggerLength = calculateStringLength(str2);
	else
		biggerLength = calculateStringLength(str1);

	for (int i = 0; i < biggerLength; i++) {
		int digit1 = 0, digit2 = 0;

		if (isCharDigit(str1[i]))
			digit1 = convertCharDigitToInt(str1[i]);

		if (isCharDigit(str2[i]))
			digit2 = convertCharDigitToInt(str2[i]);

		int currentSum = digit1 + digit2;

		if (addOneToTheNext == true)
			currentSum++;

		if (currentSum > 9) {
			currentSum = currentSum - 10;
			addOneToTheNext = true;
		}
		else
			addOneToTheNext = false;

		sum[i] = convertIntDigitToChar(currentSum);
	}

	if (addOneToTheNext == true) {
		sum[biggerLength] = '1';
		sum[biggerLength + 1] = '\0';
	}
	else
		sum[biggerLength] = '\0';

	copyStringIntoString(reverseString(sum), sum);
	
	for (int i = 0; i < calculateStringLength(sum); i++)
		str1[i] = sum[i];

	str1[calculateStringLength(sum)] = '\0';

	return str1;
}

//The operation subtraction
char* subtraction(char str1[], char str2[]) {
	int length1 = calculateStringLength(str1);
	int length2 = calculateStringLength(str2);

	int biggerLength = 0;

	char absStr1[101], absStr2[101];
	findAbsoluteValue(str1, absStr1);
	findAbsoluteValue(str2, absStr2);

	char difference[101];
	bool removeOneFromTheNext = false;

	copyStringIntoString(reverseString(absStr1), str1);
	copyStringIntoString(reverseString(absStr2), str2);

	if (length1 < length2)
		biggerLength = calculateStringLength(str2);
	else
		biggerLength = calculateStringLength(str1);

	for (int i = 0; i < biggerLength; i++) {
		int digit1 = 0, digit2 = 0;

		if (isCharDigit(str1[i]))
			digit1 = convertCharDigitToInt(str1[i]);

		if (isCharDigit(str2[i]))
			digit2 = convertCharDigitToInt(str2[i]);

		int currentDiff = digit1 - digit2;

		if (removeOneFromTheNext == true)
			currentDiff--;

		if (currentDiff < 0) {
			currentDiff = 10 + currentDiff;
			removeOneFromTheNext = true;
		}
		else
			removeOneFromTheNext = false;

		difference[i] = convertIntDigitToChar(currentDiff);
	}

	difference[biggerLength] = '\0';

	int lengthOfNew = calculateStringLength(difference);
	int currentPosOfFinalDigit = 0;

	for (int i = 0; i < lengthOfNew; i++) {
		if (isCharDigit(difference[i]) == true && difference[i] != '0')
			currentPosOfFinalDigit = i;
	}
	
	for (int i = 0; i <= currentPosOfFinalDigit; i++)
		str1[i] = difference[currentPosOfFinalDigit - i];

	str1[currentPosOfFinalDigit + 1] = '\0';

	return str1;
}

//The operation multiplication
char* multiplication(char str1[], char str2[]) {
	int length1 = calculateStringLength(str1);
	int length2 = calculateStringLength(str2);

	int result[1000];
	for (int i = 0; i < 1000; i++)
		result[i] = 0;

	int currentPosOfDigit1 = 0;
	int currentPosOfDigit2 = 0;

	int furthestPosition = 0;
	int newPosition = 0;

	for (int i = length1 - 1; i >= 0; i--) {
		int digit1 = convertCharDigitToInt(str1[i]);
		int addToTheNext = 0;

		currentPosOfDigit2 = 0;

		for (int j = length2 - 1; j >= 0; j--) {
			int digit2 = convertCharDigitToInt(str2[j]);

			newPosition = currentPosOfDigit1 + currentPosOfDigit2;

			int currentSum = (digit1 * digit2) + result[newPosition] + addToTheNext;

			addToTheNext = currentSum / 10;

			result[newPosition] = currentSum % 10;

			if (newPosition > furthestPosition)
				furthestPosition = newPosition;

			currentPosOfDigit2++;

			if (currentPosOfDigit1 + currentPosOfDigit2 > furthestPosition)
				furthestPosition = currentPosOfDigit1 + currentPosOfDigit2;
		}

		if (addToTheNext > 0)
			result[currentPosOfDigit1 + currentPosOfDigit2] = result[currentPosOfDigit1 + currentPosOfDigit2] + addToTheNext;

		currentPosOfDigit1++;
	}

	int positionInCharProduct = 0;

	if (result[furthestPosition] == 0)
		furthestPosition--;
	
	char product[1000];

	for (int i = furthestPosition; i >= 0; i--) {
		product[positionInCharProduct] = convertIntDigitToChar(result[i]);
		positionInCharProduct++;
	}

	product[positionInCharProduct] = '\0';

	if (isZero(str1) == true || isZero(str2) == true) {
		product[0] = '0';
		product[1] = '\0';
	}

	copyStringIntoString(product, str1);

	return str1;
}

//Calculates the given task
void doTheOperation(char str1[], char str2[], char operation) {
	char absoluteStr1[101], absoluteStr2[101];

	int len1 = calculateStringLength(str1);
	int len2 = calculateStringLength(str2);

	findAbsoluteValue(str1, absoluteStr1);
	findAbsoluteValue(str2, absoluteStr2);

	int comparisonResult = compareTwoStringNumbers(absoluteStr1, absoluteStr2);

	switch (operation) {
	case '+':
		if (bothArePositive(str1, str2) == true)
			cout << addition(str1, str2);
		else if (bothAreNegative(str1, str2) == true)
			cout << '-' << addition(str1, str2);
		else if (isNegative(str1) == true && isNegative(str2) == false) {
			if (comparisonResult == 1)
				cout << '-' << subtraction(absoluteStr1, str2);
			else if (comparisonResult == 2)
				cout << subtraction(absoluteStr2, str1);
			else
				cout << 0;
		}
		else {
			if (comparisonResult == 1)
				cout << subtraction(str1, absoluteStr2);
			else if (comparisonResult == 2)
				cout << '-' << subtraction(absoluteStr2, str1);
			else
				cout << 0;
		}
		break;

	case '-':
		if (bothArePositive(str1, str2) == true) {
			if (comparisonResult == 1)
				cout << subtraction(str1, str2);
			else if (comparisonResult == 2)
				cout << '-' << subtraction(str2, str1);
			else cout << 0;
		}
		else if (bothAreNegative(str1, str2) == true) {
			if (comparisonResult == 1)
				cout << '-' << subtraction(absoluteStr1, absoluteStr2);
			else if (comparisonResult == 2)
				cout << subtraction(absoluteStr2, absoluteStr1);
			else cout << 0;
		}
		else if (isNegative(str1) == false && isNegative(str2) == true)
			cout << addition(str1, absoluteStr2);
		else
			cout << '-' << addition(absoluteStr1, str2);
		break;

	case '*':
		if (bothArePositive(str1, str2) == true || bothAreNegative(str1, str2) == true)
			cout << multiplication(absoluteStr1, absoluteStr2);
		else
			cout << '-' << multiplication(absoluteStr1, absoluteStr2);
		break;
	}
}

int main() {
	char number1[101], number2[101], operation;

	operation = inputOperation();

	cout << "First number: ";
	inputStringNumber(number1);

	cout << "Second number: ";
	inputStringNumber(number2);

	cout << "\nResult: ";
	doTheOperation(number1, number2, operation);
}