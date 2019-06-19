/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/
 Name: Arron Vinyard
 Date: June 19, 2019
 Project Description: Outputs the sum of all digits in a long int via function
 Inputs: Long integer
 Outputs: Sum of each digit in the long integer
//**************************************************************/
#include <iostream>
using namespace std;

// Returns sum of all digits in value
int sumDigits(long);

int main() {
	long input;
	cout << "Enter any number to retrieve the sum of all of its digits: ";
	cin >> input;
	cout << "Sum of " << input << " is " << sumDigits(input) << endl;
	return 0;
}

int sumDigits(long n) {
	int remainder, sum = 0;
	
	while (remainder = n % 10) {
		sum += remainder;
		n /= 10;
	}
	
	return sum;
}
