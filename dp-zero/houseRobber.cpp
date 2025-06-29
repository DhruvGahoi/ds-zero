class Solution {
public:
    // -------- Recursive with memoization ----------
    // int solve(vector<int>& nums, int i, vector<int>& dp){
    //     if(i == 0) return nums[0];
    //     if(i < 0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int pick = nums[i] + solve(nums, i - 2, dp);
    //     int notPick = 0 + solve(nums, i - 1, dp);
    //     return dp[i] = max(pick, notPick);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // ----------------------
        // vector<int> dp(n + 1, -1);
        // return solve(nums, n - 1, dp);

        // ----------- Tabulation -------------
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // for(int i = 1; i < n; i++){
        //     int take = nums[i];
        //     if(i > 1) take += dp[i - 2];
        //     int notTake = 0 + dp[i - 1];
        //     dp[i] = max(take, notTake);
        // }
        // return dp[n - 1];

        // ----------- Space Optimazation ------------
        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int take = nums[i] + prev2;
            int notTake = 0 + prev;
            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
