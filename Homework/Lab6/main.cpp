#include <iostream>
#include <vector>
using namespace std;

bool AddToVector(vector<int>&, int);

int main() {
	int input;
	vector<int> vec;
	
	while (1) {
		cout << "Enter a number (zero to stop): ";
		cin >> input;
		
		if (input == 0) {
			break;
		}
		
		if (!AddToVector(vec, input)) {
			cout << input << " is a duplicate\n" << endl;
		}
		else {
			cout << "Your input: " << input << endl << endl;
		}
	}
	
	cout << "Your list of non-duplicating numbers is:\n ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	
	return 0;
}

bool AddToVector(vector<int> &vec, int val) {
	bool found = false;
	
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " " << val << endl;
		if (vec[i] == val) {
			found = true;
			break;
		}
	}
	if (!found) {
		vec.push_back(val);
	}
	return !found;
}
