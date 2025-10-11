#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to insert a new interval into a sorted list of non-overlapping intervals and merge if needed
vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newa) {
    vector<vector<int>> ans;
    int n = arr.size();
    int i = 0;

    // Add all intervals ending before the new interval starts (no overlap)
    while(i < n && arr[i][1] < newa[0]) {
        ans.push_back(arr[i]);
        i = i + 1;
    }

    // Merge all overlapping intervals with newa
    while(i < n && arr[i][0] <= newa[1]) {
        newa[0] = min(newa[0], arr[i][0]);
        newa[1] = max(newa[1], arr[i][1]);
        i = i + 1;
    }

    // Add the merged new interval
    ans.push_back(newa);

    // Add remaining intervals after newa
    while(i < n) {
        ans.push_back(arr[i]);
        i = i + 1;
    }

    return ans;
}

int main() {
    // Example input intervals (sorted, non-overlapping)
    vector<vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    // New interval to insert
    vector<int> newInterval = {4,8};

    // Call insert function
    vector<vector<int>> updatedIntervals = insert(intervals, newInterval);

    // Print the updated list of intervals
    cout << "Updated intervals after insertion:" << endl;
    for (const auto& interval : updatedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;
}
