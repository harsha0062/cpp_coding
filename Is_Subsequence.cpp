#include <iostream>
#include <string>
using namespace std;
// Function to check if 's' is a subsequence of 't'
bool isSubsequence(string s, string t) { 
    int n = s.size();      // Length of s
    int m = t.size();      // Length of t
    int i = 0, j = 0;      // Pointers for s and t
    while(i < n && j < m) { // Iterate through both strings
        if(s[i] == t[j]) {  // If characters match, move to next in s
            i++;
        }
        j++;                // Always move to next in t
    }
    return i >= n;          // If all chars of s found in t, return true
}

int main() {
    // Example input strings
    string s = "abc";
    string t = "ahbgdc";

    // Call the function and print the result
    if(isSubsequence(s, t)) {
        cout << "Yes, \"" << s << "\" is a subsequence of \"" << t << "\".\n";
    } else {
        cout << "No, \"" << s << "\" is not a subsequence of \"" << t << "\".\n";
    }

    return 0;
}
