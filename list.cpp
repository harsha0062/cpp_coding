#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

int main(){
    //list
    
    
    list<int> l;

    //insert element in list
    l.push_back(2);
    l.push_back(3);
    l.push_front(1);
    l.push_front(0);

    //element
    cout<<"element :"<<endl;
    for(int i:l)
        cout<<i<<"\t";
    cout<<endl;

    l.pop_back();
    l.pop_front();

    //element
    cout<<"element :"<<endl;
    for(int i:l)
        cout<<i<<"\t";
    cout<<endl;

    //deque
    deque<int> a={1,2,3,4,5};
    cout<<"element :"<<endl;
    for(int i:a)
        cout<<i<<"\t";
    cout<<endl;
    

    //pair
    pair<int,int> p={1,2};
    cout<<"pair element:"<<endl;
    cout<<p.first<<"\t";
    cout<<p.second<<endl;

    //DOUBLE PAIR
    pair<int,pair<char,int>> p1={1,{'c',2}};
    cout<<" double pair element:"<<endl;
    cout<<p1.first<<"\t";
    cout<<p1.second.first<<"\t";
    cout<<p1.second.second<<endl;
    
    //vector+pair
    cout<<"vector pair element:"<<endl;
    vector<pair<int,int>> vp1={{1,2},{2,3},{3,4},{4,5}};
    for(pair<int,int> j:vp1)
        cout<<j.first<<"\t\t"<<j.second<<endl;
    cout<<endl;

}