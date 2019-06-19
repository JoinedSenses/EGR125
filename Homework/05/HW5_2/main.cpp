/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Outputs a range of conversions between
   feet and meters as a formatted table
 Inputs: None
 Outputs: Formatted table of conversions
**************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

// ==== Converstion functions
double footToMeter(double f) {
	return f * 0.305;
}

double meterToFoot(double m) {
	return m / 0.305;
}
// ====

int main() {
	double feet = 1.0, meter = 20.0;
	cout << "Feet  Meters | Meters  Feet" << endl << left << fixed;
	
	// Output conversions as a formatted table
	for (int i = 1; i < 11; i++) {
		cout << setprecision(1) << setw(6) << feet << setprecision(3) << setw(7) << footToMeter(feet) << "| "
			<< setprecision(1) << setw(8) << meter << setprecision(3) << meterToFoot(meter) << endl;
		feet++;
		meter += 5;
	}
	return 0;
}
