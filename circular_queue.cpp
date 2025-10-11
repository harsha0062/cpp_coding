#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
class circularqueue{
    int *arr;
    int currsize,cap;
    int f,r;
public:
    circularqueue(int size){
        cap=size;
        arr=new int[cap];
        f=0,r=-1;
        currsize=0;
    }
    
    void push(int data){
        if(currsize==cap){
            cout<<"CQ is FULL\n";
            return;
        }

        r=(r+1)%cap;
        arr[r]=data;
        currsize++;

    }
    void pop(){
        if(empty()){
            cout<<"CQ is empty";
            return;
        }
        f=(f+1)%cap;
        currsize--;
    }
    int front(){
        return arr[f];
    }
    bool  empty(){
        return currsize==0;
    }

    void printarr(){
        for(int i=0;i<cap;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    system("cls");
    circularqueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.printarr();
    cq.pop();
    cq.push(4);
    // cq.printarr();
    while (!cq.empty())
    {
        cout<<cq.front()<<" ";
        cq.pop();
    }
    cout<<endl;
    
    return 0;
}