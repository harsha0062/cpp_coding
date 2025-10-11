#include <iostream>
#include <vector>
using namespace std;

// Function to find the single number where every other number appears three times
int singleNumber(vector<int>& nums) {
    int ones = 0, twos = 0;
    // Traverse each number in the array
    for (int i = 0; i < nums.size(); i++) {
        // Update 'ones' for bits seen once so far
        ones = (ones ^ nums[i]) & (~twos);
        // Update 'twos' for bits seen twice so far
        twos = (twos ^ nums[i]) & (~ones);
    }
    // Return the result stored in 'ones'
    return ones;
}

int main() {
    // Input: Example vector where every number except one appears three times
    vector<int> nums = {2, 2, 3, 2, 4, 3, 3};
    
    // Call the singleNumber function and store the result
    int result = singleNumber(nums);

    // Print the result
    cout << "The element that appears only once is: " << result << endl;

    return 0;
}
