/*
    Question: Search Insert Position
    Link: https://leetcode.com/problems/search-insert-position/
    Difficulty: Easy

    Approach:
    Standard binary search on a sorted array. Maintain two pointers,
    st and end, representing the current search range. At each step,
    compare the middle element with target:
      - if equal, return its index
      - if middle < target, discard the left half (search right)
      - if middle > target, discard the right half (search left)
    If target is not found, the loop exits when st > end. At this
    point, st naturally points to the correct insert position —
    the first index where target could be inserted while keeping
    the array sorted.

    Time Complexity: O(log n)  — search range halves every iteration
    Space Complexity: O(1)     — only a few pointer variables used
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
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
    return st;
    }
};