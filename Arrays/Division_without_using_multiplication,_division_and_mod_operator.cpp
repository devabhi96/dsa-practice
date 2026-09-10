/*
 * Problem   : Divide Two Integers Without Using Multiplication, Division, or Mod Operator
 * Link      : https://www.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1
 * Approach  : Bit manipulation - repeated doubling of divisor (binary long division)
 * Time      : O(log n) - divisor is doubled via left-shift each pass, quickly narrowing the remainder
 * Space     : O(1)
 * Notes     : Uses long long + XOR on sign checks to safely handle INT_MIN / negative operands
 *             without overflow.
 */


class Solution {
public:
    int divide(int a, int b) {
        long long la = a, lb = b;
        bool isNegative = (la < 0) ^ (lb < 0);   // XOR to determine result sign

        la = llabs(la);
        lb = llabs(lb);

        long long ans = 0;

        while (la >= lb) {
            long long temp = lb, multiple = 1;
            while (la >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            la -= temp;
            ans += multiple;
        }

        return isNegative ? -ans : ans;
    }
};