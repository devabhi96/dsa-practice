/**
 * LeetCode 8 - String to Integer (atoi)
 * ---------------------------------------
 * Implements a simplified version of C's atoi/stoi: parses an
 * optional leading whitespace, an optional sign, then as many
 * consecutive digits as possible, and converts them to an integer.
 *
 * Approach: Single-pass manual parsing.
 *   - Skip leading spaces.
 *   - Capture sign (+/-) if present.
 *   - Accumulate digits into a `long` to safely detect overflow
 *     before casting down to `int`.
 *   - Clamp to INT_MAX / INT_MIN on overflow, matching atoi behavior.
 *
 * Time Complexity:  O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int myAtoi(string s) {
        int i =0;
        int n = s.length();
        int sign = 1;
        long result = 0;

        while(i<n && s[i] == ' ') i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

     while (i < n && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;

        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
    }

    return (int)(result * sign);


    }
};