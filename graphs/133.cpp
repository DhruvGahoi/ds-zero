/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;

    void DFS(Node* node, Node* cloned_node){
        for(Node *n : node->neighbors){
            if(mp.find(n) == mp.end()){
                Node* clone = new Node(n -> val);
                mp[n] = clone;
                cloned_node -> neighbors.push_back(clone);

                DFS(n, clone);
            } else {
                cloned_node -> neighbors.push_back(mp[n]);

            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        mp.clear();

        // cloned the given node
        Node *cloned_node = new Node(node -> val);
        // Now clone its neigbours and recursively its newbhours
        // But if a node reappears, then we need to access that cloned node
        // So store them in a map <Node*, Node*>
        mp[node] = cloned_node;

        DFS(node, cloned_node);

        return cloned_node;
    }
};