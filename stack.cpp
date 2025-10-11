#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int main(){
    stack<int> a;

    // insert
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);

    while(!a.empty()){
        cout<<a.top()<<"\t";
        a.pop();
    }
    cout<<endl;

    for(int i=1;i<6;i++)
        a.push(i);


    stack<int> b;
    b.swap(a);
    

    cout<<"size:\t"<<a.size()<<endl;
    cout<<"size:\t"<<b.size()<<endl;
    
    cout<<endl;

    queue<int> a1;
    a1.push(1);
    a1.push(2);
    a1.push(3);
    a1.push(4);
    a1.push(5);

    while(!a1.empty()){
        cout<<a1.front()<<"\t";
        a1.pop();
    }
    cout<<endl;

    for(int i=1;i<6;i++)
        a1.push(i);


    queue<int> b1;
    b1.swap(a1);
    

    cout<<"size:\t"<<a1.size()<<endl;
    cout<<"size:\t"<<b1.size()<<endl;
    
    cout<<endl;

    
    priority_queue<int> a2;
    a2.push(1);
    a2.push(2);
    a2.push(3);
    a2.push(4);
    a2.push(5);

    while(!a2.empty()){
        cout<<a2.top()<<"\t";
        a2.pop();
    }
    cout<<endl;

    cout<<"size:\t"<<a2.size()<<endl;
    
    
    priority_queue<int,vector<int>,greater<int>> a3;
    a3.push(1);
    a3.push(2);
    a3.push(3);
    a3.push(4);
    a3.push(5);

    while(!a3.empty()){
        cout<<a3.top()<<"\t";
        a3.pop();
    }
    cout<<endl;

    cout<<"size:\t"<<a3.size()<<endl;
    

}