#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to remove the nth node from the end of the list
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* left = dummy;
    ListNode* right = head;

    // Move right pointer n steps ahead
    while (n > 0 && right) {
        right = right->next;
        n--;
    }

    // Move both pointers until right reaches the end
    while (right) {
        left = left->next;
        right = right->next;
    }

    // Remove the nth node from the end
    ListNode* nodeToDelete = left->next;
    left->next = left->next->next;
    delete nodeToDelete; // Free memory of removed node

    ListNode* newHead = dummy->next;
    delete dummy; // Free dummy node
    return newHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Construct sample list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2; // Remove the 2nd node from the end (node with value 4)
    cout << "Original list: ";
    printList(head);

    ListNode* result = removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from end: ";
    printList(result);

    // Free allocated memory after usage
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
