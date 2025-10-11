// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function to reverse nodes in k-group
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    int cnt = 0;

    // Check if there are at least k nodes to reverse
    while (cnt < k) {
        if (temp == NULL)
            return head;
        temp = temp->next;
        cnt++;
    }

    // Recursive call for the remaining list
    ListNode* prevnode = reverseKGroup(temp, k);

    // Reverse current k-group
    temp = head;
    cnt = 0;
    while (cnt < k) {
        ListNode* next = temp->next;
        temp->next = prevnode;
        prevnode = temp;
        temp = next;
        cnt++;
    }

    return prevnode;
}

// Utility function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to add node at the end
void appendNode(ListNode*& head, int val) {
    if (head == NULL) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new ListNode(val);
}

// Example usage
int main() {
    ListNode* head = NULL;
    for (int i = 1; i <= 10; i++) {
        appendNode(head, i);
    }

    cout << "Original List:\n";
    printList(head);

    int k = 3;
    ListNode* result = reverseKGroup(head, k);

    cout << "\nReversed in k=" << k << " groups:\n";
    printList(result);

    return 0;
}
