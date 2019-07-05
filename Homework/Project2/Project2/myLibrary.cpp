#include "myLibrary.h"

double inductiveReactance(double f, double L) {
	return 2.0 * M_PI * f * L;
}

double capacitiveReactance(double f, double C) {
	return -1.0 / (2.0 * M_PI * f * C);
}

double totalImpedance(double R, double X_L, double X_C) {
	return sqrt(R*R + pow(X_L + X_C, 2));
}

double current(double E, double Z) {
	return E / Z;
}

void sleepcp(int milliseconds) {
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

void printSlowText(string str, int charMS, int newlineMS) {
	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
		if (str[i] == '\n') {
			sleepcp(newlineMS);
		}
		sleepcp(charMS);
	}
}
