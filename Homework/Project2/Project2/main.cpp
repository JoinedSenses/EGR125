/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/

 Date: July 4, 2019
 Name: Arron Vinyard
 Project Description: displays a range of calculated values for a series RLC electrical circuit
 Inputs: Inputs required for calculations: R, L, C, E, and f
 Outputs: A table displaying calculations for a range of frequencies
**************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "myLibrary.h"

using namespace std;

int main() {
	double E, R, L, C, f, f_init, f_fin, X_L, X_C, Z, I, maxI = 0.0;
	int savedF = 0; // Value of f where current is max
	string unit; // Buffer for unit input
	bool
		  invalid // Used for loop validation
		, restart; // Used to loop the program
	const string 
		  valueError = "Value must be a positive number. "
		, unitError = "Invalid unit. "
		, unitInfo = "Input is case sensitive for units.\nIf unit is requested, enter input as such: <value> <unit>\n"
		, dashedLine = "--------------------------------------------------\n";
	const int W = 10; // Display Width
	
// ===== Begin main program loop
	do {
		restart = false;
		system("CLS"); // Clear console
		
// ===== Program info
		cout << dashedLine
			<< "This program displays a range of calculated values\nfor a series RLC electrical circuit\n"
			<< dashedLine << endl;
		
		sleepcp(1500); // Sleep for 1.5 seconds
		
		cout << "R: Resistance (Ohms: \352)"
			<< "\nL: Inductance (Henries: H)"
			<< "\nC: Current (Amperes: A)"
			<< "\nE: Sinusoidal voltage (Volts: V)"
			<< "\nf: Frequency (Hertz: Hz)\n"
			<< "\nInductive Reactance (\352):\n  X_L = 2 * PI * f * L"
			<< "\nCapacitive Reactance (\352):\n  X_C = -1 / (2 * PI * f * C)"
			<< "\nTotal Circuit Impedance (\352):\n  Z = sqrt(R^2 + (X_L + X_C)^2)"
			<< "\nCurrent (A):\n  I = E / Z\n" << endl;
			
		sleepcp(1000);
		
		// Get user's attention regarding units
		cout << dashedLine;
		printSlowText(unitInfo);
		cout << dashedLine << endl;
		
		sleepcp(1500);
	
// ===== Inputs
		cout << "Enter values for R, L, C, E, f_initial, and f_final.\n" << endl;

// -- R	
		do {
			cout << "R (\352): ";
			cin >> R;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (R < 1E-7)  {
				cout << valueError;
			}
		} while (R < 1E-7);

// -- L	
		do {
			invalid = false;
			cout << "L (specify unit: mH or uH): ";
			cin >> L >> unit;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (L < 1E-15) {
				cout << valueError;
				invalid = true;
			}
			else if (unit[1] == 'H' && unit[2] == '\0') {
				switch(unit[0]) {
					case 'm': L *= pow(10, -3); break;
					case 'u': L *= pow(10, -6); break;
					default: cout << unitError; invalid = true;
				}
			}
			else {
				cout << unitError;
				invalid = true;
			}
		} while(invalid);
		
// -- C	
		do {
			invalid = false;
			cout << "C (specify unit: mF, uF, or nF): ";
			cin >> C >> unit;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (C < 1.0E-15) {
				cout << valueError;
				invalid = true;
			}
			else if (unit[1] == 'F' && unit[2] == '\0') {
				switch(unit[0]) {
					case 'm': C *= pow(10, -3); break;
					case 'u': C *= pow(10, -6); break;
					case 'n': C *= pow(10, -9); break;
					default: cout << unitError; invalid = true;
				}
			}
			else {
				cout << unitError;
				invalid = true;
			}
		} while (invalid);
		
// -- E	
		do {
			cout << "E (V): ";
			cin >> E;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (E < 1E-7) {
				cout << valueError;
			}
		} while (E < 1E-7);

// -- F Initial	
		do {
			invalid = false;
			cout << "f Initial (specify unit: Hz, kHz, or mHz): ";
			cin >> f_init >> unit;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (unit[0] == 'H' && unit[2] == '\0') {
				if (unit[1] != 'z') {
					cout << unitError;
					invalid = true;
				}
			}
			else if (unit[1] == 'H' && unit[2] == 'z' && unit[3] == '\0') {
				switch(unit[1]) {
					case 'k': f_init *= pow(10, 3); break;
					case 'M': f_init *= pow(10, 6); break;
					default: cout << unitError; invalid = true;
				}
				
				if (!invalid && f_init - 1.0 < -1E-6) {
					cout << "Frequency must be greater than or equal to 1 Hz. Entered value: " << f_init << "Hz" << endl;
					invalid = true;
				}
			}
			else {
				cout << unitError;
				invalid = true;
			}
		} while (invalid);

// -- F Final	
		do {
			invalid = false;
			cout << "f Final (specify unit: Hz, kHz, or mHz): ";
			cin >> f_fin >> unit;
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			if (unit[0] == 'H' && unit[2] == '\0') {
				if (unit[1] != 'z') {
					cout << unitError;
					invalid = true;
				}
			}
			else if (unit[1] == 'H' && unit[2] == 'z' && unit[3] == '\0') {
				switch(unit[1]) {
					case 'k': f_fin *= pow(10, 3); break;
					case 'M': f_fin *= pow(10, 6); break;
					default: cout << unitError; invalid = true;
				}
			}
			else {
				cout << unitError;
				invalid = true;
			}
			
			if (!invalid) {
				if (f_fin > 1E9) {
					cout << "Frequency must be less than 1E9. Entered value: "
						<< f_fin << "Hz" << endl;
					invalid = true;
				}
				else if (f_fin - 2*f_init < 1E-6) {
					cout << "Frequency must be greater than 2*f_initial (" << f_init*2
						<< "Hz). Entered value: " << f_fin << endl;
					invalid = true;
				}
			}
		} while (invalid);
// ===== End of inputs
	

// ===== Solve and Display Table
		cout << fixed;
		f = f_init;
		
		// Display Header
		cout << endl << dashedLine
			<< setw(W) << "Freq (\352) " << "|"
			<< setw(W-1) << "XC (\352) " << "|"
			<< setw(W-1) << "XL (\352) " << "|"
			<< setw(W-1) << "Z (\352)  " << "|"
			<< setw(W-1) << "I (mA) " << endl
			<< dashedLine;
		
		// Loop through frequency range and display until > f_final
		for (;;) {
			X_L = inductiveReactance(f, L);
			X_C = capacitiveReactance(f, C);
			Z = totalImpedance(R, X_L, X_C);
			I = current(E, Z) * 1000; // mult by 1k to convert to mA
	
			// Store greatest value of current and its frequency
			if (I - maxI > 1E-6) {
				maxI = I;
				savedF = f;
			}
			
			// Output formatted results
			cout << setw(W) << static_cast<int>(f)
				<< setprecision(1)
				<< setw(W) << X_C
				<< setw(W) << X_L
				<< setw(W) << Z
				<< setprecision(3)
				<< setw(W) << I << endl;
			
			if (f > f_fin) {
				break;
			}
			
			f *= 2; // double the value of f each iteration
		}
		cout << dashedLine << endl;
		
		sleepcp(1000);
		
		cout << "Max current (I) is " << maxI
			<< " mA where frequency (f) is " << savedF << " Hz\n" << endl;
		
		sleepcp(2000);
	
		// Prompt user if they wish to repeat the program.
		do {
			invalid = false;
			cout << "Start over? [Y/N]: ";
			cin >> unit[0]; // reusing unit instead of declaring unneeded var
			cin.clear(); // Clear buffer
			cin.ignore(100, '\n');
			
			switch (tolower(unit[0])) {
				case 'y': restart = true;
				case 'n': break;
				default: cout << "Invalid input. "; invalid = true;
			}
		} while (invalid);
		
	} while (restart); // Start over
	
	return 0;
}
