/**
*
* Solution to homework assignment 2
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
using namespace std;

const int MAX_SIZE = 10;
bool solutionFound = 0; //To stop generating permutations, becomes 'true' when first solution is found and printed

void swapTwoRowsOfAMatrix(int matrix[][MAX_SIZE], int size, int row1, int row2) {
	for (int i = 0; i < size; i++) {
		int tempStorage = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = tempStorage;
	}
}

//Checks if the main diagonal in the current permutation is sorted 
bool diagonalIsOkay(int arr[][MAX_SIZE], int sizeOfMatrix) {
	for (int i = 0; i < sizeOfMatrix - 1; i++) {
		if (arr[i][i] <= arr[i + 1][i + 1])
			continue;
		else
			return 0;
	}
	return 1;
}

void printMatrix(int arr[][MAX_SIZE], int sizeOfMatrix) {
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

//Recursive function which generates permutations of a given matrix
void generatePermutationsOfRows(int arr[][MAX_SIZE], int sizeOfMatrix, int start, int end) {
	if (start == end) {
		//Stops generating permutations when the first solution of the task is found
		if (diagonalIsOkay(arr, end) && solutionFound == 0) {
			cout << endl;

			printMatrix(arr, end);

			solutionFound = 1;
		}
	}
	else {
		generatePermutationsOfRows(arr, sizeOfMatrix, start + 1, end);

		for (int i = start + 1; i < end; i++) {
			if (start == i) continue;

			swapTwoRowsOfAMatrix(arr, sizeOfMatrix, start, i);

			generatePermutationsOfRows(arr, sizeOfMatrix, start + 1, end);

			swapTwoRowsOfAMatrix(arr, sizeOfMatrix, start, i);
		}
	}
}

void reorderMatrixDiagonal(int arr[][MAX_SIZE], int sizeOfMatrix) {
	generatePermutationsOfRows(arr, sizeOfMatrix, 0, sizeOfMatrix);
}

int main() {
	int arr[MAX_SIZE][MAX_SIZE], N;

	//Input validation for N (between 1 and 10)
	do {
		cout << "Size of matrix: ";
		cin >> N;

		if (N < 1 || N > MAX_SIZE)
			cout << "N should be between 1 and 10! Try again!" << endl;
		else
			break;
	} while (true);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	reorderMatrixDiagonal(arr, N);

	//A message in case of unpossible reorder of the given matrix
	if (solutionFound == 0)
		cout << "There is no possible solution!";
}