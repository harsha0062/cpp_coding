#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int celebrity(vector<vector<int>> &arr)
{
    
    stack<int> s;
    int n = arr[0].size();
    for (int i = 0; i < n; i++)
        s.push(i);
    while (s.size() > 1)
    {
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();
        if (arr[i][j] == 0)
            s.push(i);
        else
            s.push(j);
    }
    int cel = s.top();
    for (int i = 0; i < n; i++)
    {
        cel = s.top();
        if ((i != cel) && arr[i][cel] == 0 || arr[cel][i] == 1)
            return -1;
    }
    return cel;
}
int main()
{
    vector<vector<int>> arr = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int ans = celebrity(arr);
    cout << "celebrity are:" << ans;
}