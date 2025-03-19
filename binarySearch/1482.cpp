class Solution {
public:
    bool solve(vector<int>& bloomDay, int mid, int m, int k){
        int cnt = 0;
        int bouquet = 0;
        for(int x : bloomDay){
            if(x <= mid){
                cnt++;
            } else {
                bouquet += (cnt / k);
                cnt = 0;
            }
        }
        bouquet += (cnt / k);
        return bouquet >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1ll * m * k;
        if(val > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while(low < high){
            int mid = low + (high - low) / 2;
            if(solve(bloomDay, mid, m, k)){
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
