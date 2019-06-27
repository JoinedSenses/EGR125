/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Solves a polynomial function up to the 5th order
 Inputs: Order, x, coefficients
 Outputs: Polynomial solution
**************************************************************/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Solves a polynomial function
 * Inputs: order, x, array of coefficients
 */
double Poly(int, double, double*);

int main() {
	int order;
	double x, *A;
	bool invalid;
	string exp = "";

	cout << "This program solves a polynomial function up to the 5th order." << endl;
	cout << "y = A0 + A1x + A2x^2 + A3x^3 + A4x^4 + A5x^5" << endl;

	// Loop until valid order input
	do {
		cout << "Enter the order you would like to solve (1-5): ";
		invalid = false;
		cin >> order;
		cin.ignore(100, '\n');
		if (order < 1 || order > 5) {
			invalid = true;
			cout << "Error: Invalid input. ";
		}
	} while (invalid);

	A = new double[order + 1](); // Create and initialize dynamic array

	cout << "Enter a value for x: ";
	cin >> x;
	cin.ignore(100, '\n');

	// Loop for each coefficient and store in array
	for (int i = 0; i <= order; i++) {
		cout << "Enter a value for A" << i << ": ";
		cin >> A[i];
		cin.ignore(100, '\n');
	}

	// Display input as equation
	cout << A[0];
	for (int i = 1; i <= order; i++) {
		cout << " + " << A[i] << '(' << x;
		if (i > 1) {
			cout << '^' << i;
		}
		cout << ')';
	}

	// Solve and Display
	cout << " = " << Poly(order, x, A) << endl;

	delete[] A; // Free memory
	return 0;
}

double Poly(int order, double x, double* A) {
	double result = 0;
	for (int i = 0; i <= order; i++) result += A[i] * pow(x, i);
	return result;
}