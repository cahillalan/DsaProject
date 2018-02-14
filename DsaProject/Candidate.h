#pragma once
#include <vector>
#include <string>
using namespace std;

class Candidate {
public:
	string name;
	string party;
	bool removed;
	int numberOfPrefs;
	int placeOnCard;
	Candidate();
	Candidate(string n, int place, string p = "")
	{
		name = n;
		party = p;
		placeOnCard = place;
		removed = false;
	}

	void setName(string n);
	void setParty(string p);
	string getParty();
	string getName();
};