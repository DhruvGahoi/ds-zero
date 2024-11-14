// Search in Rotated Sorted Array - II

class Solution {
public:
    int findPivot(vector<int>& nums, int n){
        int left = 0;
        int right = n - 1;
        // Checking the Duplicates
        while(left < right){
            while(left < right && nums[left] == nums[left + 1]){
                left++;
            }
            while(left < right && nums[right] == nums[right - 1]){
                right--;
            } 

            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

    bool BS(int left, int right, vector<int>& nums, int target){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return true;
            } else if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return false;
        
        int pivot = findPivot(nums, n);
        if (BS(0, pivot - 1, nums, target)) return true;
        return BS(pivot, n - 1, nums, target);
    }
};