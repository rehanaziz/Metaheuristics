/*
 * Metaheuristics.h
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#ifndef METAHEURISTICS_H_
#define METAHEURISTICS_H_

#include <iostream>
#include <list>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <math.h>
using namespace std;

class Problem;

class Solution
{
public:
	Problem* problem;
	double cost;
	bool complete;

	Solution(Problem*);
	void print();
};

class ScoredEntity
{
public:
	int numTimesInvoked;
	double score; //Lower appears first, see < below
	ScoredEntity();
	ScoredEntity(double initialScore);

	bool operator<(const ScoredEntity& rhs) const;
};

// Operations you could do on Solutions
// Generate an empty solution
// XXX: Turn the functions into public
class Generator : public ScoredEntity
{
public:
	Generator() {}
	void generate(Solution*);
	~Generator() {}
};
class NeighbourExplorer : public ScoredEntity
{
public:
	NeighbourExplorer() {}
	void nextNeighbour(Solution* in, Solution* out);
	~NeighbourExplorer() {}
};
// Insertion/repair heuristics
// Destroy heuristics
// Cross-over heuristics

class SearchAlgorithm
{
public:
	Solution* currentBestSolution;
	vector<Solution*> solutions;
	set<Generator> generators;
	set<NeighbourExplorer> neighbourExplorers;
	int iterations;
	int restarts;
	Problem& problem;

	SearchAlgorithm(Problem& p) : problem(p) {}
	Generator& nextGenerator();
	NeighbourExplorer& nextNeighbour();
	void run();
};

class SimulatedAnnealing : SearchAlgorithm
{
public:
	double temperature;

	SimulatedAnnealing(Problem& p, Generator& g, NeighbourExplorer& e);
	void run();
};

// XXX: Turn evaluate into a virtual function
class Problem
{
public:
	Problem() {}
	double evaluate(Solution*) { return 0.0; }
	~Problem() {}
};

#endif /* METAHEURISTICS_H_ */
