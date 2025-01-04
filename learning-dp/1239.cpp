class Solution {
public:
    bool hasDuplicate(string& s1, string& s2){
        int arr[26] = {0};

        for(char& ch : s1){
            if(arr[ch - 'a'] > 0){
                return true;
            }
            arr[ch - 'a']++;
        } 

        for(char& ch : s2){
            if(arr[ch - 'a'] > 0){
                return true;
            }
        }
        return false; //no duplicates found at all.
    }

    unordered_map<string, int> mp;

    int solve(int i, vector<string>& arr, string temp, int n){
        if(i >= n) return temp.length();

        if(mp.find(temp) != mp.end()) return mp[temp];

        int include = 0;
        int exclude = 0;
        if(hasDuplicate(arr[i], temp)){
            exclude = solve(i + 1, arr, temp, n);
        } else {
            exclude = solve(i + 1, arr, temp, n);
            temp += arr[i];
            include = solve(i + 1, arr, temp, n);
        }

        return mp[temp] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = ""; /// no concatenation
        mp.clear();
        int n = arr.size();
        return solve(0, arr, temp, n);
    }
};
