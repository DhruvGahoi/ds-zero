class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n ,0);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            inDegree[v]++; 
        }

        vector<int> zeroDegreeNodes;
        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0){
                zeroDegreeNodes.push_back(i);
            }
        }

        if(zeroDegreeNodes.size() == 1){
            return zeroDegreeNodes[0];
        } else {
            return -1;
        }
    }
};