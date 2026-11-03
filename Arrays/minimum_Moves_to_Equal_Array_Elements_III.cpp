//3736. Minimum Moves to Equal Array Elements III

// Approach: Find Maximum Element
// Initialize maxel with INT_MIN.
// Traverse the array to find the maximum element.
// Initialize ans = 0.
// Traverse the array again and calculate the difference between the maximum element and each array element.
// Add all differences to ans.
// Return ans.
// Time Complexity
// O(n): Two traversals of the array.
// Space Complexity
// O(1): Only constant extra space is used.
// Key Idea
// The minimum number of moves is obtained by increasing every element to the maximum element in the array.

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxel = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxel){
                maxel = nums[i];
            }
        }

        int ans= 0;

        for(int i=0; i<nums.size(); i++){
            ans += maxel - nums[i];
        }
        
return ans;

    }
};