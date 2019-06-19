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

// Returns pi/2 to n digits and number of terms needed
double halfPiToNDigits(int, int&);

int main() {
	int terms;
	double result1, result2;
	cout << fixed << setprecision(10);
	
	// Not much happening here besides printing results
	result1 = acos(-1)/2;
	cout << "Pi using acos(-1):         " << result1 << endl;
	
	result2 = halfPiToNDigits(7, terms);
	cout << "Pi to 6 decimal precision: " << result2 << " | Terms: " << terms << endl;
	cout << "Difference:                " << result1-result2 << endl;
	
	return 0;
}

double halfPiToNDigits(int n, int &terms) {
	double product = 1.0, result = 1.0, numerator = 1.0, precision = pow(10, -n);
	int denominator = 3, count = 0;
	
	// result = 1 + 1/3 + (1*2)/(3*5) + (1*2*3)/(3*5*7) + ...
	// terms:   1    2         3               4          ...
	while (product > precision) {
		count++;
		product *= numerator/denominator;
		numerator += 1.0;
		denominator += 2;
		result += product;
	}
	terms = count;
	
	return result;
}
