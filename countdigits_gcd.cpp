#include<iostream>
#include<math.h>
using namespace std;
int gcd(int a,int b){
    while(a>0&&b>0){
        if(a>b)
            a=a%b;
        else
            b=b%a;
    }
    return max(a,b);
}
int gcdrec(int a,int b){
    if(b==0)    return a;
    return gcdrec(b,a%b);
}
int lcm(int a,int b){
    int gcd=gcdrec(a,b);
    return (a*b)/gcd;

}
int main(){
    int n=453;
    cout<<"number of digits in number "<<n<<" = "<<(int)(log10(n)+1)<<endl;
    int a=20,b=28;
    cout<<"gcd of "<<a<<" & "<<b<<" = "<< gcd(a,b)<<endl;
    a=28,b=20;
    cout<<"gcd of "<<a<<" & "<<b<<" = "<< gcdrec(a,b)<<endl;
    cout<<"lcm of "<<a<<" & "<<b<<" = "<< lcm(a,b)<<endl;
}