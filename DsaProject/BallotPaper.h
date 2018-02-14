#pragma once
#include <vector>

using namespace std;
class BallotPaper {
public:
	vector<int> preference;

	BallotPaper(vector<int> votes)
	{
		for (int x = 0; x < votes.size(); x++)
		{
			preference.push_back(votes[x]);
		}
	}
	void setNthpreference(int n, int p);
	int getNthPreference(int n);
};