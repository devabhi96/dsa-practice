/**
 * Problem: Find Rotation Count in Rotated Sorted Array
 * Approach: Binary search — at each step, track the smallest element seen
 * and narrow the search toward the side containing the pivot (minimum).
 * Time: O(log n) | Space: O(1)
 * Note: Assumes distinct elements (no duplicates).
 * Link: https://www.geeksforgeeks.org/problems/rotation4723/1
 */
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int st= 0;
        int end =n-1;
        int small = INT_MAX;
        int minel = 0;
        
        while(st<=end){
            int mid = st + (end-st)/2;
            if(arr[mid] < small){
                small = min(arr[mid],small);
                minel = mid;
            }
            
            
            if(arr[mid] > arr[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
    return minel;
        
    }
};
