#include <iostream>
using namespace std;

// Function to find the bitwise AND of all numbers in the range [left, right]
int rangeBitwiseAnd(int left, int right) {
    int i = 0;
    // Keep shifting both 'left' and 'right' rightwards until they become equal
    while (left != right) {
        left = left >> 1;     // Shift left right by 1 bit
        right = right >> 1;   // Shift right right by 1 bit
        i += 1;               // Count number of shifts
    }
    // Shift back to original position to obtain the result
    return left << i;
}

int main() {
    // Example input
    int left = 5;
    int right = 7;

    // Call the function and store result
    int result = rangeBitwiseAnd(left, right);

    // Print the result to output
    cout << "Bitwise AND of range [" << left << ", " << right << "] is: " << result << endl;

    return 0;
}
