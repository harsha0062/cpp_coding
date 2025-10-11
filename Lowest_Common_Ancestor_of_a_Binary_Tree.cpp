#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Pointers to store p and q nodes during tree building
TreeNode* p = nullptr;
TreeNode* q = nullptr;
int target1 = 5; // p value
int target2 = 1; // q value

// Global index for recursive tree build
int idx = -1;

// Function to build tree from preorder input and store p & q when found
TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    TreeNode* node = new TreeNode(preorder[idx]);

    // Capture p and q during build
    if (node->val == target1) p = node;
    if (node->val == target2) q = node;

    node->left = buildTree(preorder);
    node->right = buildTree(preorder);
    return node;
}

// Your original Solution class and function — unchanged
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode* leftlca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightlca = lowestCommonAncestor(root->right, p, q);

        if (leftlca && rightlca)
            return root;
        else if (leftlca != NULL)
            return leftlca;
        else
            return rightlca;
    }
};

int main() {
    // Input: preorder traversal with -1 as NULL
    vector<int> preorder = {3, 5, 6, -1, -1, 2, 7, -1, -1, 4, -1, -1, 1, 0, -1, -1, 8, -1, -1};

    idx = -1;
    TreeNode* root = buildTree(preorder);

    // Check if both p and q were found
    if (!p || !q) {
        cout << "Either p or q node not found in the tree." << endl;
        return 0;
    }

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "Lowest Common Ancestor of " << target1 << " and " << target2 << " is: " << lca->val << endl;
    else
        cout << "Lowest Common Ancestor not found." << endl;

    return 0;
}
