#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int findDuplicate_I(vector<int>& nums) {
        unordered_set<int> s;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i])!=s.end()){
                ans=nums[i];
                break;
            }
            s.insert(nums[i]);
        }
        return ans;
    }
int findDuplicate_II(vector<int>& nums){
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);

        slow=nums[0];

        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
}
int main()
{
    vector<int> v={1,3,4,2,2};
    int i=findDuplicate_I(v);
    int j=findDuplicate_II(v);
    cout<<"given vector"<<endl;
    for(int k:v)
        cout<<" "<<k<<"";
    cout<<endl;
    cout<<"duplicate element using my method: "<<i<<endl;
    cout<<"duplicate element using other method: "<<j<<endl;
}