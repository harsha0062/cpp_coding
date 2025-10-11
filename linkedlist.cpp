#include<iostream>
#include<vector>
#include<string>
using namespace std;
class node{
    public:
        int data;
        node* nxt;
        node(int val){
            data=val;
            nxt=NULL;
        }
};
class list{
    node* head;
    node* tail;
public:
    list(){
    head=tail=NULL;
    }
    void push_front(int val){
        node* newnode= new node(val);
        if (head==NULL){
            head=tail=newnode;
            
        }
        else{
                newnode->nxt=head;    
                head=newnode;

        }

    }
    void push_back(int val){
        node* newnode=new node(val);
        if(head==NULL){            
            head=tail=newnode;
            
        } 
        else{
        tail->nxt=newnode;
            tail=newnode;
        }
    }
    void pop_front(){
        if(head==NULL)
            cout<<"empty"<<endl;
        node * temp=head;
        head=head->nxt;
        temp->nxt=NULL;
        delete temp;
    }
    void pop_back(){
        if(head==NULL)
            cout<<"empty"<<endl;
        node* temp=head;
        while(temp->nxt!=tail){
            temp=temp->nxt;
        }   
        temp->nxt=NULL;
        delete tail;
        tail=temp;
        
        
        
    }
    void insert_middle(int val,int pos){
        if(pos<0){
            cout<<"invalid positin"<<endl;
            return;
        }
        
        node* newnode=new node(val);
        node* temp=head;
        if(pos==0){
            push_front(val);
            return;
    }
        
        for(int i=0;i<pos-1;i++)
            temp=temp->nxt;
        newnode->nxt=temp->nxt;
        temp->nxt=newnode;
    }
    int  serach(int val ){
        node* temp=head;
        int idx=0;
        while (temp!=NULL)
        {
            if(temp->data==val)
            {
                return idx;
            }
            temp=temp->nxt;
            idx++;
        }
        return -1;
    }
    void print(){
        node * temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->nxt;
        }
    }
};
int main(){
    list l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.print();
    l.pop_front();
    cout<<endl;
    l.print();
    cout<<endl;
    l.pop_back();
    l.print();
    cout<<endl;
    l.insert_middle(1,2);
    l.print();
    cout<<endl;
    cout<<l.serach(2)<<endl;

}