#include <iostream>
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

// Function to count nodes in a binary tree (same as provided)
int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return 1 + left + right;
}

// Helper function to create example tree and test countNodes
int main() {
    // Creating a simple binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Count the number of nodes in the tree
    int totalNodes = countNodes(root);
    
    cout << "Total number of nodes in the binary tree: " << totalNodes << endl;

    // Cleanup dynamically allocated nodes to avoid memory leak
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
