#include <iostream>
#include <stack>
using namespace std;

// Global stacks to maintain prices and their spans
stack<int> pricestack;
stack<int> spanstack;

// Function to process next stock price and return the span
int next(int price) {
    int span = 1;
    // Pop smaller or equal prices and add their spans
    while (!pricestack.empty() && pricestack.top() <= price) {
        span += spanstack.top();
        pricestack.pop();
        spanstack.pop();
    }
    pricestack.push(price);
    spanstack.push(span);
    return span;
}

int main() {
    // Example stock prices inputs to test next function
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(prices[0]);

    cout << "Stock spans for given prices:\n";
    for (int i = 0; i < n; i++) {
        int span = next(prices[i]);
        cout << "Price: " << prices[i] << ", Span: " << span << endl;
    }

    return 0;
}
