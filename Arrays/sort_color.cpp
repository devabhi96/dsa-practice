/*
================================================================================
Problem: Sort Colors
Question No.: LeetCode 75
Link: https://leetcode.com/problems/sort-colors/

Problem Statement:
Given an array nums containing only 0, 1, and 2, sort the array in-place so
that objects of the same color are adjacent, with the colors in the order
0, 1, and 2.

================================================================================
APPROACH 1: Brute Force / Comparison-Based Sorting
================================================================================

Idea:
- Use two nested loops to compare elements.
- For every index i, compare nums[i] with all elements to its right.
- If a smaller element is found, swap it with nums[i].
- This eventually sorts the entire array.

Time Complexity: O(n^2)
Space Complexity: O(1)

Advantages:
- Simple and easy to understand.
- Works for any integer array, not just arrays containing 0, 1, and 2.

Disadvantage:
- Not optimal for this problem because it performs unnecessary comparisons.

================================================================================
APPROACH 2: Counting 0s, 1s, and 2s
================================================================================

Idea:
- Since the array contains only 0, 1, and 2, count the frequency of each
  value first.
- Store the counts of 0, 1, and 2 separately.
- Traverse the array again and place:
      - all 0s first
      - then all 1s
      - then all 2s

Steps:
1. Traverse the array and count the number of 0s, 1s, and 2s.
2. Traverse the array again.
3. Fill positions with 0 while zerocnt > 0.
4. Then fill positions with 1 while onecnt > 0.
5. Fill the remaining positions with 2.

Time Complexity: O(n)
    - First traversal for counting: O(n)
    - Second traversal for reconstruction: O(n)
    - Overall: O(n)

Space Complexity: O(1)
    - Only three integer counters are used.
    - Sorting is performed in-place.

Advantages:
- Much more efficient than the brute-force approach.
- Takes linear time.
- Uses constant extra space.

================================================================================
COMPARISON
================================================================================

Approach 1:
    Time  : O(n^2)
    Space : O(1)

Approach 2:
    Time  : O(n)
    Space : O(1)

Therefore, Approach 2 is better for this specific problem.

Note:
The most optimal and commonly expected approach for this problem is the
Dutch National Flag Algorithm, which also achieves O(n) time and O(1) space
while sorting the array in a single traversal.

================================================================================
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                if(nums[j]<nums[i]){
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                }
            }
        }
  
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int onecnt =0;
        int zerocnt =0;
        int twocnt =0;

        for(int i =0; i<n; i++){
            if(nums[i] == 0){
                zerocnt++;
            }
            if(nums[i] == 1){
                onecnt++;
            }
            if(nums[i] == 2){
                twocnt++;
            }
        }

        for(int i =0; i<n; i++){
            if(zerocnt > 0){
                nums[i] = 0;
                zerocnt--;
              
            }
            else if(onecnt > 0){
                nums[i] = 1;
                onecnt--;
             
            }
            else{
                nums[i] = 2;
                twocnt --;
            }
        }

    }
};