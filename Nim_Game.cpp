#include <iostream>

using namespace std;

// Function to determine if the player can win the Nim game given n stones
// According to Nim game theory, if the number of stones n is NOT divisible by 4,
// the first player can always win by making the right moves.
bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    int input = 7;  // Example input; you can change this value to test other cases
    if (canWinNim(input)) {
        cout << "Player can win with " << input << " stones." << endl;
    } else {
        cout << "Player cannot win with " << input << " stones." << endl;
    }
    return 0;
}
