#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    vector<int> vec;
    
    //inital size
    cout<<"inital size:"<<vec.size()<<endl;
    
    //push element
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    
    cout<<"size :"<<"\t"<<vec.size()<<endl;

    //capacity
    cout<<"capacity :"<<"\t"<<vec.capacity()<<endl;
    
    //elemnts in vector
    cout<<"elements :"<<"\t"<<endl;
    for(int i:vec)
        cout<<i<<"\t";
    cout<<endl;

    //pop element from back
    vec.pop_back();
    cout<<"pop element"<<endl;
    cout<<"elements :"<<"\t"<<endl;
    for(int i:vec)
        cout<<i<<"\t";
    cout<<endl;

    //emplace element from back
    vec.emplace_back(5);
    cout<<"emplace element"<<endl;
    cout<<"elements :"<<"\t"<<endl;
    for(int i:vec)
        cout<<i<<"\t";
    cout<<endl;
    
    //element at particular position
    //uing vec[index] or vec.at(index)
    cout<<"particular position element"<<endl;        
    cout<<vec[0]<<"\t";
    cout<<vec.at(0)<<endl;
        
    //front and back element 
    cout<<"front element"<<endl;
    cout<<vec.front()<<endl;
    cout<<"back element"<<endl;
    cout<<vec.back()<<endl;

    //vector with same numbers(number of times,number)
    vector<int> vec1(3,10);
    cout<<"element"<<endl;
    for(int i:vec1)
        cout<<i<<"\t";
    cout<<endl;
   
    //copy vector from one to other
    vector<int> vec2(vec);
    cout<<"element :"<<"\t"<<endl;
    for(int i:vec2)
        cout<<i<<"\t";
    cout<<endl;
   
    //erase function
    cout<<" erase element :"<<"\t"<<endl;
    vec2.erase(vec2.begin());   
    vec2.erase(vec2.begin()+2);   
    for(int i:vec2)
        cout<<i<<"\t";
    cout<<endl;
   
   //insert at particulat position
    cout<<"insert element :"<<"\t"<<endl;
    vec2.insert(vec2.begin()+1,100);
    vec2.insert(vec2.begin()+3,102);
    
    for(int i:vec2)
        cout<<i<<"\t";
    cout<<endl;
    
    //clear elements in vector
    cout<<"clear elements :"<<"\t"<<endl;
    vec2.clear();
    for(int i:vec2)
        cout<<i<<"\t";
    cout<<endl;
    cout<<"size :"<<"\t"<<vec2.size()<<endl;
    cout<<"capacity :"<<"\t"<<vec2.capacity()<<endl;

    //is empty true-1 & false-0  (vector)
    cout<<"is empty:"<<"\t"<<vec2.empty()<<endl;
    
    //begin and end
    cout<<"begin element:"<<*(vec1.begin())<<endl;
    cout<<"end element:"<<*(vec1.end()-1)<<endl;
    cout<<"reverse begin element:"<<*(vec1.rbegin())<<endl;
    cout<<"reverse end element:"<<*(vec1.rend()-1)<<endl;
    
    //elements in vector using iterator
    
    cout<<"iterator  element :"<<"\t"<<endl;
    // vector<int>::iterator it;
    for(auto it=vec.begin();it!=vec.end();it++)
        cout<<*(it)<<"\t";
    cout<<endl;

    //backword in vector using reverse_iterator
    // vector<int>::reverse_iterator rit;
    cout<<"reverse iterator  element :"<<"\t"<<endl;
    for(auto rit=vec.rbegin();rit!=vec.rend();rit++)
        cout<<*(rit)<<"\t";
    cout<<endl;
    
    

}