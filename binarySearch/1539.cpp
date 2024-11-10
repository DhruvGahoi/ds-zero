// Approach - 1        O(n)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k)
                k++;
        }
        return k;
    }
};

// Approach - 2        O(n)
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int num = 1;
        int i = 0;
        while(i < n && k > 0){
            if(num == nums[i]){
                i++;
            } else {
                k--;
            }
            num++;
        }
        while(k--){
            num++;
        }
        return num - 1;
    }
};

// Approach - 3       O(log n)
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int mid = -1;
        while(left <= right){
            mid = left + (right - left) / 2;
            int missingTillMid = nums[mid] - (mid + 1);
            if(missingTillMid < k){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left + k;
    }
};