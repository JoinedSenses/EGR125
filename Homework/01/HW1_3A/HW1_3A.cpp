/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: May 27, 2019
 Name: Arron Vinyard
 Project Description: Displays the distance between two points
 Inputs: Two points - (x1,y1) and (x2,y2)
 Outputs: Distance between the two input points
*/
//*************************************************************

#include <iostream>
#include <string>
using namespace std;

#define X 0
#define Y 1

// Calculates distance between two 2D points
float getPointDistance(float p1[2], float p2[2]);

int main(void)
{
	// 2D float array containing point sets - {{x1,y1},{x2,y2}}
	float p[2][2] = { 0 };

	// Prompt for first point set.
	cout << "Enter x1 and y1: ";
	cin >> p[0][X] >> p[0][Y];

	// Prompt for second point set.
	cout << "Enter x2 and y2: ";
	cin >> p[1][X] >> p[1][Y];

	// Calculate distance between two point sets.
	float distance = getPointDistance(p[0], p[1]);

	// Output distance to console.
	cout << "The distance between the two points is " << distance << flush;

	// End
	return 0;
}

float getPointDistance(float p1[2], float p2[2]) {
	return pow(pow(p1[X] - p2[X], 2) + pow(p1[Y] - p2[Y], 2), 0.5);
}