#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum element in a rotated sorted array
int findMin(vector<int>& nums) {
    int res = nums[0];                  // Initialize result to first element
    int l = 0, r = nums.size() - 1;     // Left and right pointers

    while (l <= r) {
        // If subarray is already sorted, min is at l
        if (nums[l] < nums[r]) {
            res = min(res, nums[l]);
            break;
        }
        int m = (l + r) / 2;            // Find middle index
        res = min(res, nums[m]);        // Update result if needed

        // Decide which half to explore next
        if (nums[m] >= nums[l])
            l = m + 1;                  // Left is sorted, so go right
        else
            r = m - 1;                  // Right half may have min, move left
    }
    return res;
}

int main() {
    // Example input (rotated sorted array)
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    // Call the function and print the result
    int minimum = findMin(nums);
    cout << "Minimum element in rotated sorted array: " << minimum << endl;

    return 0;
}
