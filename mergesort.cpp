#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<int> &arr,int start,int mid,int end){
    vector<int>temp;
    int i=start,j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j<=end){
        temp.push_back(arr[j]);
        j++;
    }   

    for(int index=0;index<temp.size();index++){
        arr[index+start]=temp[index];
    }
}
void mergesort(vector<int> &arr,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);//left half
        mergesort(arr,mid+1,end);//right half
        merge(arr,start,mid,end);
    }
}
int main(){
    vector<int>a={12,31,35,8,32,17};
    for (int i:a)
        cout<<i<<"\t";
    cout<<endl;

    mergesort(a,0,a.size()-1);

    for (int i:a)
        cout<<i<<"\t";
    cout<<endl;   
}