#include <iostream>
#include <vector>
#include<queue>
#include<map>
using namespace std;

// Definition for a binary tree Node
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Global index for preorder build
static int idx = -1;

// Build binary tree using preorder input (-1 as NULL marker)
Node* buildTree(const vector<int>& preorder) {
    idx++;
    if (idx >= preorder.size() || preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
void topview(Node* root ){
    queue<pair<Node*,int>> q;
    map<int,int>m;
    q.push({root,0});
    while(q.size()>0){
        Node* curr=q.front().first;
        int currhd=q.front().second;
        q.pop();
        if(m.find(currhd)==m.end())
            m[currhd]=curr->val;
        if(curr->left!=NULL)
            q.push({curr->left,currhd-1});
        if(curr->right!=NULL)
            q.push({curr->right,currhd+1});
    }

    for(auto it:m){
        cout<<it.second<<" ";
    }
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    topview(root);

    return 0;
}
