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
Node *insert(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
Node *bulidbst(vector<int> arr)
{

    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }
    return root;
}
bool search(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}
Node *getinodersuccessor(Node *root)
{ // leftmost node in right subtree
    while (root != NULL && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
Node *delnode(Node *root, int key) // key=> val to delete
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = delnode(root->left, key);
    else if (key > root->data)
        root->right = delnode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *is = getinodersuccessor(root->right);
            root->data = is->data;
            root->right = delnode(root->right, is->data);
        }
    }
    return root;
}
int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    Node *root = bulidbst(arr);
    inorder(root);
    cout << endl;
    int key = 1;
    cout << "element is found :" << search(root, key) << endl;
    delnode(root, 6);
    inorder(root);
    cout << endl;
    return 0;
}