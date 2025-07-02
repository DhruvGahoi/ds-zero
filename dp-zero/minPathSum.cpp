class Solution {
public:
    // ------- MEMOIZATION --------

    // int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
    //     if(i == 0 && j == 0) return grid[0][0];
    //     if(i < 0 || j < 0) return INT_MAX;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int up = solve(grid, i - 1, j, dp);
    //     int left = solve(grid, i, j - 1, dp);
    //     return dp[i][j] = grid[i][j] + min(up, left);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(grid, m - 1, n - 1, dp);

        // ----------- TABULATION ------------
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i == 0 && j == 0) dp[i][j] = grid[0][0];
        //         else{
        //             int up = INT_MAX, left = INT_MAX;
        //             if(i > 0) up = dp[i - 1][j];
        //             if(j > 0) left = dp[i][j - 1];

        //             dp[i][j] = grid[i][j] + min(up, left);
        //         }
        //     }
        // }

        // return dp[m - 1][n - 1];

        // ------------ SPACE OPTIMIZATION -------------
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) temp[j] = grid[0][0];
                else {
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = temp[j - 1];

                    temp[j] = min(up, left) + grid[i][j];
                }
            }
            prev = temp;
        }

        return prev[n - 1];
    }
};
