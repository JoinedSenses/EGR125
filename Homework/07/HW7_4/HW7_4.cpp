/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 1, 2019
 Name: Arron Vinyard
 Project Description: Adds input to a vector and displays related information
 Inputs: Unspecified number of temps in C until less than -273
 Outputs: Max, min, sum, count, and sorted values
**************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	vector<double> temps;
	double input;

	cout << "This program finds the max, min, sum, and count based on input." << endl;
	cout << "Input an unspecified number of temperatures in Celcius (Enter a value less than -273 to end the loop):" << endl;

	// Loop until invalid input
	for (;;) {
		cin >> input;
		if (input < -273) break;
		temps.push_back(input);
	}

	// Output information about input.
	cout << "Max value is " << *max_element(temps.begin(), temps.end()) << endl
		<< "Min value is " << *min_element(temps.begin(), temps.end()) << endl
		<< "Sum is " << accumulate(temps.begin(), temps.end(), 0.0) << endl
		<< "Count is " << temps.size() << endl;

	// Sort and display input
	sort(temps.begin(), temps.end());
	cout << "Sorted values are: ";
	for (int i = 0; i < temps.size(); i++) {
		cout << temps[i] << " ";
	}

	return 0;
}