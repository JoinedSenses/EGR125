/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/

 Date: June 6, 2019
 Name: Arron Vinyard
 Project Description: Lab 2 - Calculates the volume and lateral surface
 	area of a right circular cone.
 Inputs: radius and height of right circular cone
 Outputs: volume and surface area of circular cone
*/
//*************************************************************

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	float radius, height, volume, surfaceArea;
	
	// Prompt user to input radius and height
	cout << "Input radius and height of circular cone, respectively:" << endl;
	
	// Store input
	cin >> radius >> height;
	
	// Calculate Volume
	volume = M_PI * radius * radius * height / 3;
	
	// Calculate Lateral Surface Area
	surfaceArea = M_PI * radius * sqrt(radius * radius + height * height);
	
	// Output results
	cout << "Volume: " << volume << endl << "Lateral surface area: " << surfaceArea << endl;
	return 0;
}
