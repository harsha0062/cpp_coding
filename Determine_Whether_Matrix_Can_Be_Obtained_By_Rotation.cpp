#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rotates the matrix 90 degrees clockwise using transpose and reverse
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse each row to complete the rotation
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

// Checks if two matrices are equal
bool check(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size();

    // Compare each element for equality
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] != target[i][j])
                return false;

    return true;
}

// Checks if target matrix can be obtained by rotating mat 0, 90, 180, or 270 degrees
bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; i++) {
        if (check(mat, target))
            return true;
        rotate(mat);
    }
    return false;
}

int main() {
    // Example input matrices
    vector<vector<int>> mat = {
        {0, 1},
        {1, 0}
    };

    vector<vector<int>> target = {
        {1, 0},
        {0, 1}
    };

    // Check if target can be obtained by rotating mat
    if (findRotation(mat, target)) {
        cout << "Target can be obtained by rotating the matrix." << endl;
    } else {
        cout << "Target cannot be obtained by rotating the matrix." << endl;
    }

    return 0;
}
