#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
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
// Function to check if two binary trees are the same
bool isSameTree(Node* p, Node* q) {
    if (p == NULL || q == NULL)
        return p == q;

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    return (p->val == q->val) && isLeftSame && isRightSame;
}


int main() {
    vector<int> order1 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node *tree1 = bulidTree(order1);
    
    vector<int> order2 = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    idx = -1;
    Node *tree2 = bulidTree(order2);
    if (isSameTree(tree1, tree2))
        cout << "Both trees are the same." << endl;
    else
        cout << "Trees are different." << endl;


    return 0;
}
