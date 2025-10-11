#include <iostream>
#include <vector>
using namespace std;

/*
Definition for a QuadTree node.
*/
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    // Default constructor
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    // Constructor for leaf or value node
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    // Constructor with all children
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

// Recursive function to construct QuadTree from grid section
Node* constructQuad(vector<vector<int>>& grid, int rowstart, int rowend, int colstart, int colend) {
    if (rowstart > rowend || colstart > colend)
        return NULL;

    bool isleaf = true;
    int val = grid[rowstart][colstart];

    // Check if all cells in this section have the same value
    for (int i = rowstart; i <= rowend; i++) {
        for (int j = colstart; j <= colend; j++) {
            if (grid[i][j] != val) {
                isleaf = false;
                break;
            }
        }
        if (!isleaf)
            break;
    }

    // If all same, return leaf node
    if (isleaf)
        return new Node(val, true);

    // Otherwise, split grid into four quadrants and recurse
    int rowmid = (rowstart + rowend) / 2;
    int colmid = (colstart + colend) / 2;
    Node* topleft = constructQuad(grid, rowstart, rowmid, colstart, colmid);
    Node* topright = constructQuad(grid, rowstart, rowmid, colmid + 1, colend);
    Node* bottomleft = constructQuad(grid, rowmid + 1, rowend, colstart, colmid);
    Node* bottomright = constructQuad(grid, rowmid + 1, rowend, colmid + 1, colend);

    return new Node(false, false, topleft, topright, bottomleft, bottomright);
}

// Helper driver function to start the construction for entire grid
Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    return constructQuad(grid, 0, n - 1, 0, n - 1);
}

// Helper function to print tree structure for demo purposes
void printQuadTree(Node* node, int depth = 0) {
    if (!node) return;
    for (int i = 0; i < depth; i++) cout << "  ";
    if (node->isLeaf) {
        cout << "Leaf(val=" << node->val << ")" << endl;
    } else {
        cout << "Node" << endl;
        printQuadTree(node->topLeft, depth + 1);
        printQuadTree(node->topRight, depth + 1);
        printQuadTree(node->bottomLeft, depth + 1);
        printQuadTree(node->bottomRight, depth + 1);
    }
}

// Main function with sample input
int main() {
    // Example input for grid
    vector<vector<int>> grid = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    // Construct the quad tree
    Node* root = construct(grid);

    // Print the tree structure (for demo)
    printQuadTree(root);

    return 0;
}
