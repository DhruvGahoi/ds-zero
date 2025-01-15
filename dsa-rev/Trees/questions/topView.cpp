#include<bits/stdc++.h>

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    // Map to store the first node's value for each horizontal distance
    map<int, int> mp;

    // Queue to perform BFS, stores pairs of TreeNode and its horizontal distance
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line = it.second;

        // Insert into the map only if this horizontal distance is not already covered
        if (mp.find(line) == mp.end())
        {
            mp[line] = node->data;
        }

        // Push left child with horizontal distance - 1
        if (node->left != NULL)
        {
            q.push({node->left, line - 1});
        }

        // Push right child with horizontal distance + 1
        if (node->right != NULL)
        {
            q.push({node->right, line + 1});
        }
    }

    // Collecting the top view from the map in order of horizontal distances
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

