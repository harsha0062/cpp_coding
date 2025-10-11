#include <iostream>
#include <vector>
using namespace std;

// DFS function to mark all cells of current island as visited
void dfs(vector<vector<char>>& grid, int i, int j) {
    // Base cases: Out of bounds or cell is water ('0')
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
        return;

    // Mark cell as visited (set to '0')
    grid[i][j] = '0';

    // Visit all 4 adjacent cells (up, down, left, right)
    dfs(grid, i+1, j); // Down
    dfs(grid, i-1, j); // Up
    dfs(grid, i, j+1); // Right
    dfs(grid, i, j-1); // Left
}

// Function to count the number of islands in the grid
int numIslands(vector<vector<char>>& grid) {
    // If grid is empty, return 0
    if (grid.size() == 0 || grid[0].size() == 0)
        return 0;

    int count = 0; // To count number of islands

    // Traverse all cells in the grid
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            // If cell is land ('1'), do DFS to mark entire island
            if (grid[i][j] == '1') {
                dfs(grid, i, j); // Mark all connected land as visited
                count++;         // Increment island count
            }
        }
    }

    return count; // Return total islands found
}

int main() {
    // Example input grid representing islands ('1') and water ('0')
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    // Call numIslands and print result
    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}
