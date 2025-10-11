#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Morris Inorder Traversal Function
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* curr = root;

    while (curr != NULL) {
        // Case 1: If no left child, visit current and move to right
        if (curr->left == NULL) {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        // Case 2: If left child exists, find the rightmost node in left subtree
        else {
            TreeNode* inorderPredecessor = curr->left;

            // Find the rightmost node in left subtree (or thread that points to current)
            while (inorderPredecessor->right != NULL && inorderPredecessor->right != curr) {
                inorderPredecessor = inorderPredecessor->right;
            }

            // Create a thread to the current node
            if (inorderPredecessor->right == NULL) {
                inorderPredecessor->right = curr;  // Temporary link (thread)
                curr = curr->left;
            }
            // Thread already exists, remove it and visit current node
            else {
                inorderPredecessor->right = NULL;  // Remove the thread
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return ans;
}

// Helper function to build a simple tree for demonstration
TreeNode* createSampleTree() {
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    vector<int> result = inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
