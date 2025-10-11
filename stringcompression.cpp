#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;

        for(int i=0;i<n;i++){
            char ch=chars[i];
            int count =0;
            while(i<n && chars[i]==ch){
                count++;i++;
            }
            if(count ==1)
                chars[idx++]=ch;
            else{
                chars[idx++]=ch;
                string str=to_string(count);
                for(char c:str)
                    chars[idx++]=c;
            }
        i--;
        }
        chars.resize(idx);
        return idx;
}
int main(){
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    for(char c:chars)
    cout<<c<<" ";
    cout<<endl;
    cout<<compress(chars)<<endl;
    for(char c:chars)
    cout<<c<<" ";
    cout<<endl;
}