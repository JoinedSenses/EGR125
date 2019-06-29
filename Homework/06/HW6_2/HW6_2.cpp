/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 29, 2019
 Project Description: Calls functions on arrays and displays results
 Inputs: None
 Outputs: Function outputs
**************************************************************/
#include <iostream>
#include <string>
#include "myLibrary.h"
using namespace std;

// ========
int main() {
	int count;
	double vec[] = { 3, -1, 4, 10 };
	int A[] = { 1, 2, 3, 4, 5, 6, 7 };
	int B[] = { 8, 9, 10, 11, 12, 13, 14 };
	int C[] = { 10, 20, 30, 40, 50 };
	const char contentsOfArr[] = "The contents of array ";

	// Part A. Displays length of test vector
	count = sizeof(vec) / sizeof(vec[0]); // Number of indexes in single dim arr
	cout << "Length of vector " << toString(vec, count) << " is " << getVectorLength(vec, count) << endl << endl;

	// Part B. Display and perform swap
	count = sizeof(A) / sizeof(A[0]);
	cout << contentsOfArr << "A before swap: " << toString(A, count) << endl;
	cout << contentsOfArr << "B before swap: " << toString(B, count) << endl << endl;
	Swap(A, B, count);
	cout << contentsOfArr << "A after swap:  " << toString(A, count) << endl;
	cout << contentsOfArr << "B after swap:  " << toString(B, count) << endl << endl;

	// Part C. Display and perform reverse
	count = sizeof(C) / sizeof(C[0]);
	cout << contentsOfArr << "C before reverse: " << toString(C, count) << endl;
	Reverse(C, count);
	cout << contentsOfArr << "C after reverse:  " << toString(C, count) << endl;

	return 0;
}