/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Function to compute the right side view of a binary tree
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res; // To store the result, which is the right side view
        recursion(root, 0, res); // Helper function to traverse the tree
        return res;
    }

    // Recursive function to perform a depth-first traversal
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (!root) 
            return; // Base case: If the node is null, return

        // If we are visiting this level for the first time, add the node's value to the result
        if (res.size() == level) 
            res.push_back(root->val);

        // Recursively traverse the right subtree first to prioritize the rightmost nodes
        recursion(root->right, level + 1, res);

        // Recursively traverse the left subtree after the right subtree
        recursion(root->left, level + 1, res);
    }
};

