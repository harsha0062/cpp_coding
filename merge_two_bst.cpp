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
Node *bulidbst(vector<int> arr)
{

    Node *root = NULL;
    for (int val : arr)
    {
        root = insert(root, val);
    }
    return root;
}
void inorder(Node *root, vector<int> &arr)
{

    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
Node *merge(Node *root1, Node *root2)
{
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    int i = 0, j = 0;
    vector<int> temp;
    while (i < arr1.size() && j < arr2.size())
    {
        if(arr1[i]<arr2[j])
            temp.push_back(arr1[i++]);
        else
            temp.push_back(arr2[j++]);
    }
    while(i<arr1.size())
        temp.push_back(arr1[i++]);
    while(j<arr2.size())
        temp.push_back(arr2[i++]);

    return bulidbst(temp);
    
}
void display(Node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
int main()
{  
    vector<int> arr1={1,2,8,10};
    vector<int> arr2={0,3,5};
    Node* root1=bulidbst(arr1);
    Node* root2=bulidbst(arr2);
    Node* head=merge(root1,root2);
    display(root1);
    cout<<endl;
    display(root2);
    cout<<endl;
    display(head);
    cout<<endl;
}