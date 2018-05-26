/*
 * Metaheuristics.cpp
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#include<Metaheuristics.h>

Solution::Solution(Problem* _problem) : problem(_problem), cost(0), complete(false) {}

ScoredEntity::ScoredEntity()
{
	numTimesInvoked = 0;
	score = 0.0;
}
ScoredEntity::ScoredEntity(double initialScore)
{
	numTimesInvoked = 0;
	score = initialScore;
}

bool ScoredEntity::operator<(const ScoredEntity& rhs) const
{
   return score < rhs.score;
}

//Problem::Problem() {}

void Solution::print() {}

SimulatedAnnealing::SimulatedAnnealing(Problem& p, Generator& g, NeighbourExplorer& e) : SearchAlgorithm(p)
{
	generators.insert(g);
	neighbourExplorers.insert(e);
	temperature = 1000.0;
}

void SimulatedAnnealing::run()
{
	//(*generators.begin()).generate();
	// generate a solution
	// run the loop
	// enjoy
}


