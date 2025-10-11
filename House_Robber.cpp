#include <iostream>
#include <vector>
using namespace std;

// Function to calculate maximum money that can be robbed from houses
int rob(vector<int>& nums) {
    // If less than 2 houses, rob the only house available
    if (nums.size() < 2)
        return nums[0];
    // dp[i]: max money robbing upto house i
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        // For each house, choose max of:
        // (rob current and add dp[i-2]) or (don't rob, keep dp[i-1])
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1]; // Return max money possible
}

int main() {
    // Example input
    vector<int> houses = {2, 7, 9, 3, 1};

    // Call the function
    int maxAmount = rob(houses);

    // Output the result
    cout << "Maximum money that can be robbed: " << maxAmount << endl;
    return 0;
}

