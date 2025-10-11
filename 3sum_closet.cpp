#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MAX
#include <cstdlib>  // For abs()

using namespace std;

// Helper function to find three numbers in nums whose sum is closest to target
int helper(vector<int>& nums, int target) {
    int n = nums.size();
    // Initialize answer with sum of first three elements
    int ans = nums[0] + nums[1] + nums[2];
    int mindiff = INT_MAX; // Minimum difference initialized to max integer value

    // Sort the array to use two-pointer technique
    sort(nums.begin(), nums.end());

    // Iterate through each number, using two pointers to find closest sum
    for (int i = 0; i < n - 2; i++) {
        int j = i + 1;       // Left pointer
        int k = n - 1;       // Right pointer
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            int difft = abs(sum - target);

            // Update ans if a closer sum is found
            if (difft < mindiff) {
                ans = sum;
                mindiff = difft;
            }

            // If exact sum is found, return immediately
            if (sum == target) {
                return sum;
            }

            // Move pointers based on comparison with target
            if (sum < target)
                j++;
            else
                k--;
        }
    }
    return ans;
}

// Function that calls the helper function
int threeSumClosest(vector<int>& nums, int target) {
    return helper(nums, target);
}

// Example usage
int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int closestSum = threeSumClosest(nums, target);
    cout << "The closest sum to target " << target << " is " << closestSum << endl;

    return 0;
}
