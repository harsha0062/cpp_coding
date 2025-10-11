#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Function to check if string s follows the given pattern
bool wordPattern(string pattern, string s) {
    unordered_map<char, string> m1;          // pattern char → word mapping
    unordered_map<string, char> m2;          // word → pattern char mapping
    vector<string> words;                    // stores split words from s
    string w;
    // Split words from s (manual method, as in your code)
    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            if (!w.empty()) {
                words.push_back(w);
                w.clear();
            }
        } else {
            w += s[i];
        }
    }
    // If pattern length != number of words, return false
    if (pattern.size() != words.size()) 
        return false; 

    // Check bijection between pattern and words
    for (int i = 0; i < pattern.size(); i++) {
        if (m1.count(pattern[i])) {
            if (m1[pattern[i]] != words[i])
                return false;
        } else {
            if (m2.count(words[i]))
                return false;
            // Add mapping in both directions
            m1[pattern[i]] = words[i];
            m2[words[i]] = pattern[i];
        }
    }
    return true; // Pattern matches the word sequence
}

int main() {
    // Example input
    string pattern = "abba";
    string s = "dog cat cat dog";

    // Output result
    if (wordPattern(pattern, s)) {
        cout << "String \"" << s << "\" follows pattern \"" << pattern << "\"." << endl;
    } else {
        cout << "String \"" << s << "\" does NOT follow pattern \"" << pattern << "\"." << endl;
    }
    return 0;
}
