// LC - 1646
// Link - https://leetcode.com/problems/get-maximum-in-generated-array/description/

#include<bits/stdc++.h>
using namespace std;

int getMaximumGenerated(int n){
    if(n == 0)  return 0;
    vector<int>arr(n + 1); // Given in the question

    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i < n + 1; i++){
        if(i % 2 == 0){
            arr[i] = arr[i / 2];
        } else {
            arr[i] = arr[i / 2] + arr[i / 2 + 1];
        }
    }

    return *max_element(arr.begin(), arr.end());
}

int main(){
    int n;
    cin >> n;

    cout << getMaximumGenerated(n);
    return 0;
}

// Input: n = 7
// Output: 3
// Explanation: According to the given rules:
//   nums[0] = 0
//   nums[1] = 1
//   nums[(1 * 2) = 2] = nums[1] = 1
//   nums[(1 * 2) + 1 = 3] = nums[1] + nums[2] = 1 + 1 = 2
//   nums[(2 * 2) = 4] = nums[2] = 1
//   nums[(2 * 2) + 1 = 5] = nums[2] + nums[3] = 1 + 2 = 3
//   nums[(3 * 2) = 6] = nums[3] = 2
//   nums[(3 * 2) + 1 = 7] = nums[3] + nums[4] = 2 + 1 = 3
// Hence, nums = [0,1,1,2,1,3,2,3], and the maximum is max(0,1,1,2,1,3,2,3) = 3.