#include <iostream>
#include <vector>
using namespace std;

// Function to compute the maximum sum of a circular subarray
int maxSubarraySumCircular(vector<int>& nums) {
    int globalmax = nums[0];    // Tracks the maximum subarray sum
    int globalmin = nums[0];    // Tracks the minimum subarray sum
    int curmax = 0;             // Current max subarray sum ending here
    int curmin = 0;             // Current min subarray sum ending here
    int total = 0;              // Sum of all elements

    // Iterate through the array to calculate above values
    for (int num : nums) {
        curmax = max(curmax + num, num);        // Max subarray ending at current index
        curmin = min(curmin + num, num);        // Min subarray ending at current index
        total += num;                           // Running total sum
        globalmax = max(globalmax, curmax);     // Update global max if needed
        globalmin = min(globalmin, curmin);     // Update global min if needed
    }

    // If all numbers are negative, just return globalmax
    // Otherwise, either the max is a normal subarray or is wrapped around (use total - globalmin)
    return (globalmax > 0) ? max(globalmax, total - globalmin) : globalmax;
}

int main() {
    // Example input
    vector<int> nums = {5, -3, 5};
    
    // Call the function and print the result
    int result = maxSubarraySumCircular(nums);
    cout << "Maximum circular subarray sum: " << result << endl;

    return 0;
}
