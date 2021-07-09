/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Georgi Sabev
* @idnumber 62380
* @task 6
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
using namespace std;

bool InWhiteCircle(float x, float y) //If the lenght of the line between the centre and the point is not more than 2, the point lies in the white circle
{
	float line = sqrt((x * x) + (y * y));
	if (line < 2) return 1;
	else return 0;
}

bool InBlackSquare(float x, float y)
{
	if ((x > -1 && x < 1) && (y > -1 && y < 1))
		return 1;
	else
		return 0;
}

bool InBlackCircle(float x, float y) //If the lenght of the line between the centre and the point is between 2 and 3, the point lies in the black circle 
{
	float line = sqrt((x * x) + (y * y));	
	if (line > 2 && line < 3) return 1;
	else return 0;
}

bool Outside(float x, float y)
{
	float line = sqrt((x * x) + (y * y));
	if (line > 3) return 1;
	else return 0;
}

int main()
{
	float x, y;
	bool inputIsValid = false;

	do //Input validation
	{
		cout << "Enter coordinates of the point (X, Y): ";
		cin >> x >> y;

		if (cin.good())
		{
			inputIsValid = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Try again." << endl << endl;
		}
	} while (inputIsValid != true);

	if (InWhiteCircle(x, y) == 1)
	{
		if (InBlackSquare(x, y) == 1)
		{
			cout << "Black";
			return 0;
		}
		else if (x == 1 || x == -1)
		{
			if (y >= -1 && y <= 1)
			{
				cout << "Undefined";
				return 0;
			}
			else
			{
				cout << "White";
				return 0;
			}
		}
		else if (y == 1 || y == -1)
		{
			if (x >= -1 && x <= 1)
			{
				cout << "Undefined";
				return 0;
			}
			else
			{
				cout << "White";
				return 0;
			}
		}
		else
		{
			cout << "White";
			return 0;
		}
	}
	else if (InBlackCircle(x, y) == 1)
	{
		cout << "Black";
		return 0;
	}
	else if (Outside(x, y) == 1)
	{
		cout << "Outside";
		return 0;
	}
	else cout << "Undefined"; //If the point is neither in the black square nor the white and black circles, it is outside
}