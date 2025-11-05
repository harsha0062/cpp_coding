#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Function to convert an integer to its hexadecimal string representation
string toHex(int num) {
    stringstream ss;
    ss << hex << num;  // Insert the integer in hex format into the stringstream
    return ss.str();   // Return the string representation of the hex number
}

int main() {
    int input = 255;  // Example input; you can change this to test other values
    string hexStr = toHex(input);
    cout << "Hexadecimal representation of " << input << " is: " << hexStr << endl;
    return 0;
}
