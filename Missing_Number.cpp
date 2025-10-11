#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number in the array
int missingNumber(vector<int>& nums) {
    // Initialize ans with the size of the array, which is the range upper bound
    int ans = nums.size();

    // Traverse through the array elements
    for (int i = 0; i < nums.size(); i++)
        // Update ans by adding (i - nums[i]) at each step
        ans += (i - nums[i]);

    // Return the computed missing number
    return ans;
}

int main() {
    // Example input: array containing numbers from 0 to n, missing one value
    vector<int> nums = {3, 0, 1}; // Missing number is 2

    // Call the missingNumber function and print the result
    int result = missingNumber(nums);

    cout << "The missing number is: " << result << endl;
    return 0;
}
