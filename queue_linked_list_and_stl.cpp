#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
class queue1
{
    node *head;
    node *tail;

public:
    queue1()
    {
        head = tail = NULL;
    }

    void push(int data)
    { // insert data at tail
        node *newnode = new node(data);
        if (empty())
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "empty" << endl;
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front()
    {
        if (empty())
            return -1;
        return head->data;
    }

    bool empty()
    {
        return head == NULL;
    }
};
int main()
{
    system("cls");
    queue1 q;
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << " * " << endl;
    queue <int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;

    return 0;
}