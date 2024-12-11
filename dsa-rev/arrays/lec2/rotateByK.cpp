#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int>& arr, int n, int d){
    d = d % n;
    int temp[d];

    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }

    for(int i = d; i < n; i++){
        arr[i - d] = arr[i];
    }

    for(int i = n - d; i < n; i++){
        arr[i] = temp[i - (n - d)];
    }
}

int main(){
    int n ,d;
    cin >> n >> d;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    leftRotate(arr, n, d);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


// LC - 189
// Link - https://leetcode.com/problems/rotate-array

class Solution {
    public:

        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            k %= n;

            reverseVector(nums, 0, n - 1);
            reverseVector(nums, 0, k - 1);
            reverseVector(nums, k, n - 1);
        }
        void reverseVector(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }

    }

};