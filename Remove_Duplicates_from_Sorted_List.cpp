#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    // Constructor when no value is given
    ListNode() : val(0), next(NULL) {}
    // Constructor with value
    ListNode(int x) : val(x), next(NULL) {}
    // Constructor with value and next node
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to remove duplicates from a sorted linked list
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* temp = head;
    // Traverse the list
    while (temp != NULL && temp->next != NULL) {
        if (temp->val == temp->next->val)
            temp->next = temp->next->next; // Skip duplicate
        else
            temp = temp->next; // Move ahead if not duplicate
    }
    return head;
}

// Utility function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert node at end
void insertEnd(ListNode* &head, int val) {
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

int main() {
    // Example input: 1 -> 1 -> 2 -> 3 -> 3
    ListNode* head = NULL;
    int input[] = {1, 1, 2, 3, 3};
    int n = sizeof(input) / sizeof(input[0]);
    for (int i = 0; i < n; ++i) {
        insertEnd(head, input[i]);
    }
    cout << "Original List: ";
    printList(head);

    // Remove duplicates
    head = deleteDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    // Deallocate memory
    while (head != NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
