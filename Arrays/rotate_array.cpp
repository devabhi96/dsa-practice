// Rotate Array - LeetCode 189
// link = https://leetcode.com/problems/rotate-array/
// Rotate the array to the right by k positions using the reverse method.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n  =nums.size();
        k = k %n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};