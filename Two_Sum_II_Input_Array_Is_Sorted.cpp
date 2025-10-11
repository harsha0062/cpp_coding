#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find indices of two numbers that add up to the target
// Returns 1-based indices of the two numbers if found, else {0,0}
vector<int> twoSum(vector<int>& numbers, int target) {
    unordered_map<int, int> num_map; // map to store number and its index

    for (int i = 0; i < numbers.size(); i++) {
        int complement = target - numbers[i]; // the number needed to reach target sum

        // Check if complement exists in map
        if (num_map.find(complement) != num_map.end()) {
            // Return 1-based indices of complement and current number
            return {num_map[complement] + 1, i + 1};
        }

        // Store current number with its index
        num_map[numbers[i]] = i;
    }

    // If no pair found
    return {0, 0};
}

int main() {
    // Example input: numbers vector and target sum
    vector<int> numbers = {-10, -8, -2, 1, 2, 5, 6};
    int target = 0;

    // Call twoSum function
    vector<int> result = twoSum(numbers, target);

    // Print the results
    if (result[0] == 0 && result[1] == 0) {
        cout << "No two sum solution found." << endl;
    } else {
        cout << "Indices of the two numbers adding to " << target << " are: ";
        cout << result[0] << " and " << result[1] << endl;
        cout << "Numbers are: " << numbers[result[0] - 1] << " and " << numbers[result[1] - 1] << endl;
    }

    return 0;
}
