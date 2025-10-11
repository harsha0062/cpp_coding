#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
            int pivot=-1;
        int n=nums.size(),i,j;
        for ( i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());//in place change
            return;
        }
        //2nd step: next larger element
        for( i=n-1;i>pivot;i--)
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        //3rd step: reverse (pivot +1 to n-1)
        reverse(nums.begin()+pivot+1,nums.end());
}
int main()
{
    vector<int> a={1,2,3};
    for (int i: a)
        cout<<i<<"\t";
    cout<<endl;

    nextPermutation(a);
    for(int i: a)
        cout<<i<<"\t";
    cout<<endl;

    
}