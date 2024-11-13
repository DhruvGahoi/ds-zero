// Search in rotated sorted array

class Solution {
public:
    int findPivot(vector<int>& nums, int n){
        int left = 0;
        int right = n - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return right;
    }

    int BS(int left, int right, vector<int>& nums, int target){
        int idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                idx = mid;
                break;
            } else if(nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return idx;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int pivot = findPivot(nums, n);
        int idx = BS(0, pivot - 1, nums, target);
        if(idx != -1) return idx;
        idx = BS(pivot, n - 1, nums, target);
        return idx;
    }
};