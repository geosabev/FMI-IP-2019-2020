/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 5
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double a, b, c, discriminant, y1, y2;

	bool inputIsValid = false;

	bool group1AreComplex = false, group2AreComplex = false;

	do
	{
		cout << "Enter a, b and c: ";
		cin >> a >> b >> c;
		if (cin.good())
		{
			if (a != 0)
			{
				inputIsValid = true;
			}
			else
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Parameter 'a' cannot be equal to 0. Try again!" << endl;
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

	discriminant = (b * b) - (4 * a * c);

	if (discriminant < 0)
	{
		cout << "All roots are complex!" << endl;
		return 0;
	}

	y1 = ((-b + sqrt(discriminant)) / (2 * a));
	y2 = ((-b - sqrt(discriminant)) / (2 * a));

	if (y1 > 0)
	{
		cout << "X1 = " << sqrt(y1) << endl;
		cout << "X2 = " << (-sqrt(y1)) << endl;
	}
	else if (y1 == 0)
	{
		cout << "X1 = X2 = 0" << endl;
	}
	else
	{
		if (y2 < 0)
		{
			cout << "All roots are complex!" << endl;
			return 0;
		}
		else 
			cout << "X1 and X2 are complex numbers." << endl;
	}

	if (y2 > 0)
	{
		cout << "X3 = " << sqrt(y2) << endl;
		cout << "X4 = " << (-sqrt(y2)) << endl;
	}
	else if (y2 == 0)
	{
		cout << "X3 = X4 = 0" << endl;
	}
	else
	{
		if (y1 < 0)
			return 0;
		else
			cout << "X3 and X4 are complex numbers." << endl;
	}
}