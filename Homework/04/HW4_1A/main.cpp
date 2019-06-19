/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/

 Date: June 17, 2019
 Name: Arron Vinyard
 Project Description: A program that counts and averages an unspecified number of values until input is 0
 Inputs: Any integer
 Outputs: Average of all input numbers, positive count, negative count, total numbers
**************************************************************/
#include <iostream>
using namespace std;

int main() {
	int input, total, positives = 0, negatives = 0;
	double sum = 0.0;
	
	cout << "This program outputs the average of all input numbers." << endl
		<< "Enter an integer. The input ends if it is 0:" << endl;
	
	// Prompt for numbers until input is 0, sum, and count
	do {
		cin >> input;
		if (input) {
			sum += input;
			(input > 0 ? positives : negatives)++;
		}
	} while (input);
	
	total = positives + negatives;
	if (total) {
		cout << "The number of positives is " << positives
			<< "\nThe number of negatives is " << negatives
			<< "\nThe total is " << sum
			<< "\nThe average is " << sum/total << endl;
	}
	else {
		cout << "No numbers were entered except 0.";
	}
	
	return 0;
}
