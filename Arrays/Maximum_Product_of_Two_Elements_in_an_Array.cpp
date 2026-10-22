// LeetCode 1464: Maximum Product of Two Elements in an Array
// Approach: Brute Force (Nested Loops)
// Logic: Check every pair of distinct elements and calculate
// (nums[i] - 1) * (nums[j] - 1), updating the maximum product.
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
             int maxi = -1;
        int n = nums.size();

        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i != j){

                
                int  pro = (nums[i]-1) * (nums[j] -1);
                maxi = max(pro,maxi);
            }}
        }

return maxi;
    }
};