#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& arr) {
    int n = arr.size();
    // Sort intervals by their start time
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // If ans is empty or current interval does not overlap with the last in ans
        if(ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            // Merge the current interval with the last interval in ans
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main() {
    // Example input intervals
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    // Call the merge function
    vector<vector<int>> mergedIntervals = merge(intervals);

    // Print the merged intervals
    cout << "Merged intervals:" << endl;
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;
}
