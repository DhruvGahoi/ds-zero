class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return nums;

        int first = nums[0];
        int second = nums[0];
        int firstCount = 0;
        int secondCount = 0;;

        for(int i = 0; i < n; i++){
            if(first == nums[i]){
                firstCount++;
            } else if(second == nums[i]){
                secondCount++;
            } else if(firstCount == 0){
                first = nums[i];
                firstCount = 1;
            } else if(secondCount == 0){
                second = nums[i];
                secondCount = 1;
            } else {
                secondCount--;
                firstCount--;
            }
        }

        if(first == second) return {first};
        firstCount = 0;
        secondCount = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == first){
                firstCount++;
            } else if(nums[i] == second){
                secondCount++;
            }
        }

        vector<int> res;
        if(firstCount > floor(n / 3)) res.push_back(first);
        if(secondCount > floor(n / 3)) res.push_back(second);

        return res;
    }
};
