#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums){
    int n = nums.size();
    int i = 0;
    int currSum = 0;
    int maxSum = INT_MIN;
    while(i < n){
        if(currSum < 0) currSum = 0;
        currSum += nums[i];
        maxSum = max(maxSum, currSum);
        i++;
    }

    return maxSum;
}

int main(){

    vector<int>nums = {2, 3, -8, 7, -1, 2, 3};
    cout << solve(nums) << "\n";
    return 0;
}
