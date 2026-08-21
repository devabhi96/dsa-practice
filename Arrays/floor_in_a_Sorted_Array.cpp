/*
    Question: Find Floor of an element in a Sorted Array
    Link: https://www.geeksforgeeks.org/problems/find-the-floor-in-a-sorted-array/1
    Difficulty: Easy

    Approach:
    Binary search for the floor (largest element <= x). At each step,
    if arr[mid] <= x, it's a valid floor candidate — store it in ans
    and search the right half for a possibly larger valid floor
    (st = mid + 1). Otherwise, discard the right half and search left
    (end = mid - 1). If no element satisfies arr[mid] <= x, ans stays
    -1, correctly indicating no floor exists.

    Time Complexity: O(log n)  — search range halves every iteration
    Space Complexity: O(1)     — only a few pointer variables used
*/
class Solution {
  public:
    int findFloor(vector<int>& arr, int x) {
       
        int n = arr.size();
        
        int st =0;
        int end =n-1;
        int ans = -1;
        while(st<= end){
            int mid = st+ (end-st)/2;
            if(arr[mid] <= x){
             ans = mid;
             st = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return ans;
    }
};
