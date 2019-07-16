/*     ____   __     __
        /   /   \  /   \
       /   /      /
      /    \___/  \___/

 Date: July 1, 2019
 Name: Arron Vinyard
 Project Description: Prompts user to input int from 0 to 99 and returns amount of change returned
 Inputs: One int from 0 to 99
 Outputs: Change returned in quarters, dimes, nickels, cents
*/
//*************************************************************
#include <iostream>
using namespace std;

void Coins(int, int&, int&, int&, int&);

int main() {
	int input, Quarters, Dimes, Nickels, Cents;
	do {
		cout << "Enter an integer from 0 to 99: ";
		cin >> input;
	} while (input < 0 || input > 99);
	
	Coins(input, Quarters, Dimes, Nickels, Cents);
	
	cout << "Quarters: " << Quarters << endl
		<< "Dimes: " << Dimes << endl
		<< "Nickels: " << Nickels << endl
		<< "Cents: " << Cents << endl;
	
	return 0;
}

void Coins(int Change, int &Quarters, int &Dimes, int &Nickels, int &Cents) {
	Quarters = Change / 25;
	Change %= 25;
	Dimes = Change / 10;
	Change %= 10;
	Nickels = Change / 5;
	Cents = Change % 5;
}
