class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int i, int j, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        while(!q.empty()){
            i = q.front().first;
            j = q.front().second;
            q.pop();

            for(auto dir : directions){
                int u = i + dir[0];
                int v = j + dir[1];

                if(u >= 0 && v >= 0 && u < m && v < n && grid[u][v] > 0){
                    q.push({u, v});
                    fishCount += grid[u][v];
                    grid[u][v] = 0;
                }
            }
        }

        return fishCount;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > 0){
                    maxFish = max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};
