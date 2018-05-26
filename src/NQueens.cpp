/*
 * NQueens.cpp
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#include<NQueens.h>

NQueens::NQueens(unsigned int _n) : n(_n) {}

NQueensSolution::NQueensSolution(NQueens* parent) : Solution(parent)
{
	n = parent->n;
}

NQueensSolution::~NQueensSolution() {}

void NQueensSolutionGenerator::generate(NQueensSolution* in)
{
	in->positions.clear();
	in->positions.resize(in->n);
	for(unsigned int i = 0; i < in->n; i++)
		in->positions[i] = i;

	in->problem->evaluate(in);
}

void NQueensSolution::print()
{
	for(unsigned int i = 0; i < n; i++)
	{
		for(unsigned int j = 1; j < n; j++)
		{
			cout << (i == positions[j] ? "Q " : "- ");
		}
		cout << endl;
	}
	cout << "Clashes:" << cost << endl;
}

double NQueens::evaluate(NQueensSolution* s)
{
	double cost = 0.0;
	for(unsigned int i = 0; i < n-1; i++)
	{
		unsigned queens = 0;
		for(unsigned j = 0; j < n-i; j++)
		{
			queens += (j == s->positions[i]) ? 1 : 0;
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	for(unsigned int j = 1; j < n-1; j++)
	{
		unsigned queens = 0;
		for(unsigned int i = 0; i < n-j; i++)
		{
			queens += (j == s->positions[i]) ? 1 : 0;
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	for(unsigned int i = 0; i < n-1; i++)
	{
		unsigned queens = 0;
		for(unsigned j = n-1; j >= i; j--)
		{
			queens += (j == s->positions[i]) ? 1 : 0;
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	for(unsigned int j = n-1; j < n-1; j++)
	{
		unsigned queens = 0;
		for(unsigned i = n-1; i >= j; i--)
		{
			queens += (j == s->positions[i]) ? 1 : 0;
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	s->cost = cost;
	return cost;
}
