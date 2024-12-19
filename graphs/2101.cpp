class Solution {
public:
    typedef long long LL;
    void DFS(int node, unordered_set<int>& vis, unordered_map<int, vector<int>>& adj){
        vis.insert(node);
        for(auto& nbr : adj[node]){
            if(vis.find(nbr) == vis.end()) { // Not visited
                DFS(nbr, vis, adj);
            }
        }
    };

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> adj;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;

                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];

                LL distance = ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
                if(LL(r1 * r1) >= distance){
                    adj[i].push_back(j);
                }
            }
        }

        int result = 0;
        unordered_set<int> vis;
        for(int i = 0; i < n; i++){
            DFS(i, vis, adj);
            int count = vis.size();
            result = max(result, count);
            vis.clear();
        }
        return result;
    }
};