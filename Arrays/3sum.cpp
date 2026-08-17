/*
    LeetCode #15 - 3Sum

    Approach:
    Sorting + Two Pointers

    First, sort the array. Then fix one element using a loop and
    use two pointers (j and k) to find the remaining two elements
    whose sum with nums[i] is zero.

    Duplicate elements are skipped to avoid duplicate triplets.
    The left pointer is increased when the sum is too small, and
    the right pointer is decreased when the sum is too large.

    Time Complexity: O(n²)
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i =0; i<n; i++){            
            
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            int j = i+1;
            int k = n-1;

            while(j<k){
                int sum =nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j] == nums[j-1]){
                            j++;
                    }
                }
                
                if(sum <0 ){
                    j++;
                }
                else if(sum> 0){
                    k--;
                }
            }            
        }
        return ans;
        
    }
};