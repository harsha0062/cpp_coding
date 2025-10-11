#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> previous_smaller_element(vector<int> &arr)
{
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        while (s.size() && s.top() >= arr[i])
            s.pop();
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {3, 1, 0, 8, 6};
    vector<int> ans = previous_smaller_element(arr);
    for (int val : ans)
        cout << val << " ";
    cout << endl;
    return 0;
}