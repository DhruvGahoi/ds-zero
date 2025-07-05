class Solution {
public:
    int solve(int n, int i, int prevInd, vector<vector<int>>& dp, vector<int>& nums){
        if(i == n) return 0;
        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];
        
        int notTake = 0 + solve(n, i + 1, prevInd, dp, nums);
        int take = 0;
        if(prevInd == -1 || nums[i] > nums[prevInd]){
            take = 1 + solve(n, i + 1, i, dp, nums);
        }

        return dp[i][prevInd + 1] = max(notTake, take);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(n, 0, -1, dp, nums);
    }
};
