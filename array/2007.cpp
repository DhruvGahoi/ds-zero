class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n % 2 != 0) return {};

        sort(changed.begin(), changed.end());
        
        map<int, int> freq;

        for(int &num : changed){
            freq[num]++;
        }

        vector<int> result;

        for(int &num : changed){
            int twice = 2 * num;

            if(freq[num] == 0) continue;
            if(freq.find(twice) == freq.end() || freq[twice] == 0){
                return {};
            }

            result.push_back(num);

            freq[num]--;
            freq[twice]--;
        }

        return result;
    }
};
