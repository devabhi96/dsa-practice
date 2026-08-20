// LeetCode 152 - Maximum Product Subarray
// Approach: DP tracking running max & min product (handles negatives by swapping on sign flip)
// Time: O(n) | Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxpro = nums[0];
        int minpro = nums[0];
        int result = nums[0];

        for(int i =1; i<nums.size(); i++){
            if(nums[i]<0)
                swap(maxpro,minpro);
            
            maxpro = max(nums[i],maxpro*nums[i]);
            minpro = min(nums[i],minpro*nums[i]);
            result = max(result,maxpro);
        }
        return result;
    }
};