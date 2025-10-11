#include <iostream>
#include<stdio.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Global pointer to keep track of next node in the flattened list
TreeNode* nextRight = NULL;

// Function to flatten the tree to a linked list
void flatten(TreeNode* root) {
    if (root == NULL) return;

    // Recursively flatten right and left subtrees (reverse preorder)
    flatten(root->right);
    flatten(root->left);

    // Set the right pointer to previously visited node
    root->right = nextRight;

    // Left should be NULL as per problem
    root->left = NULL;

    // Move the next pointer to current node
    nextRight = root;
}

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    // Example Tree:
    //     1
    //    / \
    //   2   5
    //  / \   \
    // 3   4   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    return root;
}

// Helper function to print flattened tree
void printLinkedList(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

// Main function
int main() {
    TreeNode* root = createSampleTree();

    flatten(root);

    cout << "Flattened Tree (Linked List): ";
    printLinkedList(root);

    return 0;
}
