#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort intervals based on their end point
static bool comp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

// Function to find the minimum number of arrows needed
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), comp); // Sort intervals by their end points
    int arrow = 1; // At least one arrow is needed
    int last = points[0][1]; // End of the first interval

    for (int i = 1; i < points.size(); i++) {
        // If the current interval starts after the last arrow position, shoot a new arrow
        if (last < points[i][0]) {
            arrow++; // Increase arrow count
            last = points[i][1]; // Update last arrow position
        }
    }
    return arrow;
}

int main() {
    // Sample input: each vector represents an interval [start, end]
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    int result = findMinArrowShots(points);
    cout << "Minimum number of arrows needed: " << result << endl; // Output the result
    return 0;
}
