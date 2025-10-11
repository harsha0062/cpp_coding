#include <iostream>
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

// Function to connect next pointers at each level
Node* connect(Node* root) {
    if (root == NULL)
        return NULL; // If tree is empty, return NULL

    Node* head = root; // Head pointer for the current level
    while (head != NULL) {
        Node* dummy = new Node(0); // Dummy node for next level
        Node* temp = dummy; // Temp pointer to build next level links

        // Iterate through the current level
        while (head != NULL) {
            if (head->left != NULL) {
                temp->next = head->left;
                temp = temp->next;
            }
            if (head->right != NULL) {
                temp->next = head->right;
                temp = temp->next;
            }
            head = head->next; // Move to next node at same level
        }
        head = dummy->next; // Move head to the start of next level
    }
    return root; // Return the modified tree root
}

// Helper function to print level order traversal using next pointers
void printLevels(Node* root) {
    Node* level_head = root;
    while (level_head != NULL) {
        Node* curr = level_head;
        while (curr != NULL) {
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
        // Move to the first node of the next level
        if (level_head->left != NULL)
            level_head = level_head->left;
        else if (level_head->right != NULL)
            level_head = level_head->right;
        else
            level_head = NULL;
    }
}

int main() {
    // Example: Creating the following binary tree
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    // Connect next pointers
    connect(root);

    // Print level order traversal using next pointers
    printLevels(root);

    return 0;
}
