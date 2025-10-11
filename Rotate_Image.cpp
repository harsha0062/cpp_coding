#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rotates the matrix 90 degrees clockwise using transpose and reverse
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix: swap elements across the diagonal
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);

    // Reverse each row for 90-degree clockwise rotation
    for(int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
    // Sample 3x3 matrix as input
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Rotate the matrix
    rotate(matrix);

    cout << "Rotated matrix:" << endl;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
