#include <iostream>
#include <cmath>
#include <string>

// Used for sleepcp()
// https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
#ifdef WIN32
 #include <windows.h>
#else
 #include <unistd.h>
#endif

using namespace std;

// Cross-platform sleep function
void sleepcp(int milliseconds);

// Uses sleep to display text slowly
void printSlowText(string str, int charMS = 50, int newlineMS = 450);

// returns inductive reactance in ohms
double inductiveReactance(double f, double L);

// returns capacitive reactance in ohms
double capacitiveReactance(double f, double C);

// returns total circuit impedance in ohms
double totalImpedance(double R, double X_L, double X_C);

// returns current in amps
double current(double E, double Z);
