#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>> s;
void getallcom(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &com)
{

    if (idx == arr.size() || tar < 0)
    {
        return;
    }

    if (tar == 0)
    {
        if (s.find(com) == s.end())
        {
            ans.push_back(com);
            s.insert(com);
        }

        return;
    }
    com.push_back(arr[idx]);
    // single
    getallcom(arr, idx + 1, tar - arr[idx], ans, com);
    // multiple
    getallcom(arr, idx, tar - arr[idx], ans, com);

    com.pop_back();

    // exclusion
    getallcom(arr, idx + 1, tar, ans, com);
}
vector<vector<int>> combinationSum(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> com;
    getallcom(arr, 0, target, ans, com);
    return ans;
}
int main()
{
    vector<int> v = {2, 3, 5};
    int target = 8;
    cout << "\t given array :" << endl;
    for (int i : v)
        cout << " " << i << " ";
    cout << endl;
    cout << "target :" << target << endl;

    vector<vector<int>> v1 = combinationSum(v, target);
    cout << "\t given combinationsum :" << endl;
    for (vector<int> i : v1)
    {
        for (int j : i)
            cout << " " << j << " ";
        cout << endl;
    }
}