#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

// Function to group anagrams
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // 1. Store the grouped anagrams in a map
    map<string,vector<string>> mp;
    for(int i = 0; i < strs.size(); i++) {
        string s = strs[i];
        sort(s.begin(), s.end()); // sort string to form a key
        mp[s].push_back(strs[i]);
    }
    // 2. Store results in the answer vector
    vector<vector<string>> ans(mp.size());
    int index = 0;
    for(auto x : mp) {
        auto temp = x.second;
        for(auto y : temp) {
            ans[index].push_back(y);
        }
        index++;
    }
    return ans;
}

int main() {
    // Example input vector
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // Get grouped anagrams
    vector<vector<string>> result = groupAnagrams(strs);

    // Print the result
    cout << "Grouped anagrams:" << endl;
    for(const auto& group : result) {
        for(const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
