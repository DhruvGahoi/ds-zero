// TLE -> 38/ 51

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0; 
        int j = 0;
        vector<int> result;
        while(j < n){
            if(j - i + 1 < k){
                j++;
            } else {
                int maxVal = *max_element(nums.begin() + i, nums.begin() + j + 1);
                result.push_back(maxVal);
                i++;
                j++;
            }
        }
        return result;
    }
};

--------------------------------------------------------------------------------------------------------------------------

// When new element comes nums[i], make space for it (window size cant be greater than k)
// Now, when nums[i] comes, no need to store small elements in that window. pop them
// Now push i in deque --> for nums[i]
// if(i >= k - 1) then deq.front is the answer for that window

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> deq;

        vector<int> result;

        for(int i = 0; i < n; i++){
            //Step - 1 window ka size greater than k nahi hona chahiye
            while(!deq.empty() && deq.front() <= i - k){
                deq.pop_front();
            }

            // Step - 2 
            while(!deq.empty() && nums[i] > nums[deq.back()]){ // For monotonic decreasing, if we make it increasing then we can find the sliding window minimum
                deq.pop_back();
            }

            // Step - 3
            deq.push_back(i);

            // Step - 4
            if(i >= k - 1){
                result.push_back(nums[deq.front()]);
            }
        }

        return result;
    }
};