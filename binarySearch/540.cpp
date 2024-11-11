// Single Element in a Sorted Array

// O(n)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xor_Value = 0;
        
        for(int &num : nums) {
            xor_Value ^= num;
        }
        
        return xor_Value;
    }
};

