class Solution {
public:
    // ----------- MEMOIZATION -------------
    // int solve(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == n  - 1) return triangle[i][j];

    //     int down = solve(triangle, i + 1, j, n, dp);
    //     int diagonal = solve(triangle, i + 1, j + 1, n, dp);

    //     return dp[i][j] = min(down, diagonal) + triangle[i][j];
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve(triangle, 0, 0, n, dp);

        // ------------- TABULATION --------------
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        // for(int j = 0; j < n; j++){
        //     dp[n - 1][j] = triangle[n - 1][j];
        // }
        // for(int i = n - 2; i >= 0; i--){
        //     for(int j = i; j >= 0; j--){
        //         int down = triangle[i][j] + dp[i + 1][j];
        //         int diagonal = triangle[i][j] + dp[i + 1][j + 1];
        //         dp[i][j] = min(down, diagonal);
        //     }
        // }

        // return dp[0][0];

        // -------------- SPACE OPTIMIZATION ----------------
        vector<int> front(n, 0), curr(n, 0);
        for(int j = 0; j < n; j++){
            front[j] = triangle[n - 1][j];
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + front[j];
                int diagonal = triangle[i][j] + front[j + 1];
                curr[j] = min(down, diagonal);
            }
            front = curr;
        }
        return front[0];
    }
};
