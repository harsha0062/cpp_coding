#include <iostream>
#include <vector>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to build BST from sorted array
TreeNode* buildBST(vector<int>& nums, int start, int end) {
    if (start > end)
        return nullptr;  // Base case: no elements to include

    int mid = start + (end - start) / 2;  // Choose middle to keep tree balanced
    TreeNode* root = new TreeNode(nums[mid]);  // Create root node with mid value

    // Recursively build left and right subtrees
    root->left = buildBST(nums, start, mid - 1);
    root->right = buildBST(nums, mid + 1, end);

    return root;
}

// Function to start the BST building process
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return buildBST(nums, 0, nums.size() - 1);
}

// Inorder traversal to verify BST structure
void inorderTraversal(TreeNode* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Main function to test the implementation
int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};  // Must be sorted
    TreeNode* root = sortedArrayToBST(nums);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);  // Should print: -10 -3 0 5 9
    cout << endl;

    return 0;
}
