/*
    Question: Binary Search
    Link: https://leetcode.com/problems/binary-search/
    Difficulty: Easy

    Approach:
    Standard binary search on a sorted array. Maintain two pointers,
    st and end, representing the current search range. At each step,
    compare the middle element with target:
      - if equal, return its index
      - if middle < target, discard the left half (search right)
      - if middle > target, discard the right half (search left)
    Repeat until the range is empty (st > end), return -1 if not found.

    Time Complexity: O(log n)  — search range halves every iteration
    Space Complexity: O(1)     — only a few pointer variables used
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st =0;
        int n = nums.size();
        int end = n-1;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                
                st = mid+1;
            }
            else if(nums[mid]>target){
                end = mid-1;
            }
        }
    return -1;
    }
};