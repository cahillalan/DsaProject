#pragma once
#include "VoteCounter.h"
#include <iostream>

void VoteCounter::GenerateVoteResult()
{
	// loop through for the amount of candidates in the list, a candidate should be deleted after every round.
	for (int x = 0; x < candidateList.size() - 1; x++)
	{
		// create a new vector of candidates
		vector<Candidate> newCandidates;
		for (int c = 0; c < candidateList.size(); c++)
		{
			if (candidateList[c].removed == false)
			{
				newCandidates.push_back(candidateList[c]);
			}
		}
		totals.clear(); // clear totals list and implement a zero.
		for (int z = 0; z < newCandidates.size(); z++)
		{
			totals.push_back(0);
		}
		// loop through ballot vector and then vectors in the instances to find the preference of that ballot paper.
		//add one to vector position.
		for (int y = 0; y < ballotVector.size(); y++)
		{
			int i = 0;
			while ((ballotVector[y].preference[i]) == 0)
			{

				i++;
			}

			int vote = ballotVector[y].preference[i];
			for (int z = 0; z < newCandidates.size(); z++)
			{

				if (newCandidates[z].placeOnCard == vote)
				{
					totals[z] += 1;
				}
			}
		}
		int lowest = ballotVector.size();
		//find the lowest votes.
		for (int a = 0; a < totals.size(); a++)
		{
			if (totals[a] < lowest)
			{
				lowest = totals[a];
			}
		}

		// record the vector to the instances
		for (int a = 0; a < totals.size(); a++)
		{
			newCandidates[a].numberOfPrefs = totals[a];
		}
		// put lowest candidates into a vector.
		vector<Candidate> lowestCandidate;
		for (int a = 0; a < totals.size(); a++)
		{
			if (totals[a] == lowest)
			{
				lowestCandidate.push_back(newCandidates[a]);
			}
		}

		// sort the vector of candidates.
		vector <Candidate> sortedList;


		for (int a = 0; a < newCandidates.size(); a++)
		{
			Candidate current = newCandidates[a];
			if (sortedList.size() == 0)
			{
				sortedList.push_back(newCandidates[a]);
			}
			else
			{

				for (int p = 0; p < sortedList.size(); p++)
				{
					if (current.numberOfPrefs > sortedList[p].numberOfPrefs)
					{
						Candidate swap = sortedList[p];
						sortedList[p] = current;
						current = swap;
					}
				}
				sortedList.push_back(current);
			}
		}

		// list the candidates
		cout << "The Voting results for Round " << x + 1 << " are as follows" << endl;
		for (int a = 0; a < sortedList.size(); a++)
		{
			cout << a + 1 << ":" << sortedList[a].name << ".... Votes: " << sortedList[a].numberOfPrefs << endl;
		}

		//find the number to be deleted in the ballotvector
		int deletedNumber;
		deletedNumber = lowestCandidate[0].placeOnCard;

		cout << "The Candidate with lowest votes who will be removed is " << lowestCandidate[0].name << " with: " << lowestCandidate[0].numberOfPrefs << " Votes" << endl;
		cout << endl;
		cout << endl;
		if (newCandidates.size() == 2)
		{
			cout << endl;
			cout << endl;
			cout << "*****************************" << endl;
			cout << "The OverAll winner of the vote is " << sortedList[0].name << " with a final vote count of : " << sortedList[0].numberOfPrefs << endl;
			cout << "*****************************" << endl;
		}
		for (int w = 0; w < candidateList.size(); w++)
		{
			if (candidateList[w].placeOnCard == deletedNumber)
			{
				candidateList[w].removed = true;
			}
		}

		// delete the number to be deleted.
		for (int a = 0; a < ballotVector.size(); a++)
		{
			for (int b = 0; b < candidateList.size(); b++)
			{
				if (ballotVector[a].preference[b] == deletedNumber)
				{
					ballotVector[a].preference[b] = 0;
				}
			}
		}
	}
}