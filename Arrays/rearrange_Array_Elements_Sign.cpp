//Implemented O(n) time and O(n) space solution for LeetCode 2149 by placing positive elements
//at even indices and negative elements at odd indices.
// link = https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int j = 1;
        int k =0;
        for(int i =0; i<n; i++){
            if(nums[i] > 0){
                ans[k] = nums[i];
                k+=2;
            } 
            else{
            ans[j] = nums[i];
            j+=2;
        }}
        return ans;
    }
};