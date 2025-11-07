#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    // If there is only one coin, return 1 directly
    if (n == 1)
        return 1;

    int i = 1;
    // Keep subtracting coins per row until not enough coins for the next row
    while (n >= i) {
        n = n - i;  // Use i coins to fill the current row
        i++;       // Move to the next row increment
    }

    // i is incremented one extra time, so return i-1
    return i - 1;
}

int main() {
    int n = 8;  // Input number of coins to arrange
    int result = arrangeCoins(n);
    cout << "Number of complete rows that can be formed with " << n << " coins: " << result << endl;
    return 0;
}
