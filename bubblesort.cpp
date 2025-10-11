#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool isSwap = false; // Reset isSwap at the start of each iteration
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }
        if (!isSwap) // If no swaps were made, the array is already sorted
            break;
    }
}
void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int curr=a[i];
        int prev=i-1;
        while (prev>=0&&a[prev]>curr)
        {
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=curr;
        
    }
}

void printarr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << "\t";
    cout << endl;
}
void selectionsort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int smallestindex=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[smallestindex])
            smallestindex=j;
        }
    swap(a[i],a[smallestindex]);
    }
}
int main() {
    int n = 5;
    int arr[] = {4, 1, 2, 5, 3};
    bubbleSort(arr, n);
    printarr(arr, n);
     int arr1[]= {4, 1, 2, 5, 3};
    insertionsort(arr1,n);
    printarr(arr1, n);
    
     int arr2[]= {4, 1, 2, 5, 3};
     selectionsort(arr2,n);
    printarr(arr2, n);
    return 0;
}
