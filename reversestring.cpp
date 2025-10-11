#include <iostream>
#include <vector>
#include <algorithm> // For the swap function

using namespace std;

// Function to reverse the characters in a vector
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    // Test case: initialize a vector of characters
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Print the original string
    cout << "Original string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    // Call the reverseString function
    reverseString(s);

    // Print the reversed string
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}
