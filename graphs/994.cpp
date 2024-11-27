// Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                } else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int timeElapsed = 0;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int row = curr.first.first;
            int col = curr.first.second;
            int time = curr.second;

            for(auto dir : directions){
                int nRow = row + dir.first;
                int nCol = col + dir.second;

                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && grid[nRow][nCol] == 1){
                    grid[nRow][nCol] = 2; // Rot the orange
                    fresh--; // Decrement fresh orange count
                    q.push({{nRow, nCol}, time + 1}); // Add to queue with incremented time
                    timeElapsed = max(timeElapsed, time + 1);
                } 
            }
        }
        return fresh == 0 ? timeElapsed : -1;
    }
};