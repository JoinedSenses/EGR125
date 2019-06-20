/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 17, 2019
 Name: Arron Vinyard
 Project Description: This program solves two sides of a right triangle from
					  5 to 85 degrees where the third side, A, is 10
 Inputs: None
 Outputs: Formatted table of theta and solved triangle sides
**************************************************************/
#define _USE_MATH_DEFINES // Required in Visual Studio for M_PI
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	double rads, A = 10.0, B, H;
	const string line = "|-----------------------------------|\n";

	/*    |\
		  | \
		  |  \
		B |   \ H
		  |    \
		  |     \
		  |_Theta\
		   A = 10 */
	cout << fixed << right << setprecision(2)
		<< line
		<< "| Theta (degrees) |  B (m) |  H (m) |\n"
		<< line;

	// Solves for B and H from 5 to 85 degrees, outputs as formatted table
	for (int theta = 5; theta < 90; theta += 5) {
		rads = theta * M_PI / 180;
		B = A * tan(rads);
		H = A / cos(rads);

		cout << "|"
			<< setw(9) << theta << setw(9) << "|"
			<< setw(7) << B << " |"
			<< setw(7) << H << " |" << endl;
	}
	cout << line;
	return 0;
}
