#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prev = dummy;  // Pointer to node before current sequence
    ListNode* curr = head;   // Pointer to current node

    while (curr != NULL) {
        // Check if current node has duplicates following it
        if (curr->next != NULL && curr->val == curr->next->val) {
            // Move curr pointer till the last duplicate node
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }

            // Skip all duplicates by linking previous node to the node after duplicates
            prev->next = curr->next;
        } else {
            // No duplicates, move prev forward
            prev = prev->next;
        }

        // Move curr forward
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Input: sorted linked list with duplicates
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
