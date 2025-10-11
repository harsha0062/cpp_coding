#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node() : val(0), next(NULL) {}
    Node(int x) : val(x), next(NULL) {}
    Node(int x, Node* next) : val(x), next(next) {}
};

Node* swapPairs(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* first = head;
    Node* sec = head->next;
    Node* prev = NULL;

    while (first != NULL && sec != NULL) {
        Node* third = sec->next;

        sec->next = first;
        first->next = third;

        if (prev != NULL) {
            prev->next = sec;
        } else {
            head = sec; // New head of the list
        }

        // Move to next pair
        prev = first;
        first = third;

        if (third != NULL)
            sec = third->next;
        else
            sec = NULL;
    }

    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to create and append a node
void append(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = NULL;

    // Create list 1->2->3->4
    for (int i = 1; i <= 4; i++) {
        append(head, i);
    }

    cout << "Original list:\n";
    printList(head);

    head = swapPairs(head);

    cout << "After swapping pairs:\n";
    printList(head);

    return 0;
}
