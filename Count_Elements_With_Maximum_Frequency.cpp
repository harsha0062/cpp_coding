#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Function to find the sum of frequencies of the most frequent elements
int maxFrequencyElements(vector<int>& nums) {
    map<int, int> count; // Map to store element frequency
    int maxf = 0;        // Variable to track the highest frequency

    // Count the frequency of each number in nums
    for (int num : nums) {
        count[num]++;
        maxf = max(maxf, count[num]); // Update maxf if needed
    }

    int res = 0; // Store sum of highest frequencies

    // Calculate the sum of frequencies for elements with highest frequency
    for (auto it : count) {
        if (it.second == maxf)
            res += it.second;
    }

    return res; // Return the result
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 2, 3, 1, 4, 2};
    
    // Call the function and print the result
    int result = maxFrequencyElements(nums);
    cout << "Sum of frequencies of most frequent elements: " << result << endl;

    return 0;
}
