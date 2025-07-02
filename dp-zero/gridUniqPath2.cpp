class Solution {
public:
    // ----------- MEMOIZATION ------------
    // int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
    //     if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0;
    //     if(i == 0 && j == 0) return 1;
    //     if(i < 0 || j < 0) return 0;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = solve(obstacleGrid, i - 1, j, dp);
    //     int left = solve(obstacleGrid, i, j - 1, dp);

    //     return dp[i][j] = up + left;
    // }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return solve(obstacleGrid, m - 1, n - 1, dp);


        // ------------- TABULATION ---------------
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){
        //         if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) dp[i][j] = 0;
        //         else if (i == 0 && j == 0) dp[i][j] = 1;
        //         else {
        //             int up = 0, left = 0;
        //             if(i > 0) up = dp[i - 1][j];
        //             if(j > 0) left = dp[i][j - 1];

        //             dp[i][j] = up + left;
        //         }
        //     }
        // }

        // return dp[m - 1][n - 1];

        // ----------- SPACE OPTIMIZATION ------------
        vector<int> prev(n, 0);
        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++){
                if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) temp[j] = 0;
                else if (i == 0 && j == 0) temp[j] = 1;
                else {
                    int up = 0, left = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = temp[j - 1];

                    temp[j] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n - 1];
    }
};
