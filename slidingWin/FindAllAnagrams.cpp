-----------------------------Leetcode #438----------------------------

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> count(26, 0);
        for(char &ch : p) {
            count[ch - 'a']++;
        }

        int n = s.length();
        int k = p.length();
        
        int i = 0; 
        int j = 0; 
        vector<int> result;

        while(j < n) {
            count[s[j] - 'a']--;
            if(j - i + 1 == k) {
                if(count == vector<int>(26, 0)) {
                    result.push_back(i);
                }
                count[s[i] - 'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};