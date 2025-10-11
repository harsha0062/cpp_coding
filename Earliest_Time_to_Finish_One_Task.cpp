#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// This function finds the minimum sum among all the sub-vectors in 'tasks'.
// Each sub-vector represents a set of task times. The function returns
// the minimum total time required among all possible sets.
int earliestTime(vector<vector<int>>& tasks) {
    int ans = INT_MAX; // Initialize answer with maximum integer value
    for (vector<int> t : tasks) {
        int sum = 0; // Sum of times in the current set
        for (int i : t) {
            sum += i; // Accumulate task times
        }
        ans = min(ans, sum); // Update minimum sum found so far
    }
    return ans; // Return the earliest time found
}

int main() {
    // Example input: Each inner vector represents a list of task times
    vector<vector<int>> tasks = {
        {3, 4, 5}, 
        {2, 8, 1}, 
        {6, 2, 3}
    };
    
    // Call the function and output the result
    int minTime = earliestTime(tasks); 
    cout << "Earliest time: " << minTime << endl; // Output result
    
    return 0;
}
