#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the largest perimeter of a triangle from given side lengths
int largestPerimeter(vector<int>& nums) {
    // Sort the input array to check triangle condition easily
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // Iterate from the largest possible sides towards smaller
    for (int i = n - 1; i >= 2; i--) {
        // Check if the two smaller sides can sum to be greater than the largest side
        if ((nums[i-1] + nums[i-2]) > nums[i]) {
            // Return the perimeter if a valid triangle is found
            return nums[i] + nums[i-1] + nums[i-2];
        }
    }
    // If no valid triangle can be formed, return 0
    return 0;
}

int main() {
    // Example input: array of possible side lengths
    vector<int> nums = {2, 1, 2};

    // Call the function and print the result
    int result = largestPerimeter(nums);
    cout << "Largest Perimeter: " << result << endl; // Output: 5

    // Additional example to test
    vector<int> nums2 = {1, 2, 1};
    cout << "Largest Perimeter: " << largestPerimeter(nums2) << endl; // Output: 0

    return 0;
}
