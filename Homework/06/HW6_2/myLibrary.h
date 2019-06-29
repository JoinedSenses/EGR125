#pragma once // only include once
using namespace std;

// ====== Function Declarations
double getVectorLength(double[], int); // Returns length of vector of N size

void Swap(int[], int[], int); // Swaps two arrays of N size
void Swap(int&, int&); // Overloaded to swap two ints

void Reverse(int[], int); // Reverses contents of array of N size

string toString(const int[], int, const char[] = ", ", int = 2); // Formats int array contents as a string
string toString(const double[], int, const char[] = ", ", int = 1, int = 2); // Formats double array contents as a string