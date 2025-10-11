#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect the start of the cycle
ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    bool isCycle = false;

    // Step 1: Check if there is a cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            isCycle = true;
            break;
        }
    }

    // If no cycle, return NULL
    if (!isCycle) return NULL;

    // Step 2: Find the start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // The node where the cycle begins
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

// Function to create a cycle at position `pos` (0-indexed)
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

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    // Create cycle starting at node with index 2 (value 3)
    createCycle(head, 2);

    ListNode* cycleStart = detectCycle(head);

    if (cycleStart != NULL) {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    } else {
        cout << "No cycle in the linked list." << endl;
    }

    return 0;
}
