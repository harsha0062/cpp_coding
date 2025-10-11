#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Function to collect all root-to-leaf paths
void getAllPaths(TreeNode* root, string path, vector<string>& result) {
    if (!root->left && !root->right) {
        result.push_back(path); // Reached a leaf node, add path to result
        return;
    }

    // Recurse left
    if (root->left)
        getAllPaths(root->left, path + "->" + to_string(root->left->val), result);
    
    // Recurse right
    if (root->right)
        getAllPaths(root->right, path + "->" + to_string(root->right->val), result);
}

// Function to start path building from root
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> result;
    if (!root) return result;
    getAllPaths(root, to_string(root->val), result);
    return result;
}

// Example tree construction and testing
int main() {
    /*
            1
           / \
          2   3
           \
            5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // Get all root-to-leaf paths
    vector<string> paths = binaryTreePaths(root);

    // Output the paths
    cout << "Root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}
