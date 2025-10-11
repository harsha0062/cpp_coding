#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Function to find maximum in each sliding window
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // will store indices
    vector<int> res;

    // Process first k elements (first window)
    for (int i = 0; i < k; i++) {
        // Remove elements smaller than current from back
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        
        dq.push_back(i); // add current index
    }

    // Process the rest of the elements
    for (int i = k; i < nums.size(); i++) {
        res.push_back(nums[dq.front()]); // front is the largest of previous window

        // Remove elements outside the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove elements smaller than current from back
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i); // add current index
    }

    // Push the maximum of the last window
    res.push_back(nums[dq.front()]);

    return res;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Maximums of each sliding window: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}
