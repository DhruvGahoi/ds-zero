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
    // Helper function to check if a node is a leaf
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }

    // Recursive function to build paths for each root-to-leaf path
    void getPaths(TreeNode* root, string currentPath, vector<string>& result) {
        if (!root) return;

        // Append the current node value to the path
        currentPath += to_string(root->val);

        // If the current node is a leaf, add the path to the result
        if (isLeaf(root)) {
            result.push_back(currentPath);
            return;
        }

        // If not a leaf, add "->" and continue recursion for left and right children
        currentPath += "->";
        getPaths(root->left, currentPath, result);
        getPaths(root->right, currentPath, result);
    }

    // Main function to get all root-to-leaf paths
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result; // If tree is empty, return empty result

        getPaths(root, "", result);
        return result;
    }
};

