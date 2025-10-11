#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
set<vector<int>> s;
void getallsub(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &a)
{
    if (i == nums.size())
    {
        if (s.find(ans) == s.end())
        {
            s.insert(ans);
            a.push_back(ans);
        }
        return;
    }
    ans.push_back(nums[i]);
    getallsub(nums, ans, i + 1, a);
    ans.pop_back();
    getallsub(nums, ans, i + 1, a);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> a;
    vector<int> a1;
    getallsub(nums, a1, 0, a);
    return a;
}
void getallsub_I(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &a)
{
    if (i == nums.size())
    {
        a.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    getallsub_I(nums, ans, i + 1, a);
    ans.pop_back();
    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1])
        idx++;
    getallsub_I(nums, ans, idx, a);
}
vector<vector<int>> subsetsWithDup_I(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> a;
    vector<int> a1;
    getallsub_I(nums, a1, 0, a);
    return a;
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> ans;
    vector<vector<int>> a;
    a = subsetsWithDup(v);
    cout<<"my method:";
    for (vector<int> i : a)
    {
        if (i.empty())
        {
            cout << "NULL" << endl;
        }
        for (int j : i)
            cout << " " << j << " ";
        cout << endl;
    }
    cout<<"by class"<<endl;
    vector<vector<int>> b;
    b = subsetsWithDup_I(v);
    for (vector<int> i : b)
    {
        if (i.empty())
        {
            cout << "NULL" << endl;
        }
        for (int j : i)
            cout << " " << j << " ";
        cout << endl;
    }
    return 0;
}