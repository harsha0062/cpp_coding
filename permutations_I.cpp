#include <iostream>
#include <vector>
using namespace std;

// This function generates all permutations recursively.
// nums: the vector to permute
// idx: current index to fix
// ans: vector to store all permutations
void getterms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums); // Store the current permutation
        return;
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);     // Swap current index with i
        getterms(nums, idx + 1, ans); // Recurse for next index
        swap(nums[idx], nums[i]);     // Backtrack to restore order
    }
}

// This function starts the permutation process.
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    getterms(nums, 0, ans);
    return ans;
}

int main()
{
    // Input vector
    vector<int> nums = {1, 2, 3};

    // Get all permutations
    vector<vector<int>> result = permute(nums);

    // Output all permutations
    cout << "All permutations:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
