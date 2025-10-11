#include <iostream>
#include <stack>
using namespace std;

// Class to simulate a queue using two stacks
class MyQueue {
public:
    stack<int> s1; // Main stack (always maintains front at the top)
    stack<int> s2; // Helper stack used during push

    // Constructor
    MyQueue() {
        // No initialization required
    }

    // Push element x to the back of queue
    void push(int x) {
        // Step 1: Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Step 2: Push new element onto s1
        s1.push(x);

        // Step 3: Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        // Now the front of the queue is on top of s1
    }

    // Removes the element from in front of the queue and returns it
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    // Get the front element
    int peek() {
        return s1.top();
    }

    // Returns true if the queue is empty
    bool empty() {
        return s1.empty();
    }
};

// Main function to demonstrate MyQueue functionality
int main() {
    MyQueue* q = new MyQueue();

    // Pushing elements into the queue
    q->push(10);
    q->push(20);
    q->push(30);

    // Peek at the front element
    cout << "Front element: " << q->peek() << endl; // Expected: 10

    // Remove and print front
    cout << "Popped: " << q->pop() << endl;         // Expected: 10

    // Peek again after pop
    cout << "Front element after pop: " << q->peek() << endl; // Expected: 20

    // Check if the queue is empty
    cout << "Is queue empty? " << (q->empty() ? "Yes" : "No") << endl; // Expected: No

    // Remove remaining elements
    q->pop(); // Removes 20
    q->pop(); // Removes 30

    // Check again
    cout << "Is queue empty after removing all? " << (q->empty() ? "Yes" : "No") << endl; // Expected: Yes

    
    return 0;
}
