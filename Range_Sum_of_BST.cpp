#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructors for TreeNode
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Helper function performs in-order traversal.
 * - Adds the node value to sum if in [low, high].
 * - Recurses to left and right subtree.
 */
void helper(TreeNode* root, int low, int high, int &sum) {
    if (root == NULL)
        return;
    // Visit left subtree
    helper(root->left, low, high, sum);
    // Check if current node's value is in range
    if (root->val >= low && root->val <= high)
        sum = sum + root->val;
    // Visit right subtree
    helper(root->right, low, high, sum);
}

/*
 * Returns the sum of values in the BST
 * between [low, high] (inclusive).
 */
int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    helper(root, low, high, sum);
    return sum;
}

// Main function to construct BST and test above logic
int main() {
    /*
        Constructing this BST:
               10
              /  \
             5    15
            / \     \
           3   7     18
    */
    TreeNode *n1 = new TreeNode(10);
    TreeNode *n2 = new TreeNode(5);
    TreeNode *n3 = new TreeNode(15);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(18);
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->right = n6;

    int low = 7, high = 15;
    int result = rangeSumBST(n1, low, high);

    cout << "Range sum for [" << low << "," << high << "] in BST is: " << result << endl;

    // Free allocated memory for nodes
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;
    delete n6;

    return 0;
}
