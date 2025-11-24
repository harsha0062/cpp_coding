#include <iostream>
#include <vector>
using namespace std;

// Shuffle function merges two halves of the array alternately.
// This function expects the vector 'nums' and integer 'n' as input.
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> ans;
    // Iterate from 0 to n - 1
    for(int i = 0; i < n; i++) {
        // Add one element from the first half
        ans.push_back(nums[i]);
        // Add one element from the second half
        ans.push_back(nums[i + n]);
    }
    return ans;
}

int main() {
    // Example input for nums and n
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    // Call shuffle and store result
    vector<int> result = shuffle(nums, n);

    // Print the shuffled vector
    cout << "Shuffled Output: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
