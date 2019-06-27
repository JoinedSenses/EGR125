/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Solves and displays triangle given three sides
 Inputs: Three triangle sides
 Outputs: Three triangle angles
**************************************************************/
#define _USE_MATH_DEFINES // Required for Visual Studio
#include <iostream>
#include <cmath>
using namespace std;

// === Function Declaration

// Returns triangle angles by reference given three sides
void triangle_SolveAngles(double, double, double, double&, double&, double&);

// ===

int main() {
	double a, b, c, A, B, C;
	cout << "Enter length of three sides of the triangle (a, b, c):" << endl;
	cin >> a >> b >> c;

	triangle_SolveAngles(a, b, c, A, B, C);

	cout << "Side A: " << A << " degrees." << endl
		<< "Side B: " << B << " degrees." << endl
		<< "Side C: " << C << " degrees." << endl;

	return 0;
}

// === Function Definition

void triangle_SolveAngles(double a, double b, double c, double& A, double& B, double& C) {
	A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
	B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
	C = 180 - A - B;
}