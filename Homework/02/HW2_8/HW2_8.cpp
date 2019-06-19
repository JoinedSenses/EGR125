/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 3, 2019
 Name: Arron Vinyard
 Project Description: HW2_8 - Finds the number of days in a month
 Inputs: Two integers: Month and year
 Outputs: Number of days in the month
*/
//*************************************************************
#include <iostream>
using namespace std;

bool IsLeapYear(int year) {
	// True if divisible by 400 OR (not divisible by 100 AND divisible by 4)
	return !(year % 400) || (year % 100 && !(year % 4));
}

int main() {
	int days, month, year;
	const string monthNames[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

	// Prompt user for inputs and store them
	cout << "Enter month (1-12) and year to return number of days in that month:" << endl;
	cin >> month >> year;

	// Use switch statment to retrieve number of days in month	
	switch (month) {
		case 2:
			days = (IsLeapYear(year) ? 29 : 28);
			break;
		case 4: case 6: case 9: case 11:
			days = 30;
			break;
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			days = 31;
			break;
		default:
			cout << "Error: Invalid input." << endl;
			return 1;
	}

	// Output number of days in month
	cout << monthNames[month - 1] << " " << year << " has " << days << " days." << endl;

	return 0;
}