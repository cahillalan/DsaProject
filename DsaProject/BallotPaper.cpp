#pragma once
#include "BallotPaper.h"



void BallotPaper::setNthpreference(int n, int p)
{
	preference[n] = p;
}
int BallotPaper::getNthPreference(int n)
{
	int p;
	if (n < 6)
	{
		p = preference[n];
	}
	else
		p = 0;

	return p;
}