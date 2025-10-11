#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m;
    stack<int> s;
    
    for (int i = nums2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= nums2[i])
            s.pop();
        
        if (s.empty())
            m[nums2[i]] = -1;
        else
            m[nums2[i]] = s.top();
        
        s.push(nums2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++)
        ans.push_back(m[nums1[i]]);
    
    return ans;
}

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next greater elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}
