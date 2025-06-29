#include <bits/stdc++.h> 

// int solve(vector<int>& nums, int i, vector<int>& dp){
//     if(i == 0) return nums[i];
//     if(i < 0) return 0;
//     if(dp[i] != -1) return dp[i];
//     int pick = nums[i] + solve(nums, i - 2, dp);
//     int notPick = 0 + solve(nums, i - 1, dp);
//     return dp[i] = max(pick, notPick);
// }

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    // ------ Recursive with memoization ------
    // vector<int> dp(n + 1, -1);
    // return solve(nums, n - 1, dp);

    // ------------ Tabulation -----------

    // vector<int> dp(n, 0);
    // dp[0] = nums[0];
    // int neg = 0;
    // for(int i = 1; i < n; i++){
    //     int take = nums[i];
    //     if(i > 1) take += dp[i - 2];
    //     int notTake = 0 + dp[i - 1];
    //     dp[i] = max(take, notTake);
    // }
    // return dp[n - 1];

    // ------------ Space Optimization ------------
    int prev = max(nums[0], nums[1]);
    int prev2 = nums[0];
    for(int i = 2; i < n; i++){
        int take = nums[i] + prev2;
        int notTake = 0 + prev;
        int curr = max(take, notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
