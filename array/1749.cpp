class Solution {
public:
    int n;
    int kadanesMax(vector<int>& nums){
        int currSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < n; i++){
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }

    int kadanesMin(vector<int>& nums){
        int currSum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < n; i++){
            currSum = min(nums[i], currSum + nums[i]);
            minSum = min(minSum, currSum);
        }

        return minSum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        n = nums.size();
        int maxSum = kadanesMax(nums);
        int minSum = kadanesMin(nums);

        return max(maxSum, abs(minSum));
    }
};
