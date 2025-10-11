#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// Depth-First Search helper function to find the product along a path
void dfs(string s, string d, map<string, vector<pair<string, double>>> &m, set<string> &v, double &ans, double temp) {
    // If node already visited, avoid cycles
    if (v.find(s) != v.end()) return;
    v.insert(s);

    // If source equals destination, store result
    if (s == d) {
        ans = temp;
        return;
    }
    // Explore all neighbours of the current node
    for (auto a : m[s]) {
        dfs(a.first, d, m, v, ans, temp * a.second);
    }
}

// Main function to calculate answers to all queries
vector<double> calcEquation(vector<vector<string>> &e, vector<double> &v, vector<vector<string>> &q) {
    map<string, vector<pair<string, double>>> m;

    // Build the graph. For a/b = 2.0, add edge a->b (2.0) and b->a (1/2.0)
    for (int i = 0; i < e.size(); i++) {
        m[e[i][0]].push_back({e[i][1], v[i]});
        m[e[i][1]].push_back({e[i][0], 1 / v[i]});
    }

    vector<double> res;
    // Answer each query using DFS
    for (int i = 0; i < q.size(); i++) {
        string s = q[i][0];
        string d = q[i][1];
        set<string> visited;
        double ans = -1.0;
        // Only start DFS if source node exists in graph
        if (m.find(s) != m.end())
            dfs(s, d, m, visited, ans, 1.0);
        res.push_back(ans);
    }
    return res;
}

int main() {
    // Example input: equations, values, and queries 
    vector<vector<string>> equations = { {"a", "b"}, {"b", "c"} };
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = { {"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"} };

    // Compute results
    vector<double> results = calcEquation(equations, values, queries);

    // Print output
    cout << "Results:\n";
    for (double res : results) {
        cout << res << endl;
    }
    return 0;
}
