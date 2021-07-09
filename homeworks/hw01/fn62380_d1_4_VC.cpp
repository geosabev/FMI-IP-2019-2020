/**
*
* Solution to homework assignment 1
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

//Tested on Intel(R) Core(TM) i9 - 8950HK CPU @ 2.90GHz

#include <iostream>
using namespace std;

int main()
{
	int number;
	bool inputIsValid = false;

	do //Input validation
	{
		cout << "Enter a number: ";
		cin >> number;
		if (cin.good())
		{
			if (number >= 1 && number <= 65535)
			{
				inputIsValid = true;
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
			inputIsValid = false;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Try again." << endl;
		}
	} while (inputIsValid != true);

	for (int i = number; i >= 0; i--)
	{
		cout << i;
		for (int k = 1; k <= 147896325; k++)
		{
			int a = k % 2;
		}
		system("cls"); 
	}
	cout << "Finish." << endl;
}