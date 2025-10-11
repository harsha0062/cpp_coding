#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to convert integer to Roman numeral
string intToRoman(int num) {
    // List of Roman symbols and their integer values
    vector<pair<string, int>> symlist = {
        {"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10},
        {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100},
        {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}
    };
    string res = "";

    // Iterate through the symbol list in reverse to start from largest values
    for (int i = symlist.size() - 1; i >= 0; i--) {
        string s = symlist[i].first;
        int val = symlist[i].second;

        // If num is at least val, find how many times val fits into num
        if (num / val) {
            int c = num / val;
            // Append the Roman symbol c times
            for (int j = 0; j < c; j++) {
                res += s;
            }
            // Reduce num by the value multiplied by c
            num %= val;
        }
    }
    return res;
}

int main() {
    // Test input - change value to test different numbers
    int num = 1994;
    cout << "Integer: " << num << endl;
    cout << "Roman numeral: " << intToRoman(num) << endl;
    return 0;
}
