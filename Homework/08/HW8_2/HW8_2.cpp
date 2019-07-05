/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 4, 2019
 Name: Arron Vinyard
 Project Description: Reads in a text file, solves triangles, outputs to another file
 Inputs: Input text file with 8 lines, 3 values per line
 Outputs: Triangle sides and solved angles
**************************************************************/
#define _USE_MATH_DEFINES // Required for M_PI in Visual Studio
#include <cmath>
#include <fstream>
#include <numeric>
#include <iomanip>
using namespace std;

void triangle_SolveAngles(double, double, double, double&, double&, double&);
void preloadTextFile(const char file[], int lines);
double randomdouble(double min, double max);

int main() {
	const char input[] = "input.txt", output[] = "output.txt";
	const int N = 8, W1 = 9, W2 = 14;
	double sides[3], A, B, C;
	ifstream in;
	ofstream out;
	int i = 0, j = 0; // counters
	preloadTextFile(input, N); // Generates txt file to make my life easier.

	in.open(input);
	if (in.fail()) {
		in.close();
		return 1;
	}

	out.open(output, ios::out | ios::trunc);
	out << fixed << setprecision(2) << left
		<< setw(W1) << "Side a" << setw(W1) << "Side b" << setw(W1) << "Side c"
		<< setw(W2) << "Angle A(deg)" << setw(W2) << "Angle B(deg)" << "Angle C(deg)" << endl;

	// Loop through N lines, read in three doubles, solve, output
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			in >> sides[j];
		}
		triangle_SolveAngles(sides[0], sides[1], sides[2], A, B, C);
		out << setw(W1) << sides[0] << setw(W1) << sides[1] << setw(W1) << sides[2]
			<< setw(W2) << A << setw(W2) << B << C << endl;
	}

	in.close();
	out.close();

	// Open project files so i dont have to dig through folders
	system(((string)"notepad " + input).c_str());
	system(((string)"notepad " + output).c_str());
	return 0;
}

void triangle_SolveAngles(double a, double b, double c, double& A, double& B, double& C) {
	A = acos((b * b + c * c - a * a) / (2 * b * c)) * 180 / M_PI;
	B = acos((a * a + c * c - b * b) / (2 * a * c)) * 180 / M_PI;
	C = (180 - A - B);
}

// Preload with numbers from assignment and 4 lines of 3 random doubles
void preloadTextFile(const char file[], int lines) {
	ofstream out(file, ios::out | ios::trunc);
	out << "20     15     10\n5      12     13\n"
		<< "10     10     14.142\n50     60     70"
		<< fixed << setprecision(3) << left;
	for (int i = 0; i < lines - 4; i++) {
		out << endl;
		for (int j = 0; j < 3; j++) {
			out << setw(7) << randomdouble(10.0, 20.0);
		}
	}
	out.close();
}

// Similar to random int range generation, but for doubles
double randomdouble(double min, double max) {
	// Only set random seed once based on time.
	static bool set = false;
	if (!set) { srand(time(0)); set = true; }
	return  (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}