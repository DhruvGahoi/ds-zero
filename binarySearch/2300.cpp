class Solution {
public:
    int BS(int l, int r, vector<int>& potions, int target){
        // we have to find the index of first element greater than or equal to target (minPotion)

        int index = -1;
        int mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;

            if(potions[mid] >= target){
                index = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return index;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        sort(potions.begin(), potions.end());

        int maxPotion = potions[n-1];
        vector<int> answer;

        for(int i = 0; i < m; i++){
            int spell = spells[i];
            long long minPotion = ceil((1.0 * success) / spell);

            if(minPotion > maxPotion){
                answer.push_back(0);
                continue;
            }

            int index = BS(0, n - 1, potions, minPotion); 
            //lower_bound(begin(potions), end(potions), minPotion) - begin(potions);
            answer.push_back(n - index);
        }

        return answer;
    }
};