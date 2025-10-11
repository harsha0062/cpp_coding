#include <iostream>
#include <bitset>
using namespace std;

// Function to count number of set bits (Hamming weight)
int hammingWeight(int n) {
    // Create a bitset of 31 bits from integer n
    bitset<31> b(n);
    // Return the count of set bits (1s)
    return b.count();
}

int main() {
    int n = 29; // Example input
    // Call the hammingWeight function and display result
    cout << "Number: " << n << endl;
    cout << "Hamming Weight: " << hammingWeight(n) << endl;

    // Example usage of NULL keyword with pointers
    int* ptr = NULL;
    if (ptr == NULL) {
        cout << "Pointer is NULL." << endl;
    }
    int value = 5;
    ptr = &value;
    if (ptr != NULL) {
        cout << "Pointer points to value: " << *ptr << endl;
    }
    return 0;
}
