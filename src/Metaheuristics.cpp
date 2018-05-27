/*
 * Metaheuristics.cpp
 *
 *  Created on: 26 May 2018
 *      Author: raaziz
 */

#include<Metaheuristics.h>
#include <NQueens.h>

Solution::Solution() : cost(0), complete(false) {}

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

Generator* SearchAlgorithm::nextGenerator() { return generators[0]; }
NeighbourExplorer* SearchAlgorithm::nextNeighbourHeuristic() { return neighbourExplorers[0]; }

void SearchAlgorithm::run()
{
	cout << "SearchAlgo::run()\n";
	Solution* currSolution = nextGenerator()->generate();

	costBestSolution = problem.evaluate(currSolution);
	bestSolution = currSolution;
	bestSolution->print();

	Solution* nextSolution;

	cout << "After printing\n";

	while( (nextSolution = nextNeighbourHeuristic()->nextNeighbour(currSolution)) )
	{
		delete currSolution;
		currSolution = nextSolution;
		nextSolution = 0;

		iterations++;
		currSolution->print();
	}

}

/*
SearchAlgorithm::~SearchAlgorithm()
{
	if(bestSolution != NULL) delete bestSolution;
	if(currSolution != NULL) delete currSolution;
	for(Solution * s: solutions) delete s;
}*/

HillClimbing::HillClimbing(Problem& p, Generator* g, NeighbourExplorer* e) : SearchAlgorithm(p)
{
	//this->generators.clear();
	//this->neighbourExplorers.clear();
	this->generators.push_back(g);
	this->neighbourExplorers.push_back(e);
}

/*
SimulatedAnnealing::SimulatedAnnealing(Problem& p, Generator* g, NeighbourExplorer* e) : SearchAlgorithm(p)
{
	this->generators.push_back(g);
	this->neighbourExplorers.push_back(e);
	temperature = 1000.0;
}
*/

/*
template<class Sol>
void SimulatedAnnealing<Sol>::run()
{
	//(*generators.begin()).generate();
	// generate a solution
	// run the loop
	// enjoy
}
*/


