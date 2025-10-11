#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive helper function with memoization to find the minimum triangulation score
int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
    // If less than three vertices, no triangle can be formed
    if (j - i < 2)
        return 0;
    // Return memoized result if already computed
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9; // Initialize minimum score to a large value
    // Try all possible points to partition the polygon
    for (int k = i + 1; k < j; k++) {
        // Calculate cost for current partition and recurse for left and right parts
        int ans = values[i] * values[j] * values[k] + solve(values, i, k, dp) + solve(values, k, j, dp);
        mini = min(mini, ans); // Update minimum score
    }
    // Store result in dp table and return
    return dp[i][j] = mini;
}

// Main function to find minimum triangulation score
int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    // Initialize dp table with -1
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // Call the recursive function for the whole array
    return solve(values, 0, n - 1, dp);
}

int main() {
    // Example input
    vector<int> values = {1, 3, 1, 4, 1, 5};
    // Get the answer by calling minScoreTriangulation
    int result = minScoreTriangulation(values);
    cout << "Minimum Score Triangulation: " << result << endl;
    return 0;
}
