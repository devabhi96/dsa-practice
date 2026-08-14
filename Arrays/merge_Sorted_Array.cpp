/*
    LeetCode #88 - Merge Sorted Array

    Approach:
    First, copy all elements of nums2 into the empty positions at
    the end of nums1. Then, sort the entire nums1 array to obtain
    the final merged sorted array.

    Time Complexity: O((m + n) log(m + n))
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/merge-sorted-array/
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i =m; i<m+n; i++){
            nums1[i] = nums2[i-m];
        }   

        sort(nums1.begin(),nums1.end());
    }
};