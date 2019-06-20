/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Counts the number of uppercase chars in a string
 Inputs: A string
 Outputs: Number of uppcase characters in input string
//**************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main() {
	int count = 0;
	string input = "";

	cout << "This program counts the number of uppercase characters in a string.\n"
		<< "Enter a string:" << endl;
	getline(cin, input);

	for (int i = 0; i < input.length(); i++) {
		if (isupper(input[i])) {
			count++;
		}
	}

	cout << "The number of uppercase letters is " << count << endl;

	return 0;
}