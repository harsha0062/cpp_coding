#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Merges k sorted linked lists into one sorted list
ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Min-heap to store tuple (value, corresponding ListNode*)
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

    // Add head nodes of each list to the heap if not NULL
    for (int i = 0; i < lists.size(); i++)
        if (lists[i])
            pq.push({lists[i]->val, lists[i]});

    // Dummy node to start the merged list
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    // Continue until heap is empty
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        // If next node exists, add it to the heap
        if (it.second->next)
            pq.push({it.second->next->val, it.second->next});

        // Add the smallest node to the result
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& nums) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    for (int val : nums) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy->next;
}

int main() {
    // Sample input: three sorted linked lists
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    // Creating linked lists from vectors
    ListNode* l1 = createList(arr1);
    ListNode* l2 = createList(arr2);
    ListNode* l3 = createList(arr3);

    // Storing the list heads in a vector
    vector<ListNode*> lists = {l1, l2, l3};

    // Merging and printing the final sorted list
    ListNode* mergedList = mergeKLists(lists);
    printList(mergedList); // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

    return 0;
}
