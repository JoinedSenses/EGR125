/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: May 27, 2019
 Name: Arron Vinyard
 Project Description: Sums all digits of an integer
 Inputs: Integer value between 0 and 1000
 Outputs: Summation of each digit within the input integer
*/
//*************************************************************

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "";
	int buffer = 0;

	// Prompt for input. If not within range, prompt again.
	do {
		cout << "Enter a number between 0 and 1000: ";
		cin >> input;
		buffer = stoi(input);
	} while (buffer <= 0 || buffer >= 1000);

	int total = 0;

	// Loop through each character.
	for (int i = 0; i < input.length(); i++) {
		// ASCII conversion of char to int and add to total
		total += (input[i] - '0');
	}

	// Output total of each digit.
	cout << "The sum of the digits is " << total;
	return 0;
}