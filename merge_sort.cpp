#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])//here the main arrangement 
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int idx = 0; idx < temp.size(); idx++)
    {
        arr[idx + st] = temp[idx];
    }
}
void mergesort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergesort(arr, st, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}
int main()
{
    vector<int> arr = {2, 3, 4, 1, 5, 6};
    cout << "before sorting:" << endl;
    for (int i : arr)
        cout << " " << i << " ";
    cout << endl;
    mergesort(arr, 0, arr.size() - 1);
    cout << "after sorting:" << endl;
    for (int i : arr)
        cout << " " << i << " ";
    cout << endl;
}