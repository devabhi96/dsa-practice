// Check if Array Is Sorted and Rotated - LeetCode 1752 
// link = https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Copy the array, sort it, and check whether the original array
// contains the sorted array as a rotated sequence.

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> arr = nums;

        sort(arr.begin(),arr.end());

        int n  =nums.size();
        for(int i =0; i<n; i++){
            nums.push_back(nums[i]);
        }

        int j = 0;
        for(int i =0; i<nums.size(); i++){
            if(arr[j] == nums[i]){
                j++;
            }
            else{
                j=0;
            }
            if(j == arr.size()){
                return true;
            }
        }
return false;

    }
};