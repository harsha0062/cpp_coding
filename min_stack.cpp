#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> s;

    MinStack() {}

    void push(int val) {
        if (s.empty())
            s.push({val, val});
        else {
            int minval = min(val, s.top().second);
            s.push({val, minval});
        }
    }

    void pop() {
        if (!s.empty())
            s.pop();
    }

    int top() {
        if (!s.empty())
            return s.top().first;
        return -1; // or throw an exception
    }

    int getMin() {
        if (!s.empty())
            return s.top().second;
        return -1; // or throw an exception
    }
};

int main() {
    MinStack* obj = new MinStack();

    obj->push(5);
    obj->push(3);
    obj->push(7);
    obj->push(2);

    cout << "Top: " << obj->top() << endl;       // Should print 2
    cout << "Min: " << obj->getMin() << endl;   // Should print 2

    obj->pop(); // Pops 2

    cout << "Top after pop: " << obj->top() << endl;     // Should print 7
    cout << "Min after pop: " << obj->getMin() << endl;  // Should print 3

    delete obj; // Free the memory

    return 0;
}
