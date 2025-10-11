#include <iostream>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    stack<TreeNode*> s;

    // Helper function to push all left children of a subtree into the stack
    void store(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        store(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        store(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return s.size();
    }
};

// Example usage
int main() {
    /*
      Construct this BST:
          7
         / \
        3   15
            / \
           9  20
    */
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15, new TreeNode(9), new TreeNode(20));

    BSTIterator *obj = new BSTIterator(root);

    cout << "BST Iterator Output:\n";
    while(obj->hasNext()) {
        cout << obj->next() << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;
    delete obj;

    return 0;
}
