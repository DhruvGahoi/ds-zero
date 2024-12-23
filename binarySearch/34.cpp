// Find First & Last Position Of Element In Sorted Array

class Solution {
public:
    int findLeftMost(vector<int>& nums, int target, int n){
        int left = 0;
        int right = n - 1;
        int left_most = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left_most = mid; // possible answer
                right = mid - 1; 
            } else if(nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left_most;
    }

    int findRightMost(vector<int>& nums, int target, int n){
        int left = 0;
        int right = n - 1;
        int right_most = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right_most = mid;
                left = mid + 1; 
            } else if(nums[mid] > target){
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }

        return right_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findLeftMost(nums, target, n);
        int right_most = findRightMost(nums, target, n);

        return {left_most, right_most};
    }
};