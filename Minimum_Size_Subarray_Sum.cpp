#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0, total = 0;
    int ans = INT_MAX;
    // Use two pointers to find the minimal length subarray
    for (int r = 0; r < (int)nums.size(); r++) {

        // Add the current element to the total sum
        total += nums[r];

        // Shrink the window as small as possible while the sum is >= target
        while (total >= target) {
            ans = min(r - l + 1, ans);
            total -= nums[l];
            l += 1;
        }

    }
    // If no valid subarray was found, return 0
    return (ans == INT_MAX) ? 0 : ans;
}

int main() {
    // Input: target sum and array of numbers
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    // Call the function and print the result
    int result = minSubArrayLen(target, nums);
    cout << "Minimum length of subarray with sum >= " << target << " is: " << result << endl;

    return 0;
}