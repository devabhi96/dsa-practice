// LeetCode 55. Jump Game
// Approach: Greedy — track the farthest reachable index while
//           scanning left to right. If current index exceeds
//           the farthest reachable point, return false.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currjump = 0;
   

        for(int i =0; i<n; i++){
            if(i > currjump){
                return false;
            }

        currjump = max(currjump, nums[i] +i);
        }
        return true;
    }
};