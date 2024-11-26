// --------------------------DFS----------------------------

class Solution {
    private : 
        void dfs(int node, vector<vector<int>>& adj, int vis[], vector<int> &ls){
            vis[node] = 1;
            ls.push_back(node);

            for(auto it : adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, ls);
                }
            }
        }

    public : 
        vector<int> dfsOfGraph(vector<vector<int>>& adj){
            int n = adj.size();
            int vis[n] = {0};
            int start = 0;
            vector<int> ls;
            dfs(start, adj, vis, ls);
            return ls;
        }
}

// SC : O(n) + O(n) + O(n)
// TC : O(n) + O(2*E)