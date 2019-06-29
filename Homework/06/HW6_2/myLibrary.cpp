#include <cmath>
#include <string>
#include <sstream> // string stream. used in formatting double to string
#include <iomanip>
#include "myLibrary.h"
using namespace std;

// ======== Function Definitions
double getVectorLength(double vec[], int size) {
	double unsquared = 0.0;
	for (int idx = 0; idx < size; idx++) {
		unsquared += pow(vec[idx], 2);
	}
	return sqrt(unsquared);
}

void Swap(int A[], int B[], int size) {
	for (int idx = 0; idx < size; idx++) {
		Swap(A[idx], B[idx]);
	}
}

// Made this even though 'swap()' is a standard function
void Swap(int& a, int& b) {
	int buffer = a;
	a = b;
	b = buffer;
}

void Reverse(int arr[], int size) {
	for (int i = 0; i < size / 2; i++) {
		Swap(arr[i], arr[size - 1 - i]);
	}
}

string toString(const int arr[], int size, const char split[], int width) {
	ostringstream stream; // Output stream object, similar to cout.
	stream << '{' << setw(width) << arr[0];
	for (int idx = 1; idx < size; idx++) {
		stream << split << setw(width) << arr[idx];
	}
	return stream.str() + '}'; // return stream object as a string
}

string toString(const double arr[], int size, const char split[], int precision, int width) {
	ostringstream stream; // Output stream object, similar to cout.
	stream << fixed << setprecision(precision) << '{' << setw(width) << arr[0];
	for (int idx = 1; idx < size; idx++) {
		stream << split << setw(width) << arr[idx];
	}
	return stream.str() + '}'; // return stream object as a string
}