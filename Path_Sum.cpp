#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Default constructors
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Checks if the tree has a root-to-leaf path with the given sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL)
        return false; // If tree is empty, no path exists

    // If it is a leaf node, check if remaining sum equals the node value
    if(root->left == NULL && root->right == NULL)
        return root->val == targetSum;

    // Recursively check left and right subtrees with updated sum
    bool left = hasPathSum(root->left, targetSum - root->val);
    bool right = hasPathSum(root->right, targetSum - root->val);

    return left || right; // Return true if any path found
}

int main() {
    // Example tree:
    //      5
    //     / \
    //    4   8
    //   /   / \
    //  11  13  4
    // /  \      \
    //7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    // Check for root-to-leaf path sum
    if (hasPathSum(root, targetSum))
        cout << "Yes, there is a root-to-leaf path with sum " << targetSum << endl;
    else
        cout << "No, there is no root-to-leaf path with sum " << targetSum << endl;

    return 0;
}
