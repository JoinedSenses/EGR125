/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 29, 2019
 Project Description: Finds the smallest value in a double array
 Inputs: None
 Outputs: Smallest value in array
**************************************************************/
#include <iostream>
using namespace std;

double min(double[], int);

int main() {
	double arr[10];
	// Prompt for input and return min
	cout << "Enter ten numbers: ";
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}
	cout << "The minimum number is " << min(arr, 10);
	return 0;
}

double min(double array[], int size) {
	double minimum = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] < minimum) {
			minimum = array[i];
		}
	}
	return minimum;
}