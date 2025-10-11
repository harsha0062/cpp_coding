#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool isPalin(string s1){
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
    void getallparti(string s,vector<string> &parti,vector<vector<string>> &ans){
        if(s.size()==0){
            ans.push_back(parti);
            return;
        }

        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);

            if(isPalin(part)){
                parti.push_back(part);
                getallparti(s.substr(i+1),parti,ans);
                parti.pop_back();
            }

        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> parti;
        getallparti(s,parti,ans);
        return ans;

    }
int main()
{
    string s="aab";
    cout<<"given string: "<<s<<endl;
    vector<vector<string>> s1=partition(s);
    cout<<"given palindrome partition"<<endl;
    for (vector<string> i : s1)
    {
    for (string j : i)
        cout << " " << j << " ";
    cout << endl;
    }
    
    
}