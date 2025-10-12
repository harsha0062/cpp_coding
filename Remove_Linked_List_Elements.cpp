#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to remove all elements with given value from the linked list
ListNode* removeElements(ListNode* head, int val) {
    // Create a dummy node to simplify edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* curr = dummy;

    // Traverse the list and skip nodes with the target value
    while (curr->next != NULL) {
        if (curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return dummy->next;
}

// Helper function to create a linked list from vector of values
ListNode* createList(const vector<int>& vals) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int v : vals) {
        curr->next = new ListNode(v);
        curr = curr->next;
    }
    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 6, 3, 4, 5, 6}; // Input list
    int valToRemove = 6;                      // Value to remove
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    head = removeElements(head, valToRemove);

    cout << "List after removing " << valToRemove << ": ";
    printList(head);

    return 0;
}
