#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find the largest triangle area from a set of points
double largestTriangleArea(vector<vector<int>>& points) {
    double ans = 0.0;
    int n = points.size();
    // Iterate through all possible combinations of 3 points
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int x3 = points[k][0];

                int y1 = points[i][1];
                int y2 = points[j][1];
                int y3 = points[k][1];

                // Calculate the area using the shoelace formula
                double area = (x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2));
                // Store the maximum area found so far
                ans = max(ans, abs(area));
            }
    // Return the maximum area divided by 2
    return ans * 1.0 / 2.0;
}

int main() {
    // Example input: list of points as described in the problem
    vector<vector<int>> points = {{0,0}, {0,1}, {1,0}, {0,2}, {2,0}};
    
    // Call the function and display the result
    double result = largestTriangleArea(points);
    cout << "Largest Triangle Area: " << result << endl;
    return 0;
}
