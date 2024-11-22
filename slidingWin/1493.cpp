------------------------Leetcode----------------------------

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int count0 = 0;
        int count1 = 0;
        int maxCount = 0;

        while(j < n){
            if(nums[j] == 1){
                count1++;
            } else {
                count0++;
            }

            while(count0 > 1){
                if(nums[i] == 1){
                    count1--;
                } else {
                    count0--;
                }
                i++;
            }
            maxCount = max(maxCount, count1);
            j++;
        }
        return maxCount == nums.size() ? maxCount - 1 : maxCount;
    }
};