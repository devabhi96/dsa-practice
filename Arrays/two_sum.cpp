// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Approach: Single-pass hashmap — store each number's index, check if complement exists
// Time: O(n) | Space: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mpp;

        for(int i =0; i<nums.size(); i++){
            int a = nums[i];
            int b = target-nums[i];
            if(mpp.find(b) != mpp.end()){
                return {mpp[b],i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};