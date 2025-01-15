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

// -2 -1 0 1 2 This will be the order of vertical tarversal

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // will store the (vertical, level, multiNodes in that level)
        map<int, map<int, multiset<int>>> nodes;
        // Queue(node, verticalLine, level)
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while(!todo.empty()){
            // Takes the front queue
            auto p = todo.front();
            todo.pop();
            // Node
            TreeNode* node = p.first;
            // Vertical Line of that node
            int x = p.second.first;
            // Horizontal Level of that node
            int y = p.second.second;
            nodes[x][y].insert(node -> val);

            if(node -> left){
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if(node -> right){
                todo.push({node -> right, {x + 1, y + 1}});
            }
        } 
        // List stores the all nodes -> result
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
