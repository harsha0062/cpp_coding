#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// Function to evaluate Reverse Polish Notation expression
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (size_t i = 0; i < tokens.size(); ++i) {
        string c = tokens[i];
        // Check for operators and apply operations
        if (c == "+") {
            int b = s.top(); s.pop();    // Second operand
            int a = s.top(); s.pop();    // First operand
            s.push(a + b);
        } else if (c == "-") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a - b);
        } else if (c == "*") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a * b);
        } else if (c == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(a / b);
        } else {
            // Operand: convert string to integer and push
            s.push(stoi(c));
        }
    }
    // Final result is at the top of the stack
    return s.top();
}

int main() {
    // Example input: Reverse Polish Notation tokens
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    int result = evalRPN(tokens); // Expected output: (2 + 1) * 3 = 9
    cout << "Evaluated result: " << result << endl;
    return 0;
}
