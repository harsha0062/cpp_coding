#include <iostream>
#include <vector>

using namespace std;

// Function to set entire row and column to zero if an element is zero
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();    // Number of rows
    int m = matrix[0].size(); // Number of columns
    int col0 = 1;             // Flag to track if first column needs to be zeroed

    // Mark rows and columns that need to be zeroed
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;      // Mark row i
                if (j != 0)
                    matrix[0][j] = 0;  // Mark column j
                else
                    col0 = 0;          // First column needs to be zeroed
            }
        }
    }

    // Set zeroes based on marks, excluding first row and first column
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    // Zero out the first row if needed
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    // Zero out the first column if needed
    if (col0 == 0) {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}

int main() {
    // Input matrix for testing
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original matrix:" << endl;
    for (auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    setZeroes(matrix);

    cout << "\nMatrix after setZeroes:" << endl;
    for (auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}
