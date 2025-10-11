#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the alternating sum of an array
int alternatingSum(vector<int>& nums) {
    int ans = 0;
    // Traverse the vector and add or subtract based on index parity
    for(int i = 0; i < nums.size(); i++) {
        if(i % 2 == 0)
            ans += nums[i]; // Add if index is even
        else
            ans -= nums[i]; // Subtract if index is odd
    }
    return ans;
}

int main() {
    // Example input
    vector<int> nums = {3, 1, 4, 2, 5};

    // Call the function and print the result
    int result = alternatingSum(nums);
    cout << "Alternating sum: " << result << endl;

    return 0;
}
