class Solution {
    private:
        void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&vis){
            vis[i][j] = 1;
            queue<pair<int,int>>q;
            q.push({i,j});

            int row=grid.size();
            int col=grid[0].size();

            int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};

            while(!q.empty()) {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();

                for(int k = 0; k < 4; k++) {
                int newrow=r+delrow[k];
                int newcol=c+delcol[k];

                if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1' && !vis[newrow][newcol]) {
                    vis[newrow][newcol]=1;
                    q.push({newrow,newcol});
                }
            }
            
        }
    }
    public:
        int numIslands(vector<vector<char>>& grid) {
            int n=grid.size();
            int m=grid[0].size();

            vector<vector<int>>vis(n,vector<int>(m,0));
            int count=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(!vis[i][j] && grid[i][j]=='1')
                    {
                        bfs(grid,i,j,vis);
                        count++;
                    }
                }
            }
            return count;
        }
};

-----------------------------------GFG--------------------------------------------

  private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delRow = -1; delRow <= 1; delRow++){
                for(int delCol = -1; delCol <= 1; delCol++){
                    int nRow = row + delRow;
                    int nCol = col + delCol;
                    if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m
                    && grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});
                    }
                }
            }
        }
    }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m ,0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        
        return cnt;
    }