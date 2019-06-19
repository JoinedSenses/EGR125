#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double A, B, C, D, E, F, x, y;
	double slope1, slope2;
	bool invalid;
	char input;
	for (;;) {
		
		cout << "Enter the coefficients of two line equations: A, B, C, D, E, and F, respectively\n"
			<< "\tAx+By=C\n"
			<< "\tDx+Ey=F" << endl;
		cin >> A >> B >> C >> D >> E >> F;
		
		slope1 = -A/B;
		slope2 = -D/E;
		
		if (abs(slope1 - slope2) <= 1.0E-6) {
			cout << "\nThese lines are parallel\n" << endl;
		}
		else {
			cout << "\nThese lines insersect";
			
			if (abs((slope1 * slope2) + 1.0) <= 1.0E-6) {
				cout << " and are perpendicular";
			}
			cout << "." << endl;
			
			x = ((F/E) - (C/B))/((-A/B)-(-D/E));
			y = (C - A*x)/B;
			
			cout << "These two lines intersect at (" << x << ", " << y << ")\n" << endl;
		}
			
		cout << "Retry? Y/N" << endl;
		do {
			invalid = false;
			cin >> input;
			input = tolower(input);
			switch (input) {
				case 'y': continue;
				case 'n': return 0;
				default: invalid = true;
			}
		} while (invalid);
	}
	
	return 0;
}
// (-A/B)x + C/B = (-D/E)x + F/E
// x = ((F/E) - (C/B))/((-A/B)-(-D/E))
//Ax+By=C
//y = (C - Ax)/B
//y = C/B - A/Bx
//y = (-A/B)x + C/B
//
//y = mx+b

