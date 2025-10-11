#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // Default constructor
    TreeNode() : val(0), left(NULL), right(NULL) {}
    // Constructor with a value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // Constructor with value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Zigzag level order traversal function (no class wrapper)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;  // Return empty if tree is empty
    queue<TreeNode*> q;
    q.push(root); // Start with root in the queue
    bool leftToRight = true; // Boolean to alternate zigzag direction
    while (!q.empty()) {
        int size = q.size(); // Number of nodes on current level
        vector<int> row(size); // Vector to store current level values
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            int index = (leftToRight) ? i : (size - 1 - i); // Determine index based on direction
            row[index] = node->val;

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        leftToRight = !leftToRight; // Flip direction for next level
        ans.push_back(row);
    }
    return ans;
}

int main() {
    // Construct example tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Get zigzag level order traversal
    vector<vector<int>> result = zigzagLevelOrder(root);

    // Print the result
    cout << "Zigzag Level Order Traversal:" << endl;
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " "; 
        }
        cout << endl;
    }

    return 0;
}
