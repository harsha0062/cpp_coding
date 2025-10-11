#include <iostream>
#include <vector>

using namespace std;

// Backtracking helper function to generate combinations of k numbers out of 1..n
void backtrack(int start, vector<int> &comb, vector<vector<int>> &ans, int n, int k) {
    // If current combination size is k, add it to the results
    if (comb.size() == k) {
        ans.push_back(comb);
        return;
    }
    // Iterate from start to n inclusive to build combinations
    for (int i = start; i <= n; i++) {
        comb.push_back(i);           // Choose number i
        backtrack(i + 1, comb, ans, n, k); // Explore further with i+1
        comb.pop_back();             // Backtrack, remove i
    }
}

// Main function to return all combinations of k numbers from 1 to n
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> comb;
    backtrack(1, comb, ans, n, k);
    return ans;
}

int main() {
    int n = 4;  // Total numbers from 1 to n
    int k = 2;  // Size of combinations

    // Get all combinations
    vector<vector<int>> result = combine(n, k);

    // Print all combinations
    cout << "Combinations of " << k << " from 1 to " << n << ":" << endl;
    for (const vector<int> &v : result) {
        cout << "[ ";
        for (int num : v) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    // Demonstration of NULL usage
    int* ptr = NULL;
    if (ptr == NULL) {
        cout << "Pointer is NULL (demonstration only)" << endl;
    }

    return 0;
}
