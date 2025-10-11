#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if ransomNote can be constructed from magazine letters
bool canConstruct(string ransomNote, string magazine) {
    // Array to count occurrences of each letter in the magazine
    vector<int> count(26, 0);
    // Count each character in the magazine
    for(char c : magazine) {
        count[c - 'a']++;
    }
    // Check if each character in ransomNote exists in magazine (enough times)
    for(char c : ransomNote) {
        if(count[c - 'a'] == 0)
            return false; // Not enough of character c
        count[c - 'a']--;
    }
    // All characters found in sufficient numbers
    return true;
}

int main() {
    // Example input values
    string ransomNote = "aabbcc";
    string magazine = "abcabcabc";

    // Call the function and print result
    if (canConstruct(ransomNote, magazine)) {
        cout << "ransomNote can be constructed from magazine" << endl;
    } else {
        cout << "ransomNote cannot be constructed from magazine" << endl;
    }

    return 0;
}
