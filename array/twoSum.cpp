// ------------------------LeetCode-1---------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int a = nums[i];
            int rem = target - a;
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem], i};
            }
            mpp[a] = i;
        }
        return{-1, -1};
    }
};






// ------------------------LeetCode-167---------------------------
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;
        while(i < j){
            if(numbers[i] + numbers[j] == target){
                return {i+1, j+1};
            }
            if(numbers[i] + numbers[j] > target){
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};