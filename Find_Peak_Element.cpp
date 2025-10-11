#include <iostream>
#include <vector>
using namespace std;

// Function to find a peak element in the array
int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    // Binary search for a peak element
    while (left < right) {
        int mid = left + (right - left) / 2;
        // If mid element is less than the next element, move to right half
        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        // If mid element is greater than or equal to the next, move to left half (including mid)
        else
            right = mid;
    }
    // At the end, left and right will be equal and pointing to a peak element
    return left; // or right (both are same)
}

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 1};

    // Calling the function
    int peakIndex = findPeakElement(nums);

    // Output the index and value of the peak
    cout << "Peak element index: " << peakIndex << endl;
    cout << "Peak element value: " << nums[peakIndex] << endl;

    return 0;
}
