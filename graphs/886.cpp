class Solution {
public:
    bool bfs(int start, vector<vector<int>>& adj, vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (const auto& pair : dislikes) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) { // If the node is unvisited
                if (!bfs(i, adj, color)) {
                    return false; // If one component is not bipartite
                }
            }
        }
        return true;
    }
};