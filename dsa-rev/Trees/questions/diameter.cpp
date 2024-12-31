class Solution {
  public: 
      int diameterOfBinaryTree(TreeNode* root){
          int diameter = 0;
          height(root, diameter);
          return diameter;
      }

      int height(TreeNode* node, int& diameter){
          if(!node) return 0;
          int lh = height(node -> left);
          int rh = height(node -> right);
          diameter = max(diameter, lh + rh);
          return 1 + max(lh, rn);
      }
}
