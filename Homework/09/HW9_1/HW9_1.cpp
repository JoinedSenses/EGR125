/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/
 Name: Arron Vinyard
 Date: July 9, 2019
 Project Description: Develops email addresses for a fictional company
 Inputs: Employee name and id
 Outputs: employee email
**************************************************************/
#include <iostream>
#include <string>
using namespace std;

void clearcin(); // clears cin buffer and makes it only accept limited input

int main() {
	const char email[] = "@XYZ.com";
	char first;
	string last, id;

	cout << "This program produces the email address for employees." << endl;

	// Prompt for input and store
	cout << "Last Name: ";
	cin >> last; clearcin();

	cout << "First Name: ";
	cin >> first; clearcin();

	cout << "EmployeeID: ";
	cin >> id; clearcin();

	last[0] = toupper(last[0]); // Make first char upper, rest lower
	for (unsigned int i = 1; i < last.length(); i++) {
		last[i] = tolower(last[i]);
	}

	cout << "Your email address is " // Output email - LastF123@XYZ.com
		<< last.substr(0, last.length() > 3 ? 4 : last.length())
		<< (char)toupper(first) // Make char upper
		<< id.substr(id.length() > 3 ? id.length() - 3 : 0, 3)
		<< email;

	return 0;
}

void clearcin() {
	cin.clear();
	cin.ignore(100, '\n');
}