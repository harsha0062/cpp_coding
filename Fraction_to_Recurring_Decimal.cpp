#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;

// Function to convert a fraction to its decimal representation,
// including recurring decimals in parentheses.
string fractionToDecimal(int numerator, int denominator) {
    bool flag = true;  // To check if the result is positive
    // If signs are different, result should be negative
    if (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
        flag = false;
    string ans = "";
    // Take absolute values for easier calculation and prevent overflow
    long long a = abs((long long)(numerator));
    long long b = abs((long long)(denominator));
    // If numerator is 0, the result is 0
    if (a == 0)
        return "0";

    long long int temp = b;
    // Remove factors of 2 from denominator
    while (temp % 2 == 0)
        temp = temp / 2;
    // Remove factors of 5 from denominator
    while (temp % 5 == 0)
        temp = temp / 5;
    // If denominator is now 1, the decimal terminates
    if (temp == 1) {
        // If numerator is divisible, no decimal
        if (a % b == 0) {
            if (flag) {
                ans = to_string(a / b);
                return ans;
            } else {
                ans = to_string(a / b);
                ans = '-' + ans;
                return ans;
            }
        }
        // Otherwise, build decimal digits one at a time
        long long int r = a % b;
        int q = a / b;
        ans += to_string(q);
        ans += '.';
        while (r != 0) {
            r = r * 10;
            q = r / b;
            r = r % b;
            ans += to_string(q);
        }
    } else {
        // If denominator has other prime factors, the decimal repeats
        long long int r = a % b;
        int q = a / b;
        ans += to_string(q);
        ans += '.';
        map<int, int> mp;  // To remember decimal places for repeating
        string dum = "";
        int len = 0;
        // Find the start of the repeating sequence.
        while (mp.find(r) == mp.end()) {
            mp[r] = len;
            len++;
            r = r * 10;
            q = r / b;
            r = r % b;
            dum += to_string(q);
        }
        // Add the non-repeating part
        for (int j = 0; j < mp[r]; j++) {
            ans += dum[j];
        }
        // Insert the repeating part in parentheses
        ans += '(';
        for (int j = mp[r]; j < dum.size(); j++)
            ans += dum[j];
        ans += ')';
    }
    // Add negative sign if needed
    if (flag)
        return ans;
    ans = '-' + ans;
    return ans;
}

int main() {
    // Test cases with input in code
    int numerator = 4;
    int denominator = 333;
    cout << "fractionToDecimal(" << numerator << ", " << denominator << ") = "
         << fractionToDecimal(numerator, denominator) << endl;

    numerator = 1;
    denominator = 2;
    cout << "fractionToDecimal(" << numerator << ", " << denominator << ") = "
         << fractionToDecimal(numerator, denominator) << endl;

    numerator = -22;
    denominator = 7;
    cout << "fractionToDecimal(" << numerator << ", " << denominator << ") = "
         << fractionToDecimal(numerator, denominator) << endl;

    numerator = 1;
    denominator = 6;
    cout << "fractionToDecimal(" << numerator << ", " << denominator << ") = "
         << fractionToDecimal(numerator, denominator) << endl;

    numerator = 7;
    denominator = -12;
    cout << "fractionToDecimal(" << numerator << ", " << denominator << ") = "
         << fractionToDecimal(numerator, denominator) << endl;

    return 0;
}
