#include <iostream>
#include <string>
using namespace std;

// Function to add two large numbers represented as strings
string addStrings(string nums1, string nums2) {
    int i = nums1.length() - 1;   // Index for nums1 (starting from the end)
    int j = nums2.length() - 1;   // Index for nums2 (starting from the end)
    int carry = 0;                // To handle carry during addition
    int sum = 0;                  // Temporary sum at each digit
    string ans;                   // To store the result

    // Loop until both strings are exhausted
    while (i >= 0 || j >= 0) {
        if (i >= 0 && j >= 0) {
            // Both strings have digits at current indices
            sum = carry + (nums1[i] - '0') + (nums2[j] - '0');
            i--;
            j--;
        }
        else if (i >= 0) {
            // Only nums1 has remaining digits
            sum = carry + (nums1[i] - '0');
            i--;
        }
        else {
            // Only nums2 has remaining digits
            sum = carry + (nums2[j] - '0');
            j--;
        }
        ans = char((sum % 10) + '0') + ans; // Prepend current digit to answer
        carry = sum / 10;                   // Update carry
    }

    // If there's any carry left, prepend to result
    if (carry > 0)
        ans = '1' + ans;

    return ans;
}

int main() {
    string s1 = "12345678901234567890"; // Example input 1
    string s2 = "98765432109876543210"; // Example input 2

    // Call the function to add the strings
    string result = addStrings(s1, s2);

    // Output the final result
    cout << "Sum of " << s1 << " + " << s2 << " = " << result << endl;

    return 0;
}
