#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Function to convert Roman numeral string to integer
int romanToInt(string s) {
    unordered_map<char,int> um;

    // Mapping Roman numerals to their integer values
    um['I'] = 1;
    um['V'] = 5;
    um['X'] = 10;
    um['L'] = 50;
    um['C'] = 100;
    um['D'] = 500;
    um['M'] = 1000;

    int i = 1;
    int sum = 0;

    // Iterate through the string from second char onwards
    while (i < s.length()) {
        // If previous char's value is greater or equal to current char's value, add it to sum
        if (um[s[i - 1]] >= um[s[i]]) {
            sum += um[s[i - 1]];
        } else {
            // Else subtract previous char's value
            sum -= um[s[i - 1]];
        }
        i++;
    }
    // Add the last character's value
    sum += um[s[s.length() - 1]];
    
    return sum;
}

int main() {
    // Input Roman numeral string (change to test other inputs)
    string romanStr = "MCMXCIV";
    cout << "Roman numeral: " << romanStr << endl;
    cout << "Integer value: " << romanToInt(romanStr) << endl;

    return 0;
}
