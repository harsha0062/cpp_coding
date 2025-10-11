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
void kthlevel(Node* root,int k){
    if(root==NULL)  return;
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}
int main()
{
        vector<int> order = {1, 2,7,-1, -1,-1,3, 4, -1, -1, 5, -1, -1};
        Node *root = bulidTree(order);
        int k=2;
        kthlevel(root,k);

}