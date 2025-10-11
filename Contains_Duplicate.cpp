    #include <iostream>
#include <vector>
#include <set>

using namespace std;

// Function to check if the vector contains any duplicates
bool containsDuplicate(vector<int>& nums) {
    // Create a set from the vector elements.
    // Set stores only unique elements, so duplicates are removed.
    set<int> s(nums.begin(), nums.end());

    // If the size of the set is less than the vector size,
    // it means there were duplicates in the vector.
    return nums.size() != s.size();
}

int main() {
    // Hardcoded input vector with some duplicates
    vector<int> nums = {1, 2, 3, 4, 5, 3};

    // Check if duplicates exist in the vector
    if (containsDuplicate(nums)) {
        cout << "The vector contains duplicates." << endl;
    } else {
        cout << "The vector does not contain duplicates." << endl;
    }

    return 0;
}
