#pragma once
#include "Candidate.h"
#include <string>



void Candidate::setName(string n)
{
	name = n;
}
void Candidate::setParty(string p)
{
	Candidate::party = p;
}
string Candidate::getParty()
{
	return party;
}
string Candidate::getName()
{
	return name;
}