#include <iostream>
#include <fstream>
using namespace std;

void strToLower(string& str);

int main() {
	const int FILECOUNT = 4;
	const string
		output = "output.txt",
		files[FILECOUNT] = {
			  "file1"
			, "file2"
			, "file3"
			, "file4"
		},
		filetype = ".txt";
	int choices[2];
	string input, buffer;
	ifstream in;
	ofstream out;
	bool found;
	
	cout << "Which files would you like to combine?" << endl
		<< "file1\nfile2\nfile3\nfile4\n" << endl;
	
	do {
		found = false;
		cout << "Enter first file name: ";
		cin >> input;
		cin.clear();
		cin.ignore(100, '\n');
		
		strToLower(input);
		
		for (int i = 0; i < FILECOUNT; i++) {
			if (files[i].compare(input) == 0) {
				choices[0] = i;
				found = true;
			}
		}
		if (!found) {
			cout << input << " not found. ";
		}
	} while (!found);
		
	do {
		found = false;
		cout << "Enter second file name: ";
		cin >> input;
		cin.clear();
		cin.ignore(100, '\n');
		strToLower(input);
		
		for (int i = 0; i < FILECOUNT; i++) {
			if (files[i].compare(input) == 0) {
				choices[1] = i;
				found = true;
			}
		}
		if (!found) {
			cout << input << " not found. ";
		}
	} while (!found);		
	
	cout << "Combining files to " << output << endl;
	in.open((static_cast<string>(files[choices[0]]) + filetype).c_str());

	if (in.fail()) {
		cout << "Unable to open " << files[choices[0]];
		return 1;
	}
	
	out.open(output.c_str(), ios::out|ios::trunc);
	
	while (getline(in, buffer)) {
		out << buffer << endl;
	}
	
	in.close();
	in.open((static_cast<string>(files[choices[1]]) + filetype).c_str());
	
	if (in.fail()) {
		cout << "Unable to open " << files[choices[1]];
		return 1;		
	}
	
	while (getline(in, buffer)) {
		out << buffer << endl;
	}
	
	in.close();
	out.close();
	
	cout << "Successfully wrote " << files[choices[0]] << " and " << files[choices[1]] << " to " << output << endl;
	
	return 0;
}

void strToLower(string& str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
}
