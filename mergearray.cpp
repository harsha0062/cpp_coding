#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index=m+n-1,i=m-1,j=n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j])
                nums1[index--]=nums1[i--];
            else
                nums1[index--]=nums2[j--];
        }
        while(j>=0)
            nums1[index--]=nums2[j--];
        
}
int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    for (int i:nums1)
        cout<<i<<"\t";
    cout<<endl;
    for (int i:nums2)
        cout<<i<<"\t";
    cout<<endl;
    merge(nums1,3,nums2,3);
        for (int i:nums1)
        cout<<i<<"\t";
    cout<<endl;
    
} 