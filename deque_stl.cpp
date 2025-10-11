#include<iostream>
#include<deque>
#include<cstdlib>
using namespace std;
int main(){
    system("cls");
    deque <int> q;
q.push_back(1);
q.push_back(2);
q.push_back(3);
q.push_front(4);
cout<<q.front()<<" "<<q.back()<<endl;
q.pop_back();
q.pop_front();
cout<<q.front()<<" "<<q.back()<<endl;
}