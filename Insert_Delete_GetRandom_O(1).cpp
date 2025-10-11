#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
using namespace std;

// Function to handle set operations and randomness
// No change to your original functions, just moved outside class
unordered_set<int> s;

void initialize() {
    // Seed the RNG once at start
    srand(time(0));
}

// Insert value into set
bool insert(int val) {
    if (s.find(val) != s.end()) {
        return false;  // Value already exists
    } else {
        s.insert(val);
        return true;
    }
}

// Remove value from set
bool remove(int val) {
    if (s.find(val) != s.end()) {
        s.erase(val);
        return true;
    } else {
        return false;  // Value not found
    }
}

// Get a random element from the set
int getRandom() {
    if (s.empty()) {
        return -1;  // Return -1 if the set is empty
    }
    // No random access in unordered_set, convert to vector temporarily
    vector<int> vec(s.begin(), s.end());
    int idx = rand() % vec.size();
    return vec[idx];
}

int main() {
    initialize();

    // Example inputs and outputs inside the code as requested
    cout << insert(10) << endl;  // Output: 1 (true)
    cout << insert(20) << endl;  // Output: 1 (true)
    cout << insert(10) << endl;  // Output: 0 (false, duplicate)
    cout << remove(15) << endl;  // Output: 0 (false, not found)
    cout << remove(20) << endl;  // Output: 1 (true)
    cout << getRandom() << endl; // Output: 10 (the only element left)
    cout << insert(30) << endl;  // Output: 1 (true)
    cout << getRandom() << endl; // Output: could be 10 or 30 randomly

    return 0;
}
