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
#include <algorithm>
#include <numeric>

using namespace std;

class Problem;

class Solution
{
public:
	double cost;
	bool complete;

	Solution();
	virtual void print() {}
	//XXX: Change to copy-constructor
	Solution* copy();
	virtual ~Solution() = default;
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
	virtual Solution* generate() { return 0; }
	virtual ~Generator() = default;
};
class NeighbourExplorer : public ScoredEntity
{
public:
	NeighbourExplorer() {}
	virtual Solution* nextNeighbour(Solution* in) { cout << "BADDD\n"; return 0; }
	virtual ~NeighbourExplorer() = default;
};
// Insertion/repair heuristics
// Destroy heuristics
// Cross-over heuristics

class SearchAlgorithm
{
public:
	Problem& problem;
	Solution* bestSolution;
	Solution* currSolution;
	double costBestSolution;
	vector<Solution*> solutions;
	vector<Generator*> generators; //XXX: Convert this into a sorted set
	vector<NeighbourExplorer*> neighbourExplorers; //XXX: Convert this into a sorted set
	int iterations;
	int restarts;

	SearchAlgorithm(Problem& p) : problem(p), iterations(0), restarts(0) {}
	Generator* nextGenerator();
	NeighbourExplorer* nextNeighbourHeuristic();
	virtual void run();
	bool getNextIteration();
	virtual ~SearchAlgorithm() = default;
};

class Problem
{
public:
	Problem() {}
	virtual double evaluate(Solution*, double maxCost = 100000000.0) { cout << "BAD\n"; return 100000.0; }
	virtual ~Problem() = default;
};

/*
class SimulatedAnnealing : public SearchAlgorithm
{
public:
	double temperature;

	SimulatedAnnealing(Problem& p, Generator& g, NeighbourExplorer& e);
	bool getNextIteration();
};
*/

class HillClimbing : public SearchAlgorithm
{
public:
	HillClimbing(Problem& p, Generator* g, NeighbourExplorer* e);
	~HillClimbing() {}
};


#endif /* METAHEURISTICS_H_ */
