#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle up to numRows
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;       // This will store the final Pascal's triangle

    if (numRows == 0)
        return ans;                // If no rows requested, return empty vector

    vector<int> firstrow;          // First row of Pascal's triangle
    firstrow.push_back(1);
    ans.push_back(firstrow);       // Add first row to result

    if (numRows == 1)
        return ans;                // If only one row requested, return the result

    // Generate rows from 2 to numRows
    for (int i = 1; i < numRows; i++) {
        vector<int> prev = ans[i - 1];  // Previous row
        vector<int> row;                 // Current row to build
        row.push_back(1);                // First element of each row is always 1

        // Calculate middle elements of the current row by summing adjacent elements of previous row
        for (int j = 0; j < i - 1; j++) {
            row.push_back(prev[j] + prev[j + 1]);
        }

        row.push_back(1);                // Last element of each row is always 1
        ans.push_back(row);              // Add the completed row to the result
    }

    return ans;                 // Return the full Pascal's triangle
}

int main() {
    int numRows=5;

    vector<vector<int>> triangle = generate(numRows);

    // Print the Pascal's triangle
    for (const auto& row : triangle) {
        for (int val : row) {
            cout <<" "<< val << " ";
        }
        cout << endl;
    }

    return 0;
}
