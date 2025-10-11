#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class info
{
public:
    int min, max, size;
    info(int mi, int ma, int si)
    {
        min = mi;
        max = ma;
        size = si;
    }
};
info helper(Node *root)
{
    if (root == NULL)
        return info(INT_MAX, INT_MIN, 0);

    info left = helper(root->left);
    info right = helper(root->right);

    if (root->data > left.max && root->data < right.min)
    {
        int CurrMin = min(root->data, left.min);
        int CurrMax = max(root->data, right.max);
        int Currsize = left.size + right.size + 1;
        return info(CurrMin, CurrMax, Currsize);
    }
    return info(INT_MIN, INT_MAX, max(left.size, right.size));
}
int Largestbst(Node *root)
{
    info inf = helper(root);
    return inf.size;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    cout << Largestbst(root) << endl;
    cout << endl;
}