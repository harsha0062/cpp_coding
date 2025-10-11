#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Global pointers to track the misplaced nodes and previous node during in-order traversal
TreeNode *prevNode = nullptr, *firstNode = nullptr, *secondNode = nullptr;

/**
 * Helper function to swap values of two nodes
 */
void swapNodes(TreeNode *node1, TreeNode *node2)
{
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}

/**
 * Recursive in-order traversal to find the two swapped nodes.
 */
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);

    // Detect the swapped nodes by looking for a pair where prev->val > root->val
    if (prevNode && root->val < prevNode->val)
    {
        if (!firstNode)
            firstNode = prevNode;
        // Always update secondNode (it gets set twice if nodes are not adjacent)
        secondNode = root;
    }
    prevNode = root;

    inorder(root->right);
}

/**
 * Restores the BST by finding and swapping the two misplaced nodes.
 */
void recoverTree(TreeNode *root)
{
    // Reset global pointers before traversal
    prevNode = firstNode = secondNode = nullptr;
    inorder(root);
    if (firstNode && secondNode)
        swapNodes(firstNode, secondNode);
}

/**
 * Helper to print in-order traversal (should be sorted if BST is correct)
 */
void printInorder(TreeNode *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Example usage
int main()
{
    /*
        Construct a BST:
            1
           / \
          3   4
           \
            2

        But 1 and 3 are swapped, so the tree is:
            3
           / \
          1   4
           \
            2
        Correct inorder should be: 1 2 3 4
    */
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(2);

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    // Recover the BST
    recoverTree(root);

    cout << "Inorder after recovery:  ";
    printInorder(root);
    cout << endl;

    // Clean up memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
