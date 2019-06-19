/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 3, 2019
 Name: Arron Vinyard
 Project Description: HW2_5 - Accept input of six values and solve a 2x2 linear equation
	using Cramer's rule.
 Inputs: Six real values.
 Outputs: Solution for x and y if exists, otherwise no solution.
*/
//*************************************************************
#include <iostream>
using namespace std;

int main() {
	float a, b, c, d, e, f;

	// Prompt for input and store each value
	cout << "This generates a solution for a 2x2 linear equation." << endl;
	cout << "Please enter values for a, b, c, d, e, and f:" << endl;
	cin >> a >> b >> c >> d >> e >> f;

	// Check if the equation has a solution
	if (a * d - b * c == 0) {
		cout << "The equation has no solution.";
	}
	// Output solution for x and y using Cramer's rule
	else {
		cout << "x is " << (e * d - b * f) / (a * d - b * c);
		cout << " and y is " << (a * f - e * c) / (a * d - b * c) << endl;
	}

	return 0;
}