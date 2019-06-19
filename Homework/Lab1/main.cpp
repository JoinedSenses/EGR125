// Name : Arron Vinyard
// Project: Lab1
// Date: 5/22/2019
// EGR-125 Lab
//
// **************************
#include <iostream> //cout, cin, <<, >>, system function
#include <string> // to use string class

using namespace std;

int main()
{
	string fullName;
	double numerator, denominator, result;
	
	cout << "Enter your full name: ";
	getline(cin, fullName);
	
	cout << "\nWelcome to the world of C++ " << fullName;
	cout << "\nNow try some integer division.";
	
	cout << "\nEnter a numerator: ";
	cin >> numerator;
	
	cout << "\nEnter a denominator: ";
	cin >> denominator;
	
	result = numerator / denominator;
	
	cout << "\nResult of " << numerator << " / " << denominator << " = " << result;
	cout << "\nI hope this ";
	cout << "program works" << endl;
	
	return 0;
}
