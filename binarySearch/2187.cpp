// Minimum time to complete trips

class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& time, ll givenTime, int totalTrips){
        ll actualTrips = 0;
        for(auto& t : time){
            actualTrips += givenTime / t;
        }

        return actualTrips >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        ll left = 1;
        ll right = (ll) *min_element(time.begin(), time.end()) * totalTrips;
        while(left < right){
            ll midTime = left + (right - left) / 2;
            if(possible(time, midTime, totalTrips)) {
                right = midTime;
            } else {
                left = midTime + 1;
            }
        }

        return left;
    }
};