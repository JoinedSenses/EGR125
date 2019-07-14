/*     ____   __     __
		/   /   \  /   \
	   /   /      /
	  /    \___/  \___/
 Name: Arron Vinyard
 Date: July 9, 2019
 Project Description:
 Inputs:
 Outputs:
**************************************************************/
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isVowel(char c);
bool isWhiteSpace(char c);

int main() {
	unsigned int tempE, wordCount, charCount=0, whitespaceCount=0
		, eEndCount=0, sixLetterCount=0, vowelStartCount=0, ateCount=0
		, eCount=0, twoECount=0;
	char c;
	string word;
	vector<string> words;
	ifstream in("USDictionary.txt");

	if (in.fail()) {
		in.close();
		return 1;
	}

	while (in.get(c)) { // Loop through every char
		if (!isWhiteSpace(c)) { // if not whitespace, push char to string
			word.push_back(c);
		}
		else { 
			whitespaceCount++;
			if (!word.empty()) { // else, push word to vector
				words.push_back(word);
				word.clear();
			}
		}
	}

	if (!word.empty()) {
		words.push_back(word);
		word.clear();
	}

	in.close();

	wordCount = words.size(); // loop through list of words & get info
	for (unsigned int i = 0; i < wordCount; i++) {
		tempE = 0;
		word = words[i];
		charCount += word.length();

		if (word.length() == 6) {
			sixLetterCount++;
		}

		if (isVowel(word[0])) {
			vowelStartCount++;
		}

		if (word.find("ate") != -1) {
			ateCount++;
		}

		for (unsigned int i = 0; i < word.length(); i++) {
			char c = word[i];
			if (c == 'e') {
				tempE++;
				if (i == word.length() - 1) {
					eEndCount++;
				}
			}
		}

		eCount += tempE;
		if (tempE > 1) {
			twoECount++;
		}
	}

	cout << "Word count: " << wordCount << endl
		<< "Char count (non-whitespace): " << charCount << endl
		<< "Char count (including whitespace): " << charCount + whitespaceCount << endl
		<< "Words ending with 'e': " << eEndCount << endl
		<< "Six letter words: " << sixLetterCount << endl
		<< "Words starting with vowel: " << vowelStartCount << endl
		<< "Words containing \"ate\": " << ateCount << endl
		<< "Total 'e' count: " << eCount << endl
		<< "Words containing two 'e's: " << twoECount << endl;

	return 0;
}

bool isVowel(char c) {
	switch (tolower(c)) {
		case 'a': case 'e': case 'i': case 'o': case 'u': return true;
	}
	return false;
}

bool isWhiteSpace(char c) {
	switch (c) {
		case ' ': case '\t': case '\n': case '\f': case '\r': return true;
	}
	return false;
}