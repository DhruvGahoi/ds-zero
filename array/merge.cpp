class Solution {
public:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2){
        if(nums1[idx1] > nums2[idx2]){
            swap(nums1[idx1], nums2[idx2]);
        }
    };

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = (m + n);
        int gap = (len / 2) + (len % 2);
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                // left is in left array and right is in right array
                if(left < n && right >= n){
                    swapIfGreater(nums1, nums2, left, right - n);
                }
                // left is in right array and right also in right array
                else if(left >= n){
                    swapIfGreater(nums1, nums2, left - n, right - n);
                } 
                // left and right are in left array
                else {
                    swapIfGreater(nums1, nums2, left, right);
                }
                //Dont forget this
                left++;
                right++;
            }
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
    }
};
