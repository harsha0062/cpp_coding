#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void helper(vector<vector<int>> &m, int r, int c, string path, vector<string> &ans)
{
    int n = m.size();
    if (r < 0 || c < 0 || r >= n || c >= n || m[r][c] == 0||m[r][c]==-1)
        return;
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }

    m[r][c]=-1;
    
    helper(m, r + 1, c, path + "D", ans); // down
    helper(m, r - 1, c, path + "U", ans); // up
    helper(m, r, c - 1, path + "L", ans); // left
    helper(m, r, c + 1, path + "R", ans); // right

    m[r][c]=1;
}

vector<string> findpath(vector<vector<int>> &m)
{
    int n = m.size();
    vector<string> ans;
    string path = "";
    helper(m, 0, 0, path, ans);
    return ans;
}
int main()
{
    vector<vector<int>> m = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findpath(m);
    for (string path : ans)
        cout << " " << path << " ";

    return 0;
}