// LeetCode 7 - Reverse Integer
// Reverses the digits of a 32-bit signed integer.
// Returns 0 if the reversed value overflows the 32-bit int range.
// Uses long long internally to safely detect overflow (including the
// INT_MIN negation edge case) before casting back down to int.

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        long long temp = x;   
        bool flag = temp < 0;
        if (flag) temp = -temp;

        while (temp > 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;
        }

        if (flag) rev = -rev;

        if (rev < INT_MIN || rev > INT_MAX) return 0;

        return (int)rev;
    }
};