/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 8, 2019
 Name: Arron Vinyard
 Project Description: Prompt user for a letter and display corresponding number for phone keys.
 Inputs: A single letter
 Outputs: Corresponding key for letter on phone.
*/
//*************************************************************
#include <iostream>
using namespace std;

int main() {
	char letter, lower;
	int num;

	// Prompt for input and store as char.
	cout << "This program outputs the phone key for a letter." << endl;
	cout << "Please enter a letter: ";
	cin >> letter;

	// Get the corresponding number
	lower = tolower(letter);
	if (lower >= 'a' && lower <= 'z') {
		switch (lower) {
			case 'z': lower--;
			case 's': case 'v': case 'y': lower--;
			default: num = (lower - 'a') / 3 + 2;
		}
	}
	else {
		cout << "Error: \'" << letter << "\' is an invalid input." << endl;
		return 1;
	}

	// Output result;
	cout << "The corresponding number is " << num << endl;
	return 0;
}