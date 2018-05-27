//============================================================================
// Name        : Metaheuristics.cpp
// Author      : Rehan Aziz
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<Metaheuristics.h>
#include<NQueens.h>

using namespace std;

int main() {
	NQueens nqueens(300);
	NQueensSolutionGenerator nqueensGen(nqueens);
	NQueensHillClimbingNeighbourhood nQueensNeighbourhood(nqueens);

	HillClimbing algo(nqueens, &nqueensGen, &nQueensNeighbourhood);

	cout<<"Running the algorithm...\n";
	algo.run();

	return 0;
}
