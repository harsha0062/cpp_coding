#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x) {
    if ((!head) || (!head->next))
        return head;

    // Create two dummy nodes for left and right partitions
    ListNode* left = new ListNode(0);
    ListNode* right = new ListNode(0);

    // Tail pointers for left and right lists
    ListNode* lefttail = left;
    ListNode* righttail = right;

    // Traverse original list and distribute nodes accordingly
    while (head != NULL) {
        if (head->val < x) {
            lefttail->next = head; // Append to left list
            lefttail = lefttail->next;
        } else {
            righttail->next = head; // Append to right list
            righttail = righttail->next;
        }
        head = head->next;
    }

    // Connect left list to right list
    lefttail->next = right->next;
    righttail->next = NULL; // End of final list

    return left->next;
}

// Helper to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper to create linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Input: list and partition value x
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    head = partition(head, x);

    cout << "List after partitioning around " << x << ": ";
    printList(head);

    return 0;
}
