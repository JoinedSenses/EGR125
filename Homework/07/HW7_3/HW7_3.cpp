/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 1, 2019
 Name: Arron Vinyard
 Project Description: Outputs a table of Farenheit, Celcius, and Kelvin using 2D array
 Inputs: None
 Outputs: Table of temperature conversions
**************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double farenToCelc(double f) {
	return (f - 32) * 5 / 9;
}
double celcToKelv(double c) {
	return c + 273.15;
}

int main() {
	const int F = 0, C = 1, K = 2, W = 13, N = 19;
	int f;
	double temps[3][N];

	// Format and display header
	cout << fixed << setprecision(2);
	cout << setw(W) << "degrees F" << setw(W) << "degrees C" << setw(W) << "K" << endl;

	// Loop to calculate range of temps and display from 32 f to 212 f
	for (int i = 0, f = 32; i < N; i++, f += 10) {
		temps[F][i] = f;
		temps[C][i] = farenToCelc(temps[F][i]);
		temps[K][i] = celcToKelv(temps[C][i]);
		cout << setw(W) << temps[F][i] << setw(W) << temps[C][i] << setw(W) << temps[K][i] << endl;
	}

	return 0;
}