#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the kth largest element in the array
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());              // Sort the array in ascending order
    return nums[nums.size() - k];                // The kth largest is at index n - k
}

int main() {
    // Example input
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    // Call the function and print result
    int result = findKthLargest(nums, k);
    cout << "The " << k << "th largest element is: " << result << endl;

    return 0;
}
