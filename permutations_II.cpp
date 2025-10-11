#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Recursively generates all unique permutations
void getterms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
    if (idx == nums.size()) {
        ans.push_back(nums); // Store the current permutation
        return;
    }
    unordered_set<int> s; // Used to avoid duplicate values at current position
    for (int i = idx; i < nums.size(); i++) {
        if (s.find(nums[i]) != s.end()) // Skip if value already used at current idx
            continue;
        s.insert(nums[i]);
        swap(nums[idx], nums[i]);           // Swap nums[idx] with nums[i]
        getterms(nums, idx + 1, ans);       // Recurse for the next index
        swap(nums[idx], nums[i]);           // Backtrack: restore original order
    }
}

// Initializes permutation process and returns all unique permutations
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    getterms(nums, 0, ans);
    return ans;
}

int main() {
    // Input vector containing possible duplicates
    vector<int> nums = {1, 1, 2};

    // Get all unique permutations
    vector<vector<int>> result = permuteUnique(nums);

    // Output all unique permutations
    cout << "Unique permutations:" << endl;
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
