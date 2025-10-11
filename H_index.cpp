#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate H-Index
// This function sorts the citation counts in descending order
// and finds the maximum h such that at least h papers have >= h citations.
int hIndex(vector<int>& c) {
    // Sort in descending order using reverse iterators
    sort(c.rbegin(), c.rend());

    // Traverse the sorted list
    for (int i = 0; i < c.size(); i++) {
        // (i+1) is the number of papers considered so far
        if (c[i] >= i + 1) {
            // Still valid, continue checking
            continue;
        } else {
            // First failure, return current index as h-index
            return i;
        }
    }
    // If all elements are valid, h-index is full size of vector
    return c.size();
}

int main() {
    // Example input citations
    vector<int> citations = {3, 0, 6, 1, 5};

    // Call hIndex function
    int result = hIndex(citations);

    // Print result
    cout << "H-Index = " << result << endl;

    return 0;
}
