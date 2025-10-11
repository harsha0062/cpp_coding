#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Function to check if s can be segmented into words in wordDict
bool wordBreak(string s, vector<string>& wordDict) {
    // Convert wordDict to a set for O(1) lookups
    set<string> wordset(wordDict.begin(), wordDict.end());

    // Find the maximum length of a word in the dictionary
    int maxlen = 0;
    for (const string& word : wordDict)
        maxlen = max(maxlen, (int)word.size());

    int n = s.size();
    // dp[i] means s[0..i-1] can be segmented
    vector<bool> dp(n + 1, false);
    dp[0] = true; // Base case: empty string

    for (int i = 1; i <= n; i++) {
        // Check substrings ending at i of lengths up to maxlen
        for (int j = i - 1; j >= max(0, i - maxlen); j--) {
            if (dp[j] && wordset.find(s.substr(j, i - j)) != wordset.end()) {
                dp[i] = true;
                break; // Found segmentation, no need to check more
            }
        }
    }
    return dp[n];
}

int main() {
    // Example input
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    // Call the function and output result
    bool result = wordBreak(s, wordDict);
    cout << "Can the string \"" << s << "\" be segmented? " << (result ? "Yes" : "No") << endl;

    return 0;
}
