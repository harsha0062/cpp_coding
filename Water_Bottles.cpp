#include <iostream>
using namespace std;

// Function to calculate maximum number of water bottles that can be drunk
int numWaterBottles(int a, int b) {
    int count = a;        // Start with the initial full bottles
    while (a >= b) {      // While there are enough empty bottles to exchange for a new one
        count += a / b;   // Add new bottles obtained by exchanging
        int val = a / b;  // Number of new bottles obtained in this exchange
        a -= (val) * b;   // Subtract used empty bottles from total
        a += val;         // Add new empty bottles after drinking new ones
    }
    return count;         // Return the total number of bottles drunk
}

int main() {
    int a = 9; // number of full water bottles initially
    int b = 3; // number of empty bottles needed for an exchange

    // Call the function and display the result
    cout << "Total bottles that can be drunk: " << numWaterBottles(a, b) << endl;

    return 0;
}
