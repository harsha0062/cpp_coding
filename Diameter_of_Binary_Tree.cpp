#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Global index for preorder build
static int idx = -1;

// Build binary tree using preorder input (-1 as NULL marker)
TreeNode* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    TreeNode* root = new TreeNode(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
int ans=0;
int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        ans=max(ans,left+right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
// Compute the diameter of the tree
int diameterOfBinaryTree1(TreeNode* root) {
    if (root == NULL)
        return 0;

    int leftDiameter = diameterOfBinaryTree1(root->left);
    int rightDiameter = diameterOfBinaryTree1(root->right);
    int currentDiameter = height(root->left) + height(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}


int main() {
    // Example input: {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1}
    vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};

    idx = -1;
    TreeNode* root = buildTree(preorder);

    int diameter = diameterOfBinaryTree1(root);
    cout << "Diameter of the binary tree is: " << diameter << endl;

    diameter = diameterOfBinaryTree(root);
    cout << "best case: Diameter of the binary tree is: " << diameter << endl;
    
    return 0;
}
