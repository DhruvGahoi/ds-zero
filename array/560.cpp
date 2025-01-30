class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        mp[0] = 1;
        int preSum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            preSum += nums[i];
            int rem = preSum - k;
            cnt += mp[rem];
            mp[preSum] += 1;
        }

        return cnt;
    }
};
