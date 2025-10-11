#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Default constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    // Constructor with value
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

/**
 * This function checks whether a binary tree is a valid BST or not.
 * It uses the concept of maintaining min and max boundaries allowed for each node.
 *
 * @param root The current node being validated
 * @param min The minimum allowed value a node can have (exclusive)
 * @param max The maximum allowed value a node can have (exclusive)
 * @return true if the subtree rooted at 'root' is a valid BST
 */
bool isBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    // An empty tree is a valid BST
    if (root == nullptr) {
        return true;
    }

    // Check the current node's value against min and max bounds
    if (min != nullptr && root->val <= min->val) {
        return false;
    }

    if (max != nullptr && root->val >= max->val) {
        return false;
    }

    // Recurse for left and right subtrees
    // For the left subtree: max is current node
    // For the right subtree: min is current node
    return isBST(root->left, min, root) && isBST(root->right, root, max);
}

/**
 * Public function to validate the entire binary tree.
 * Starts the validation with no min/max constraints.
 *
 * @param root Pointer to the root node of the tree
 * @return true if the binary tree is a valid BST
 */
bool isValidBST(TreeNode* root) {
    return isBST(root, nullptr, nullptr);
}

// Example test case
int main() {
    // Creating a simple binary tree:
    //
    //      2
    //     / \
    //    1   3

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(2, node1, node3);

    // Check if the binary tree is a valid BST
    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Clean up dynamic memory
    delete node1;
    delete node3;
    delete root;

    return 0;
}
