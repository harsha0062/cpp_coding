#include <iostream>
#include <vector>

using namespace std;

// Function to generate the specified row of Pascal's Triangle
vector<int> getRow(int rowIndex) {
    vector<vector<int>> ans;

    // Handle base case for rowIndex 0 (first row)
    if (rowIndex == 0) {
        return {1};
    }

    // First row
    vector<int> firstrow = {1};
    ans.push_back(firstrow);

    // Build rows up to rowIndex
    for (int i = 1; i <= rowIndex; i++) {
        vector<int> prev = ans[i - 1];
        vector<int> row;
        row.push_back(1);
        for (int j = 0; j < i - 1; j++) {
            row.push_back(prev[j] + prev[j + 1]);
        }
        row.push_back(1);
        ans.push_back(row);
    }

    // Return the requested row
    return ans[rowIndex];
}

int main() {
    int rowIndex;

    cout << "Enter the row index of Pascal's Triangle you want to generate: ";
    cin >> rowIndex;

    vector<int> row = getRow(rowIndex);

    cout << "Row " << rowIndex << " of Pascal's Triangle is: ";
    for (int val : row) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
