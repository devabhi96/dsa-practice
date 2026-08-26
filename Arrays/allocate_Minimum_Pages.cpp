/*
 * Problem : Allocate Minimum Pages
 * Approach: Binary search on the answer.
 *
 *   - Search space: [max(arr), sum(arr)]
 *       lo = max(arr)  -> minimum possible answer, since whichever
 *                          student gets the largest book must carry
 *                          at least that many pages.
 *       hi = sum(arr)  -> maximum possible answer, when a single
 *                          student is allocated all the books.
 *
 *   - For a candidate "mid" (max pages allowed per student), isvalid()
 *     greedily walks the array, accumulating pages into the current
 *     student's pile and starting a new student whenever adding the
 *     next book would exceed mid. It returns true if the number of
 *     students required is <= k.
 *
 *   - Feasibility is monotonic in mid (looser caps never need more
 *     students), so binary search over mid finds the smallest
 *     feasible value.
 *
 * Time complexity : O(n log(sum(arr) - max(arr)))
 * Space complexity: O(1) extra
 */
class Solution {
  public:
    bool isvalid(vector<int>&arr , int n ,int k,long long mid){
        int st =1;
        long long pages = 0;
        
        for(int  i =0; i<n; i++){
            
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }
            else{
                st++;
                pages = arr[i];
            }
        }
        
        if(st>k){
            return false;
        }
        else{
            return true;
        }
    }
  
  
    int findPages(vector<int> &arr, int k) {
         int n = arr.size();
        long long st =0;
         long long end = n-1;
         long long ans = -1;
         
         if(k> n){
             return -1;
         }
         
         for(int x : arr){
             st = max(st,(long long)x);
             end += x;
         }
         
         
         while(st <= end){
             long long mid = st + (end-st)/2;
             
             if(isvalid(arr,n,k,mid)){
                 ans = mid;
                 end = mid-1;
             }
             else{
                 st = mid+1;
             }
         }
        return (int)ans;
    }
};