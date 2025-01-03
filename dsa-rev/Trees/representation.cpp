#include<bits/stdc++.h>
using namespace std;

class Node {
  public :
	int data;
	Node *left, *right;
	Node(int data){
		this -> data = data;
		this -> left = NULL;
		this -> right = NULL;
	}
};

Node* createTree(vector<int>& arr){
	Node* root = new Node(arr[0]);

	queue<Node*> q;
	q.push(root);
	int i = 1;
	int n = arr.size();
	while(!q.empty() && i < n){
		auto it = q.front();
		q.pop();
		it -> left = new Node(arr[i++]);
		q.push(it -> left);

		if(i < n){
			it -> right = new Node(arr[i++]);
			q.push(it -> right);
		}
	}
	return root;
}
