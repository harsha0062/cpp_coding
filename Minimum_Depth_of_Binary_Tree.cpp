#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructors
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Returns minimum depth of the binary tree
int minDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);

    // If right subtree is missing, return 1 + left subtree depth
    if(root->right == NULL)
        return 1 + left;
    // If left subtree is missing, return 1 + right subtree depth
    if(root->left == NULL)
        return 1 + right;
    // If both children exist, return 1 + minimum of left and right
    return 1 + min(left, right);
}

// Example tree construction and minDepth usage
int main() {
    // Creating a sample tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    //
    // Minimum depth: 2 (1->3)

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, NULL);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    cout << "Minimum Depth: " << minDepth(root) << endl; // Output: 2

    // Cleanup
    delete node4;
    delete node2;
    delete node3;
    delete root;
    return 0;
}
