#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Global index for building tree
int idx = -1;

// Function to build a binary tree from preorder input (-1 denotes NULL)
TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

// Function to calculate maximum width of binary tree
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long start = q.front().second;
        unsigned long long end = q.back().second;
        maxWidth = max(maxWidth, (int)(end - start + 1));

        for (int i = 0; i < levelSize; ++i) {
            auto curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            unsigned long long index = curr.second - start; // Normalize to prevent overflow

            if (node->left)
                q.push({node->left, 2 * index + 1});
            if (node->right)
                q.push({node->right, 2 * index + 2});
        }
    }

    return maxWidth;
}

int main() {
    // Example tree: [1,3,5,-1,-1,3,-1,-1,2,-1,9,-1,-1]
    vector<int> preorder = {1, 3, 5, -1, -1, 3, -1, -1, 2, -1, 9, -1, -1};

    idx = -1; // reset index
    TreeNode* root = buildTree(preorder);

    int maxWidth = widthOfBinaryTree(root);
    cout << "Maximum width of the binary tree: " << maxWidth << endl;

    return 0;
}
