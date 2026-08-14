/*
    Problem: Remove Duplicates from Sorted Array

    https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    Approach:
    - Use a two-pointer technique.
    - 'i' traverses the array and checks for unique elements.
    - 'j' keeps track of the position where the next unique element
      should be placed.
    - Since the array is sorted, an element is unique if it is
      different from the previous element.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();

        int j =1;

        for(int i =1; i<n; i++){
              
                if(nums[i] != nums[i-1] ){
                    nums[j] = nums[i];
                    j++;
                }

        } 
        return j;
    }
};