#include <iostream>
#include <vector>

using namespace std;

// Find the leftmost (first) index of target in nums
int findLeftMost(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int index = -1;  // will store the leftmost index if target found
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            index = mid;      // record this index
            right = mid - 1;  // but continue search in left half to find lower index
        } else if (nums[mid] < target) {
            left = mid + 1;   // move right if mid element less than target
        } else {
            right = mid - 1;  // move left otherwise
        }
    }
    return index;
}

// Find the rightmost (last) index of target in nums
int findRightMost(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int index = -1;  // will store the rightmost index if target found
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            index = mid;     // record this index
            left = mid + 1;  // continue search in right half to find higher index
        } else if (nums[mid] < target) {
            left = mid + 1;  // move right if mid element less than target
        } else {
            right = mid - 1; // move left otherwise
        }
    }
    return index;
}

// Returns the first and last position of target in nums, or [-1, -1] if not found.
vector<int> searchRange(vector<int>& nums, int target) {
    int leftIndex = findLeftMost(nums, target);
    if (leftIndex == -1)
        return {-1, -1};  // target not found
    int rightIndex = findRightMost(nums, target);
    return {leftIndex, rightIndex};
}

// Example usage
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> range = searchRange(nums, target);
    cout << "First and last position of " << target << " is: ["
         << range[0] << ", " << range[1] << "]" << endl;

    return 0;
}

