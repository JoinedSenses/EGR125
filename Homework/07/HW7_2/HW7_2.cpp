/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 1, 2019
 Name: Arron Vinyard
 Project Description: Returns the sum of all elements in a specified 2d array column
 Inputs: 3-by-4 matrix
 Outputs: Sum of elements at each column
**************************************************************/
#include <iostream>

using namespace std;

const int SIZE = 4;
double sumColumn(const double[][SIZE], int, int);

int main() {
	const int ROWS = 3;
	double arr[ROWS][SIZE];

	// Prompt for input and initialize the array
	cout << "Enter a 3-by-4 matrix row by row:" << endl;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> arr[i][j];
		}
	}

	// Loop through each column and print column sum
	for (int i = 0; i < SIZE; i++) {
		cout << "Sum of elements at column " << i << " is " << sumColumn(arr, ROWS, i) << endl;
	}

	return 0;
}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex) {
	double sum = 0;

	if (0 <= columnIndex && columnIndex < SIZE) {
		for (int i = 0; i < rowSize; i++) {
			sum += m[i][columnIndex];
		}
	}

	return sum;
}