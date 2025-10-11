#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the length of the longest consecutive sequence
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;

    // Insert all elements into the set for O(1) lookup
    for(int i = 0; i < n; i++)
        st.insert(nums[i]);

    // Check for the start of a sequence
    for(int i : st) {
        if(st.find(i - 1) == st.end()) { // If previous number doesn't exist
            int count = 1;
            int x = i;

            // Count all consecutive numbers
            while(st.find(x + 1) != st.end()) {
                x = x + 1;
                count = count + 1;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}

int main() {
    // Example input
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    // Call the function and print the output
    cout << "Longest consecutive sequence length: " << longestConsecutive(nums) << endl;
    return 0;
}
