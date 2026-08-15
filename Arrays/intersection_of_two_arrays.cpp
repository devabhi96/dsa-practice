/*
    LeetCode #349 - Intersection of Two Arrays

    Approach:
    Two Pointer Approach with Sorting

    First, sort both arrays. Then use two pointers to traverse
    both arrays simultaneously. When both elements are equal,
    add the element to the result only if it is not already present.
    If nums1[i] is greater, move j forward; otherwise, move i forward.

    Time Complexity: O(n log n + m log m)
    Space Complexity: O(1) auxiliary space

    Question:
    https://leetcode.com/problems/intersection-of-two-arrays/
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      vector<int> ans;
      sort(nums1.begin(),nums1.end());
      sort(nums2.begin(),nums2.end());  
    

        int i =0;
        int j = 0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
             if (ans.empty() || ans.back() != nums1[i]){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
                else if(nums1[i] > nums2[j]){
                    j++;
                }
                else{
                    i++;
                }
            }
        

return ans;
    }
};