#pragma once
#include <string>
using namespace std;

class Runner {
private:
	string First, Last, Filename;
	int Hours, Minutes, Seconds, Month, Day, Year;
	double Distance, Average;
	bool isLoggedIn;
	string fmtDate();
	string fmtTime(), fmtTime(int secs), fmtTime(double min);
	void displayHeader();
	void displayLine(int n);
	void clear();
public:
	Runner() { clear(); };
	int Login();
	void Logout();
	void EnterRun();
	void FindAverage();
	void DisplayRunResults();
	void Summary();
};

void clearcin();

enum { // Login return values
	Login_Ok = 0,
	Login_Fail,
	Login_Exit,
	Login_Back
};