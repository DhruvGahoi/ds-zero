class Solution {
public:
    // Function to check if a binary tree is symmetric
    bool isSymmetric(TreeNode* root) {
        // A tree is symmetric if:
        // 1. The root is NULL, or
        // 2. The left and right subtrees are mirror images of each other
        return root == nullptr || isSymmetricHelp(root->left, root->right);
    }

    // Helper function to check if two subtrees are mirror images
    bool isSymmetricHelp(TreeNode* left, TreeNode* right) {
        // If either subtree is NULL, they are symmetric only if both are NULL
        if (left == nullptr || right == nullptr) 
            return left == right;

        // If the values of the nodes don't match, the tree is not symmetric
        if (left->val != right->val) 
            return false;

        // Recursively check:
        // 1. The left child of the left subtree with the right child of the right subtree
        // 2. The right child of the left subtree with the left child of the right subtree
        return isSymmetricHelp(left->left, right->right) &&
               isSymmetricHelp(left->right, right->left);
    }
};

