#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Function to convert string to integer (emulating C/C++ atoi)
int myAtoi(string s) {
    // If string is empty, return 0
    if (s.size() == 0) return 0;
    
    int i = 0;
    // Skip initial spaces
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
    // Remove leading spaces
    s = s.substr(i);
    int sign = +1;
    long ans = 0;
    // Handle sign
    if (s[0] == '-') sign = -1;
    int MAX = INT_MAX, MIN = INT_MIN;
    // Start from beginning or after sign
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
    while (i < s.size()) {
        // Stop at first non-digit character
        if (!isdigit(s[i])) break;
        ans = ans * 10 + s[i] - '0';
        // Check for overflow for negative numbers
        if (sign == -1 && -1 * ans < MIN) return MIN;
        // Check for overflow for positive numbers
        if (sign == 1 && ans > MAX) return MAX;
        i++;
    }
    return (int)(sign * ans);
}

int main() {
    // Example test cases
    cout << "Input: \"42\"       Output: " << myAtoi("42") << endl;
    cout << "Input: \"   -42\"   Output: " << myAtoi("   -42") << endl;
    cout << "Input: \"4193 with words\" Output: " << myAtoi("4193 with words") << endl;
    cout << "Input: \"words and 987\" Output: " << myAtoi("words and 987") << endl;
    cout << "Input: \"-91283472332\" Output: " << myAtoi("-91283472332") << endl;
    cout << "Input: \"2147483648\" Output: " << myAtoi("2147483648") << endl;
    return 0;
}
