#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printallsubsets(vector<int> &arr, vector<int> &ans, int i)
{
    if (i == arr.size())
    {
        for (int val : ans)
            cout << " " << val << " ";
        cout << endl;
        return;
    }
    ans.push_back(arr[i]);
    printallsubsets(arr, ans, i + 1);
    ans.pop_back();
    printallsubsets(arr, ans, i + 1);
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<int> ans;

    printallsubsets(v, ans, 0);
    return 0;
}