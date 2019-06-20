/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 17, 2019
 Name: Arron Vinyard
 Project Description: Outputs smallest value such at 3N^3-27N^2 > 100,000
 Inputs: None
 Outputs: Result and N count
**************************************************************/
#include <iostream>
using namespace std;

// Performs arbitrary calculation from the assignment
int GetValue(int);

int main() {
	int N = 0;

	// Loops until the calculation is greater than 100,000
	do {
	} while (GetValue(++N) <= 100000);

	cout << "Smallest value such at 3N^3-27N^2 > 100,000 is "
		<< GetValue(N) << " where N is " << N << endl;
	return 0;
}

int GetValue(int N) {
	return 3 * N* N* N - 27 * N * N;
}