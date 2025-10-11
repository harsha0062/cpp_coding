#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s, string t) {
    // Maps to store character mappings from s to t and t to s
    unordered_map<char, char> m1;  // For s → t mapping
    unordered_map<char, char> m2;  // For t → s mapping

    for (int i = 0; i < s.size(); i++) {
        // If mapping for s[i] exists, ensure it matches t[i]
        if (m1.count(s[i])) {
            if (m1[s[i]] != t[i])
                return false; // Conflict: s[i] already mapped to different t[i]
        } else {
            // If t[i] is already mapped to a different s[i], mapping isn't unique
            if (m2.count(t[i]))
                return false; // t[i] already mapped
            // Record new mappings in both directions
            m1[s[i]] = t[i];
            m2[t[i]] = s[i];
        }
    }
    // All checks passed; strings are isomorphic
    return true;
}

int main() {
    // Example input strings (can be changed to test other cases)
    string s = "egg";
    string t = "add";

    // Call the function and display result
    if(isIsomorphic(s, t)) {
        cout << "Strings \"" << s << "\" and \"" << t << "\" are isomorphic." << endl;
    } else {
        cout << "Strings \"" << s << "\" and \"" << t << "\" are NOT isomorphic." << endl;
    }

    return 0;
}
