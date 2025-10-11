#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to summarize ranges in sorted integer vector
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int n = nums.size();
    if(n == 0) return result;
    int a = nums[0];
    for(int i = 0; i < n; i++) {
        // If current is last element or next element is not consecutive
        if(i == n-1 || nums[i] + 1 != nums[i+1]) {
            if(nums[i] != a)
                result.push_back(to_string(a) + "->" + to_string(nums[i]));
            else
                result.push_back(to_string(a));
            if(i != n-1) a = nums[i+1];
        }
    }
    return result;
}

int main() {
    // Example input vector
    vector<int> nums = {0, 1, 2, 4, 5, 7};

    // Call summaryRanges function
    vector<string> ranges = summaryRanges(nums);

    // Print out summarized ranges
    cout << "Summary Ranges:" << endl;
    for(const string& s : ranges) {
        cout << s << endl;
    }
    return 0;
}
