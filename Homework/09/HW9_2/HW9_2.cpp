/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: July 9, 2018
 Project Description: Reads in dates from file, formats and outputs
 Inputs: Dates from file as ints
 Outputs: Formatted date to file
**************************************************************/
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	const string
		  fileIn = "dates.txt", fileOut = "dateOutput.txt"
		, months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	int month, day, year;
	ifstream in(fileIn);
	if (in.fail()) {
		in.close();
		return 1;
	}

	ofstream out(fileOut, ios::out, ios::trunc);
	// loop through each line. read in as ints, output/format
	while (in >> month >> day >> year) {
		if (month < 0 || month > 12 || year < -99) continue;
		out << months[month-1] << " " << -day << ", " << "20" << setfill('0') << setw(2) << -year << endl;
	}
	out.close();

	return 0;
}