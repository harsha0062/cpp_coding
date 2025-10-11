#include<iostream>
using namespace std;
int diagonalsum(int m[][4],int n){
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=m[i][i];
        if(i!=n-i-1)
            sum+=m[i][n-i-1];
    }
    return sum;
}
int main(){
    int m[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;
    cout<<" diagonal sum: "<<diagonalsum(m,n)<<endl;
}