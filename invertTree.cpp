#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to invert the binary tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // Recursively invert left and right subtrees
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);

    // Swap the left and right pointers
    root->left = right;
    root->right = left;

    return root;
}

// Inorder traversal to print the tree
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
         Original Tree:
              4
            /   \
           2     7
          / \   / \
         1   3 6   9

         Inverted Tree:
              4
            /   \
           7     2
          / \   / \
         9   6 3   1
    */

    // Manually building the tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Inorder traversal before inversion: ";
    printInorder(root);
    cout << endl;

    // Invert the tree
    root = invertTree(root);

    cout << "Inorder traversal after inversion: ";
    printInorder(root);
    cout << endl;

    return 0;
}
