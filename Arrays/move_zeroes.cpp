// Move Zeroes - LeetCode 283
//https://leetcode.com/problems/move-zeroes/
// Move all zeroes to the end of the array while maintaining
// the relative order of the non-zero elements.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n<2){
            return;
        }

        int i=0; 
        for(int j =1; j<nums.size(); j++){
            if(nums[i] == 0 && nums[j] != 0 ){
                swap(nums[i],nums[j]);
            }
            if(nums[i] !=0){
                i++;
            }
        }


    }
};