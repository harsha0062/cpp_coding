#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Recursively constructs the BST from preorder traversal.
 * 
 * @param preorder vector of values in preorder traversal
 * @param i index reference for current value
 * @param bound upper bound to maintain the BST property
 * @return pointer to TreeNode (root of current subtree)
 */
TreeNode* buildBSTFromPreorder(vector<int>& preorder, int& i, int bound) {
    // Base case: out of bounds or violates BST ordering
    if (i >= preorder.size() || preorder[i] > bound)
        return nullptr;

    // Create the current node
    TreeNode* root = new TreeNode(preorder[i]);
    i++;

    // Left subtree: elements < root->val
    root->left = buildBSTFromPreorder(preorder, i, root->val);

    // Right subtree: elements > root->val but <= bound
    root->right = buildBSTFromPreorder(preorder, i, bound);

    return root;
}

// Wrapper function
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return buildBSTFromPreorder(preorder, i, INT_MAX);
}

// Helper function to print inorder traversal (should be sorted if BST is correct)
void printInorder(TreeNode* root) {
    if (root == nullptr)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main test
int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* root = bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    // Optional: manually delete nodes to free memory if needed
    // (skipping here for simplicity in short test code)

    return 0;
}
