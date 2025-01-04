class Solution {
public:
    //Memoization
    int t[301][11]; 

    int solve(int n, int d, vector<int>& jd, int idx){
        // BASE CASE
        // If there is only 1 day left, then we have to do all the jobs
        if(d == 1){
            return *max_element(jd.begin() + idx, jd.end());
        }

        if(t[idx][d] != -1) return t[idx][d]; //this exists

        int maxD = 0;
        int finalResult = INT_MAX; // have to find min val
        // Try one by one with all possibility
        // Take index = {idx} job in first day
        // Take index = {idx, idx + 1} job in second day and so on...

        for(int i = idx; i <= n - d; i++){
            maxD = max(maxD, jd[i]);
            int result = maxD + solve(n, d - 1, jd, i + 1);
            finalResult = min(finalResult, result);
        }

        return t[idx][d] = finalResult; //if not then store it.

    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if(n < d) return -1;

        memset(t, -1, sizeof(t)); //cache

        return solve(n, d, jobDifficulty, 0);
    }
};
