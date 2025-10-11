#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to find index of current root in inorder vector
int searchInorder(vector<int>& inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1; // Should not reach here if input is valid
}

// Recursive helper function to build tree
TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preIndex, int left, int right) {
    if (left > right)
        return nullptr;

    // Create root node from current preorder index
    TreeNode* root = new TreeNode(preorder[preIndex]);

    // Find the root's index in inorder traversal
    int inIndex = searchInorder(inorder, left, right, preorder[preIndex]);

    preIndex++; // Move to the next node in preorder

    // Recursively build the left and right subtrees
    root->left = buildTreeHelper(preorder, inorder, preIndex, left, inIndex - 1);
    root->right = buildTreeHelper(preorder, inorder, preIndex, inIndex + 1, right);

    return root;
}

// Main buildTree function
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return buildTreeHelper(preorder, inorder, preIndex, 0, inorder.size() - 1);
}

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example input
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    // Build the tree
    TreeNode* root = buildTree(preorder, inorder);

    // Print the inorder traversal of the constructed tree to verify
    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}

