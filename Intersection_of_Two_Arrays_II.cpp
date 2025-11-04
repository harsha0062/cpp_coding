#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Method 1: Using a hashmap (unordered_map) to count frequencies
// Time Complexity: O(n + m), where n = size of nums1 and m = size of nums2
vector<int> intersectHashMap(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    vector<int> ans;

    // Count frequency of each element in nums1
    for (int num : nums1) {
        mp[num]++;
    }

    // For each element in nums2, if it exists in the map and count > 0, add to result
    for (int num : nums2) {
        if (mp[num] > 0) {
            mp[num]--;
            ans.push_back(num);
        }
    }

    return ans;
}

// Method 2: Sorting both arrays and using two pointers
// Time Complexity: O(n log n + m log m), because of sorting
vector<int> intersectTwoPointers(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ans;

    // Use two pointers to find common elements
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    // Using hashmap method
    vector<int> resultHashMap = intersectHashMap(nums1, nums2);
    cout << "Intersection using hashmap method: ";
    for (int num : resultHashMap)
        cout << num << " ";
    cout << endl;

    // Using two pointers method
    vector<int> resultTwoPointers = intersectTwoPointers(nums1, nums2);
    cout << "Intersection using two pointers method: ";
    for (int num : resultTwoPointers)
        cout << num << " ";
    cout << endl;

    return 0;
}
