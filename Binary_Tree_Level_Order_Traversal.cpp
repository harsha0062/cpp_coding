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
    // Constructor with a value and children
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to return the level order traversal as a vector of vectors
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL)  return ans; // If tree is empty, return empty result
    queue<TreeNode*> q;
    q.push(root); // Start with root node in the queue
    while(!q.empty()){
        int size = q.size(); // Number of nodes at current level
        vector<int> level;
        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)   q.push(node->left); // Add left child if exists
            if(node->right != NULL)  q.push(node->right); // Add right child if exists
            level.push_back(node->val); // Add current node's value
        }
        ans.push_back(level); // Add current level to answer
    }
    return ans;
}

int main() {
    // Create binary tree:
    //         1
    //        / \
    //       2   3
    //      /   / \
    //     4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Get level order traversal
    vector<vector<int>> result = levelOrder(root);

    // Print the result
    cout << "Level Order Traversal:" << endl;
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
