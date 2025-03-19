class Solution {
public:
    bool solve(vector<int>& weights, int mid, int days){
        int daysUsed = 1;
        int currWeight = 0;
        for(int& x : weights){
            if(currWeight + x > mid){
                daysUsed++;
                currWeight = 0;
            }
            currWeight += x;
            if(daysUsed > days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low < high){
            int mid = low + (high - low) / 2;
            if(solve(weights, mid, days)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
