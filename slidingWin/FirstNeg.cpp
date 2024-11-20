--------------------------First Negative in a Subarray-----------------------

class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        
        int n = arr.size();
        deque<int> deq;
        vector<int> result;
        int i = 0; 
        int j = 0;
        
        while(j < n) {
            if(arr[j] < 0){
                deq.push_back(arr[j]);
            }
            if(j-i+1 == k) {
                // Checked the window, if neg found then push if not then pushed 0.
                if(!deq.empty()) {
                    result.push_back(deq.front());
                } else {
                    result.push_back(0);
                }
                
                if(arr[i] < 0 && !deq.empty()) {
                    deq.pop_front();
                }
                i++;
            }
            j++;
        }
        return result;
        
    }
};

// Link : https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1