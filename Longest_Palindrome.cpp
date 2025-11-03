#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to find the length of the longest palindrome that can be built with the letters of the input string
int longestPalindrome(string s) {
    int n = s.length(), ans = 0;
    unordered_map<char, int> freq;

    // Count frequency of each character in the string
    for (char c : s) {
        freq[c]++;
    }

    bool isOdd = false; // Track if there is at least one character with an odd frequency

    // Calculate the length of the longest palindrome possible
    for (auto [c, fr] : freq) {
        if (fr % 2 == 0) {
            ans += fr; // If frequency is even, add all occurrences
        } else {
            ans += fr - 1; // If odd, add the largest even number less than frequency
            isOdd = true;  // Mark that there is an odd frequency
        }
    }
    // If there's any odd frequency character, add 1 for the middle character of palindrome
    return (isOdd) ? ans + 1 : ans;
}

int main() {
    string input = "abccccdd";  // Example input
    int result = longestPalindrome(input);
    cout << "The length of the longest palindrome that can be built is: " << result << endl;
    return 0;
}
