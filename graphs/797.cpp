class Solution {
public:
    void DFS(vector<vector<int>>& graph, int start, vector<int>& temp, vector<vector<int>>& result){
        temp.push_back(start);
        if(start == graph.size() - 1){
            result.push_back(temp);
        } else {
            for(auto x : graph[start]){
                DFS(graph, x, temp, result);
            }
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        for(int edge : graph[0]){
            vector<int> temp;
            temp.push_back(0);
            DFS(graph, edge, temp, result);
        }

        return result;
    }
};
