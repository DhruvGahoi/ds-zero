bool poss(vector<int> &stalls, int mid, int k) {
    int cntCows = 1, last = stalls[0];
    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - last >= mid){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= k) return true;
    }

    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(poss(stalls, mid, k)){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return high;
}
