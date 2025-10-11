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

// Function to find the middle node of the linked list
ListNode* findmiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;           // moves one step
        fast = fast->next->next;     // moves two steps
    }
    return slow;
} 

// Function to merge two sorted linked lists
ListNode* mergetwolist(ListNode* list1, ListNode* list2) {
    ListNode* dummyNode = new ListNode(); // dummy node to simplify merging
    ListNode* temp = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;  // append remaining nodes of list1, if any
    else temp->next = list2;        // append remaining nodes of list2, if any
    return dummyNode->next;         // return merged list head
}

// Function to sort the linked list using merge sort
ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;               // base case: 0 or 1 node is already sorted

    ListNode* middle = findmiddle(head);  // find middle node
    ListNode* right = middle->next;        // start of right half
    middle->next = NULL;                   // split the list into two halves
    ListNode* left = head;

    left = sortList(left);    // recursive sort left half
    right = sortList(right);  // recursive sort right half
    return mergetwolist(left, right); // merge sorted halves
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Helper function to create a linked list from array and return the head
ListNode* createList(int arr[], int n){
    if(n == 0) return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for(int i = 1; i < n; i++){
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main(){
    // Input array for linked list
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Create linked list from array
    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    // Sort the linked list
    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
