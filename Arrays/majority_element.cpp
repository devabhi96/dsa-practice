/*
    LeetCode #169 - Majority Element

    Approach:
    Sorting

    First, sort the array. Since the majority element appears more
    than n/2 times, it must occupy the middle position after sorting.
    Therefore, we can directly return the middle element.

    Time Complexity: O(n log n)
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/majority-element/
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[(nums.size()-1)/2];
    }
};