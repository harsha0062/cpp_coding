#include <iostream>
#include <queue>
using namespace std;

// Class to simulate a stack using two queues
class MyStack {
public:
    queue<int> q1; // Main queue to hold stack elements
    queue<int> q2; // Helper queue used during push operation

    // Constructor
    MyStack() {
        // No special initialization required
    }

    // Pushes element x onto the stack
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push new element into q1
        q1.push(x);

        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        // Now the top element is at the front of q1
    }

    // Removes and returns the top element of the stack
    int pop() {
        // Front of q1 is the top of the stack
        int ans = q1.front();
        q1.pop(); // Remove it
        return ans;
    }

    // Returns the top element without removing it
    int top() {
        return q1.front();
    }

    // Checks if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

// Main function to demonstrate stack operations
int main() {
    // Create a stack object
    MyStack* obj = new MyStack();

    // Push elements onto the stack
    obj->push(10);
    obj->push(20);
    obj->push(30);

    // Display the top element
    cout << "Top element: " << obj->top() << endl; // Expected: 30

    // Pop the top element and display it
    cout << "Popped element: " << obj->pop() << endl; // Expected: 30

    // Display the new top after pop
    cout << "Top element after pop: " << obj->top() << endl; // Expected: 20

    // Check if the stack is empty
    cout << "Is stack empty? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: No

    // Pop remaining elements
    obj->pop(); // Removes 20
    obj->pop(); // Removes 10

    // Check again if the stack is empty
    cout << "Is stack empty after removing all? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: Yes

    return 0;
}
