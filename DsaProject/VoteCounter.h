#pragma once
#include <vector>
#include "Candidate.h"
#include "BallotPaper.h"


using namespace std;

class VoteCounter {
public:
	vector<BallotPaper> ballotVector;
	vector<Candidate> candidateList;
	int deleteCandidate;
	vector<int> totals;

	VoteCounter(vector<BallotPaper>bv, vector<Candidate>cv)
	{
		ballotVector = bv;
		candidateList = cv;
	}
	void GenerateVoteResult();
};
