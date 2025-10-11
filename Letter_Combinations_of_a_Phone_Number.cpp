#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char, string> digitToChar = {
    {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

// Backtracking helper function to generate combinations
void backtrack(int i, string curStr, string digits, vector<string> &ans) {
    // Base case: if current string length equals digits length, add to result
    if (curStr.size() == digits.size()) {
        ans.push_back(curStr);
        return;
    }
    // Iterate over possible characters for current digit
    for (char c : digitToChar[digits[i]]) {
        backtrack(i + 1, curStr + c, digits, ans);
    }
}

// Main function to get letter combinations
vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (!digits.empty())
        backtrack(0, "", digits, ans);
    return ans;
}

int main() {
    string digits = "23"; // Input digits

    // Call the function to get combinations
    vector<string> result = letterCombinations(digits);

    // Print the results
    cout << "Letter combinations for digits \"" << digits << "\":" << endl;
    for (string s : result) {
        cout << s << " ";
    }
    cout << endl;

    // Example usage of NULL (though not required here)
    int* ptr = NULL;
    if (ptr == NULL) {
        cout << "Pointer is NULL (demonstration only)" << endl;
    }

    return 0;
}
