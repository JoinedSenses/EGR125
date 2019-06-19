/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 3, 2019
 Name: Arron Vinyard
 Project Description: HW2_7 - Accepts int input for month and outputs name with a switch statement
 Inputs: Value 1 through 12
 Outputs: Corresponding month name
*/
//*************************************************************
#include <iostream>
using namespace std;

int main() {
	int input;
	string monthName;

	// Prompt for input and store it
	cout << "Enter a value 1 - 12 for its corresponding month name:" << endl;
	cin >> input;

	// Use switch for resulting month name
	switch (input) {
		case 1:  monthName = "January"; break;
		case 2:  monthName = "February"; break;
		case 3:  monthName = "March"; break;
		case 4:  monthName = "April"; break;
		case 5:  monthName = "May"; break;
		case 6:  monthName = "June"; break;
		case 7:  monthName = "July"; break;
		case 8:  monthName = "August"; break;
		case 9:  monthName = "September"; break;
		case 10: monthName = "October"; break;
		case 11: monthName = "November"; break;
		case 12: monthName = "December"; break;
		default: {
			cout << "Error: Invalid input." << endl;
			return 1;
		}
	}

	// Output result
	cout << "The month corresponding to " << input << " is " << monthName << endl;

	//End
	return 0;
}