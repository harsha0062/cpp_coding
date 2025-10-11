#include <iostream>
#include <vector>
using namespace std;

// Your jump function exactly as provided, with added comments
int jump(vector<int>& nums) {
    int jumps = 0, l = 0, r = 0;
    // Continue until the right boundary reaches or passes the last index
    while (r < (nums.size() - 1)) {
        int far = 0;
        // For all indices in the current range [l, r], find how far we can jump
        for (int i = l; i <= r; i++) {
            far = max(i + nums[i], far);
        }
        // Move the left pointer just past the current right pointer to define next window
        l = r + 1;
        // Increment the jump count since we are making a jump to the new window
        jumps = jumps + 1;
        // Update right boundary to the farthest reachable index in this jump
        r = far;
    }
    return jumps;
}

int main() {
    // Example input array representing jump lengths from each position
    vector<int> nums = {2, 3, 1, 1, 4};

    // Call the jump function and store the result
    int result = jump(nums);

    // Output the minimum number of jumps needed to reach the last index
    cout << "Minimum jumps to reach the end: " << result << endl;

    return 0;
}
