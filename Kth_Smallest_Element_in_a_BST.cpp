#include <iostream>
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

// Global variable to count the number of nodes visited in in-order traversal
int count = 0;

/**
 * Finds the k-th smallest element in a Binary Search Tree (BST).
 * This is achieved via an in-order traversal which visits nodes in sorted order.
 *
 * @param root The current node in traversal
 * @param k The k-th smallest position we're looking for
 * @return The value of the k-th smallest node, or -1 if not found
 */
int kthSmallest(TreeNode* root, int k) {
    if (root == nullptr)
        return -1;

    // Search in left subtree
    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    // Visit current node
    count++;
    if (count == k)
        return root->val;

    // Search in right subtree
    return kthSmallest(root->right, k);
}

// Example usage in main()
int main() {
    /*
        Construct the following BST:
               5
              / \
            3    6
           / \
          2   4
         /
        1
    */
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2, node1, nullptr);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, node2, node4);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* root  = new TreeNode(5, node3, node6);

    int k = 3;
    int result = kthSmallest(root, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    // Free memory
    delete node1;
    delete node2;
    delete node4;
    delete node3;
    delete node6;
    delete root;

    return 0;
}

