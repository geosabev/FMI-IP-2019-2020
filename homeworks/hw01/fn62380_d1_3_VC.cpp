/**
*
* Solution to homework assignment 1
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
#include <math.h>
using namespace std;

bool isAnOperator(char symbol) //Checks if the given symbol is a mathematical operation
{
	return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%');
}

bool isANumber(char number) //Checks if the given symbol is a digit in the ASCII Table
{
	return (number >= 48 && number <= 57);
}

bool isACapitalLetter(char number) //Checks if the given symbol is a capital letter in the ASCII Table
{
	return (number >= 65 && number <= 70);
}

int hexadecimalToDecimal(char hexNumber) //Converts CORRECT symbols to their decimal form;
{
	switch (hexNumber)
	{
	case '0':
	{
		return 0;
	}
	case '1':
	{
		return 1;
	}
	case '2':
	{
		return 2;
	}
	case '3':
	{
		return 3;
	}
	case '4':
	{
		return 4;
	}
	case '5':
	{
		return 5;
	}
	case '6':
	{
		return 6;
	}
	case '7':
	{
		return 7;
	}
	case '8':
	{
		return 8;
	}
	case '9':
	{
		return 9;
	}
	case 'A':
	{
		return 10;
	}
	case 'B':
	{
		return 11;
	}
	case 'C':
	{
		return 12;
	}
	case 'D':
	{
		return 13;
	}
	case 'E':
	{
		return 14;
	}
	case 'F':
	{
		return 15;
	}
	}
}

int doTheOperation(char operation, int number1, int number2) //Calculates the result of the operation between the two decimal numbers
{
	switch (operation)
	{
	case '+':
	{
		return (number1 + number2);
	}
	case '-':
	{
		return (number1 - number2);
	}
	case '*':
	{
		return (number1 * number2);
	}
	case '/':
	{
		return (number1 / number2);
	}
	case '%':
	{
		return (number1 % number2);
	}
	}
}

void decimalToHexadecimal(int decNumber) //Converts and displays a number from decimal to hexadecimal
{
	switch (decNumber)
	{
	case 0:
	{
		cout << 0;
		break;
	}
	case 1:
	{
		cout << 1;
		break;
	}
	case 2:
	{
		cout << 2;
		break;
	}
	case 3:
	{
		cout << 3;
		break;
	}
	case 4:
	{
		cout << 4;
		break;
	}
	case 5:
	{
		cout << 5;
		break;
	}
	case 6:
	{
		cout << 6;
		break;
	}
	case 7:
	{
		cout << 7;
		break;
	}
	case 8:
	{
		cout << 8;
		break;
	}
	case 9:
	{
		cout << 9;
		break;
	}
	case 10:
	{
		cout << 'A';
		break;
	}
	case 11:
	{
		cout << 'B';
		break;
	}
	case 12:
	{
		cout << 'C';
		break;
	}
	case 13:
	{
		cout << 'D';
		break;
	}
	case 14:
	{
		cout << 'E';
		break;
	}
	case 15:
	{
		cout << 'F';
		break;
	}
	}
}

int main()
{
	char firstNumber, secondNumber, operation;
	bool validInput = false;

	while (validInput != true) //Input validation
	{
		cout << "Enter an operator and two hexadecimal numbers:" << endl;
		cin >> operation >> firstNumber >> secondNumber;

		if (isAnOperator(operation) && (isACapitalLetter(firstNumber) || isANumber(firstNumber))
			&& (isACapitalLetter(secondNumber) || isANumber(secondNumber)))
			validInput = true;
		else
			cout << endl << "Invalid input!" << endl << endl;
	}

	int decNumber1 = hexadecimalToDecimal(firstNumber);
	int decNumber2 = hexadecimalToDecimal(secondNumber);

	if(decNumber2 == 0 && (operation == '/' || operation == '%'))
	{
		cout << "Division by 0 is not possible!" << endl;
		return 0;
	}
	else
	{
		int result = doTheOperation(operation, decNumber1, decNumber2);

			/*The maximum ammount of digits the new number can have is 3!
			* This can easily be calculated: F = 15, F * F = 225;
			* Then, when dividing the number by 16 and saving the remainder, there ...
			* can only be 2 decimal numbers;
			*
			* Therefore, there are only two variables for the digits - decDigit1 and decDigit2.
			*/
			int decDigit1 = (abs(result) / 16) % 16;
		int decDigit2 = abs(result) % 16;

		cout << endl;

		cout << "Result = ";
		if (result < 0) //If the number is negative, prints a '-' on the console
		{
			cout << '-';
		}

		if (decDigit1 != 0)
		{
			decimalToHexadecimal(decDigit1);
		}
		decimalToHexadecimal(decDigit2);
	}
}