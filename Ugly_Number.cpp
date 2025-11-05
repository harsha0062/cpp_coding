#include <iostream>

using namespace std;

// Function to check if a number is ugly (only has prime factors 2, 3, or 5)
bool isUgly(int n) {
    if (n <= 0)
        return false;
    while (n != 1) {
        if (n % 2 == 0)
            n = n / 2;        // Divide by 2 if divisible
        else if (n % 3 == 0)
            n = n / 3;        // Divide by 3 if divisible
        else if (n % 5 == 0)
            n = n / 5;        // Divide by 5 if divisible
        else
            break;            // If not divisible by 2, 3, or 5, it's not ugly
    }
    return n == 1;            // Return true if reduced to 1
}

int main() {
    int input = 6; // Example input, you can change this value for testing
    if (isUgly(input))
        cout << input << " is an ugly number." << endl;
    else
        cout << input << " is not an ugly number." << endl;
    return 0;
}
