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
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *rightmostinleftsubtree(Node *root)
{
    Node *ans;
    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }
    return ans;
}
Node *leftmostinrightsubtree(Node *root)
{
    Node *ans;
    while (root != NULL)
    {
        ans = root;
        root = root->left;
    }
    return ans;
}
vector<int> getpresucc(Node *root, int key)
{
    Node *curr = root;
    Node *prev = NULL;
    Node *succ = NULL;
    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            prev = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                prev = rightmostinleftsubtree(curr->left);
            }
            if (curr->right != NULL)
            {
                succ = leftmostinrightsubtree(curr->right);
            }
            break;
        }
    }
    return {prev->data, succ->data};
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    inorder(root);
    cout<<endl;
    int key = 4;
    vector<int> ans = getpresucc(root, key);
    cout << "predecessor:\t" << ans[0] << endl;
    cout << "successor:\t" << ans[1] << endl;
    return 0;
}