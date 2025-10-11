#include<iostream>
#include<list>
#include<stack>
using namespace std;
class Stack{
    list<int> l;
    public:
        void push(int data){
            l.push_front(data);
        }
        void pop(){
            l.pop_front();
        }
        int top(){
            return l.front();
        }
        bool empty(){
            return l.size()==0;    
        }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
    return 0;

}