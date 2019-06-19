/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 8, 2019
 Name: Arron Vinyard
 Project Description: Determines if a character input is a vowel or consonant.
 Inputs: A single character
 Outputs: Vowel, consonant, or invalid.
*/
//*************************************************************
#include <iostream>
using namespace std;

int main() {
	char letter, lower;

	// Prompt for input, store letter.
	cout << "This program will output if a letter is a vowel or consonant." << endl;
	cout << "Enter a letter: ";
	cin >> letter;

	// Make char lower so we have less checks.
	lower = tolower(letter);

	// Check if char is a letter and if vowel/consonant.
	if (lower >= 'a' && lower <= 'z') {
		switch (lower) {
		case 'a': case 'e': case 'i': case 'o': case 'u':
			cout << '\'' << letter << "\' is a vowel." << endl;
			break;
		default:
			cout << "\'" << letter << "\' is a consonant." << endl;
		}
	}
	else {
		cout << "Error: \'" << letter << "\' is not a letter." << endl;
	}

	return 0;
}