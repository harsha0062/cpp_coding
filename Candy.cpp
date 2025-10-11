#include <iostream>
#include <vector>
#include <algorithm>  // for max
using namespace std;

// Function to find minimum candies needed given ratings
// Each child must have at least one candy
// Child with higher rating than neighbor gets more candies
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int s = 0;

    // Initialize candies array: everyone gets at least 1 candy
    vector<int> candy(n, 1);

    // Left to right: if current rating is higher than previous,
    // give one more candy than previous child
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    // Right to left: if current rating is higher than next,
    // ensure current candy count is more than next by at least 1
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1])
            candy[i] = max(candy[i], candy[i + 1] + 1);
    }

    // Sum all candies to get minimum required
    for (int i : candy)
        s += i;

    return s;
}

int main() {
    // Example input: ratings of children
    vector<int> ratings = {1, 0, 2};

    // Call function and print result
    int result = candy(ratings);
    cout << "Minimum candies needed: " << result << endl;  // Expected output: 5

    return 0;
}
