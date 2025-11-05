#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is a perfect square
// It uses sqrt to get the square root and fmod to check if the fractional part is 0
bool isPerfectSquare(int num) {
    return (fmod(sqrt(num), 1.0) == 0.0);
}

int main() {
    int input = 16;  // Example input; change this value to test other numbers
    if (isPerfectSquare(input))
        cout << input << " is a perfect square." << endl;
    else
        cout << input << " is not a perfect square." << endl;
    return 0;
}
