/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Displays two tables side by side containing
   mile and kilometer conversions
 Inputs: None
 Outputs: Two tables, side by side
**************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int i, j;
	cout << fixed << setprecision(3) << left
		<< "Miles  Kilometers | Kilometers  Miles\n";
	// Output two formatted conversion tables, side by side
	for (i = 1, j = 20; i < 11; i++, j+=5) {
		cout << setw(7) << i << setw(11) << i * 1.609 << "| "
			<< setw(12) << j << j / 1.609 << endl;
	}
	return 0;
}
