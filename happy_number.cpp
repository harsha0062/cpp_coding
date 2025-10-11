#include <iostream>
#include <set>
using namespace std;

// Function to calculate the sum of squares of digits of n
int sumofsquares(int n) {
    int sum = 0;
    while (n != 0) {
        int digit = n % 10;      // Extract last digit
        sum += (digit * digit);  // Add square of digit to sum
        n = n / 10;              // Remove last digit
    }
    return sum;
}

// Function to determine if a number is a happy number
bool isHappy(int n) {
    set<int> s;  // Set to track numbers seen to detect cycles
    while (s.find(n) == s.end()) {  // While n is not already seen
        s.insert(n);                // Insert current number into set
        n = sumofsquares(n);         // Get sum of squares of digits
        if (n == 1)
            return true;           // If reaches 1, it is happy
    }
    return false;                  // Cycle detected, not happy
}

int main() {
    int number = 19;  // Input number to test
    cout << "Checking if " << number << " is a Happy Number." << endl;
    if (isHappy(number)) {
        cout << number << " is a Happy Number." << endl;
    } else {
        cout << number << " is NOT a Happy Number." << endl;
    }
    return 0;
}
