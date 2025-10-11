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

// Function to reverse a sublist between positions left and right
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* leftprev = dummy;
    ListNode* curr = head;
    // Move leftprev and curr to the correct start positions
    for (int i = 0; i < left - 1; i++) {
        leftprev = curr;
        curr = curr->next;
    }

    // Reverse the sublist between left and right
    ListNode* prev = NULL;
    for (int i = 0; i < (right - left + 1); i++) {
        ListNode* tempNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tempNext;
    }

    // Connect the reversed sublist back to the list
    leftprev->next->next = curr;
    leftprev->next = prev;
    return dummy->next;
}

// Helper function to print list
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

    int left = 2, right = 4; // Positions to reverse from 2 to 4
    cout << "Original list: ";
    printList(head);

    ListNode* result = reverseBetween(head, left, right);

    cout << "List after reversing from " << left << " to " << right << ": ";
    printList(result);

    // Free memory (optional for small demo)
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}
