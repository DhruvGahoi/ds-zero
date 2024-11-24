
----------------------LeetCode--------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        int maxCount = 0;
        unordered_map<char, int> charCount;

        while(j < n){
            charCount[s[j]]++;

            while(charCount[s[j]] > 1){
                charCount[s[i]]--;
                i++;
            }

            maxCount = max(maxCount, j - i + 1);
            j++;
        }
        return maxCount;
    }
};