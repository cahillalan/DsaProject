#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "BallotPaper.h"
//#include "Candidate.h"
#include "VoteCounter.h"

using namespace std;



	
int main()
{
	// Get The infrmation from the file
	string incomingData;
	ifstream infile;
	infile.open("CandidatesAndVotes.txt");
	vector<string> textvector;
	while (!infile.eof())
	{
		getline(infile, incomingData); // Saves the line in STRING.
		textvector.push_back(incomingData); //push string on to vector.
	}
	infile.close();

	string temp = textvector[0];
	char numOfCan = temp[0];
	int newnum = temp[0] - '0';
	vector<string> candidateDetails;
	for (int x = 1; x <= newnum; x++)
	{
		candidateDetails.push_back(textvector[x]); //put all candidate details into single vector.
	}
//*****************************************************************************
	int voteStart = newnum + 2;
	int xpos = 0;
	vector<BallotPaper> ballotList;
	for (int x = voteStart; x < textvector.size(); x++)
	{	
		vector<int> tempv;
		string temp = textvector[x];
		for (int y = 0; y < temp.size(); y++)
		{
			int newint = temp[y] - '0';
			tempv.push_back(newint);
		}

		BallotPaper alan = BallotPaper(tempv);

		ballotList.push_back(alan);  // Create Ballot Paper Instances
		xpos = xpos + 1;
	}

	// Create Candidate Instances.*************************************************************
	vector<Candidate> candidateList;
	for (int x = 0; x < candidateDetails.size(); x++)
	{
		vector<string> split;
		stringstream ss(candidateDetails[x]);
		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			split.push_back(substr);
		}
		if (split.size() == 2)
		{
			candidateList.push_back(Candidate(split[0], x + 1, split[1]));
		}
		else
		{
			candidateList.push_back(Candidate(split[0], x + 1));
		}
	}
	VoteCounter myvote(ballotList,candidateList);
	myvote.GenerateVoteResult();
	system("pause");
}
