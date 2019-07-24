#define _CRT_SECURE_NO_WARNINGS // suppress deprecation warnings for ctime
#include "Runner.h"
#include <iostream>
#include <sstream> // used for formatting date
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime> // used to get year and timestamp
#include <direct.h> // used for _mkdir()
using namespace std;

void fmtStr(std::string&);
int timeToSecs(int H, int M, int S);

void Runner::clear() { // Sets all values to default
	First = Last = Filename = "";
	Hours = Minutes = Seconds = Month = Day = Year = 0;
	Distance = Average = 0.0;
	isLoggedIn = false;
}

int Runner::Login() {
	fstream in, out;
	bool invalid, newUser;
	int input;
	char c;

	if (isLoggedIn) {
		cout << "A user is already logged in.";
		return Login_Fail;
	}

	// Attempt to create user folder.
	// If unable to create, put files in same dir as exe
	Filename = ".\\users\\";
	if (_mkdir(Filename.c_str()) && errno != EEXIST) {
		Filename.clear();
	}

	time_t t = time(NULL);
	cout << ctime(&t) // Display current time
		<< "Welcome to Run Logger v1.0\n-----" << endl;

	cout << "1. Login"
		<< "\n2. Exit." << endl;

	do {
		invalid = false;
		cin >> input; clearcin();
		switch (input) {
			case 1:
				break;
			case 2:
				return Login_Exit;
			default:
				invalid = true;
		}
	} while (invalid);
	
	cout << "Are you a:"
		<< "\n1. New User"
		<< "\n2. Returning User" << endl;

	do {
		invalid = false;
		cin >> input; clearcin();
		switch (input) {
			case 1: {
				newUser = true;
				break;
			}
			case 2: {
				newUser = false;
				break;
			}
			default: invalid = true;
		}
	} while (invalid);

	cout << "Please enter first and last name: ";
	cin >> First >> Last; clearcin();
	cout << endl;

	fmtStr(First);
	fmtStr(Last);

	Filename += Last + First + ".txt";

	if (newUser) {
		in.open(Filename.c_str());
		if (!in.fail()) { // Check if program could open file
			cout << "Profile already exists. " << endl;
		}
		else {
			cout << "Creating new profile." << endl;
			out.open(Filename.c_str(), ios::out | ios::trunc);
			out.close();
			cout << "Profile saved to " << Filename << endl;
		}
		in.close();
	}
	else {
		in.open(Filename.c_str());
		if (in.fail()) {
			cout << "No existing profile with name " << First << " " << Last
				<< ".\nCreate new profile? [Y/N]" << endl;

			do {
				invalid = false;
				cin >> c; clearcin();
				switch (tolower(c)) {
					case 'y': break; // Continue making profile
					case 'n': // End function and back out
						cout << endl;
						in.close();
						return Login_Back;
					default: invalid = true;
				}
			} while (invalid);

			out.open(Filename.c_str(), ios::out|ios::trunc); // Create file
			out.close();

			cout << "Profile saved to " << Filename << endl;
		}
		in.close();
	}
	isLoggedIn = true;
	cout << "Welcome " << First << ' ' << Last << ".\n" << endl;
	return Login_Ok;
}

void Runner::Logout() {
	if (!isLoggedIn) return;
	clear();
	cout << "Successfully logged out." << endl;
}

void Runner::EnterRun() {
	ofstream out;
	bool invalid, save = false;
	char input;
	if (!isLoggedIn) { // User verification
		cout << "No user is logged in." << endl;
		return;
	}
//== Prompt for run data
	do {
		invalid = false;
		cout << "Enter date of run (MM-DD-YYYY): ";
		cin >> Month >> Day >> Year; clearcin();
		Day = abs(Day); Year = abs(Year);

		if (Month < 1 || Month > 12) {
			cout << "Invalid month. ";
			invalid = true;
		}
		if (Day < 1 || Day > 31) {
			cout << "Invalid day. ";
			invalid = true;
		}

		/* Project says to have year input, but then to require it be
		   current year, which is pointless. Either allow any year or
		   just have project make it current year. I'm only adding this
		   because project requirements tells me to. Normally I would
		   question this sort of decision as an engineer, but it's the
		   last week of class and I don't care. */

		time_t t = time(NULL); // Provided via ctime
		if (Year != localtime(&t)->tm_year + 1900) {
			cout << "Invalid year. Must be current year. ";
			invalid = true;
		}

		if (invalid) cout << endl;
	} while (invalid);

	do {
		invalid = false;
		cout << "Enter distance (miles): ";
		cin >> Distance; clearcin();
		if (Distance <= 0) {
			cout << "Distance must be positive." << endl;
			invalid = true;
		}
	} while (invalid);

	do {
		invalid = false;
		cout << "Enter time (HH MM SS): ";
		cin >> Hours >> Minutes >> Seconds; clearcin();
		if (Hours < 0) {
			cout << "Hours must be non-negative." << endl;
			invalid = true;
		}
		if (Minutes < 0 || Minutes > 60) {
			cout << "Minutes must be in range of 0 to 60." << endl;
			invalid = true;
		}
		if (Seconds < 0 || Seconds > 60) {
			cout << "Seconds must be in range of 0 to 60." << endl;
			invalid = true;
		}
	} while (invalid);
	cout << endl;
	DisplayRunResults();

	do { // Prompt to save
		invalid = false;
		cout << "Would you like to save this run? [Y/N]: ";
		cin >> input; clearcin();
		switch (tolower(input)) {
			case 'y':
				save = true;
				break;
			case 'n':
				break;
			default:
				cout << "Invalid input." << endl;
				invalid = true;
		}
	} while (invalid);

	if (save) { // Output to file if they chose to save
		out.open(Filename.c_str(), ios::out | ios::app);
		out << Month << ' '
			<< Day << ' '
			<< Year << ' '
			<< Distance << ' '
			<< Hours << ' '
			<< Minutes << ' '
			<< Seconds << endl;
		out.close();
		cout << "Your run has been saved.\n" << endl;
	}
}

