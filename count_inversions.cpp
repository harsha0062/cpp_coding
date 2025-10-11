#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int merge(vector<int> &arr, int st, int mid, int end)
{
    vector<int> temp;
    int i = st, j = mid + 1;
    int invcount=0;

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
            invcount+=(mid-i+1);
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
    return invcount;
}
int  mergesort(vector<int> &arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        int leftinvcount=mergesort(arr, st, mid);
        int rightinvcount=mergesort(arr, mid + 1, end);
        int invcount= merge(arr, st, mid, end);
        return leftinvcount+rightinvcount+invcount;
    }
    return 0;
}
int main(){
    vector<int> arr={1, 3, 5, 10, 2, 6, 8, 9};
    cout << " given arr" << endl;
    for (int i : arr)
        cout << " " << i << " ";
    cout << endl;

    cout<<"count inversion : \t"<< mergesort(arr,0,arr.size()-1)<<endl;

}
// Input: {1, 3, 5, 10, 2, 6, 8, 9}
// Inversions: 5
// (Explanation: (3,2), (5,2), (10,2), (10,6), (10,8))