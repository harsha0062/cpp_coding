#include <iostream>
#include <vector>
using namespace std;

// Function to compute triangular sum as described
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    // Process the array from end to start
    for(int i = n - 1; i >= 0; i--)
        // For each position, update nums[j] as the sum of itself and its next element modulo 10
        for(int j = 0; j < i; j++)
            nums[j] = (nums[j] + nums[j + 1]) % 10;
    // After completion, the first element contains the triangular sum
    return nums[0];
}

int main() {
    // Example input for demonstration
    vector<int> nums = {5, 3, 7, 4};
    // Call the triangularSum function and store the result
    int result = triangularSum(nums);
    // Print the output
    cout << "Triangular Sum: " << result << endl;
    return 0;
}
