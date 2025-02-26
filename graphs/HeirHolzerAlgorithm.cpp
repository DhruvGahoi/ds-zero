class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> eulerPath;
    
    void dfs(int node){
        while(!adj[node].empty()){
            int nextNode = adj[node].back();
            adj[node].pop_back();
            dfs(nextNode);
        }
        eulerPath.push_back(node);
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();

        unordered_map<int, int> inDegree;
        unordered_map<int, int> outDegree;

        for(auto& it : pairs){
            adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
            outDegree[it[0]]++;
        }

        int startNode = pairs[0][0];
        for(auto& it : adj){
            int node = it.first;
            if(outDegree[node] - inDegree[node] == 1){
                startNode = node;
                break;
            }
        }

        dfs(startNode);

        reverse(eulerPath.begin(), eulerPath.end());
        
        vector<vector<int>> res;
        for(int i = 0; i < eulerPath.size() - 1; i++){
            res.push_back({eulerPath[i], eulerPath[i + 1]});
        }
        
        return res;
    }
};
