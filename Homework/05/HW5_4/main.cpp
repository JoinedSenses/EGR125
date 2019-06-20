#include <iostream>
#include <cmath>
using namespace std;

// === Function Declaration

// Determines if a triangle is valid given three sides
bool triangle_AreSidesValid(double, double, double);

// Returns triangle angles by reference given three sides
void triangle_SolveAngles(double, double, double, double&, double&, double&);

// === Main

int main() {
	double a, b, c, A, B, C;
	cout << "Enter length of three sides of the triangle (a, b, c):" << endl;
	cin >> a >> b >> c;
	if (triangle_AreSidesValid(a, b, c) {
		triangle_SolveAngles(a, b, c, A, B, C);
	}
	else {
		cout << "Error: Invalid triangle sides." << endl;
		return 0;
	}
	
	cout << "Side A: " << A << " degrees." << endl;
		<< "Side B: " << B << " degrees." << endl;
		<< "Side C: " << C << " degrees." << endl;
	
	return 0;
}

// === Function Definition

bool triangle_AreSidesValid(double a, double b, double c) {
	if (a <= 1.0E-6 || b <= 1.0E-6 || c <= 1.0E-6) {
		return false;
	}
	return (a < b + c && b < a + c && c < a + b);

void triangle_SolveAngles(double a, double b, double c, double &A, double &B, double &C) {
	A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
	B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
	C = 180 - A - B;
}
