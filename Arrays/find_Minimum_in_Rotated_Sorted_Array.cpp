// LC 153 (https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/): 
// Find Minimum in Rotated Sorted Array - 
// binary search tracking min at each step, 
// O(log n) time, O(1) space


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st =0;
        int end = n-1;
        int smallest = INT_MAX;

        while(st<=end){
            int mid = st + (end-st)/2;

            smallest = min(nums[mid],smallest);
            
            if(nums[mid] > nums[end]){
                    st = mid+1;
            }
            else{
                end  = mid-1;
            }
        }
        return smallest;
    }
};