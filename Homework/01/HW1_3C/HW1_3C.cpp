/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: May 27, 2019
 Name: Arron Vinyard
 Project Description: Calculates the remaining one side and two angles for a triangle
 Inputs: Sides a,b and Angle A
 Outputs: Angles B, C and side c (in degrees)
*/
//*************************************************************
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
using namespace std;

// Conversions between radians and degrees
float degToRad(float deg) {
	return deg * M_PI / 180;
}

float radToDeg(double rad) {
	return rad * 180 / M_PI;
}

int main() {
	float a = 0.0, b = 0.0, c = 0.0;
	float A = 0.0, B = 0.0, C = 0.0;

	// Prompt for input
	cout << "Please enter: side a, side b, and angle A: ";
	cin >> a >> b >> A;

	// Solve for angles and side
	B = radToDeg(asin(b * sin(degToRad(A)) / a));
	C = 180 - A - B;
	c = a * sin(degToRad(C)) / sin(degToRad(A));

	// Output resulting angles and side.
	cout << "Angle B: " << B << " degrees" << endl;
	cout << "Angle C: " << C << " degrees" << endl;
	cout << "Side c: " << c;

	// End
	return 0;
}