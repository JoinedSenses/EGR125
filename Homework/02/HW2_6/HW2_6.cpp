/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 3, 2019
 Name: Arron Vinyard
 Project Description: HW2_6 - Accept input of three integers and sorts it in increasing order.
 Inputs: Three integers
 Outputs: Sorted input from smallest to largest
*/
//*************************************************************

#include <iostream>
using namespace std;

int main() {
	int first, second, third;

	// Prompt for input
	cout << "Please enter three integers to be sorted:" << endl;
	cin >> first >> second >> third;

	// Check each input and swap if need.
	if (first > third) {
		swap(first, third);
	}

	if (second > third) {
		swap(second, third);
	}

	if (first > second) {
		swap(first, second);
	}

	// Output result
	cout << "Sorted values: ";
	cout << first << " " << second << " " << third << endl;
	return 0;
}