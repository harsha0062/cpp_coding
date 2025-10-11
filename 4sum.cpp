#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; ) {
                
                int p = j + 1, q = n - 1;

                while (p < q) {
                    long long sum = (long long)nums[i] +(long long) nums[j] +(long long) nums[p] + (long long)nums[q];
                    if (sum < tar) {
                        p++;
                    } else if (sum > tar) {
                        q--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;
                        while (p < q && nums[p] == nums[p - 1]) p++;
                        
                    }
                }
                j++;
                while(j<n&&nums[j]==nums[j-1])  j++;
            }
        }
        return ans;
    }

int main(){
    vector<int> arr={-2,-1,-1,1,1,2,2};
    int target=0;
    vector<vector<int>> ans=fourSum(arr,target);
    cout<<"given element:"<<endl;
    for (int k:arr)
         cout<<" "<<k<<" ";
    cout<<endl;

    cout<<"given answer:"<<endl;
    for(vector<int> i:ans){
        for(int j:i)
            cout<<" "<<j<<" ";
        cout<<endl;
    }
}