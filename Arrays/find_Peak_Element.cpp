// Problem: Find Peak Element
// Given an integer array `nums`, find a peak element and return its index.
// A peak element is an element strictly greater than its neighbors.
// nums[-1] and nums[n] are considered -infinity (array boundaries).
// If multiple peaks exist, returning the index of any one is valid.
//
// Approach: Binary Search
// At each `mid`, compare nums[mid] with nums[mid+1]:
//   - If nums[mid] < nums[mid+1]  -> ascending slope, a peak must exist to the right, so st = mid + 1
//   - Otherwise                   -> descending slope (or peak at mid), so end = mid
// Loop until st == end, which converges on a valid peak index.
//
// Time Complexity:  O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int st =0;
        int end =n-1;

        while(st < end){
            int mid = st + (end-st)/2;
          
            if(nums[mid] < nums[mid+1]){
                 st = mid+1;
            }
            else{
                end =mid;
            }

            }




            
       return st; 
    }
};