/**
*
* Solution to homework assignment 1
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

bool leapYearCheck(int yearToCheck) //This function checks if the year is loop
{
	if (yearToCheck % 4 == 0)
	{
		if (yearToCheck % 100 == 0)
		{
			if (yearToCheck % 400 == 0) return 1;
			else return 0;
		}
		else return 1;
	}
	else return 0;
}

int main()
{
	int ammountOfDays = ValidInput(0, 1000000);

	while (ammountOfDays == 0) //Zero days cannot pass, the input is invalid!
	{
		cout << "There is no such thing as 0th day. Invalid input! Try again." << endl;
		ammountOfDays = ValidInput(0, 1000000);
	}

	int counterOfYears = 0; //Stores the ammount of days passed;

	while (ammountOfDays > 0)
	{
		counterOfYears = counterOfYears + 1;

		if (leapYearCheck(counterOfYears) == 1) //If the year is leap, it has 366 days; if not: 365;
		{
			ammountOfDays = ammountOfDays - 366;
		}

		else
		{
			ammountOfDays = ammountOfDays - 365;
		}
	}

	cout << endl << "Current year: " << counterOfYears;
}