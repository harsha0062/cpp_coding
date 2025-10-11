#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include<cstdlib>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);  // Nearest smaller to left
    vector<int> right(n, 0); // Nearest smaller to right
    stack<int> s;
    
    // Fill right[]
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    
    // Clear stack for reuse
    while (!s.empty()) s.pop();
    
    // Fill left[]
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    
    // Calculate max area
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

// Example usage
int main() {
    system("cls");
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << largestRectangleArea(histogram) << endl;
    return 0;
}
