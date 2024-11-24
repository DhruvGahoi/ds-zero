class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int currentCost = 0;
        int maxLen = 0;

        while(j < n){
            currentCost += abs(s[j] - t[j]);

            while(currentCost > maxCost){
                currentCost -= abs(s[i] - t[i]);
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        return maxLen;
    }
};