#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;
Node *bulidTree(vector<int> preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;
    Node *root = new Node(preorder[idx]);
    root->left = bulidTree(preorder);
    root->right = bulidTree(preorder);
    return root;
}

int sumTree(Node* root){
    if(root ==NULL)
        return 0;
    return root->data+sumTree(root->left)+sumTree(root->right);
}
int main()
{
    vector<int> order = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = bulidTree(order);
    cout<<"sum of node:\t"<<sumTree(root)<<endl;
}