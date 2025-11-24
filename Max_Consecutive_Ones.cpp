#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum number of consecutive 1's in a vector 'nums'
int findMaxConsecutiveOnes(vector<int>& nums) {
    int c = 0, maxi = 0;
    // Iterate through the vector
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            c = 0; // Reset count if 0 is found
        } else {
            c++; // Increment count for 1
        }
        // Update maximum consecutive count
        maxi = max(maxi, c);
    }
    return maxi;
}

int main() {
    // Example input vector
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    // Call the function and store the result
    int result = findMaxConsecutiveOnes(nums);

    // Print the result
    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}
