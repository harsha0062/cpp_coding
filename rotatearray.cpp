#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
    int j,n=nums.size();
    k=k%n;
    vector<int>n1(n);
    for(int i=0;i<(n);i++){
        j=(i+k)%n;
        n1[j]=nums[i];
    } 
    nums=n1;
}
void printvector(vector<int>&nums){
    for (int i :nums){
        cout<<"\t"<<i<<"\t";
    }
    cout<<endl;
}
int main(){
    vector<int>nums={1,2,3,4,5};
    int k=3;
    cout<<"before rotate nums:\t"<<endl;
    printvector(nums);
    rotate(nums,k);
    cout<<"after rotate nums:\t"<<endl;
    printvector(nums);
}