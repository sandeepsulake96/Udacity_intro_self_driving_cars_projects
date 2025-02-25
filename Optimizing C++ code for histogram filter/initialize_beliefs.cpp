#include "headers/initialize_beliefs.h"

using namespace std;

// OPTIMIZATION: pass large variables by reference
vector< vector <float> > initialize_beliefs(vector< vector <char> > &grid) {

	// OPTIMIZATION: Which of these variables are necessary?
	// OPTIMIZATION: Reserve space in memory for vectors
  
  	vector< vector <float> > newGrid (grid.size(), vector<float> (grid[0].size(), 1.0 / (grid.size()* grid[0].size()))) ;
                                                                
  return newGrid;
}