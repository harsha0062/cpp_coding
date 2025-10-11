#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Method 1: Using lmax and rmax arrays
int trapWithPrefixArrays(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> lmax(n), rmax(n);
    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
        lmax[i] = max(lmax[i - 1], height[i]);

    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(rmax[i + 1], height[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(lmax[i], rmax[i]) - height[i];

    return ans;
}

// Method 2: Using two pointers
int trapWithTwoPointers(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    int l = 0, r = n - 1;
    int lmax = 0, rmax = 0;

    while (l < r) {
        lmax = max(lmax, height[l]);
        rmax = max(rmax, height[r]);

        if (lmax < rmax) {
            ans += lmax - height[l];
            l++;
        } else {
            ans += rmax - height[r];
            r--;
        }
    }

    return ans;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << "Trapped water (Prefix Arrays Method): " << trapWithPrefixArrays(height) << endl;
    cout << "Trapped water (Two Pointer Method): " << trapWithTwoPointers(height) << endl;

    return 0;
}
