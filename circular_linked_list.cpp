#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = next = NULL;
    }
};
class circularlist
{
    node *head;
    node *tail;

public:
    circularlist()
    {
        head = tail = NULL;
    }
    void insert_at_head(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }
    void insert_at_tail(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
        {
            head = tail = newnode;
            tail->next = head;
        }
        else
        {
            newnode->next = head;
            tail->next = newnode;
            tail = newnode;
        }
    }
    void delete_at_head()
    {
        if (head == NULL)
            cout << "empty" << endl;
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            node *temp = head;
            head = head->next;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }
    void delete_at_tail()
    {
        if (head == NULL)
            cout << "empty" << endl;
        else if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else{
            node*temp=tail;
            node*prev=head;
            while(prev->next!=tail){
                prev=prev->next;
            }
            tail=prev;
            tail->next=head;
            temp->next=NULL;
            delete temp;
        }
    }
    void print()
    {
        if (head == NULL)
            cout << "NULL" << endl;
        cout << head->data << " ";
        node *temp = head->next;
        while (temp != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
};
int main()
{
    circularlist cl;
    cl.insert_at_head(-2);
    cl.insert_at_head(-1);
    cl.print();
    cl.insert_at_tail(0);
    cl.insert_at_tail(1);
    cl.print();
    cl.delete_at_head();
    cl.print();
    cl.delete_at_tail();
    cl.print();
}