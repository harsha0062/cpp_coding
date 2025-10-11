#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Function to find average of nodes on each level
vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> levelQueue;
    levelQueue.push(root);
    levelQueue.push(NULL); // NULL marks the end of a level

    vector<double> ans;

    while (levelQueue.front() != NULL) { // While there is a valid level left
        double sum = 0;
        int nodes = 0;

        // Process all nodes on the current level
        while (levelQueue.front() != NULL) {
            TreeNode* node = levelQueue.front();
            levelQueue.pop();
            sum += node->val;
            nodes++;

            // Add children to queue for next level
            if (node->left != NULL)
                levelQueue.push(node->left);
            if (node->right != NULL)
                levelQueue.push(node->right);
        }
        levelQueue.push(levelQueue.front()); // push NULL again to mark next level
        levelQueue.pop(); // remove the previous NULL
        ans.push_back(sum / nodes); // average for current level
    }
    return ans;
}

int main() {
    // Example input tree:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Get average of each level
    vector<double> averages = averageOfLevels(root);

    // Print averages
    cout << "Average of each level: ";
    for (double avg : averages)
        cout << avg << " ";
    cout << endl;

    return 0;
}
