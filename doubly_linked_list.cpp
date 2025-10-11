#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};
class doublylist
{
    node *head;
    node *tail;

public:
    doublylist()
    {
        head = tail = NULL;
    }
    void push_front(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
            head = tail = newnode;
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void push_back(int val)
    {
        node *newnode = new node(val);
        if (head == NULL)
            head = tail = NULL;
        else
        {
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
        }
    }
    void pop_front()
    {
        if (head == NULL)
            cout << "empty" << endl;
        node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (head == NULL)
            cout << "empty" << endl;
        node *temp = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
};

int main()
{
    doublylist dll;
    dll.push_front(-1);
    dll.push_front(-2);
    dll.push_front(-3);
    dll.print();
    dll.push_back(0);
    dll.push_back(1);
    dll.push_back(2);
    dll.print();
    dll.pop_front();
    dll.print();
    dll.pop_back();
    dll.print();
}
