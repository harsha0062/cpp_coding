#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Recursive function to merge two sorted lists
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    if (head1 == NULL || head2 == NULL) {
        return head1 == NULL ? head2 : head1;
    }
    if (head1->val <= head2->val) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

// Helper function to insert at the end of a list
void insertAtEnd(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* list1 = NULL;
    ListNode* list2 = NULL;

    // Create first sorted list: 1 -> 3 -> 5
    insertAtEnd(list1, 1);
    insertAtEnd(list1, 3);
    insertAtEnd(list1, 5);

    // Create second sorted list: 2 -> 4 -> 6
    insertAtEnd(list2, 2);
    insertAtEnd(list2, 4);
    insertAtEnd(list2, 6);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
