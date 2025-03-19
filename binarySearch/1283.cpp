class Solution {
public:
    int solve(vector<int>& nums, int mid){
        int sum = 0;
        for(int& x : nums){
            sum += ceil((double)x/ (double)mid);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low < high){
            int mid = low + (high - low) / 2;
            if(solve(nums, mid) <= threshold){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
