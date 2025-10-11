#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum path sum in a triangle using bottom-up DP
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size(); // Number of rows in the triangle

    // Create DP table and initialize all values to a large number (1e9)
    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    // Fill the last row of DP with the last row of the triangle
    for (int j = 0; j < n; j++)
        dp[n - 1][j] = triangle[n - 1][j];

    // Start from the second last row and work upwards
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // For each cell, add its value to the minimum of the two cells directly below it
            dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    // The top cell contains the final answer
    return dp[0][0];
}

int main() {
    // Example triangle input
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    // Call the function and print the result
    cout << "Minimum path sum is: " << minimumTotal(triangle) << endl;

    return 0;
}
