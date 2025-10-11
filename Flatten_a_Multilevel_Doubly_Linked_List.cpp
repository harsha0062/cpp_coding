// Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
// Output: [1,2,3,7,8,11,12,9,10,4,5,6]
// Original Multilevel List:
//
// Level 1:    1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
//                    |
//                    v
// Level 2:         7 <-> 8 <-> 9 <-> 10
//                        |
//                        v
// Level 3:             11 <-> 12
// Flattened List (Depth-first traversal):
//
// 1 <-> 2 <-> 3 <-> 7 <-> 8 <-> 11 <-> 12 <-> 9 <-> 10 <-> 4 <-> 5 <-> 6
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

// Function to flatten the list
Node* flatten(Node* head) {
    if (head == NULL)
        return head;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->child != NULL) {
            // Save next node
            Node* next = curr->next;

            // Flatten the child list
            Node* childFlattened = flatten(curr->child);
            curr->next = childFlattened;
            childFlattened->prev = curr;
            curr->child = NULL;

            // Move to the end of the flattened child list
            while (curr->next != NULL)
                curr = curr->next;

            // Reconnect to the next part of the main list
            if (next != NULL) {
                curr->next = next;
                next->prev = curr;
            }
        }

        curr = curr->next;
    }

    return head;
}

// Helper to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);
    Node* n9 = new Node(9);
    Node* n10 = new Node(10);

    head->next = n2; n2->prev = head;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;
    n5->next = n6; n6->prev = n5;

    n3->child = n7;
    n7->next = n8; n8->prev = n7;
    n8->next = n9; n9->prev = n8;
    n9->next = n10; n10->prev = n9;

    cout << "Flattened List:\n";
    Node* flatHead = flatten(head);
    printList(flatHead);

    return 0;
}
