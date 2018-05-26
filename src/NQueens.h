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
	double evaluate(NQueensSolution*);
	~NQueens() {}
};

class NQueensSolution : public Solution
{
public:
	unsigned int n;
	vector<unsigned int> positions;
	NQueensSolution(NQueens*);
	void print();
	~NQueensSolution();
};

class NQueensSolutionGenerator : public Generator
{
public:
	void generate(NQueensSolution* in);
};


#endif /* NQUEENS_H_ */
