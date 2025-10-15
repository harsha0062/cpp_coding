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
 * Helper function to perform postorder traversal.
 * Recursively visits all children first, then the root.
 */
void helper(Node* root, vector<int> &l) {
    if (root == NULL)
        return;

    // Visit children first
    for (Node* r : root->children)
        helper(r, l);

    // Visit the current node last
    l.push_back(root->val);
}

/*
 * Performs postorder traversal of the N-ary tree
 * and returns the result as a vector of integers.
 */
vector<int> postorder(Node* root) {
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

        Expected postorder traversal: 5 6 3 2 4 1
    */
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    vector<Node*> children3 = {node5, node6};
    Node* node3 = new Node(3, children3);
    Node* node2 = new Node(2);
    Node* node4 = new Node(4);
    vector<Node*> children1 = {node3, node2, node4};
    Node* root = new Node(1, children1);

    // Perform postorder traversal
    vector<int> result = postorder(root);

    // Output the result
    cout << "Postorder traversal of the N-ary tree: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    // Clean up memory
    delete node5;
    delete node6;
    delete node3;
    delete node2;
    delete node4;
    delete root;

    return 0;
}
