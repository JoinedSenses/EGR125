/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date:
 Name:
 Project Description:
 Inputs:
 Outputs:
**************************************************************/
#include <iostream>
#include <fstream>
#include <ctime> // used for random int seed
using namespace std;

void preloadFile(string); // Loads file with random ints
int randomint(int min, int max);

int main() {
	ifstream in;
	const int SIZE = 200;
	int data[SIZE], buffer, count = 0, sum = 0, above = 0, below = 0;
	double average;
	const string file = "file.txt";
	preloadFile(file);

	in.open(file);
	if (in.fail()) {
		in.close();
		return 1;
	}

	while (in >> buffer && count < SIZE) {
		data[count++] = buffer;
		sum += buffer;
	}

	average = static_cast<double>(sum) / count;

	for (int i = 0; i < count; i++) {
		if (data[i] > average) {
			above++;
		}
		else if (data[i] < average) {
			below++;
		}
	}

	cout << "The average of " << count << " values is " << average
		<< "\nThere are " << below << " values less than the average\n"
		<< " and " << above << " values greater than the average" << endl;

	system(((string)"notepad " + file).c_str()); // Open file
	return 0;
}

void preloadFile(string file) {
	ofstream out(file, ios::out | ios::trunc);
	int randc; // Random int count to output to file
	do { // As per instruction, close to 100, but not exactly
		randc = randomint(90, 110);
	} while (randc == 100);

	for (int i = 0; i < randc; i++) { // Load up file with randc ints from -500 to 500
		out << randomint(-500, 500)
		<< (randomint(1, 4) == 4 ? "\n" : " "); // .25 chance of new line
	}

	out.close();
}

int randomint(int min, int max) {
	static bool set = false;
	if (!set) { srand(time(0)); set = true; }
	return min + (rand() % (max - min + 1));
}