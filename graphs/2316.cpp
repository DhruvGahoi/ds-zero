class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>&adj, vector<int>& vis, long long&sizeOfComponent) {
        vis[u] = 1;
        sizeOfComponent++;
        for(int &v : adj[u]) {
            if(!vis[v]) {
                dfs(v, adj, vis, sizeOfComponent);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto& vec : edges){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        long long remainingNodes = n;
        long long result = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                long long sizeOfComponent = 0;
                dfs(i, adj, vis, sizeOfComponent);
                result += (sizeOfComponent) * (remainingNodes - sizeOfComponent);
                remainingNodes -= sizeOfComponent;
            }
        }

        return result;
    }
};