#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// global variable to track cycle
bool hasCycle = false;

// DFS to detect cycles and build course order
void dfs(int crs, set<int> &vis, set<int> &completed, map<int, vector<int>> &preMap, vector<int> &ans) {
    if (hasCycle) return; // return immediately if a cycle is found elsewhere

    // If already visiting this node, cycle detected
    if (vis.find(crs) != vis.end()) {
        hasCycle = true;
        return;
    }
    // If course is already completed (visited before), no need to visit again
    if (completed.find(crs) != completed.end()) {
        return;
    }
    // Mark this course as being visited in the current path
    vis.insert(crs);

    // Visit all prerequisites (neighbors)
    for (int pre : preMap[crs]) {
        dfs(pre, vis, completed, preMap, ans);
    }

    // Finished visiting all neighbors, remove from path
    vis.erase(crs);
    // Mark this course as completed so we don't revisit in future DFS calls
    completed.insert(crs);
    ans.push_back(crs); // After all prerequisites, add course to order
}

// Returns a valid order to take all courses or empty if not possible
vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
    map<int, vector<int>> preMap;
    // Initialize empty prerequisite lists
    for (int i = 0; i < n; i++)
        preMap[i] = {};
    // Build graph from prerequisites
    for (auto& pair : prerequisites) {
        int crs = pair[0];
        int pre = pair[1];
        preMap[crs].push_back(pre);
    }

    set<int> vis;
    set<int> completed;
    vector<int> ans;

    // Run DFS for each course
    for (int crs = 0; crs < n; crs++) {
        dfs(crs, vis, completed, preMap, ans);
        if (hasCycle) // If any cycle is found, return empty order
            return {};
    }
    return ans; // This is one possible valid order (reverse postorder DFS)
}

int main() {
    // Example input: 4 courses, with dependencies [1,0], [2,0], [3,1], [3,2]
    int numCourses = 4;
    vector<vector<int>> prerequisites = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };

    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty())
        cout << "No valid ordering possible (Cycle detected)." << endl;
    else {
        cout << "Valid ordering of courses:" << endl;
        for (int course : order)
            cout << course << " ";
        cout << endl;
    }
    return 0;
}
