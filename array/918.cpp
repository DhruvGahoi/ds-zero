class Solution {
public:
    int kadanesMax(vector<int>& nums, int n){
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < n; i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int>& nums, int n){
        int currSum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < n; i++){
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
    
        int maxSum = kadanesMax(nums, n);
        int minSum = kadanesMin(nums, n);

        int circSum = sum - minSum;

        if(maxSum > 0){
            return max(maxSum, circSum);
        }

        return maxSum;
    }
};
