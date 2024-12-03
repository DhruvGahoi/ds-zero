class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid){
        int row = grid.size();
        int col = grid[0].size();
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int u = curr.first;
            int v = curr.second;

            if (grid[u][v] != 1) continue;
            grid[u][v] = -1;

            for(auto& dir : directions){
                int nRow = u + dir.first;
                int nCol = v + dir.second;

                if(nRow >= 0 && nCol >= 0 && nRow < row && nCol < col && grid[nRow][nCol] == 1){
                    q.push({nRow, nCol});
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if((i == 0 || j == 0 || i == row - 1 || j == col - 1) && grid[i][j] == 1){
                    bfs(i, j, grid);
                }
            }
        }

        int finalCount = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    finalCount++;
                }
            }
        }

        return finalCount;
    }
};