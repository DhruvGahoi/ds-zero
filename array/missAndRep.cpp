vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        // S - Sn => x - y
        // S^2 - S^2n
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
        long long S = 0, S2 = 0;
        for(int i = 0; i < n; i++){
            S += arr[i];
            S2 += (long long)arr[i] * (long long)arr[i]; 
        }
        long long val1 = S - SN;
        long long val2 = S2 - S2N;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
        
    }


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int xr = 0;
        for(int i = 0; i < n; i++){
            xr ^= arr[i];
            xr ^= (i + 1); // value = 4
        }
        
        // Finding the bitNumber
        int bitNo = 0;
        while(1){
            if((xr & (1 << bitNo)) != 0){
                break;
            }
            bitNo++;
        }
        
        // Segregating number on behalf of bit
        int zero = 0;
        int one = 0;
        for(int i = 0; i < n; i++){
            // Part of 1 club
            if((arr[i] & (1 << bitNo)) != 0){
                one ^= arr[i];
            } 
            // Part of zero club
            else {
                zero ^= arr[i];
            }
        }
        
        for(int i = 1; i <= n; i++){
            if((i & (1 << bitNo)) != 0){
                one ^= i;
            } else {
                zero ^= i;
            }
        }
        // Identifing the missing and repeating number
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == zero) {
                cnt++;
            }
        }
        
        if(cnt == 2) return {zero, one};
        return {one, zero};
    }
};
