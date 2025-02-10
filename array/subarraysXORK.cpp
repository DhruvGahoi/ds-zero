class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        map<int, int> mp;
        mp[0] = 1;
        int xr = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
            cnt += mp[x];
            mp[xr]++;
        }
        
        return cnt;
    }
};
