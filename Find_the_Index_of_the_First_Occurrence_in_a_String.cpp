#include <iostream>
#include <string>

using namespace std;

// Function to find the first occurrence of 'needle' in 'haystack'
// Returns the starting index or -1 if not found
int strStr(string haystack, string needle) {
    if (needle == "")
        return 0; // If needle is empty, return 0 as per problem statement

    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++) {       // Loop through haystack up to possible start indices
        for (int j = 0; j < m; j++) {        // Check each character of needle
            if (haystack[i + j] != needle[j]) // If mismatch, stop checking this position
                break;
            if (j == m - 1)                   // If all characters matched, return start index
                return i;
        }
    }

    return -1; // Needle not found in haystack
}

int main() {
    // Inputs to test
    string haystack = "hello world";
    string needle = "world";

    // Call the function and print result
    int index = strStr(haystack, needle);

    if (index != -1)
        cout << "Needle found at index: " << index << "\n";
    else
        cout << "Needle not found\n";

    return 0;
}
