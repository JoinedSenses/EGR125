
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Prints string to console with desired setw
void padOutput(int, string = " ");

int main(int argc, char** argv) {
	int input;
	int day;
	bool invalid;
	
	cout << "This program outputs a calendar month based on inputs." << endl;
	
	// Prompt for input
	do {
		invalid = false;
		cout << "Enter start day (0 = Sun, 1 = Mon, etc.): ";
		cin >> input;
		cin.ignore(100, '\n');
		if (input < 0 || input > 6) {
			invalid = true;
		}
	} while (invalid);
	
	day = input;
	
	do {
		invalid = false;
		cout << "Enter number of days in the month: ";
		cin >> input;
		
		if (input < 1) {
			invalid = true;
		}
	} while (invalid);
	
	padOutput(4, "Sun");
	padOutput(4, "Mon");
	padOutput(4, "Tue");
	padOutput(4, "Wed");
	padOutput(4, "Thu");
	padOutput(4, "Fri");
	padOutput(5, "Sat\n");
	
	for (int i = 0; i < 7; i++) {
		cout << setw(4) << "---";
	}
	cout << endl;
	
	for (int i = 0; i < day; i++) {
		padOutput(4);
	}
	
	for (int i = 1; i <= input; i++) {
		cout << setw(4) << i;
		
		if (++day > 6) {
			cout << endl;
			day = 0;
		}
	}
	
	return 0;
}

void padOutput(int size, string buffer) {
	cout << setw(size) << buffer;
}
