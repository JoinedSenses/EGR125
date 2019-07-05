/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 4, 2019
 Name: Arron Vinyard
 Project Description: Reads ints from a text file, calculates sum/avg
 Inputs: None
 Outputs: Text file with name, sum of scores, avg of scores
**************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

void preloadTextFile(const char file[], bool random = false, int count = 15);
int randomint(int min, int max);

int main() {
	ifstream in;
	ofstream out;
	vector<int> scores;
	int buffer;
	const char file13[] = "Exercise13_3.txt", fileLastname[] = "Vinyard.txt";
	// preloadTextFile(file13); // Preload text file for test case 1;
	preloadTextFile(file13, true); // Preload text file for test case 2;

	in.open(file13);
	if (in.fail()) {
		cout << "Failed to open text file" << endl;
		in.close();
		return 1;
	}

	// Read all ints from text file
	while (in >> buffer) {
		scores.push_back(buffer);
	}

	// Output name, sum, and avg to lastname.txt
	out.open(fileLastname);
	out << fixed << setprecision(1)
		<< "Arron Vinyard\n"
		<< "Total = " << (buffer = accumulate(scores.begin(), scores.end(), 0))
		<< "\nAverage = " << static_cast<double>(buffer) / scores.size();
	out.close();

	// Open text files so I dont have to dig through my folders for them
	system(((string)"notepad " + file13).c_str());
	system(((string)"notepad " + fileLastname).c_str());

	return 0;
}

// Preload with numbers from assignment or N random ints from 50 to 100
void preloadTextFile(const char file[], bool random, int count) {
	ofstream out(file, ios::out | ios::trunc);
	if (random) {
		for (int i = 0; i < count; i++) {
			out << randomint(50, 100) << " ";
		}
	}
	else {
		out << "100 95 88 97 71 67 80 81 82";
	}

	out.close();
}

// C style of generating random ints
// https://en.cppreference.com/w/cpp/numeric/random/rand
// https://en.cppreference.com/w/cpp/numeric/random/srand
int randomint(int min, int max) {
	// Only set random seed once based on time.
	static bool set = false;
	if (!set) { srand(time(0)); set = true; }
	return min + (rand() % (max - min + 1));
}