#include <iostream>
#include <vector>
using namespace std;

/*
 * Returns the number of unique paths from top-left to bottom-right
 * of an m x n grid moving only down or right.
 */
int uniquePaths(int m, int n) {
    vector<vector<int>> grid(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0)
                grid[i][j] = 1;  // Only one way to reach first row/column cells
            else
                grid[i][j] = grid[i][j - 1] + grid[i - 1][j];  // Sum of left and top cells
        }
    return grid[m - 1][n - 1];
}

int main() {
    int m = 3, n = 7;  // Example grid dimensions

    int result = uniquePaths(m, n);
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << result << endl;

    return 0;
}
