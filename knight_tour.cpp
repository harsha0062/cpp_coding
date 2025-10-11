#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
 bool isvalid(vector<vector<int>>& grid,int r,int c,int n,int exp){

        if(r<0||c<0||r>=n||c>=n||grid[r][c]!=exp)
            return false;
        if(exp==n*n-1)
            return true;
        //8 possible moves
        int ans1=isvalid(grid,r-2,c+1,n,exp+1);
        int ans2=isvalid(grid,r-1,c+2,n,exp+1);
        int ans3=isvalid(grid,r+1,c+2,n,exp+1);
        int ans4=isvalid(grid,r+2,c+1,n,exp+1);
        int ans5=isvalid(grid,r+2,c-1,n,exp+1);
        int ans6=isvalid(grid,r+1,c-2,n,exp+1);
        int ans7=isvalid(grid,r-1,c-2,n,exp+1);
        int ans8=isvalid(grid,r-2,c-1,n,exp+1);
        
        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return isvalid(grid,0,0,grid.size(),0);   
    }
int main(){
    vector<vector<int>> grid= {{0,3,6},{5,8,1},{2,7,4}};
    cout<<"given grid"<<endl;
    for(vector<int> i:grid)
    {
        for(int j:i)
            cout<<"\t"<<j<<"\t";
        cout<<endl;
    }
    bool val = checkValidGrid(grid);
    string str = val ? "true" : "false";

    cout<<"support the knight path :\t"<<str<<endl;
}