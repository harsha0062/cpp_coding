#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;
int subarraySum_m1(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}
int subarraySum_m2(vector<int> &nums, int k)
{
    int n=nums.size();
        int count=0;
        vector<int>prefixsum(n,0);
        prefixsum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+nums[i];
        }
        unordered_map<int,int>m;
        for(int j=0;j<n;j++){
            if(prefixsum[j]==k) count++;
            int val=prefixsum[j]-k;
            if(m.find(val)!=m.end()){
                count+=m[val];
            }
            if(m.find(prefixsum[j])==m.end()){
                m[prefixsum[j]]=0;
            }
            m[prefixsum[j]]++;
        }
        return count;
}
int main()
{
    vector<int> v = {9,4,20,3,10,5};
    int k = 33;
    cout<<"cout of the subarray sum equals k in method 1( using brute solution): "<< subarraySum_m1(v,k)<<endl;
    cout<<"cout of the subarray sum equals k in method 2 (using unorderded map): "<< subarraySum_m2(v,k)<<endl;
}