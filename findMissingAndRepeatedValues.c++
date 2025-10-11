#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;
        int n=grid.size();
        int a,b;
        int expsum=0,actualsum=0;
        for(int i= 0;i<n;i++){
            for(int j=0;j<n;j++){
                actualsum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(a);

                }
                s.insert(grid[i][j]);

            }
        }
        expsum=((n*n)*((n*n)+1))/2;
        b=expsum+a-actualsum;
        ans.push_back(b);
        return ans;
    }

int main()
{
    vector<vector<int>>v={{1,3},{2,2}};
    vector<int> j=findMissingAndRepeatedValues(v);
    cout<<"given grid"<<endl;
    for(vector<int>i:v)
        for(int k:i)
            cout<<" "<<k<<"";
        cout<<endl;
    cout<<"find_Missing_And_Repeated_Values"<<endl;
    for(int i:j)
        cout<<" "<<i<<" ";
    

}