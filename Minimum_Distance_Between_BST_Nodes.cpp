#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

// Global pointer to keep track of the previous node during in-order traversal
TreeNode* prevNode = nullptr;

/**
 * Finds the minimum absolute difference between values of any two nodes in a BST.
 * This is done via an in-order traversal, which gives values in increasing order.
 * At each step, we compare the current node with the previous node visited,
 * and update the minimum difference accordingly.
 */
int minDiffInBST(TreeNode* root) {
    if (root == nullptr)
        return INT_MAX;

    int ans = INT_MAX;

    // Traverse left subtree
    if (root->left) {
        ans = min(ans, minDiffInBST(root->left));
    }

    // Process current node
    if (prevNode != nullptr) {
        ans = min(ans, root->val - prevNode->val);
    }
    prevNode = root; // Update previous node

    // Traverse right subtree
    if (root->right) {
        ans = min(ans, minDiffInBST(root->right));
    }

    return ans;
}

// Example usage
int main() {
    /*
        Constructing the following BST:
              4
             / \
            2   6
           / \
          1   3
    */
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(2, node1, node3);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* root  = new TreeNode(4, node2, node6);

    // Compute minimum difference
    int result = minDiffInBST(root);
    cout << "Minimum difference in BST: " << result << endl;

    // Free allocated memory
    delete node1;
    delete node3;
    delete node2;
    delete node6;
    delete root;

    return 0;
}
