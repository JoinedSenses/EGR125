/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: June 9, 2019
 Name: Arron Vinyard
 Project Description: An menu based project which generates information about triangles.
 Inputs: Triangle sides and menu options
 Outputs: Information about a triangle based on menu choices
//************************************************************* */
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

// Class declarations
class Triangle {
private:
	double a, b, c, A, B, C, radA, radB, radC, area, perimeter;
public:
	Triangle() {}; // Default constructor.
	void init(double sideA, double sideB, double sideC); // Initializes triangle
	static void print(); // Prints a triangle to console
	static bool isValid(double a, double b, double c); // Checks if triangle is valid
	void outputAngles(); // Prints angles
	void outputIncircle(); // Prints incircle and remainder triangle area
	void outputCircumcircle(); // Prints circumcircle and remainder circle area
	bool isRadians; // Toggles output between radians/degrees

	string unit; // Displayed unit of measurement
};

class Circle {
public:
	/* Calculates a circle's area given radius
	 * @param radius        Radius of circle
	 * @return              Area of circle */
	static double getArea(double radius) {
		return 	M_PI * radius* radius;
	}
};
// ---

int main() {
	Triangle triangle;
	double sideA, sideB, sideC;
	bool invalid, restart, toggle;
	int choice;
	string unit;

	cout << "This program performs various calculations on a triangle given its three sides." << endl;
	Triangle::print(); // Extra credit: Display a triangle.

	// Extra Credit: Loop until exit.
	for (;;) {
		restart = false;

		// Prompt for length of three sizes of triangle
		do {
			invalid = false;
			cout << "Please enter length of sides a, b, and c, respectively:\n";
			cin >> sideA >> sideB >> sideC;

			if (!Triangle::isValid(sideA, sideB, sideC)) {
				cout << "Error: Invalid triangle. ";
				invalid = true;
			}
		} while (invalid);

		// Initialize triangle class
		triangle.init(sideA, sideB, sideC);

		// Extra Credit: Prompt for optional unit
		do {
			invalid = false;

			cout << "\nOptional: Select unit of length:\n";
			cout << "1. Meters\n";
			cout << "2. Feet\n";
			cout << "3. Inches\n";
			cout << "4. None\n\n";
			cout << "8. Restart\n";
			cout << "9. Exit\n";
			cin >> choice;

			switch (choice) {
				case 1: triangle.unit = " m"; break;
				case 2: triangle.unit = " ft"; break;
				case 3: triangle.unit = " in"; break;
				case 4: triangle.unit = ""; break;
				case 8: restart = true; break;
				case 9: return 0;
				default:
					cout << "Error: Invalid input.\n";
					invalid = true;
			}
		} while (invalid);

		if (restart) {
			continue;
		}

		// Loop menu options until restart or exit
		for (;;) {
			toggle = false;

			cout << "\n---------------------------------------------\n";
			// Provide main menu options and prompt user for input
			cout << "Enter an option:\n";
			cout << "1. Find triangle's angles and area.\n";
			cout << "2. Find the incircle radius and remaining triangle area.\n";
			cout << "3. Find the circumcircle radius and remaining circle area.\n";
			cout << "4. Change output between radians and degrees.\n\n";
			cout << "8. Restart.\n";
			cout << "9. Exit." << endl;

			// Loop until valid menu input or exit.
			do {
				invalid = false;
				cin >> choice;

				switch (choice) {
					case 1: triangle.outputAngles(); break;
					case 2: triangle.outputIncircle(); break;
					case 3: triangle.outputCircumcircle(); break;
					case 4: toggle = true; break;
					case 8: restart = true; break;
					case 9: return 0;
					default:
						cout << "Error: Invalid input.\n";
						invalid = true;
				}
			} while (invalid);

			if (restart) {
				break;
			}

			if (!toggle) {
				continue;
			}

			// Extra Credit: Prompt for option to toggle output
			do {
				invalid = false;
				toggle = false;

				cout << "\nSelect angle mode:\n";
				cout << "1. Degrees\n";
				cout << "2. Radians" << endl;
				cin >> choice;

				switch (choice) {
					case 1: triangle.isRadians = false; break;
					case 2: triangle.isRadians = true; break;
					default:
						cout << "Error: Invalid input. ";
						invalid = true;
				}
			} while (invalid);
		}
	}

	return 0;
}

/* Initializes sides, angles, area, and perimeter */
void Triangle::init(double sideA, double sideB, double sideC) {
	double s; // Semi-perimenter

	// Set object sides
	a = sideA;
	b = sideB;
	c = sideC;

	// Set object angles
	radA = acos((b * b + c * c - a * a) / (2 * b * c));
	radB = acos((a * a + c * c - b * b) / (2 * a * c));
	A = radA * 180 / M_PI;
	B = radB * 180 / M_PI;
	C = (180 - A - B);
	radC = C * M_PI / 180;

	// Set object area
	s = 1.0 / 2 * (a + b + c);
	area = pow(s * (s - a) * (s - b) * (s - c), 0.5);

	perimeter = a + b + c;

	isRadians = false;
}

// Prints triangle to console
void Triangle::print() {
	cout << "\n\t    /B\\\n"
		<< "\t c /   \\ a\n"
		<< "\t  /     \\\n"
		<< "\t /A_____C\\\n"
		<< "\t     b\n" << endl;
}

/* Determines if a triangle is valid based on input sides: a, b, and c
 * @param a, b, c       Length of sides - a, b, and c
 * @return              True if valid triangle, else false */
bool Triangle::isValid(double a, double b, double c) {
	if (a <= 0.0 || b <= 0.0 || c <= 0.0) {
		return false;
	}
	return (a < b + c && b < a + c && c < a + b);
}

/* Outputs angles and area of a triangle given three sides. */
void Triangle::outputAngles() {
	cout << fixed << setprecision(2) << endl;

	if (isRadians) {
		cout << "A: " << radA << " radians.\n"
			<< "B: " << radB << " radians.\n"
			<< "C: " << radC << " radians.\n"
			<< "Area: " << area
			<< unit << (unit[0] == '\0' ? "" : "^2") << endl;
	}
	else {
		cout << "A: " << A << " degrees.\n"
			<< "B: " << B << " degrees.\n"
			<< "C: " << C << " degrees.\n"
			<< "Area: " << area
			<< unit << (unit[0] == '\0' ? "" : "^2") << endl;
	}
}

/* Outputs largest incircle of a triangle given three sides
 * and outputs remaining triangle area. */
void Triangle::outputIncircle() {
	double radius = 2 * area / perimeter;
	double remainingArea = area - Circle::getArea(radius);

	cout << fixed << setprecision(2) << endl
		<< "Incircle radius: " << radius << unit << endl
		<< "Remainder triangle area: " << remainingArea
		<< unit << (unit[0] == '\0' ? "" : "^2") << endl;
}

/* Outputs circumcircle of a triangle given three sides
 * and outputs remaining circle area. */
void Triangle::outputCircumcircle() {
	double radius = (a * b * c) / pow((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c), 0.5);
	double remainingArea = Circle::getArea(radius) - area;

	cout << fixed << setprecision(2) << endl
		<< "Circumcircle radius: " << radius << unit << endl
		<< "Remainder circle area: " << remainingArea
		<< unit << (unit[0] == '\0' ? "" : "^2") << endl;
}
