#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double Poly(double, double, double, double=0, double=0, double=0, double=0);

int main() {
	int order;
	double x, A[5] = {0};
	bool invalid;
	string exp = "";
	cout << "This program solves a polynomial function up to the 5th order." << endl;
	cout << "y = A0 + A1x + A2x^2 + A3x^3 + A4x^4 + A5x^5" << endl;
	cout << "Enter the order you would like to solve (1-5): " << endl;
	do {
		invalid = false;
		cin >> order;
		cin.ignore(100, '\n');
		if (order < 1 || order > 5) {
			invalid = true;
			cout << "Error: Invalid input. ";
		}
	} while (invalid);
	
	cout << "Enter a value for x: ";
	cin >> x;
	cin.ignore(100, '\n');
	
	for (int i = 0; i <= order; i++) {
		cout << "Enter a value for A" << i << ": ";
		cin >> A[i];
		cin.ignore(100, '\n');
	}
	
	cout << A[0];
	for (int i = 1; i <= order; i++) {
		cout << " + " << A[i] << '(' << x;
		if (i > 1) {
		    cout << '^' << i;
		}
		cout << ')';
	}
	
	cout << " = " << Poly(x, A[0], A[1], A[2], A[3], A[4], A[5]) << endl;
	return 0;
}

double Poly(double x, double A0, double A1, double A2, double A3, double A4, double A5) {
	return A0 + A1*x + A2*pow(x,2) + A3*pow(x,3) + A4*pow(x,4) + A5*pow(x,5);
}
