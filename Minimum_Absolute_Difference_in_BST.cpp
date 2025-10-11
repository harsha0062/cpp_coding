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

// Helper function to do inorder traversal and store node values in sorted order
void inorderTraversal(TreeNode* root, vector<int>& nodes) {
    if (root == nullptr) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
}

// Function to find the minimum difference between values of any two nodes in a BST
int getMinimumDifference(TreeNode* root) {
    vector<int> nodes;
    inorderTraversal(root, nodes);

    int minDiff = INT_MAX;
    for (size_t i = 1; i < nodes.size(); i++) {
        int diff = nodes[i] - nodes[i - 1];
        if (diff < minDiff)
            minDiff = diff;
    }
    return minDiff;
}

int main() {
    // Constructing the BST:
    //         4
    //        / \
    //       2   6
    //      / \
    //     1   3
    
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    
    // Call the function to find the minimum difference
    int result = getMinimumDifference(root);
    
    cout << "Minimum difference between values of any two nodes: " << result << endl;

    // Cleanup allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
