/*
============================================================
Problem: 4Sum
Question No.: LeetCode 18
Link: https://leetcode.com/problems/4sum/

Approach:
- Sorting + Two Pointers
- Fix the first two elements using nested loops.
- Use two pointers (left and right) to find the remaining
  two elements.
- Skip duplicates at every relevant position to ensure that
  the answer contains only unique quadruplets.

How the approach works:
1. Sort the array.
2. Fix nums[i] as the first element.
3. Fix nums[j] as the second element.
4. Set:
      left  = j + 1
      right = n - 1
5. Calculate the sum of nums[i], nums[j], nums[left],
   and nums[right].
6. If sum == target:
      - Store the quadruplet.
      - Move both pointers.
      - Skip duplicate values.
7. If sum < target:
      - Increase left to get a larger sum.
8. If sum > target:
      - Decrease right to get a smaller sum.
9. Skip duplicate values for i and j as well.

Why sorting is used:
- Allows the two-pointer technique to work.
- Helps determine whether to move left or right.
- Makes duplicate handling easier.

Time Complexity:
- Sorting: O(n log n)
- Three effective nested traversals: O(n^3)
- Overall: O(n^3)

Space Complexity:
- O(1) auxiliary space
- O(k) for storing the answer, where k is the number
  of valid quadruplets.

Important:
- Use long long for calculating the sum to avoid integer
  overflow when adding four integers.

============================================================
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i= 0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j = i+1; j<n-2; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }

            int left = j+1;
            int right = n-1;

            while(left < right){
                long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                if(sum == target){
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                    left++;
                    right--;
                
                while(left< right && nums[left] == nums[left-1] ){
                    left++;
                }
                while(left < right && nums[right] == nums[right+1] ){
                    right--;
                }
                }
                else if(sum< target){
                    left++;
                }
                else{
                    right--;
                }


                
            }


            }




        }


return ans;

    }
};