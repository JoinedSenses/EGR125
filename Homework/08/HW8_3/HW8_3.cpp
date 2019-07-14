/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/

 Date: July 6, 2019
 Name: Arron Vinyard
 Project Description: Reads in a large file of data and outputs information
 Inputs: BigData.dat, containing a large quantity of values
 Outputs: Count, min, max, negatives, and count between 100-200
**************************************************************/
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream in;
	double data, min = 0.0, max = 0.0;
	int count = 0, negc = 0, rangec = 0;

	in.open("BigData.dat");
	if (in.fail()) {
		in.close();
		return 1;
	}

	// Begin reading in values
	while (in >> data) {
		static bool first = true;
		// Initialize min/max to first value
		if (first) {
			min = max = data;
			first = false;
		}
		else if (max < data) {
			max = data;
		}
		else if (data < min) {
			min = data;
		}

		if (100.0 < data && data < 200.0) {
			rangec++;
		}
		else if (data < 0) {
			negc++;
		}
		count++;
	}

	// Output resutls
	cout << "There are " << count << " values in the data file." << endl
		<< "The smallest value is " << min << endl
		<< "The largest value is " << max << endl
		<< negc << " values are negative" << endl
		<< rangec << " values are between 100 and 200" << endl;

	in.close();
	return 0;
}