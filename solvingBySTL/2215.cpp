// Khoob saari learningsss
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        vector<int> v1;
        vector<int> v2;

        // Set difference --> The STL copies the elements from the sorted s1 that are not found in the sorted s2 to a container in sorted order.

        // back_inserter --> can be used to add element at the end of container.

        // Find the difference between s1 and s2 and put unique element of s1 into v1
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v1));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(v2));

        return {v1, v2};
    }
};