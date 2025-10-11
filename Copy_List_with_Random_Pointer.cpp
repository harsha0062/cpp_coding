#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Function to copy the list with random pointers
Node* copyRandomList(Node* head) {
    if (head == NULL)
        return NULL;

    unordered_map<Node*, Node*> m;

    // Step 1: Create all new nodes and map them to original nodes
    Node* oldTemp = head;
    while (oldTemp != NULL) {
        m[oldTemp] = new Node(oldTemp->val);
        oldTemp = oldTemp->next;
    }

    // Step 2: Assign next and random pointers
    oldTemp = head;
    while (oldTemp != NULL) {
        m[oldTemp]->next = m[oldTemp->next];
        m[oldTemp]->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
    }

    return m[head];
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Example usage
int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);

    a->next = b;
    b->next = c;

    a->random = c;
    b->random = a;
    c->random = b;

    cout << "Original List:\n";
    printList(a);

    Node* copiedList = copyRandomList(a);

    cout << "\nCopied List:\n";
    printList(copiedList);

    return 0;
}
