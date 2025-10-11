#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Function to find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
 * - If both p and q are smaller than root, traverse left.
 * - If both are greater than root, traverse right.
 * - Otherwise, root is the LCA (as one is on each side or equal to root).
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL)
        return NULL;

    // If both p and q are smaller than root, LCA lies in left subtree
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);

    // If both p and q are greater than root, LCA lies in right subtree
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    // If one is on the left and one on the right, root is the LCA
    else
        return root;
}

// Sample test case
int main() {
    /*
        Building the BST:
                  6
                /   \
               2     8
              / \   / \
             0   4 7   9
                / \
               3   5
    */

    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);

    // Define the two nodes to find LCA of (e.g., 0 and 4)
    TreeNode* p = root->left->left;    // Node with value 0
    TreeNode* q = root->left->right;   // Node with value 4

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    // Clean up memory
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
