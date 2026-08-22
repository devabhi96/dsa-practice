/*
LC 81 
(https://leetcode.com/problems/search-in-rotated-sorted-array-ii/):
Search in Rotated Sorted Array II -
add unordered_set brute force (O(n)
time, O(n) space) and modified binary 
search (O(log n) avg / O(n) worst case time,
O(1) space) handling duplicates via nums[mid]==nums[end]
ambiguity shrink
 */


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        unordered_set<int> st(nums.begin(),nums.end());
        int n = nums.size();

        for(int i =0; i<n; i++){
            if(st.find(target) !=  st.end()){
                return true;
            }
        }
    return false;
    }
};


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        int st =0;
        int end =n-1;

        while(st<= end){
            int mid = st + (end-st)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[end]){
    end--;               
    continue;
}
            if(nums[mid] > nums[end]){
                if(target >= nums[st] && target < nums[mid]){
                    end = mid-1;
                }
                else{
                    st = mid+1;
                }
            }
            else{
               if(target > nums[mid] && target <= nums[end]){
                st = mid+1;
               }
               else{
                end = mid-1;
               }
            }
        }
        return false;
    }
};