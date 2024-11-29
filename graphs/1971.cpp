class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adj;
        for(const auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        } 

        queue<int> que;
        unordered_set<int> vis;

        que.push(source);
        vis.insert(source);

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            if(curr == destination) return true;

            for(int nbr : adj[curr]){
                if(!vis.count(nbr)){
                    vis.insert(nbr);
                    que.push(nbr);
                }
            }
        }

        return false;
    }
};