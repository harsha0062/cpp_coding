#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Doubly linked list node to hold key-value pair
    class node {
    public:
        int key, val;
        node* prev;
        node* next;

        node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    node* head = new node(-1, -1);  // Dummy head (most recently used side)
    node* tail = new node(-1, -1);  // Dummy tail (least recently used side)

    unordered_map<int, node*> m;  // Map key -> node pointer
    int limit;  // Max capacity of the cache

    // Adds a node right after the head (most recently used)
    void addnode(node* newnode) {
        node* oldnext = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = oldnext;
        oldnext->prev = newnode;
    }

    // Deletes a node from the doubly linked list
    void delnode(node* oldnode) {
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    // Constructor to initialize cache with given capacity
    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Returns the value for the given key, and moves it to the front
    int get(int key) {
        // If key not found, return -1
        if (m.find(key) == m.end())
            return -1;

        // Key found: move node to the front (most recently used)
        node* ansnode = m[key];
        int ans = ansnode->val;

        // Remove from current position and reinsert at front
        m.erase(key);
        delnode(ansnode);
        addnode(ansnode);
        m[key] = ansnode;

        return ans;
    }

    // Inserts or updates a key-value pair
    void put(int key, int value) {
        // If key already exists, remove the old node
        if (m.find(key) != m.end()) {
            node* oldnode = m[key];
            delnode(oldnode);
            m.erase(key);
        }

        // If cache is full, remove the least recently used (before tail)
        if (m.size() == limit) {
            node* lru = tail->prev;
            m.erase(lru->key);
            delnode(lru);
        }

        // Insert new node at front
        node* newnode = new node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};

// Test the LRUCache implementation
int main() {
    // Create a cache with capacity 2
    LRUCache cache(2);

    // Add two items
    cache.put(1, 10);               // Cache: {1=10}
    cache.put(2, 20);               // Cache: {2=20, 1=10}

    cout << cache.get(1) << endl;   // Output: 10 (1 becomes most recently used)
                                    // Cache: {1=10, 2=20}

    cache.put(3, 30);               // Cache is full, remove LRU key=2
                                    // Cache: {3=30, 1=10}

    cout << cache.get(2) << endl;   // Output: -1 (key 2 was evicted)
    cout << cache.get(3) << endl;   // Output: 30
    cout << cache.get(1) << endl;   // Output: 10

    return 0;
}
