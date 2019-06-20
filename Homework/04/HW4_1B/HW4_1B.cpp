/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 17, 2019
 Name: Arron Vinyard
 Project Description: This project calculates the value of pi/2 to 6 decimals
 Inputs: none
 Outputs: Value of pi/2 using acos, pi/2 to 6 decimals, number of terms needed
**************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Returns pi/2 to 6 decimal precision and number of terms
double halfPi(int&);

int main() {
	int terms = 0;
	double result1, result2;
	cout << fixed << setprecision(10);

	// Output results
	result1 = acos(-1) / 2;
	result2 = halfPi(terms);
	cout << "Pi using acos(-1):         " << result1 << endl;
	cout << "Pi to 6 decimal precision: " << result2 << " | Terms: " << terms << endl;
	cout << "Difference:                " << result1 - result2 << endl;

	return 0;
}

double halfPi(int& terms) {
	double product = 1.0, result = 1.0, numerator = 1.0, precision = pow(10, -7);
	int denominator = 3, count = 1;

	// result = 1 + 1/3 + (1*2)/(3*5) + (1*2*3)/(3*5*7) + ...
	// terms:   1    2         3               4          ...
	while (product > precision) {
		count++;
		product *= numerator / denominator;
		numerator += 1.0;
		denominator += 2;
		result += product;
	}
	terms = count;

	return result;
}
