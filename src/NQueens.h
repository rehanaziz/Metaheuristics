/*
 * NQueens.h
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#ifndef NQUEENS_H_
#define NQUEENS_H_

#include<Metaheuristics.h>

class NQueensSolution;

class NQueens : public Problem
{
public:
	unsigned int n;
	NQueens(unsigned int _n);
	double evaluate(Solution*, double maxCost = 10000000.0);
	~NQueens() {}
};

class NQueensSolution : public Solution
{
public:
	unsigned int n;
	vector<unsigned int> positions;
	NQueensSolution(unsigned int _n) : n(_n) { positions.resize(_n); }
	void print();
	bool hasQueen(unsigned int x, unsigned int y);
	NQueensSolution* copy();
	~NQueensSolution();
};

class NQueensSolutionGenerator : public Generator
{
	NQueens& queens;
public:
	NQueensSolutionGenerator(NQueens& q) : Generator(), queens(q) {}
	NQueensSolution* generate();
};


class NQueensHillClimbingNeighbourhood : public NeighbourExplorer
{
	NQueens& queens;
public:
	NQueensHillClimbingNeighbourhood(NQueens& q) : queens(q) {}
	Solution* nextNeighbour(Solution* in);
};

#endif /* NQUEENS_H_ */
