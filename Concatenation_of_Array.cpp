#include <iostream>
#include <vector>

using namespace std;

// Your function exactly as provided (kept unchanged).
vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n * 2);
    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];
        ans[i + (n)] = nums[i];
    }
    return ans;
}

int main() {
    // Example input: modify these values if you want to test other cases.
    vector<int> nums = {1, 2, 1};

    // Call the function with the input vector.
    vector<int> result = getConcatenation(nums);

    // Print the resulting concatenated vector to stdout.
    cout << "Output: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i + 1 < result.size()) cout << " ";
    }
    cout << endl;

    return 0;
}
