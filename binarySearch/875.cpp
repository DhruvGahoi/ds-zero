// Koko eating banana

class Solution {
public:
     bool canEat(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while(left < right){
            int mid = left + (right - left) / 2;
            if(canEat(piles, mid, h)){
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};