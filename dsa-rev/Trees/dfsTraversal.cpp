#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

// Recursice Approach
class Solution{
  public:
	void inOrderT(struct Node* root, vector<int>& inorder){
		if(root == NULL) return;
		inOrderT(root -> left, inorder);
		inorder.push_back(root -> data);
		inOrderT(root -> right, inorder);
	}

	void preOrderT(struct Node* root, vector<int>& preorder){
		if(root == NULL) return;
		preorder.push_back(root -> data);
		preOrderT(root -> left, preorder);
		preOrderT(root -> right, preorder);
	}

	void postOrderT(struct Node* root, vector<int>& postorder){
		if(root == NULL) return;
		postOrderT(node -> left, postorder);
		postOrderT(node -> right, postorder);
		postorder.push_back(root -> data);
	}

	vector<vector<int>>& dfs(struct Node* root){
		vector<vector<int>> res;
		vector<int> inorder;
		vector<int> preorder;
		vector<int> postorder;

		inOrderT(root, inorder);
		preOrderT(root, preorder);
		postOrderT(root, postorder);

		ans.push_back(preorder);
		ans.push_back(inorder);
		ans.push_back(postorder);
	}
};

// Any recursive approach can be converted into iterative by using STACK

// Iterative Approach

class Solution{
  public:
	vector<int> preOrder(struct Node* root){
		vector<int> ans;
		if(root == NULL) return ans;
		stack<Node*> st;
		st.push(root);

		// preorder is root -> left -> right but while using stack we need to first push right and thenn ledt because then only left would be at the top and woulf be considered before right node
		while(!st.empty()){
			auto it = st.top();
			st.pop();

			ans.push_back(it -> data);
			if(it -> right){
				st.push(it -> right)
			}
			if(it -> left){
				st.push(it -> left);
			}
		}

		return ans;

	}

	vector<int> postOrder(struct Node* root){
		vector<int> ans;
		if(!root) return ans;
		stack<Node*> st;
		Node* curr = root;

		while(curr || !st.empty()){
			if(curr){
				st.push(curr);
				curr = curr -> left;
			} else {
				Node* temp = st.top() -> right;

				if(temp){
					curr = temp;
				} else {
					temp = st.top();
					ans.push_back(temp -> data);
					st.pop();
					while(!st.empty() && temp == st.top() -> right){
						temp = st.top();
						st.pop();
						ans.push_back(temp -> data);
					}
				}
			}
		}

		return ans;
	}
};

// Iterative inorder traversal
//
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(NULL), right(NULL) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
  public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> ans;
		TreeNode* curr = root;
		stack<TreeNode*> st;
		while(curr || !st.empty()){
			if(curr){
				st.push(curr);
				curr = curr -> left;
			} else {
				TreeNode* temp = st.top();
				st.pop();
				ans.push_back(temp -> val);
				curr = temp -> right;
			}
		}

		return ans;
	}
}
