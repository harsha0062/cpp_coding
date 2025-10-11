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

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 0)
    {
        Node *Curr = q.front();
        q.pop();
        if (Curr == NULL)
        {

            if (!q.empty())
            {
                cout << endl;
                q.push(NULL);
                continue;
            }
            else
                break;
        }
        cout << Curr->data << " ";
        if (Curr->left != NULL)
            q.push(Curr->left);
        if (Curr->right != NULL)
            q.push(Curr->right);
    }
    cout << endl;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int leftht = height(root->left);
    int rightht = height(root->right);
    return max(leftht, rightht) + 1;
}

int count(Node *root)
{
    if (root == NULL)
        return 0;
    int leftcount = count(root->left);
    int rightcount = count(root->right);
    return leftcount + rightcount + 1;
}
int sumofnode(Node* root){
    if(root==NULL) return 0;
    int leftsum=sumofnode(root->left);
    int rightsum=sumofnode(root->right);
    return leftsum+rightsum+root->data;
}
int main()
{
    vector<int> order = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = bulidTree(order);
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    levelorder(root);
    cout << "height : " << height(root) << endl;
    cout << "count : " << count(root) << endl;
    cout<<"sum : "<<sumofnode(root)<<endl;
}