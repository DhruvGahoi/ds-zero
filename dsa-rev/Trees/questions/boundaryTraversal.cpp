// For the left node --> Simply exclude the leaf node and check for the left children of that node
// For the leaf node --> Simply do the inorder traversal
// For the right node --> Process the nodes into stack, and check for the right children of the node

// TC -> Left     -> O(H) (Height of tree)
//       Right    -> O(H)
//       Boundary -> O(N)

// SC -> O(N)

bool isLeaf(TreeNode<int>* node){
    return !node -> left && !node -> right;
}

void addLeftBoundary(TreeNode<int>* root, vector<int> &res) {
    TreeNode<int>* curr = root -> left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr -> data);
        if(curr -> left) curr = curr -> left;
        else curr = curr -> right;
    }
}

void addRightNode(TreeNode<int>* root, vector<int>& res){
    TreeNode<int>* curr = root -> right;
    vector<int> tmp;
    while(curr){
        if(!isLeaf(curr)) tmp.push_back(curr -> data);
        if(curr -> right) curr = curr -> right;
        else curr = curr -> left;
    }
    for(int i = tmp.size() - 1; i >= 0; i--){
        res.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode<int>* root, vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root -> data);
        return;
    }
    if(root -> left) addLeaves(root -> left, res);
    if(root -> right) addLeaves(root -> right, res);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root -> data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightNode(root, res);
    return res;
}

