// Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while(left < right){ // from the below condn r = mid, if we do equal here, we will stuck in an infinite loop, where right = mid, and we calculate mid everytime and it will be equal
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid; // why not mid - 1 ? Because it might be a case where left is at the index which is the min valaue, and if we do mid - 1 for right, it will skip the left and then right > left
                // [3 4 5 1 2]
                //        l r, now if we do r = mid - 1 it will skip the 1 and goes to 5 and then l > r
            }
        }
        return nums[right];
    }
};