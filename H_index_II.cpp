#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Finds the H-Index for a sorted (ascending) citations array using binary search
int hIndex(vector<int>& c) {
    int left = 0, right = c.size() - 1;
    int ans = 0;
    int n = c.size();

    // Binary search for the optimal H-index value
    while (left <= right) {
        int mid = (left + right) / 2;       // Calculate the mid index
        int idx = n - mid;                  // Calculate number of remaining papers

        // If citations at mid is enough for 'idx' papers
        if (c[mid] >= idx) {
            ans = idx;                      // Update temporary answer
            right = mid - 1;                // Search for possibly higher H-index
        } else {
            left = mid + 1;                 // Narrow search to right half
        }
    }
    return ans;                             // Return final H-Index value
}

int main() {
    // Example input: citations must be sorted in ascending order for this binary search method
    vector<int> citations = {0, 1, 3, 5, 6};

    // Call function and display the result
    int result = hIndex(citations);
    cout << "H-Index = " << result << endl; // Output expected: H-Index = 3

    return 0;
}
