    #include<iostream>
    #include<map>
    using namespace std;
        int romanToInt(string s) {
            map<char,int > um;
            um['I']=1;
            um['V']=5;
            um['X']=10;
            um['L']=50;
            um['C']=100;
            um['D']=500;
            um['M']=1000;
            
            int i=1;
            int sum=0;
            while(i<s.length())
            {
                if(um[s[i-1]]>=um[s[i]]){
                    sum=sum+um[s[i-1]];
                    
                }
                else
                {
                    sum=sum-um[s[i-1]];
                }
                i++;
              } 
                sum=sum+um[s[s.length()-1]];
                return sum;
        
        }
        int main(){
            string s="MCMXCIV";
            int i=romanToInt(s);
            cout<<"roman number:\t"<<s<<endl;
            cout<<"number:\t"<<i<<endl;
        }