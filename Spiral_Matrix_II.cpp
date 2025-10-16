#include <iostream>
#include <vector>
using namespace std;

/*
 * Generates an n×n matrix filled with numbers from 1 to n²
 * in spiral order (clockwise direction).
 */
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int r1 = 0, r2 = n - 1;
    int c1 = 0, c2 = n - 1;
    int val = 1;

    // Fill the matrix layer by layer
    while (r1 <= r2 && c1 <= c2) {
        // Fill top row (left → right)
        for (int i = c1; i <= c2; i++)
            ans[r1][i] = val++;

        // Fill right column (top → bottom)
        for (int i = r1 + 1; i <= r2; i++)
            ans[i][c2] = val++;

        // Fill bottom row (right → left)
        if (r1 < r2 && c1 < c2) {
            for (int i = c2 - 1; i >= c1; i--)
                ans[r2][i] = val++;

            // Fill left column (bottom → top)
            for (int i = r2 - 1; i > r1; i--)
                ans[i][c1] = val++;
        }

        // Move inward to next layer
        r1++;
        r2--;
        c1++;
        c2--;
    }

    return ans;
}

int main() {
    int n = 4; // Example input

    vector<vector<int>> matrix = generateMatrix(n);

    cout << "Spiral Matrix of size " << n << "×" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
