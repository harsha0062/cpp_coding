#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive helper to get all unique combinations
void getallcom(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& com) {
    if (tar == 0) {
        ans.push_back(com); // Found a valid combination
    } else if (tar < 0) {
        return; // Exceeded target, stop searching
    } else {
        for (int i = idx; i < arr.size(); i++) {
            // Skip duplicates to avoid repeating the same combination
            if (i > idx && arr[i] == arr[i - 1]) continue;
            // Optimization: Since array is sorted, no need to continue if current number is greater than remaining target
            if (arr[i] > tar) break;
            com.push_back(arr[i]);
            getallcom(arr, i + 1, tar - arr[i], ans, com); // Move to next index with reduced target
            com.pop_back(); // Backtrack to try next candidate
        }
    }
}

// Main function to find all combinations that sum to target
vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end()); // Sort array to make duplicate skipping possible
    vector<vector<int>> ans;
    vector<int> com;
    getallcom(arr, 0, target, ans, com);
    return ans;
}

int main() {
    // Example input
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> results = combinationSum2(arr, target);

    // Print all unique combinations
    for (auto& v : results) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
