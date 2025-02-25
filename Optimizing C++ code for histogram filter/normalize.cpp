#include "headers/normalize.h"
using namespace std;

// OPTIMIZATION: Pass variable by reference
vector< vector<float> > normalize(vector< vector <float> > &grid) {

  float tot_sum=0;
  static int rows=grid.size(); // assigning the size of rows from the grid to rows variable to use it in the loops
  static int cols = grid[0].size();// assigning the size of columns from the grid to cols variable

  for (int i=0; i<rows; i++){
     for (int j=0; j<cols; j++){
        tot_sum += grid[i][j];
      }
    }
  
  	for (int i=0; i<rows; i++){
      for (int j=0; j<cols; j++){
        grid[i][j]=grid[i][j]/tot_sum;
      }
    }

	return grid;
}
