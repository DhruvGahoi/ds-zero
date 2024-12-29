class Solution{
  public:
    bool isBalanced(TreeNode* root){
        return dfsHeight(root) != -1;
    }
    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;
        int leftHeight = defHeight(root -> left);
        if(leftHeight == -1) return -1;
        int rightHeight = dfsHeight(root -> right);
        if(rightHeight == -1) return -1;
        
        if(abs(leftHeeight - rightHeight) > 1) return -1;
        return max(leftHeight, rigthHeight) + 1; 
    }
}
