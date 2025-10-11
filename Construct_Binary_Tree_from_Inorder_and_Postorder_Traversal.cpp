#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int>& hm) {
    if (ps > pe || is > ie)
        return NULL;

    // Last element of postorder is the root node
    TreeNode* root = new TreeNode(postorder[pe]);

    // Find the root index in inorder traversal using hashmap
    int inroot = hm[postorder[pe]];

    // Numbers of nodes in left subtree
    int numsleft = inroot - is;

    // Recursively build left subtree
    root->left = buildTreePostIn(inorder, is, inroot - 1, postorder, ps, ps + numsleft - 1, hm);

    // Recursively build right subtree
    root->right = buildTreePostIn(inorder, inroot + 1, ie, postorder, ps + numsleft, pe - 1, hm);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() != postorder.size())
        return NULL;

    map<int,int> hm;
    // Store value -> index for quick lookup in inorder
    for (int i = 0; i < (int)inorder.size(); i++)
        hm[inorder[i]] = i;

    return buildTreePostIn(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
}

// Helper to print tree inorder for verification
void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Helper to print tree postorder for verification
void printPostorder(TreeNode* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    TreeNode* root = buildTree(inorder, postorder);

    cout << "Constructed tree inorder traversal: ";
    printInorder(root);
    cout << endl;

    cout << "Constructed tree postorder traversal: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
