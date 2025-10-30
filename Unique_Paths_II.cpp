#include <iostream>
#include <vector>
using namespace std;

// Function to compute the number of unique paths with obstacles
int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();         // Number of rows
    int n = grid[0].size();      // Number of columns
    if(grid[0][0]==1)            // If the starting cell has an obstacle, return 0
        return 0;
    
    // Update the grid in place to store the count of paths for each cell
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            // Handling the first row or first column separately
            if(i==0 || j==0){
                if((grid[i][j]==1) || (i!=0 && grid[i-1][0]==0) || (j!=0 && grid[i][j-1]==0)) {
                    // If current cell is obstacle or previous cell in the row/col is 0 (not reachable)
                    grid[i][j]=0;
                } else {
                    // Path is possible for the first cell in its row or column
                    grid[i][j]=1;
                }
            } else {
                if(grid[i][j]==1)
                    grid[i][j]=0; // Obstacle cell is unreachable
                else
                    // Number of ways to reach current cell: sum of ways from top and left
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
    // Result in the bottom-right cell
    return grid[m - 1][n - 1];
}

int main() {
    // Example input grid: 0 for free cell, 1 for obstacle
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Print the number of unique paths from top-left to bottom-right
    cout << "Unique Paths with Obstacles: " << uniquePathsWithObstacles(grid) << endl;

    return 0;
}
