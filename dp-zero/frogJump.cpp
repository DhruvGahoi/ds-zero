class Solution {
  public:
    // ---------- Recursive with memoization -------------
    // int solve(vector<int>& height, int i, vector<int>& dp){
    //     if(i == 0) return 0;
    //     if(dp[i] != -1) return dp[i];
        
    //     int left = solve(height, i - 1, dp) + abs(height[i] - height[i - 1]);
    //     int right = INT_MAX;
    //     if(i > 1) right = solve(height, i - 2, dp) + abs(height[i] - height[i - 2]);
        
    //     return dp[i] = min(left, right);
    // }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        // vector<int> dp(n + 1, -1);
        // return solve(height, n - 1, dp);
        
        // ------- Tabulation ---------
        // vector<int> dp(n, 0);
        // dp[0] = 0;
        // for(int i = 1; i < n; i++){
        //     int fs = dp[i - 1] + abs(height[i] - height[i - 1]);
        //     int ss = INT_MAX;
        //     if(i > 1) ss = dp[i - 2] + abs(height[i] - height[i - 2]);
        //     dp[i] = min(fs, ss);
        // }
        // return dp[n -1];
        
        // ---------- Space Optimization ---------------
        int prev = 0;
        int prev2 = 0;
        for(int i = 1; i < n; i++){
            int fs = prev + abs(height[i] - height[i - 1]);
            int ss = INT_MAX;
            if(i > 1) ss = prev2 + abs(height[i] - height[i - 2]);
            int curr = min(fs, ss);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
