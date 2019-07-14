#include <fstream>
#include <iostream>
#include <cmath>
#include "myLibrary.h"
using namespace std;

bool loadCoeffs(const char file[], map<string, double>& _map) {
	ifstream in(file);
	string material;
	double coefficient;

	if (in.fail()) {
		in.close();
		return false;
	}
	
	while (in >> material >> coefficient) {
		_map[material] = coefficient; // Map value to material
	}

	in.close();
	return true;
}

bool loadAWGs(const char file[], double* awg, int size) {
	ifstream in(file);
	int i;
	double mils;

	if (in.fail()) {
		in.close();
		return false;
	}

	while (in >> i >> mils) {
		if (-1 < i && i < size) {
			awg[i] = mils;
		}
	}

	in.close();
	return true;
}

void displayAvailable(map<string, double> resistMap) {
	// Iterate through map and display material name
	map<string, double>::iterator it = resistMap.begin();
	while (it != resistMap.end()) {
		cout << "  " << it->first << endl;
		it++;
	} cout << endl;
}

bool getCoeff(map<string, double> _map, string material, double& coeff) {
	map<string, double>::iterator it = _map.find(material);
	if (it == _map.end()) { // Not found
		return false;
	}
	coeff = it->second; // 2nd item (Coefficient)
	return true;
}

double milsToMeters(double mils) {
	return mils * 2.54E-5;
}

double getCrossSectionArea(double diameter) {
	return PI * pow(diameter/2, 2);
}

double getBaseResistance(double resistCoeff, double length, double crossSectionArea) {
	return resistCoeff * length / crossSectionArea;
}

double getWireResistance(double baseResistance, double tempCoeff, double temp) {
	return baseResistance * (1 + tempCoeff * (temp - 20));
}

void customFormat(string &str) {
	str[0] = toupper(str[0]);
	for (unsigned int i = 1; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
}

void clearcin() {
	cin.clear();
	cin.ignore(100, '\n');
}