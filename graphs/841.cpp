class Solution {
public:

    void dfs(vector<vector<int>>& rooms, int source, vector<bool>& vis){
        vis[source] = true;
        for(int &node : rooms[source]){
            if(!vis[node]){
                dfs(rooms, node, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> vis(n, false);
        dfs(rooms, 0, vis);

        for(bool x : vis){
            if(x == false) return false;
        }
        return true;
    }
};