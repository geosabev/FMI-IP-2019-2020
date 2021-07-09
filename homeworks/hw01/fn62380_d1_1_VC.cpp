/**
*
* Solution to homework assignment 1
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
using namespace std;

int ValidInput(int minValue, int maxValue) //Input validation
{
	int input = 0;
	bool valid = false;
	do
	{
		cout << "Enter a number: ";
		cin >> input;
		if (cin.good())
		{
			if (input >= minValue && input <= maxValue)
			{
				valid = true;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input! Try again." << endl;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Try again." << endl;
		}
	} while (valid != true);

	return input;
}

int main()
{
	int number, copyOfNumber;
	bool hasEqualDigits = false;

	number = ValidInput(INT_MIN, INT_MAX);

	copyOfNumber = number;

	while (number != 0)
	{
		int mainDigit = number % 10; //The last digit of the number

		copyOfNumber = number / 10; //Removes the saved digit from the copy-number

		while (copyOfNumber != 0) //The saved digit gets compared to each digit in the copy-number
		{
			int digitToCompare = copyOfNumber % 10;

			if (mainDigit == digitToCompare)
			{
				hasEqualDigits = true; //If the digits are equal, the loop stops
				break;
			}
			else
			{
				copyOfNumber = copyOfNumber / 10;
				digitToCompare = copyOfNumber % 10;
			}
		}

		if (hasEqualDigits == true) //If there are already equal digits, the main loop stops;
			break;

		number = number / 10;
		copyOfNumber = number / 10;
	}

	if (hasEqualDigits == true)
	{
		cout << endl << "Yes, there are equal digits!" << endl;
	}
	else
	{
		cout << endl << "No, there are no equal digits!" << endl;
	}
}