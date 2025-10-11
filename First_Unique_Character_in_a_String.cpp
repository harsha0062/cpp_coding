#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> m;  // Map to store character frequencies
    queue<int> q;                // Queue to track indices of characters

    for (int i = 0; i < s.size(); i++) {
        if (m.find(s[i]) == m.end()) {
            q.push(i);           // Push index of first-time characters
        }
        m[s[i]]++;               // Increase frequency count

        // Remove non-unique characters from front of queue
        while (!q.empty() && m[s[q.front()]] > 1) {
            q.pop();
        }
    }

    return q.empty() ? -1 : q.front();  // Return index or -1 if none
}

int main() {
    string input="leetcode";

    int index = firstUniqChar(input);

    if (index == -1) {
        cout << "No non-repeating character found." << endl;
    } else {
        cout << "First non-repeating character is '" << input[index]
             << "' at index " << index << "." << endl;
    }

    return 0;
}
