#include <iostream>
#include <vector>
using namespace std;

// Function to find the first missing positive integer
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    bool contains1 = false;

    // Step 1: Replace negative numbers, zeros, and numbers greater than n with 1
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1)
            contains1 = true;
        if (nums[i] <= 0 || nums[i] > n)
            nums[i] = 1;
    }

    // If 1 is not present, 1 is the smallest missing positive number
    if (contains1 == false)
        return 1;

    // Step 2: Use the elements as index and mark corresponding places as negative
    for (int i = 0; i < n; i++) {
        int num = abs(nums[i]);
        int idx = num - 1;
        if (nums[idx] < 0)
            continue;
        nums[idx] *= -1;
    }

    // Step 3: The first positive index+1 is the answer
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0)
            return i + 1;
    }

    // Step 4: If all places are marked, the answer is n+1
    return n + 1;
}

int main() {
    // Example input
    vector<int> nums = {3, 4, -1, 1};

    // Call the function and print the result
    int result = firstMissingPositive(nums);
    cout << "First missing positive: " << result << endl;

    return 0;
}
