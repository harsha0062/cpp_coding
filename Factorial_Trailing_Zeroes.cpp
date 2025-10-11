#include <iostream>
using namespace std;

// Function to count trailing zeroes in n!
int trailingZeroes(int n) {
    int sum = 0;
    while (n / 5 > 0) {
        sum += (n / 5); // Add the number of multiples of 5
        n /= 5;         // Move to the next power of 5
    }
    return sum;
}

int main() {
    int n = 100; // Example input
    cout << "Number of trailing zeroes in " << n << "! is " << trailingZeroes(n) << endl;
    return 0;
}
