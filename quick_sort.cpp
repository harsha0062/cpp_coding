#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int partiton(vector<int> &arr, int st, int end){
    int idx=st-1,pivot=arr[end];
    for(int j=st;j<end;j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j],arr[idx]);

        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
}
void quicksort(vector<int> &arr, int st, int end){
    if(st<end){
        int pividx=partiton(arr, st,  end);
        quicksort(arr,st,pividx-1);
        quicksort(arr,pividx+1,end);
    }
}
int main()
{
    vector<int> arr = {2, 3, 4, 1, 5, 6};
    cout << "before sorting:" << endl;
    for (int i : arr)
        cout << " " << i << " ";
    cout << endl;
    quicksort(arr, 0, arr.size() - 1);
    cout << "after sorting:" << endl;
    for (int i : arr)
        cout << " " << i << " ";
    cout << endl;
}