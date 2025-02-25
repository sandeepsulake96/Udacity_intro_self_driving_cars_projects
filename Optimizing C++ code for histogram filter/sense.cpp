#include "headers/sense.h"

using namespace std;

// OPTIMIZATION: Pass larger variables by reference
vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{

  int hit;
	for (int i=0; i<grid.size(); i++) {
		for (int j=0; j<grid[0].size(); j++) {
          	// OPTIMIZATION: Which of these variables are 					needed?
           hit = (grid[i][j] == color);
           beliefs[i][j]=beliefs[i][j]*(hit*p_hit + (1-hit)*p_miss);
        }
    }
	return beliefs;
}
