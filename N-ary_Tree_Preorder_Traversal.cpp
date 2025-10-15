#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/*
 * Helper function to perform preorder traversal.
 * Visits the root first, then recursively traverses all children.
 */
void helper(Node* root, vector<int> &l) {
    if (root == NULL)
        return;

    // Visit the current node
    l.push_back(root->val);

    // Recursively visit each child
    for (Node* r : root->children)
        helper(r, l);
}

/*
 * Performs preorder traversal of the N-ary tree
 * and returns the result as a vector of integers.
 */
vector<int> preorder(Node* root) {
    vector<int> l;
    helper(root, l);
    return l;
}

int main() {
    /*
        Construct this N-ary tree manually:
        
                  1
               /  |  \
              3   2   4
             / \
            5   6
            
        Expected preorder traversal: 1 3 5 6 2 4
    */
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    vector<Node*> children3 = {node5, node6};
    Node* node3 = new Node(3, children3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    vector<Node*> children1 = {node3, node2, node4};
    Node* root = new Node(1, children1);

    // Perform preorder traversal
    vector<int> result = preorder(root);

    // Output the result
    cout << "Preorder traversal of the N-ary tree: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    // Free allocated memory
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}
