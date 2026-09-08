// LeetCode 136 - Single Number
// Every element appears twice except one — find it.
// Approach: XOR all elements. a^a=0 and a^0=a, so pairs cancel out,
// leaving only the unique number.
// Time: O(n) | Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
                int n= nums.size();
                int ans= 0;
                for(int i=0;  i<n; i++){
                    ans= ans^nums[i];
                }
                return ans;
    }
};