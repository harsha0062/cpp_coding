#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Depth-First Search to detect cycle in the prerequisite graph
bool dfs(int crs, set<int> &vis, map<int, vector<int>> &preMap) {
    // If the course is already in the current recursion path, cycle detected
    if (vis.find(crs) != vis.end())
        return false;
    // If there are no prerequisites, course can be completed
    if (preMap[crs].empty())
        return true;
    // Add course to the recursion path
    vis.insert(crs);
    // DFS for all prerequisites
    for (int pre : preMap[crs])
        if (!dfs(pre, vis, preMap))
            return false;
    // Backtrack: remove from path, mark as completed
    vis.erase(crs);
    preMap[crs] = {};
    return true;
}

// Determines if all courses can be completed
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    map<int, vector<int>> preMap;
    // Initialize mapping for each course
    for (int i = 0; i < n; i++)
        preMap[i] = {};
    // Build the graph from prerequisites
    for (auto& pair : prerequisites) {
        int crs = pair[0];
        int pre = pair[1];
        preMap[crs].push_back(pre);
    }
    set<int> vis;
    // Check each course for possible cycles
    for (int crs = 0; crs < n; crs++) {
        if (!dfs(crs, vis, preMap))
            return false;
    }
    return true;
}

int main() {
    // Example input: number of courses and prerequisites pairs
    int numCourses = 2;
    vector<vector<int>> prerequisites = { {1, 0} };

    // Call canFinish and print result
    if (canFinish(numCourses, prerequisites))
        cout << "All courses can be finished (no cycle)." << endl;
    else
        cout << "It is not possible to finish all courses (cycle detected)." << endl;
    return 0;
}
