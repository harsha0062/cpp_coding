#include <iostream>
#include <string>
using namespace std;

// Function to find the longest palindromic substring using center expansion
string longestPalindrome(string s) {
    // If the string has length 0 or 1, it is already a palindrome
    if (s.size() <= 1)
        return s;
    
    string lps = ""; // Variable to store the longest palindromic substring found

    // Loop through each possible palindrome center
    for (int i = 1; i < s.size(); i++) {
        // Handle odd length palindrome centered at i
        int low = i;
        int high = i;
        // Expand as long as characters at low and high are equal
        while (s.at(low) == s.at(high)) {
            low--;
            high++;
            // Break if pointers go out of bounds
            if (low == -1 || high == s.size())
                break;
        }
        // Check if this palindrome is longest
        string pali = s.substr(low + 1, high - low - 1);
        if (pali.size() > lps.size())
            lps = pali;

        // Handle even length palindrome between i-1 and i
        low = i - 1;
        high = i;
        while (s.at(low) == s.at(high)) {
            low--;
            high++;
            if (low == -1 || high == s.size())
                break;
        }
        pali = s.substr(low + 1, high - low - 1);
        if (pali.size() > lps.size())
            lps = pali;
    }
    return lps;
}

int main() {
    // Sample input string
    string s = "babad";

    // Call the function and display the result
    cout << "Longest palindromic substring: " << longestPalindrome(s) << endl;

    // Additional test examples:
    // string s2 = "cbbd";
    // cout << "Longest palindromic substring for s2: " << longestPalindrome(s2) << endl;

    return 0;
}
