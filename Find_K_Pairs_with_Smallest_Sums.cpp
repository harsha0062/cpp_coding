#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find k pairs with smallest sums
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    vector<vector<int>> ans;
    if (n1 == 0 || n2 == 0) return ans; // If any array is empty, return

    // Min-heap priority queue for smallest sums
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>> > pq;

    // Only push pairs with index j=0 initially, at most k pairs
    for (int i = 0; i < n1 && i < k; i++)
        pq.push({nums1[i] + nums2[0], {i, 0}});

    // Extract k pairs with minimal sums
    while (!pq.empty() && ((k--) > 0)) {
        int sum = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;

        pq.pop();
        vector<int> v = {nums1[i], nums2[j]};
        ans.push_back(v);

        // If at the end of nums2, don't push further pairs
        if (j + 1 == n2)
            continue;

        // Push the next pair from nums2 for current i
        pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
    }
    return ans;
}

int main() {
    // Example input
    vector<int> nums1 = {1, 7, 11};
    vector<int> nums2 = {2, 4, 6};
    int k = 3;

    // Get k smallest pairs
    vector<vector<int>> result = kSmallestPairs(nums1, nums2, k);

    // Print the k pairs
    cout << "K smallest pairs are:\n";
    for (const auto& pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "]\n";
    }
    return 0;
}
