/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Prints a range of characters based on input
 Inputs: Two characters
 Outputs: Range of characters between two chars, 10 per line
**************************************************************/
#include <iostream>
using namespace std;

// Prints a range of characters between char1 and char2,
// displaying n chars per line.
void printChars(char, char, int = 10);

int main() {
	char ch1, ch2;
	cout << "Enter two characters to print a range of characters between the two:" << endl;
	cin >> ch1 >> ch2;
	printChars(ch1, ch2);
	return 0;
}

void printChars(char ch1, char ch2, int numberPerLine) {
	int count = 0;
	while (ch1 <= ch2) {
		cout << ch1++;
		if (++count % numberPerLine == 0) {
			cout << endl;
		}
	}
}