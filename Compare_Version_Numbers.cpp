#include <iostream>
#include <string>
using namespace std;

// Function to compare version numbers
int compareVersion(string v1, string v2) {
    int i=0, j=0, v1len=v1.size(), v2len=v2.size(), n1, n2;

    // Continue while there are digits left in either version string
    while (i < v1len || j < v2len) {
        n1 = 0;
        n2 = 0;

        // Build number for version 1 until a '.' or end
        while (i < v1len && v1[i] != '.') {
            n1 = n1 * 10 + (v1[i] - '0');
            i++;
        }

        // Build number for version 2 until a '.' or end
        while (j < v2len && v2[j] != '.') {
            n2 = n2 * 10 + (v2[j] - '0');
            j++;
        }

        // Compare the current numbers
        if (n1 < n2)
            return -1;
        else if (n1 > n2)
            return 1;

        // Move past the '.' delimiter
        i++;
        j++;
    }
    // Both versions are equal
    return 0;
}

int main() {
    // Example inputs
    string version1 = "1.01";
    string version2 = "1.001";

    // Call the function and output the result
    int result = compareVersion(version1, version2);

    // Print comparison result
    // 0: equal, 1: version1 > version2, -1: version1 < version2
    cout << "Comparison result: " << result << endl;

    return 0;
}
