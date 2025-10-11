#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Dummy Node class, included as per request
class Node {
public:
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

// Function to check valid parentheses
bool isValid(string str) {
    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
            st.push(str[i]);
        else {
            if (st.size() == 0)
                return false;
            if ((st.top() == '{' && str[i] == '}') ||
                (st.top() == '[' && str[i] == ']') ||
                (st.top() == '(' && str[i] == ')'))
                st.pop();
            else
                return false;
        }
    }
    return st.size() == 0;
}

// Example usage
int main() {
    string input1 = "()[]{}";
    string input2 = "([)]";
    string input3 = "{[()]}";

    cout << input1 << " => " << (isValid(input1) ? "Valid" : "Invalid") << endl;
    cout << input2 << " => " << (isValid(input2) ? "Valid" : "Invalid") << endl;
    cout << input3 << " => " << (isValid(input3) ? "Valid" : "Invalid") << endl;

    return 0;
}