// Averages current run as min per mile
void Runner::FindAverage() {
	double mins = timeToSecs(Hours, Minutes, Seconds) / 60.0;
	Average = mins / Distance;
}

// Displays current run
void Runner::DisplayRunResults(bool summary) {
	if (!isLoggedIn) {
		cout << "No user is logged in." << endl;
		return;
	}

	// If this isn't displayed via summary, display header/footer
	if (!summary) { 
		displayHeader();
	}

	FindAverage();
	cout << fixed;
	cout << fmtDate() << setw(4) << ':'
		<< setw(16) << setprecision(2) << Distance
		<< setw(12) << fmtTime()
		<< fmtTime(Average) << endl;

	if (!summary) {
		displayLine(61);
	}
}

// Displays all run results if they exist
void Runner::Summary() {
	bool hasContents = false;
	int totalSeconds = 0;
	double totalMiles = 0.0;
	ifstream in;

	if (!isLoggedIn) {
		cout << "No user is logged in." << endl;
		return;
	}

	in.open(Filename.c_str());
	if (in.fail()) {
		cout << "Unable to open profile." << endl;
		return;
	}

	displayHeader();

	while (in >> Month >> Day >> Year >> Distance >> Hours >> Minutes >> Seconds) {
		hasContents = true;
		totalSeconds += timeToSecs(Hours, Minutes, Seconds);
		totalMiles += Distance;
		DisplayRunResults(true);
	}
	in.close();

	if (!hasContents) {
		cout << "No previous run data." << endl;
		displayLine(61);
		return;
	}

	displayLine(61);

	cout << "Total duration: " << fmtTime(totalSeconds) << endl;
	cout << "Total miles: " << totalMiles << endl;
	cout << "Overall Average: " << fmtTime(totalSeconds / 60.0 / totalMiles) << " (min/mile)" << endl << endl;
}

// Returns string of run date
string Runner::fmtDate() {
	static string const months[] = {
		"Jan", "Feb", "Mar", "Apr",
		"May", "Jun", "Jul", "Aug",
		"Sep", "Oct", "Nov", "Dec"
	};
	stringstream stream;
	stream << setw(2) << setfill('0') << months[Month - 1] << ' '
		<< setw(2) << setfill('0') << Day << ' '
		<< Year;
	return stream.str();
}

// Returns string of run time
string Runner::fmtTime() {
	stringstream stream;
	stream << Hours << ':' << Minutes << ':' << Seconds;
	return stream.str();
}

// Converts seconds to HH:MM:SS string
string Runner::fmtTime(int sec) {
	stringstream stream;
	stream << setw(2) << setfill('0') << sec / 3600 << ':'
		<< setw(2) << setfill('0') << sec % 3600 / 60 << ':'
		<< setw(2) << setfill('0') << sec % 3600 % 60;
	return stream.str();
}

// Converts minutes to MM::SS string
string Runner::fmtTime(double min) {
	stringstream stream;
	int m = (int)min;
	stream << m << ':' << setw(2) << setfill('0') << (int)((min - m) * 60);
	return stream.str();
}

// Clears cin for controlled input
void clearcin() {
	cin.clear();
	cin.ignore(100, '\n');
}

// Formatter for consistent strings
void fmtStr(string& str) {
	str[0] = toupper(str[0]);
	for (size_t i = 1; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
}

int timeToSecs(int H, int M, int S) {
	return H * 3600 + M * 60 + S;
}

// Displays header for run summaries
void Runner::displayHeader() {
	cout << left << setw(15) << "Date"
		<< setw(16) << "Distance (mi)"
		<< setw(12) << "Time"
		<< "Average (min/mile)\n";
	displayLine(61);
}

// Outputs n number of '-'s to a line
void Runner::displayLine(int n) {
	for (int i = 0; i < n; i++) {
		cout << '-';
	} cout << endl;
}
