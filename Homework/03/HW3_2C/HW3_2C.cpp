/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 8, 2019
 Name: Arron Vinyard
 Project Description: Prompt for two materials/densities and output in formatted table
 Inputs: Two materials (strings) and their densities (double)
 Outputs: Formatted table containing the materials and densities.
//**************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
#define MAX_MATS 2

void DisplayTable(int w, const string mat[MAX_MATS], const double dens[MAX_MATS]);

int main() {
	string materials[MAX_MATS];
	double density[MAX_MATS];

	// Prompt and save input as strings;
	for (int i = 0; i < MAX_MATS; i++) {
		cout << "Enter name for material #" << i + 1 << ": ";
		cin >> materials[i];

		cout << "Enter density for material #" << i + 1 << " in g/cm^3: ";
		cin >> density[i];
	}

	// Format and call table display function
	cout << left << fixed << setprecision(8);
	DisplayTable(12, materials, density);
	
	cout << right << scientific << setprecision(4);
	DisplayTable(18, materials, density);

	return 0;
}

// Function which formats and displays tables to reduce redunant code.
void DisplayTable(int w, const string mats[MAX_MATS], const double dens[MAX_MATS]) {
	static int tableNum = 1;
	cout << "\nTable " << tableNum++ << ":\n";
	cout << setw(w) << "Material" << setw(w) << "Density(g/cm^3)" << endl;

	for (int i = 0; i < MAX_MATS; i++) {
		cout << setw(w) << mats[i] << setw(w) << dens[i] << endl;
	}
}