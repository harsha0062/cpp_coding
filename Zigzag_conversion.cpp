#include <iostream>
#include <string>

using namespace std; // Allow string and cout without std::

string convert(string s, int numRows) {
    if (numRows == 1)
        return s;                                // Special case: only one row

    string res = "";                             // The result string

    for (int r = 0; r < numRows; r++) {          // Iterate over each row
        int jump = 2 * (numRows - 1);            // Compute the jump (cycle length)
        for (int i = r; i < s.size(); i += jump) { // Process characters in jumps
            res += s[i];                         // Add the current character to result
            // For middle rows, add the diagonal character if within bounds
            if ((r > 0) && r < (numRows - 1) && (i + jump - 2 * r) < s.size())
                res += s[i + jump - 2 * r];
        }
    }
    return res;                                  // Return the final zigzag string
}

int main() {
    // Example input string and number of rows
    string s = "PAYPALISHIRING";
    int numRows = 3;

    // Call the convert function and print output
    string result = convert(s, numRows);
    cout << "Converted string: " << result << "\n";
    return 0;
}
