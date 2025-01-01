#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> bottomView(TreeNode<int> *root) {
    vector<int> ans;
    if (!root)
        return ans;

    // Map to store the last node's value for each horizontal distance
    map<int, int> mpp;

    // Queue for BFS, stores pairs of TreeNode and its horizontal distance
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode<int> *node = it.first;
        int line = it.second;

        // Update the map for the horizontal distance with the current node's value
        mpp[line] = node->data;

        // Push the left child with horizontal distance - 1
        if (node->left)
            q.push({node->left, line - 1});

        // Push the right child with horizontal distance + 1
        if (node->right)
            q.push({node->right, line + 1});
    }

    // Collecting the bottom view from the map in order of horizontal distances
    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}


