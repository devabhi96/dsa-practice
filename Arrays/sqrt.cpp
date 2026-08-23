/**
 * Problem: Sqrt(x) — Integer Square Root
 * Approach: Binary search for the largest integer `ans` such that
 * ans*ans <= x.
 * Time: O(log x) | Space: O(1)
 */
class Solution {
public:
    int mySqrt(int x) {
        if ( x == 0 || x == 1){
            return x;
        }

        long long st =0; 
        int end = x;
        int ans =1;

        while(st<=end){
            long long mid = st + (end-st)/2;

            if(mid * mid <= x ){
                ans = mid;
                st= mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};