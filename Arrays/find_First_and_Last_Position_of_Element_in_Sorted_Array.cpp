/*
    Question: Find First and Last Position of Element in Sorted Array
    Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
    Difficulty: Medium

    Approach:
    Two separate binary searches using a helper function findBound.
    First search finds the leftmost occurrence of target: whenever a
    match is found, store it and keep shrinking left (end = mid - 1)
    to check for an earlier occurrence. Second search finds the
    rightmost occurrence similarly, shrinking right (st = mid + 1).
    If target doesn't exist, both searches return -1.

    Time Complexity: O(log n)  — two independent binary searches
    Space Complexity: O(1)     — only a few pointer variables used
*/
class Solution {
public:
    int findBound(vector<int>& nums, int target, bool findFirst) {
        int st = 0, end = nums.size() - 1;
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (findFirst) {
                    end = mid - 1;   
                } else {
                    st = mid + 1;    
                }
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target, false);
        return {first, last};
    }
};