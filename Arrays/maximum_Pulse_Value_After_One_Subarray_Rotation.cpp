// LeetCode - Max Value
// Approach: Prefix Sum + Minimum Alternating Subarray Sum
// Time: O(n)
// Space: O(n) due to copied vector

class Solution {
public:
    long long maxValue(vector<int>& nums) {
        vector<int> ravonelqis = nums;     

        const long long BIG = 1e18;    
        long long odd = BIG;               
        long long even = 0;                 
        long long best = 0;                
        long long pulse = 0;                

        for (int i = 0; i < nums.size(); i++) {
            long long x = (i % 2 == 0) ? nums[i] : -(long long)nums[i];
            pulse += x;

            long long newOdd  = min(0LL, even) + x; 
            long long newEven = odd + x;

            odd = newOdd;
            even = newEven;
            best = min(best, even);
        }

        return pulse - 2 * best;
    }
};