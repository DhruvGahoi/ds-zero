// Similar to LC : 3258 but the hard one

// 620/627 --> TLE
// That was my approach
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        vector<long long> results;

        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int count0 = 0, count1 = 0;
            int i = l;
            long long result = 0;

            for (int j = l; j <= r; ++j) {
                if (s[j] == '0') count0++;
                else count1++;

                while (count0 > k && count1 > k) {
                    if (s[i] == '0') count0--;
                    else count1--;
                    i++;
                }
                result += (j - i + 1);
            }

            results.push_back(result);
        }

        return results;
    }
};

// Learning
