#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

// Function to perform integer division without using /, *, or %
// Returns dividend divided by divisor
int divide(int dividend, int divisor) {
    // If both numbers are the same, result is 1
    if (dividend == divisor)
        return 1;

    // Determine the sign of the result
    bool sign = true;
    if ((dividend >= 0 && divisor < 0) || (dividend <= 0 && divisor > 0))
        sign = false;
    
    // Use long to prevent overflow and get absolute values
    long n = labs(dividend);
    long d = labs(divisor);

    long quotient = 0;

    // Perform division using bit manipulation (subtract largest shifted divisor)
    while (n >= d) {
        int cnt = 0;
        // Find the maximum cnt such that (d << (cnt + 1)) <= n
        while (n >= (d << (cnt + 1)))
            cnt += 1;
        quotient += 1L << cnt;
        n -= d << cnt;
    }

    // Handle overflow edge cases
    if (quotient == (1L << 31) && sign)
        return INT_MAX;
    if (quotient == (1L << 31) && !sign)
        return INT_MIN;

    // Apply the sign to the result
    return sign ? quotient : -quotient;
}

int main() {
    // Example input
    int dividend = 10;
    int divisor = 3;

    // Call the function and print the result
    int result = divide(dividend, divisor);
    cout << "Result: " << result << endl;

    return 0;
}
