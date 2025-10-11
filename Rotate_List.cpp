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

ListNode* findnth(ListNode* head, int k) {
    int count = 1;
    ListNode* temp = head;

    // Traverse the list until we reach the kth node
    while (temp != NULL) {
        if (count == k) return temp;
        temp = temp->next;
        count++;
    }

    // If k is greater than length of list, return nullptr (or temp which is NULL here)
    return temp;
}

ListNode* rotateRight(ListNode* head, int k) {
    if ((!head) || (!head->next) || k == 0)
        return head;

    ListNode* tail = head;
    int len = 1;

    // Find the tail and length of the list
    while (tail->next != NULL) {
        len++;
        tail = tail->next;
    }

    // If k is multiple of length, list stays same
    if (k % len == 0) return head;

    // Modulo k by length to handle cases where k > len
    k = k % len;

    // Connect tail to head to form a circular list temporarily
    tail->next = head;

    // Find new last node after rotation (len-k th node)
    ListNode* newlastnode = findnth(head, len - k);

    // Head is the node next to newlastnode
    head = newlastnode->next;

    // Break the circle
    newlastnode->next = NULL;

    return head;
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
    // Input: list and rotation k
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "List after rotating right by " << k << ": ";
    printList(head);

    return 0;
}
