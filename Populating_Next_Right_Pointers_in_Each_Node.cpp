#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * Connects each node's next pointer to its next right node.
 * If there is no next right node, the next pointer is set to NULL.
 * It uses a level order traversal (BFS) with a queue.
 * 
 * @param root Root of the binary tree.
 * @return Root of the binary tree after connecting next pointers.
 */
Node* connect(Node* root) {
    // If the tree is empty or root has no children, just return the root
    if (root == NULL || root->left == NULL)
        return root;

    // Queue for BFS traversal, stores nodes of each level
    queue<Node*> q;

    // Push root to start BFS, and NULL acts as a level delimiter
    q.push(root);
    q.push(NULL);  // NULL marks the end of current level

    Node* prev = NULL; // To keep track of the previous node in same level

    // Perform BFS
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // If current node is NULL, we've reached the end of a level
        if (curr == NULL) {
            // If queue is empty after this NULL, we're done
            if (q.empty())
                break;

            // Otherwise, push another NULL to mark the next level's end
            q.push(NULL);
            prev = NULL; // Reset prev for the new level
        }
        else {
            // If there is a previous node on same level, connect its next to current
            if (prev != NULL)
                prev->next = curr;

            // Enqueue left and right children for next level BFS
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);

            // Update prev node to current node
            prev = curr;
        }
    }

    return root;
}

// Helper function to print next pointers of each level for verification
void printLevels(Node* root) {
    Node* level_start = root;
    while (level_start) {
        Node* curr = level_start;
        level_start = NULL;
        while (curr) {
            cout << curr->val << "->";
            if (!level_start) {
                if (curr->left)
                    level_start = curr->left;
                else if (curr->right)
                    level_start = curr->right;
            }
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}

int main() {
    /*
        Construct this tree:
               1
             /   \
            2     3
           / \     \
          4   5     7
    */
    Node* node7 = new Node(7);
    Node* node5 = new Node(5);
    Node* node4 = new Node(4);
    Node* node3 = new Node(3, NULL, node7, NULL);
    Node* node2 = new Node(2, node4, node5, NULL);
    Node* root = new Node(1, node2, node3, NULL);

    // Connect next pointers
    connect(root);

    // Print levels to verify the next pointers
    printLevels(root);

    return 0;
}
