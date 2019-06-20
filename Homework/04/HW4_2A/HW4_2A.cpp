/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 17, 2019
 Name: Arron Vinyard
 Project Description: Outputs a formatted table of even square roots from 0 to 20
 Inputs: None
 Outputs: Table of even numbers number and its square root from 0 to 20
**************************************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int i = 0;

	// Set up formatting and display table header
	cout << fixed << setprecision(4) << left;
	cout << "Number  SquareRoot\n";

	// Display even numbers and its sqrt from 0 to 20
	do {
		cout << setw(8) << i << sqrt(i) << endl;
		i += 2;
	} while (i < 21);

	return 0;
}