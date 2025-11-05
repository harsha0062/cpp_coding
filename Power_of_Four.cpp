#include <iostream>

using namespace std;

// Function to check if a number is a power of four
bool isPowerOfFour(int n) {
    if (n < 4 && n != 1)
        return false;  // Numbers less than 4 except 1 cannot be power of 4
    
    // Keep dividing by 4 while divisible
    while (n % 4 == 0) {
        n = n / 4;
    }
    
    // If reduced to 1, the number is a power of 4
    return n == 1;
}

int main() {
    int input = 64;  // Example input; you can change this to test other values
    if (isPowerOfFour(input))
        cout << input << " is a power of four." << endl;
    else
        cout << input << " is not a power of four." << endl;
    
    return 0;
}
