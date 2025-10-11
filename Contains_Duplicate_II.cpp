#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

// Function to check if there exists two duplicate elements within at most k indices apart
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> indexMap; // Map to store the last seen index of each element

    for (int i = 0; i < nums.size(); i++) {
        // Check if nums[i] has been seen before
        if (indexMap.find(nums[i]) != indexMap.end()) {
            // If the difference between current index and last seen index is <= k, return true
            if (abs(i - indexMap[nums[i]]) <= k) {
                return true;
            }
        }
        // Update last seen index for nums[i]
        indexMap[nums[i]] = i;
    }
    // If no nearby duplicate found, return false
    return false;
}

int main() {
    // Hardcoded input vector and k value
    vector<int> nums = {1, 2, 3, 1, 4, 5};
    int k = 3;

    if (containsNearbyDuplicate(nums, k)) {
        cout << "true" << endl;  // Nearby duplicate exists within distance k
    } else {
        cout << "false" << endl; // No nearby duplicate found within distance k
    }

    return 0;
}
