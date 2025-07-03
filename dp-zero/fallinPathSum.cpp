class Solution {
public:
    // int solve(vector<vector<int>>& matrix, int i, int j, int m, vector<vector<int>>& dp){
    //     if(j < 0 || j >= m) return INT_MAX;
    //     if(i == 0) return matrix[0][j];
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = solve(matrix, i - 1, j, m, dp);
    //     int leftDiagonal = solve(matrix, i - 1, j - 1, m, dp);
    //     int rightDiagonal = solve(matrix, i - 1, j + 1, m, dp);

    //     if (up != INT_MAX) up += matrix[i][j]; else up = INT_MAX;
    //     if (leftDiagonal != INT_MAX) leftDiagonal += matrix[i][j]; else leftDiagonal = INT_MAX;
    //     if (rightDiagonal != INT_MAX) rightDiagonal += matrix[i][j]; else rightDiagonal = INT_MAX;

    //     return dp[i][j] = min({up, leftDiagonal, rightDiagonal});
    // }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // int mini = INT_MAX;
        // for(int j = 0; j < m; j++){
        //     int ans = solve(matrix, n - 1, j, m, dp);
        //     mini = min(mini, ans);
        // }
        // return mini;

        // ---------- TABULATION -------------
        // vector<vector<int>> dp(n, vector<int>(m, 0));
        // for (int j = 0; j < m; j++) {
        //     dp[0][j] = matrix[0][j];
        // }

        // for (int i = 1; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         int up = dp[i - 1][j];
        //         int leftDiagonal = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;
        //         int rightDiagonal = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MAX;

        //         dp[i][j] = matrix[i][j] + min({up, leftDiagonal, rightDiagonal});
        //     }
        // }

        // int mini = INT_MAX;
        // for (int j = 0; j < m; j++) {
        //     mini = min(mini, dp[n - 1][j]);
        // }

        // return mini;

        // ------------ SPACE OPTIMIZATION -----------------
        vector<int> prev(m, 0), cur(m, 0);

        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += prev[j - 1];
                } else {
                    leftDiagonal += 1e9;
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += prev[j + 1];
                } else {
                    rightDiagonal += 1e9;
                }

                cur[j] = min({up, leftDiagonal, rightDiagonal});
            }

            prev = cur;
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, prev[j]);
        }

        return mini;
    }
};

