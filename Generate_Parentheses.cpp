#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Backtracking helper function to generate all valid parentheses combinations
void backtrack(int open, int close, int n, string current, vector<string> &ans) {
    // If the current string has n opening and n closing parentheses, add to answer
    if (open == n && close == n) {
        ans.push_back(current);
        return;
    }
    // If we can still add opening parentheses, do so
    if (open < n) {
        backtrack(open + 1, close, n, current + '(', ans);
    }
    // If we can add closing parentheses without exceeding open ones, do so
    if (close < open) {
        backtrack(open, close + 1, n, current + ')', ans);
    }
}

// Main function to generate all combinations of well-formed parentheses for given n
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    backtrack(0, 0, n, "", ans);
    return ans;
}

int main() {
    int n = 3; // Number of pairs of parentheses

    vector<string> result = generateParenthesis(n);

    cout << "All valid combinations of " << n << " pairs of parentheses:" << endl;
    for (const string &s : result) {
        cout << s << endl;
    }

    // Demonstration of NULL pointer usage (not required, shown only for example)
    int *ptr = NULL;
    if (ptr == NULL) {
        cout << "Pointer is NULL (example only)" << endl;
    }

    return 0;
}
