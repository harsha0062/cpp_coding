#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count the number of possible triangles
int triangleNumber(vector<int>& nums) {
    // Sort the array to enable efficient triangle checking
    sort(nums.begin(), nums.end());

    int count = 0;
    int n = nums.size();

    // Iterate over possible largest side c (from end towards start)
    for (int c = n - 1; c >= 2; c--) {
        int a = 0;        // Left pointer
        int b = c - 1;    // Right pointer

        // Use two-pointer technique
        while (a < b) {
            // If nums[a] + nums[b] > nums[c], then all elements between a and b can form a triangle
            if (nums[a] + nums[b] > nums[c]) {
                // All pairs from (a, b) to (b-1, b) are valid
                count += (b - a);

                // Move the right pointer to the left to check other pairs
                b -= 1;
            } else {
                // Otherwise, move the left pointer to the right for bigger nums[a]
                a += 1;
            }
        }
    }
    return count;
}

int main() {
    // Sample input vector
    vector<int> nums = {2, 2, 3, 4};

    // Call the function and display the result
    cout << "Number of triangles that can be formed: " << triangleNumber(nums) << endl;

    // You can test with more inputs:
    // vector<int> nums2 = {4, 2, 3, 4};
    // cout << "Number of triangles for second input: " << triangleNumber(nums2) << endl;

    return 0;
}
