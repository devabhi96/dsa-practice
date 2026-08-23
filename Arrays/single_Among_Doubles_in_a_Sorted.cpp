/**
 * Problem: Single Non-Duplicate Element in a Sorted Array
 * (every other element appears exactly twice, one appears once)
 *
 * Approach 1 (SolutionLinear): Linear scan over index pairs (i, i+1),
 *   return the element where the pair breaks.
 *   Time: O(n) | Space: O(1)
 *
 * Approach 2 (SolutionBinarySearch): Binary search on the pairing pattern.
 *   Before the singleton, pairs start at even indices; after it, pairs
 *   start at odd indices. Search for where this flips.
 *   Time: O(log n) | Space: O(1)
 */
class Solution {
  public:
    int single(vector<int>& arr) {
      int n = arr.size();
      if(n <= 1){
          return arr[0];
      }
      
      for(int i = 0; i<n; i += 2){
          if(arr[i] != arr[i+1] && i<= n){
              return arr[i];
          }
      }
      return -1;
        
    }
};



class Solution {
  public:
    int single(vector<int>& arr) {
       int n = arr.size();
       int st =0;
       int end =n-1;
       
       while(st<end){
           int mid = st + (end-st)/2;
           
           if(mid % 2 == 1){
               mid--;
           }
           
           if(arr[mid] == arr[mid+1]){
               st = mid+2;
           }
           else{
               end = mid;
           }
       }
       return arr[st];
        
    }
};