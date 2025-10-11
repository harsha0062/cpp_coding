#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for an undirected graph node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Map to remember already-cloned nodes.
unordered_map<Node*, Node*> oldToNew;

/**
 * Recursively clones the graph using DFS.
 * Each node is cloned only once and stored in 'oldToNew' map.
 * @param node Pointer to the node to clone.
 * @return Pointer to the cloned node.
 */
Node* cloneGraph(Node* node) {
    // If node is NULL, return NULL
    if (node == NULL)
        return NULL;
    // If node already cloned, return its clone
    if (oldToNew.find(node) != oldToNew.end())
        return oldToNew[node];

    // Otherwise clone the node and recursively clone neighbors
    Node* copy = new Node(node->val);
    oldToNew[node] = copy;
    for (Node* nei : node->neighbors)
        copy->neighbors.push_back(cloneGraph(nei));
    return copy;
}

// Utility to print the graph
void printGraph(Node* node) {
    if (!node) return;
    unordered_map<Node*, bool> visited;
    vector<Node*> queue;
    queue.push_back(node);
    visited[node] = true;
    cout << "Graph nodes and their neighbors:\n";
    while (!queue.empty()) {
        Node* cur = queue.back();
        queue.pop_back();
        cout << "Node " << cur->val << ": ";
        for (Node* n : cur->neighbors) {
            cout << n->val << " ";
            if (!visited[n]) {
                queue.push_back(n);
                visited[n] = true;
            }
        }
        cout << endl;
    }
}

int main() {
    // Example: Creating a simple connected graph with 4 nodes
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    // Connect nodes (undirected edges)
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    cout << "Original graph:\n";
    printGraph(n1);

    // Clone the graph
    oldToNew.clear(); // Clear the map before cloning
    Node* cloned = cloneGraph(n1);

    cout << "\nCloned graph:\n";
    printGraph(cloned);

    // Clean up memory (best practice, for interview/contest context this is NOT strictly required)
    delete n1;
    delete n2;
    delete n3;
    delete n4;
    // The cloned nodes are not deleted here for simplicity.

    return 0;
}
