/**
 * Problem: N-th Root of a Number
 * Approach: Binary search for integer x such that x^n == m.
 * power() computes mid^n with early overflow-safe exit if it exceeds m.
 * Edge case: m == 0 handled separately (0^n = 0 for any n > 0).
 * Time: O(log m * n) | Space: O(1)
 */
class Solution {
  public:
    int nthRoot(int n, int m) {
                if(m== 0) return 0;
               
            int st =1; 
            int end =m;
            
            while(st<= end ){
                int mid = st + (end-st)/2;
                int val = power(mid,n,m);
                
                if(val == 1) return mid;
                else if(val == 0) st = mid+1;
                else end = mid-1;
            }
            return -1;
        
    }
    
    int power(int mid ,int n,int m ){
        long long ans =1;
        long long base = mid;
        
        for(int i =1; i<= n; i++){
            ans *= base;
            if(ans > m) return 2;
        }
        if( ans == m) return 1;
        return 0;
    }
};