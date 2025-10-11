#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Function to find the minimum number of mutations needed to reach 'end' from 'start'
// Each mutation must be in the bank and change exactly one character at a time
int minMutation(string start, string end, vector<string>& bank) {
    queue<string> q;                // Queue for BFS
    unordered_set<string> visited;  // Set to track visited mutations

    q.push(start);                  // Start BFS from the initial string
    visited.insert(start);

    int steps = 0;                  // Number of steps/mutations taken

    while (!q.empty()) {
        int nq = q.size();          // Number of mutations at this BFS level

        // Process all mutations at the current level
        for (int j = 0; j < nq; j++) {
            string node = q.front();
            q.pop();

            // If we have reached the end, return current mutation count
            if (node == end) {
                return steps;
            }

            // Try mutating each position in the string
            for (char c : "ACGT") {
                for (int i = 0; i < node.size(); i++) {
                    string mutant = node;
                    mutant[i] = c;

                    // Check for unvisited valid mutation in bank
                    if (!visited.count(mutant) && find(bank.begin(), bank.end(), mutant) != bank.end()) {
                        q.push(mutant);
                        visited.insert(mutant);
                    }
                }
            }
        }
        steps++; // Increase mutation count (level of BFS)
    }
    // Return -1 if mutation to 'end' is not possible
    return -1;
}

int main() {
    // Example input for testing:
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    // Call the function and print the result
    int result = minMutation(start, end, bank);
    cout << "Minimum mutations required: " << result << endl;

    return 0;
}
