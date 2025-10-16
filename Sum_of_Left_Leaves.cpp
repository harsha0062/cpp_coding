#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Helper function to traverse the tree recursively.
 * If a node is a left leaf (i.e., child of left and has no children),
 * add its value to 'sum'.
 */
void helper(TreeNode* root, int& sum, bool isleaf) {
    if (root == NULL)
        return ;

    // When it’s a left leaf, add to sum
    if (root->left == NULL && root->right == NULL && isleaf)
        sum += root->val;

    // Recur for left and right children
    helper(root->left, sum, true);
    helper(root->right, sum, false);
}

/*
 * Main function returning the sum of left leaves.
 */
int sumOfLeftLeaves(TreeNode* root) {
    int sum = 0;
    helper(root, sum, false);
    return sum;
}

int main() {
    /*
        Construct the following binary tree manually:

                   3
                 /   \
                9     20
                     /  \
                    15   7

        Left leaves: 9 and 15
        Sum = 9 + 15 = 24
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int result = sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << result << endl;

    // Free allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
