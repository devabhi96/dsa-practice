/*
    LeetCode #268 - Missing Number

    Approach:
    Sorting

    The array is first sorted, then each element is compared with
    its expected index. The first mismatch gives the missing number.
    If no mismatch is found, the missing number is the next number
    after the last element.

    Time Complexity: O(n log n)
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/missing-number/
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       for(int i =0; i<nums.size(); i++){
        if(nums[i] != i){
            return i;
        }
       }
       return nums[nums.size()-1]+1;
    }
};