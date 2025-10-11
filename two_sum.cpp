#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i=0;i<arr.size();i++){

            int first=arr[i];
            int sec=tar-first;

            if(m.find(sec)!=m.end()){
                ans.push_back(m[sec]);
                ans.push_back(i);
                break;
            }
            m[first]=i;

        }
        return ans;
    }

int main()
{
    vector<int> v={5,2,11,7,15};
    int target=7;
    vector<int> j=twoSum(v,target);
    cout<<"given vector:"<<endl;
    for(int i:v)
        cout<<" "<<i<<" ";
    cout<<endl;
    cout<<"given target :"<<endl;
    for(int i:j)
        cout<<" "<<i<<" ";
    
}