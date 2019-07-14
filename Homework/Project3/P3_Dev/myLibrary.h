#pragma once
#include <string>
#include <map> // used to store materials & its resist coeff
// http://www.cplusplus.com/reference/map/map/
using namespace std;

//== Constants
const double PI = 3.14159265359;

//== File loaders
bool loadCoeffs(const char file[], map<string, double>& _map);
bool loadAWGs(const char file[], double* awg, int size);

//== Map functions
// Displays available materials
void displayAvailable(map<string, double> resistMap);
// Returns resist/temp coefficients
bool getCoeff(map<string, double> _map, string material, double& coeff);

//== Formulas
double milsToMeters(double mils);
double getCrossSectionArea(double diameter);
double getBaseResistance(double resistCoeff, double length, double crossSectionArea);
double getWireResistance(double resistivity, double tempCoeff, double temp);


//== Misc
void customFormat(string &str); // First char upper, rest lower
void clearcin(); // Ensures specific input is entered, rather than a ton of input at once