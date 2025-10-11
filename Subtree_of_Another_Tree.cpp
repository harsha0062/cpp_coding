#include <iostream>
#include <vector>
using namespace std;

// Binary tree node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree using preorder input with -1 as NULL marker
static int idx = -1;
TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Check if two trees are exactly the same
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL || q == NULL)
        return p == q;

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    return (p->val == q->val) && isLeftSame && isRightSame;
}

// Check if subRoot is a subtree of root
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == NULL || subRoot == NULL)
        return root == subRoot;

    if (root->val == subRoot->val && isSameTree(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main() {
    // Tree 1 (main tree)
    vector<int> mainTree = {3, 4, 1, -1, -1, 2, -1, -1, 5, -1, -1};
    idx = -1;
    TreeNode* root = buildTree(mainTree);

    // Tree 2 (subtree to search for)
    vector<int> subTree = {4, 1, -1, -1, 2, -1, -1};
    idx = -1;
    TreeNode* subRoot = buildTree(subTree);

    // Check if subtree
    if (isSubtree(root, subRoot))
        cout << "subRoot is a subtree of root." << endl;
    else
        cout << "subRoot is NOT a subtree of root." << endl;

    return 0;
}
