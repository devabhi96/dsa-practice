/*
 * LeetCode 4 - Median of Two Sorted Arrays
 * Difficulty: Hard
 *
 * Given two sorted arrays nums1 and nums2, return the median of the
 * two arrays combined.
 *
 * Approach: Merge & Sort (brute force)
 * - Concatenate both arrays into one
 * - Sort the combined array
 * - If size is odd, return the middle element
 * - If size is even, return the average of the two middle elements
 *
 * Time Complexity:  O((n+m) log(n+m))  due to sorting
 * Space Complexity: O(n+m) for the combined array
 *
 * Note: This does not meet the problem's optimal requirement of
 * O(log(n+m)) time, which would require a binary search approach
 * instead of merging and sorting.
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            ans.insert(ans.end(),nums1.begin(),nums1.end());
            ans.insert(ans.end(),nums2.begin(),nums2.end());
            sort(ans.begin(),ans.end());
            int n = ans.size();

            if(n%2 == 1){
                return ans[n/2];
            }
            else{
                return (ans[n/2 -1] + ans[n/2])/2.0;
            }


    }
};