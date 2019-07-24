/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: July 23, 2019
 Project Description: Run logger which stores and displays run summaries
 Inputs: Login, Run info, misc prompts
 Outputs: User profile text file, run summaries
**************************************************************/
#include <iostream>
#include <string>
#include "Runner.h"
using namespace std; //introduces namespace std

int main() {
	int input;
	bool logout;

	Runner r;

	for (;;) {
		logout = false;
		switch (r.Login()) {
			case Login_Fail: return 1; // Login failed for some reason.
			case Login_Exit: return 0; // User chose to exit.
			case Login_Back: continue; // New user chose not to make profile.
		}

		for (;;) { // Main menu
			cout << "Select an option:"
				<< "\n1. Add a new run"
				<< "\n2. Display summary of previous runs"
				<< "\n3. Logout"
				<< "\n4. Exit" << endl;

			cin >> input; clearcin();

			switch (input) {
				case 1: // Add new run
					r.EnterRun();
					system("pause");
					break;
				case 2: // Display Summary
					r.Summary();
					system("pause");
					break;
				case 3: // Logout
					r.Logout();
					logout = true;
					break;
				case 4: // Exit
					return 1;
				default:
					cout << "Invalid input.";
			}
			cout << endl;
			if (logout) break;
		}
		cout << "-----" << endl;
	}
	
	return 0;
}

