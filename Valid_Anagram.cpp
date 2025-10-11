
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool isAnagram(string s, string t) {
    // If lengths differ, they cannot be anagrams
    if (s.size() != t.size()) return false;

    // Vector to count occurrences of each character (a-z)
    vector<int> count(26, 0);

    // Increment character counts from string s
    for (char c : s) {
        count[c - 'a']++;
    }

    // Decrement counts based on characters in string t
    for (char c : t) {
        if (count[c - 'a'] <= 0)
            return false; // Not enough occurrences of this char
        count[c - 'a']--;
    }

    // If all counts matched, strings are anagrams
    return true;
}

int main() {
    // Example inputs
    string s = "anagram";
    string t = "nagaram";

    // Call function and output result
    if (isAnagram(s, t)) {
        cout << "\"" << s << "\" and \"" << t << "\" are anagrams." << endl;
    } else {
        cout << "\"" << s << "\" and \"" << t << "\" are NOT anagrams." << endl;
    }

    return 0;
}
