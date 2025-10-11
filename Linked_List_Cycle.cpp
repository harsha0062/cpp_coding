#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect if there is a cycle in the linked list
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

// Function to insert node at the end
void insertAtEnd(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
}

// Function to create a cycle for testing
void createCycle(ListNode* head, int pos) {
    if (pos == -1) return;
    ListNode* temp = head;
    ListNode* cycleNode = NULL;
    int count = 0;
    while (temp->next != NULL) {
        if (count == pos)
            cycleNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = cycleNode;
}

int main() {
    ListNode* head = NULL;

    // Create a list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Create cycle: connect last node to node at position 2 (0-based index)
    createCycle(head, 2);

    // Check for cycle
    if (hasCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
