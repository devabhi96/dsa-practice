
/**
 * LeetCode 169. Majority Element
 * 
 * Approach: Sorting
 * Sort the array; the majority element (appears > n/2 times) 
 * is guaranteed to occupy the middle index n/2.
 * 
 * Time Complexity:  O(n log n)
 * Space Complexity: O(1) (or O(log n)/O(n) depending on sort implementation)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         int n= nums.size();
         sort(nums.begin(),nums.end());
         
         return nums[n/2];
         
    }
};