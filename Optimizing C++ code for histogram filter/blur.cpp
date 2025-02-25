#include "headers/blur.h"

using namespace std;

// OPTIMIZATION: Pass large variable by reference
vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	// OPTIMIZATION: window, DX and  DY variables have the 
    // same value each time the function is run.
  	// It's very inefficient to recalculate the vectors
    // every time the function runs. 
    // 
    // The const and/or static operator could be useful.
  	// Define and declare window, DX, and DY using the
    // bracket syntax: vector<int> foo = {1, 2, 3, 4} 
    // instead of calculating these vectors with for loops 
    // and push back
  vector < vector <float> > newGrid(grid.size(), vector<float>(grid[0].size(),0));
  
  static int h = grid.size();
  static int w = grid[0].size();
  
  static float center_p = 1.0-blurring;
  static float corner_p = blurring/12.0;
  static float adj_p = blurring/6.0;
  
  static vector<vector<float>> window ={{corner_p,adj_p,corner_p},{adj_p,center_p, adj_p},{corner_p,adj_p,corner_p}};
  
  for (int i=0; i< h; i++){
    for (int j=0; j<w; j++){
      //float grid_val = grid[i][j];
      for (int dx=-1; dx<2; dx++){
        for (int dy=-2; dy<2; dy++){
          float mult = window[dx+1][dy+1];
          int new_i = (i+dy+h)%h;
          int new_j = (j+dx+w)%w;
          newGrid[new_i][new_j] += mult*grid[i][j];
        }
      }
    }
  }
	
	// your code here
  
	return newGrid;
}
