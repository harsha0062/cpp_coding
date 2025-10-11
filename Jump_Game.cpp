#include <iostream>
#include <vector>
using namespace std;

// Function to check if you can reach the last index of nums
bool canJump(vector<int>& nums) {
    int max_idx = 0; // The farthest position you can reach so far
    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // If current position is beyond what you can reach, return false
        if (i > max_idx) return false;
        // Update the farthest position you can reach
        max_idx = max(max_idx, i + nums[i]);
    }
    // If loop finishes, return true (last index is reachable)
    return true;
}

int main() {
    // Example input array
    vector<int> nums = {2, 3, 1, 1, 4}; // You can reach the last index

    // Call the function and print the result
    if (canJump(nums)) {
        cout << "You can reach the last index." << endl;
    } else {
        cout << "You cannot reach the last index." << endl;
    }

    return 0;
}
