/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: June 29, 2019
 Project Description: 
 Inputs: 
 Outputs: 
**************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

double farenToCelc(double f) {
	return (f - 32) * 5 / 9;
}
double celcToK(double c) {
	return c + 273.15;
}

int main() {
	const int N = 19, W = 13;
	double F[N], C[N], K[N];

	cout << fixed << setprecision(2);
	cout << setw(W) << "degrees F" << setw(W) << "degrees C" << setw(W) << "K" << endl;

	for (int i = 0, f = 32; i < 19; i++, f += 10) {
		F[i] = f;
		C[i] = farenToCelc(F[i]);
		K[i] = celcToK(C[i]);
		cout << setw(W) << F[i] << setw(W) << C[i] << setw(W) << K[i] << endl;
	}
	
	return 0;
}