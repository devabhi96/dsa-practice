/**
 * LeetCode 29. Divide Two Integers
 * https://leetcode.com/problems/divide-two-integers/
 *
 * Divide two integers without using multiplication, division, or mod.
 * Result is truncated toward zero and clamped to 32-bit signed int range.
 *
 * Approach: Bit-shift (exponential subtraction)
 *   - Work with absolute values in `long long` to avoid overflow (esp. INT_MIN).
 *   - Repeatedly find the largest power-of-two multiple of the divisor that
 *     fits into the remaining dividend, subtract it, and accumulate that
 *     multiple into the quotient.
 *   - Apply the sign at the end and clamp to [INT_MIN, INT_MAX].
 *
 * Time:  O(log^2 n)  — outer loop O(log n), inner doubling O(log n)
 * Space: O(1)
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
      
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
     
        long long dvd = dividend;
        long long dvs = divisor;
        
 
        bool negative = (dvd < 0) ^ (dvs < 0);
        
   
        if (dvd < 0) dvd = -dvd;
        if (dvs < 0) dvs = -dvs;
        
        long long quotient = 0;
        
        while (dvd >= dvs) {
            long long temp = dvs, multiple = 1;
           
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            quotient += multiple;
        }
        
    
        if (negative) quotient = -quotient;
        

        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        return (int)quotient;
    }
};