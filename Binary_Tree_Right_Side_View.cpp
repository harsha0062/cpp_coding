#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructors for initializing nodes
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Returns the right side view of the tree
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans; // If tree is empty

    queue<TreeNode*> q;
    q.push(root); // Start BFS from root

    while (!q.empty()) {
        TreeNode* rightSide = NULL; // Holds rightmost node of current level
        int qsize = q.size(); // Number of nodes at this level

        for (int i = 0; i < qsize; i++) {
            TreeNode* node = q.front();
            q.pop();
            if (node != NULL) {
                rightSide = node; // Update rightmost node for this level
                q.push(node->left); // Add left child for next level
                q.push(node->right); // Add right child for next level
            }
        }
        if (rightSide != NULL)
            ans.push_back(rightSide->val); // Add rightmost value to answer
    }
    return ans;
}

int main() {
    // Example tree:
    //      1
    //     / \
    //    2   3
    //     \    \
    //      5    4

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Get right side view
    vector<int> view = rightSideView(root);

    // Print the right side view
    cout << "Right side view: ";
    for (int val : view)
        cout << val << " ";
    cout << endl;

    return 0;
}
