/*
 * NQueens.cpp
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#include<NQueens.h>

NQueens::NQueens(unsigned int _n) : n(_n) {}

NQueensSolution::~NQueensSolution() {}

NQueensSolution* NQueensSolutionGenerator::generate()
{
	NQueensSolution* s = new NQueensSolution(queens.n);
	s->positions.clear();
	s->positions.resize(queens.n);
	for(unsigned int i = 0; i < s->n; i++)
		s->positions[i] = i;

	random_shuffle(s->positions.begin(), s->positions.end());

	return s;
}

void NQueensSolution::print()
{
//	for(unsigned int i = 0; i < n; i++)
//	{
//		for(unsigned int j = 0; j < n; j++)
//		{
//			cout << (hasQueen(i,j) ? "Q " : "- ");
//		}
//		cout << endl;
//	}
	cout << "Clashes:" << cost << endl;
	for(unsigned int i = 0; i < n; i++) cout << positions[i] << " ";
	cout << endl;
}

bool NQueensSolution::hasQueen(unsigned int x, unsigned int y)
{
	return positions[y] == x;
}

double NQueens::evaluate(Solution* s, double maxCost)
{
	NQueensSolution* sCast = dynamic_cast<NQueensSolution*>(s);
	double cost = 0.0;
	unsigned int high = n - 1;

	for(unsigned int i = 0; i <= high && cost < maxCost; i++)
	{
		unsigned int queens = 0;
		for(unsigned j = 0; j <= high-i; j++)
		{
			queens += sCast->hasQueen(i+j, j);
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	for(unsigned int j = 1; j < high && cost < maxCost; j++)
	{
		unsigned int queens = 0;
		for(unsigned int i = 0; i <= high-j; i++)
		{
			queens += sCast->hasQueen(i, i+j);
		}
		cost += queens > 0 ? queens - 1 : 0;
	}

	//cout << endl << endl << endl;
	for(unsigned int i = high; i > 0 && cost < maxCost; i--)
	{
		unsigned int queens = 0;
		for(unsigned j = 0; j <= i; j++)
		{
			queens += sCast->hasQueen(i-j, j);
		}
		cost += queens > 0 ? queens - 1 : 0;
		//if(i == 6) cout << "i " << i << " queens" << queens << endl;
	}

	for(unsigned int j = 1; j < high && cost < maxCost; j++)
	{
		unsigned int queens = 0;
		for(unsigned i = high; i >= j; i--)
		{
			queens += sCast->hasQueen(i, j-i+high);
		}
		cost += queens > 0 ? queens - 1 : 0;

		//if(j == 2) cout << "j " << j << " queens" << queens << endl;
	}

	sCast->cost = cost;
	return cost;
}

NQueensSolution* NQueensSolution::copy()
{
	NQueensSolution* c = new NQueensSolution(n);
	for(unsigned int i = 0; i < n; i++) c->positions[i] = positions[i];
	return c;
}

Solution* NQueensHillClimbingNeighbourhood::nextNeighbour(Solution* in)
{
	//cout << "NQueensHillClimbingNeighbourhood::nextNeighbour()\n";
	double inCost = in->cost;
	unsigned int n = queens.n - 1; //highest index

	NQueensSolution* inCast = dynamic_cast<NQueensSolution*>(in);
	NQueensSolution* best = inCast;

	//NQueensSolution* best = in;
	double currBestCost = inCost;

	vector<unsigned int> v(n);
	iota(v.begin(), v.end(), 0);
	random_shuffle(v.begin(), v.end()); // speeds up significantly

	for(unsigned int i = 0; i < n; i++)
	{
		for(unsigned int j = i+1; j < n; j++)
		{
			NQueensSolution* neighbour = inCast->copy();
			unsigned int iPos = neighbour->positions[v[i]];
			unsigned int jPos = neighbour->positions[v[j]];

			neighbour->positions[v[i]] = jPos;
			neighbour->positions[v[j]] = iPos;

			double neighbourCost = queens.evaluate(neighbour, currBestCost);
			if(neighbourCost < currBestCost)
			{
				if(best != in) delete best;
				currBestCost = neighbourCost;
				best = neighbour;
				return best; // Comment if we want to explore the entire neighbourhood and pick the best improvement, but this works much better
			}
			else delete neighbour;
		}
	}

	return best == in ? NULL : best;
}
