#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to simplify a given Unix-style file path.
// It processes the components and builds the canonical path.
string simplifyPath(string path) {
    stack<string> s;
    string cur;

    // Append '/' so the last directory gets processed
    for (char c : path + "/") {
        if (c == '/') {
            if (cur == "..") { // ".." means go up one directory
                if (!s.empty())
                    s.pop();
            } else if (!cur.empty() && cur != ".") { // Ignore empty segments and current directory '.'
                s.push(cur);
            }
            cur = ""; // Reset cur for next segment
        } else {
            cur += c; // Build the current directory/file name
        }
    }

    // Build the final path from the stack
    string result;
    while (!s.empty()) {
        result = "/" + s.top() + result;
        s.pop();
    }

    // If the stack is empty, path is root
    return result.empty() ? "/" : result;
}

int main() {
    // Example input path
    string input = "/a/./b/../../c/";
    string output = simplifyPath(input);
    cout << "Simplified path: " << output << endl; // Output: "/c"
    return 0;
}
