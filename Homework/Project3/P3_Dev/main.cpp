/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: July 14, 2019
 Project Description: Calculates wire resistance based in input
 Inputs:  Material information (name, temp, gauge, etc)
 Outputs: Temperature/Resistance (either to console or file)
**************************************************************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include "myLibrary.h"
using namespace std;

int main() {
//== Variable declaration
	const int SIZE = 41;
	const char file_awg[] = "AWG_Table.txt";
	const char file_resist[] = "Resistivity_Coefficients.txt";
	const char file_temp[] = "Temperature_Coefficients.txt";
	map<string, double> resistCoeffs, tempCoeffs; // { "Material", coeff }
	ofstream out;
	vector<double*> vec;
	string material, buffer;
	double awg[SIZE], length, resistCoeff, tempCoeff, temp, tempInitial, tempFinal, tempIncrement, area, *arr, baseResistance;
	bool retry, invalid;
	int input, input2, gauge;

//== Load files
	if (!loadCoeffs(file_resist, resistCoeffs)) {
		cout << "Unable to open " << file_resist << endl;
		return 1;
	}
	if (!loadAWGs(file_awg, awg, SIZE)) {
		cout << "Unable to open " << file_awg << endl;
		return 1;
	}
	if (!loadCoeffs(file_temp, tempCoeffs)) {
		cout << "Unable to open " << file_temp << endl;
		return 1;
	}

//== Begin main program
	do {
		// Output info
		retry = false;
		cout << "This program calculates wire resistance.\n" << endl;
		cout << "Information is available for these materials:" << endl;
		displayAvailable(resistCoeffs);

//== Inputs
		do {
			invalid = false;
			cout << "Choose an option:\n1. Find resistance at a specific temperature\n2. Find resistance over range of temperatures" << endl;
			cin >> input;
			clearcin();
			if (input < 1 || input > 2) {
				cout << "Invalid input. ";
				invalid = true;
			}
		} while (invalid);

		// Prompt for material info.
		do {
			invalid = false;
			cout << "Enter material: ";
			cin >> material;
			clearcin();
			customFormat(material);

			if (!getCoeff(resistCoeffs, material, resistCoeff)) {
				cout << "No resistance data found for " << material << ". ";
				invalid = true;
				continue;
			}

			if (!getCoeff(tempCoeffs, material, tempCoeff)) {
				cout << "No temperature data found for " << material << ". ";
				invalid = true;
				continue;
			}

			do {
				invalid = false;
				cout << "Enter wire length in meters: ";
				cin >> length;
				clearcin();
				if (length < 0.0) {
					cout << "Invalid input. ";
					invalid = true;
				}
			} while (invalid);

			do {
				invalid = false;
				cout << "Enter wire gauge (0-40): ";
				cin >> gauge;
				clearcin();
				if (gauge < 0 || gauge > 40) {
					cout << "Invalid input. ";
					invalid = true;
				}
			} while (invalid);

		} while (invalid);

		if (input == 1) {
			invalid = false;
			cout << "Enter temperature in celcius: ";
			cin >> temp;
			clearcin();

			tempInitial = temp;
			tempFinal = temp;
			tempIncrement = 1.0;
		}
		else { // Additional steps required for option 2
			cout << "Enter starting temperature in celcius: ";
			cin >> tempInitial;

			do {
				invalid = false;
				cout << "Enter final temperature in celcius: ";
				cin >> tempFinal;
				clearcin();
				if (tempFinal < tempInitial) {
					cout << "Invalid input. ";
					invalid = true;
				}
			} while (invalid);

			do {
				invalid = false;
				cout << "Enter temperature increment in celicius: ";
				cin >> tempIncrement;
				clearcin();
				if (tempIncrement < 0.0) {
					cout << "Invalid input. ";
					invalid = true;
				}
			} while (invalid);

			do {
				invalid = false;
				cout << "Select option:" << endl
					<< "1. Display formatted table of temperatures and resistances.\n"
					<< "2. Output temperatures and resistances to file" << endl;
				cin >> input2;
				clearcin();
				if (input2 < 1 || input2 > 2) {
					cout << "Invalid output" << endl;
					invalid = true;
				}
			} while (invalid);
		}

//== Calculations
		// Note: These values are returning different than the assignment pdf for an unknown reason
		area = getCrossSectionArea(milsToMeters(awg[gauge])); // Convert mils to m^2
		baseResistance = getBaseResistance(resistCoeff, length, area);
		for (double i = tempInitial; i <= tempFinal; i += tempIncrement) {
			arr = new double[2];
			arr[0] = i; // temperature
			arr[1] = getWireResistance(baseResistance, tempCoeff, i); // resistance
			vec.push_back(arr);
		}

//== Output
		if (input == 1 || input2 == 1) {
			cout << left << "\n------------------------------------------------" << endl
				<< "Material: " << material
				<< " #" << gauge << endl
				<< "------------------------------------------------" << endl
				<< setw(16) << "Temperature (\370C)" << " Resistance (\352)" << endl;
			for (unsigned int i = 0; i < vec.size(); i++) { // loop and output to screen
				cout << setw(16) << vec[i][0] << " " << vec[i][1] << endl;
			}
			cout << "------------------------------------------------" << endl;
		}
		else if (input2 == 2) {
			cout << "Enter a name for the file: ";
			cin >> buffer;
			clearcin();

			// if no file type specified, make it .txt
			if (buffer.rfind('.') == -1) {
				buffer += ".txt";
			}

			out.open(buffer.c_str(), ios::out|ios::trunc);
			for (unsigned int i = 0; i < vec.size(); i++) { // loop and output to file
				out << vec[i][0] << "," << vec[i][1] << endl;
			}
			out.close();
			cout << "Data written to " << buffer << endl;
		}

		for (unsigned int i = 0; i < vec.size(); i++) {
			delete[] vec[i]; // Free memory
		}
		vec.clear();

		do { // Prompt to restart program
			invalid = false;
			cout << "\nRestart program? [Y/N]: ";
			cin >> buffer;
			switch (tolower(buffer[0])) {
				case 'y': retry = true; break;
				case 'n': break;
				default: {
					cout << "Invalid input. ";
					invalid = true;
				}
			}
		} while (invalid);
	} while (retry);
	return 0;
}
