//LC 1498 (Number of Subsequences That Satisfy
//     the Given Sum Condition) — 
//     https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/ —
//    Two-pointer + precomputed powers of 2 approach —
//      Time: O(n log n) (sort dominates; scan and precompute are O(n)) — Space: O(n) (pow2 array)
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        const int MOD = 1e9 +7;
        vector<int> pow2(n,1);

        for(int i=1; i<n; i++){
            pow2[i] = (pow2[i-1] *2)%MOD;
        }
            int ans =0;
            int i =0;
            int j = n-1;

            while(i<= j){
                if(nums[i] + nums[j] <= target){
                    ans = (ans + pow2[j-i])%MOD;
                    i++;
                }
                else{
                    j--;
                }        
            }

return ans;
    }
};