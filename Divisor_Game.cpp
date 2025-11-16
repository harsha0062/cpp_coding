#include <bits/stdc++.h>
using namespace std;

// Your function (unchanged)
bool divisorGame(int n) {
    // If n is even, Alice (the first player) will always win.
    // If n is odd, Alice will lose assuming both play optimally.
    return (n % 2 == 0) ? true : false;
}

int main() {
    int n;

    // Take input for n
    cout << "Enter n: ";
    cin >> n;

    // Call the function and store the result
    bool result = divisorGame(n);

    // Print the result in a readable form
    if (result) {
        cout << "Alice wins (true)" << endl;
    } else {
        cout << "Alice loses (false)" << endl;
    }

    return 0;
}
